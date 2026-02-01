#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

enum class TimerMode {
    OneShot,
    Periodic
};

class Timer{
public:   
    Timer(TimerMode eTimerMode, std::chrono::steady_clock::duration rDelay, std::function<void()> funcTimer);
    Timer(const Timer&) = delete;
    Timer& operator=(const Timer&) = delete;
    ~Timer();
    bool Start();
    void Stop();
    bool Restart();
    void Reset(std::chrono::steady_clock::duration rDelay);              
    void Reset(std::function<void()> funcTimer);                               
    void Reset(std::chrono::steady_clock::duration rDelay, std::function<void()> funcTimer);
    bool IsRunning() const;
private:
    const TimerMode m_eTimerMode;
    std::chrono::steady_clock::duration m_rDelay;
    std::function<void()> m_FuncTimer;    
    mutable std::mutex m_mtxTimer;
    std::condition_variable m_cvTimer;
    std::thread m_tTimer;
    bool m_blStopRequested{false};
    std::atomic<bool> m_blRunning{false};
};

#endif // TIMER_H