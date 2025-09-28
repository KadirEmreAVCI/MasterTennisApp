#include "Stat.h"
#include "Score.h"
// template <typename T, typename FuncCond>
// void Stat<T, FuncCond>::AssignDataByFilter(const std::vector<T>& vecData)
// {
//     m_vecData = std::copy_if(vecData.cbegin(), vecData.cend(), vecData.cbegin(), FuncCond);
// }
// template <typename T, typename FuncCond>
// size_t Stat<T, FuncCond>::GetCount()const
// {
//     return m_vecData.size();
// }
// template <typename T, typename FuncCond>
// size_t Stat<T, FuncCond>::GetWins()const
// {
//     return std::count_if(m_vecData.cbegin(), m_vecData.cend(), [](const T& item){item.GetOutcome() == Outcome::HomeWin; });
// }
// template <typename T, typename FuncCond>
// size_t Stat<T, FuncCond>::GetLoses()const
// {
//     return GetCount() - GetWins();
// }
// template <typename T, typename FuncCond>
// float Stat<T, FuncCond>::GetWinRatePercentage()const
// {
//     size_t szWin = GetWins();
//     size_t szLose = GetLoses();
//     return (szWin + szLose != 0) ? static_cast<float>(szWin) / (szWin + szLose) * 100.0f : 0.0f;
// }