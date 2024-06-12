#pragma once
#include <iostream>
#include <utility>
#include "Config.h"
class Score
{
public:
	Score(unsigned uiHomeScore = 0, unsigned uiAwayScore = 0);
	std::pair<unsigned, unsigned> GetScore()const;
	void SetScore(std::pair<unsigned, unsigned>);
	unsigned GetHomeScore()const;
	unsigned GetAwayScore()const;
	bool operator==(const Score& score)const;
	bool operator!=(const Score& score)const;
	void Clear();
	Winner GetWinner()const;
	unsigned GetDiff()const;
	std::string ToString()const;
	friend std::ostream& operator<<(std::ostream& os, const Score& s)
	{
		return os << s.m_Score.first << "-" << s.m_Score.second;
	}
private:
	std::pair<unsigned, unsigned> m_Score;
};

