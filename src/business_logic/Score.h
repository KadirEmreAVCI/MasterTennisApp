#ifndef SCORE_H
#define SCORE_H

// Project Headers
#include "Common.h"

// Standar Headers
#include <iostream>
#include <utility>
// enum class Outcome {
// 	HomeWin = 0,
// 	AwayWin = 1,
// 	Tied = 2
// };
class Score
{
public:
	explicit Score(unsigned uiHomeScore = 0, unsigned uiAwayScore = 0);
	std::pair<unsigned, unsigned> GetScore()const;
	unsigned GetHomeScore()const;
	unsigned GetAwayScore()const;
	common::Outcome GetOutcome()const;
	std::string ToString()const;
	static Score FromString(const std::string&);
	friend bool operator==(const Score& lhs, const Score& rhs)
	{
		return (lhs.GetHomeScore() == rhs.GetHomeScore()) && (lhs.GetAwayScore() == rhs.GetAwayScore());
	}
	friend std::ostream& operator<<(std::ostream& os, const Score& s)
	{
		return os << s.m_Score.first << "-" << s.m_Score.second;
	}
private:
	std::pair<unsigned, unsigned> m_Score;
};

#endif