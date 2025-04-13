#pragma once
#include <iostream>
#include <utility>
#include <optional>
#include "Score.h"

class Set{
public:
	explicit Set(const Score& MajorScore = Score(0,0), std::optional<Score> TBScore = std::nullopt);
	Score GetMajorScore()const;
	void SetSetScore(const Score& ss, std::optional<Score> ts = std::nullopt);
	Score GetTBScore()const;
	void SetTBScore(const Score&);
	void Clear();
	Outcome GetOutcome()const;
	bool IsSetTBPlayed()const;
	std::string ToString()const;
	static Set FromString(const std::string&);
	friend bool operator==(const Set& lhs, const Set& rhs)
	{
		return	lhs.m_MajorScore == rhs.m_MajorScore &&
				lhs.GetTBScore() == rhs.GetTBScore();
	}
	friend std::ostream& operator<<(std::ostream& os, const Set& s)
	{
		os << s.m_MajorScore;
		if (s.IsSetTBPlayed())
			os << "(" << s.m_optTBScore.value() << ")";
		return os;
	}
private:
	Score m_MajorScore = Score(0,0);
	std::optional<Score> m_optTBScore = Score(0,0);
};

