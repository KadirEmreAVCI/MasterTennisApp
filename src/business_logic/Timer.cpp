#include "Timer.h"

Timer::Timer(TimerMode eTimerMode, std::chrono::steady_clock::duration rDelay, std::function<void()> funcTimer)
    : 
    m_eTimerMode{eTimerMode}, 
    m_rDelay{rDelay}, 
    m_FuncTimer{std::move(funcTimer)}
{}

Timer::~Timer() 
{
    Stop();
}
bool Timer::Start()
{
    if(m_tTimer.joinable() && !IsRunning() && std::this_thread::get_id() != m_tTimer.get_id())
    {
        m_tTimer.join();
    }
    if(!m_tTimer.joinable())
    {
        {
            std::lock_guard<std::mutex> lock{m_mtxTimer};
            m_blStopRequested = false;
        }
        m_blRunning.store(true, std::memory_order_release);
        m_tTimer = std::thread{[this]()
        {
            while(true)
            {
                std::unique_lock<std::mutex> ulock{m_mtxTimer};
                if(m_cvTimer.wait_for(ulock, m_rDelay, [this](){ return m_blStopRequested; }))
                {
                    break;
                }
                ulock.unlock();
                m_FuncTimer();
                if(m_eTimerMode == TimerMode::OneShot)
                {
                    break;
                }
            }
            m_blRunning.store(false, std::memory_order_release);
        }};
        return true;
    }
    else
    {
        return false;
    }
}
void Timer::Stop()
{
    {
        std::lock_guard<std::mutex> lock{m_mtxTimer};
        m_blStopRequested = true;
    }
    m_cvTimer.notify_one();
    if(m_tTimer.joinable())
    {
        if(std::this_thread::get_id() != m_tTimer.get_id())
        {
            m_tTimer.join();
        }
    }
    m_blRunning.store(false, std::memory_order_release);
}
bool Timer::Restart()
{
    Stop();
    return Start();
}
void Timer::Reset(std::chrono::steady_clock::duration rDelay)
{
    if(m_tTimer.joinable())
    {
        Stop();
    }
    {
        std::lock_guard<std::mutex> lock{m_mtxTimer};
        m_rDelay = rDelay;
    }
}     
void Timer::Reset(std::function<void()> funcTimer)
{
    if(m_tTimer.joinable())
    {
        Stop();
    }
    {
        std::lock_guard<std::mutex> lock{m_mtxTimer};
        m_FuncTimer = std::move(funcTimer);
    }
}
void Timer::Reset(std::chrono::steady_clock::duration rDelay, std::function<void()> funcTimer)
{
    if(m_tTimer.joinable())
    {
        Stop();
    }
    {
        std::lock_guard<std::mutex> lock{m_mtxTimer};
        m_rDelay = rDelay;
        m_FuncTimer = std::move(funcTimer);
    }
}
bool Timer::IsRunning() const
{
    return m_blRunning.load(std::memory_order_acquire);
}