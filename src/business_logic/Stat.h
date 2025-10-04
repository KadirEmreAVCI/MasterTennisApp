#ifndef STAT_H
#define STAT_H

// Project Headers
#include "Score.h"

// Standard Headers
#include <vector>
#include <algorithm>

struct StatReport{
public:
	StatReport(unsigned uiWin, unsigned uiLose, float fWinRatePercentage) : m_uiWin(uiWin), m_uiLose(uiLose), m_fWinRatePercentage{fWinRatePercentage}{}
	unsigned m_uiWin = 0;
	unsigned m_uiLose = 0;
    float m_fWinRatePercentage = 0.0f;
    friend bool operator==(const StatReport& lhs, const StatReport& rhs)
    {
        return lhs.m_uiWin == rhs.m_uiWin && lhs.m_uiLose == rhs.m_uiLose && lhs.m_fWinRatePercentage == rhs.m_fWinRatePercentage;
    }
    friend std::ostream& operator<<(std::ostream& os, const StatReport& rStatReport)
    {
        return os << "Win = " << rStatReport.m_uiWin << ", Lose = " << rStatReport.m_uiLose << ", Win Rate = " << rStatReport.m_fWinRatePercentage << "\n";
    }
};

inline constexpr auto DefaultTrue = [] (auto const&) { return true; };

template <typename T, typename FuncCond = decltype(DefaultTrue)>
class Stat{
public:
    Stat() = default;
	void AssignDataByFilter(const std::vector<T>& vecData, FuncCond fCond = FuncCond{})
    {
        m_vecData.clear();
        std::copy_if(vecData.cbegin(), vecData.cend(), std::back_inserter(m_vecData), fCond);
    }
    StatReport GetStatReport()const
    {
        return StatReport(GetWins(), GetLoses(), GetWinRatePercentage());
    }
private:
	size_t GetCount()const
    {
        return m_vecData.size();
    }
	size_t GetWins()const
    {
        return std::count_if(m_vecData.cbegin(), m_vecData.cend(), [](const T& item){return item.GetOutcome() == Outcome::HomeWin; });
    }
	size_t GetLoses()const
    {
        return GetCount() - GetWins();
    }
    float GetWinRatePercentage()const
    {
        size_t szWin = GetWins();
        size_t szLose = GetLoses();
        return (szWin + szLose != 0) ? static_cast<float>(szWin) / (szWin + szLose) * 100.0f : 0.0f;
    }
private:
	std::vector<T> m_vecData;
};

#endif