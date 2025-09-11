#ifndef SET_H
#define SET_H

#include <iostream>
#include <utility>
#include <optional>
#include "Score.h"

class Set{
public:
	explicit Set(const Score& MajorScore = Score(0,0), std::optional<Score> TBScore = std::nullopt);
	Score GetMajorScore()const;
	Score GetTBScore()const;
	Outcome GetOutcome()const;
	bool IsSetTBPlayed()const;
	bool IsValid()const;
	std::string ToString()const;
	static Set FromString(const std::string&);
	friend bool operator==(const Set& lhs, const Set& rhs)
	{
		return	lhs.GetMajorScore() == rhs.GetMajorScore() && lhs.GetTBScore() == rhs.GetTBScore();
	}
	friend std::ostream& operator<<(std::ostream& os, const Set& s)
	{
		os << s.m_MajorScore;
		if (s.IsSetTBPlayed())
			os << "(" << s.m_optTBScore.value() << ")";
		return os;
	}
private:
	bool IsUninitialized()const;
	bool IsSetScoreEqual()const;
	bool IsOutcomeValid()const;
	Score m_MajorScore = Score(0,0);
	std::optional<Score> m_optTBScore = Score(0,0);
};

#endif