#pragma once
#include <iostream>
#include <utility>
#include <optional>
#include "Score.h"
#include "Config.h"

class Set{
public:
	Set(bool blSuperTB, const Score& MajorScore = (0,0), std::optional<Score> TBScore = std::nullopt, unsigned uiGameToWinSet = 6, unsigned uiPointToWinSetTB = 7, unsigned uiPointToWinSuperTB = 10);
	Score GetMajorScore()const;
	void SetSetScore(const Score& ss, std::optional<Score> ts = std::nullopt);
	Score GetTBScore()const;
	void SetTBScore(const Score&);
	void Clear();
	Winner GetWinner()const;
	bool IsValid()const;
	bool IsSuperTB()const;
	void SetSuperTB(bool blSuperTB);
	std::string ToString()const;
	friend std::ostream& operator<<(std::ostream& os, const Set& s)
	{
		os << s.m_MajorScore;
		if (s.IsSetTBPlayed())
			os << "(" << s.m_optTBScore.value() << ")";
		return os;
	}
private:
	bool IsSetTBPlayed()const;
	unsigned m_uiGameToWinSet;
	unsigned m_uiPointToWinSetTB;
	unsigned m_uiPointToWinSuperTB;
	Score m_MajorScore = (0,0);
	std::optional<Score> m_optTBScore = (0,0);
	bool m_blSuperTB{false};
};

