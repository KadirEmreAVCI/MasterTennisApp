#pragma once
#include <iostream>
#include <vector>
#include <optional>
#include <utility>
#include <string>
#include "Set.h"
enum class MatchWinner {
	eHome = 1,
	eAway = 2
};
class Match {
public:
	using enum MatchStatus;
	Match(MatchStatus eMatchStatus, std::pair<std::string, std::optional<std::string> > sAwayName, unsigned uiMaxSetInMatch = 3, unsigned uiMinGameToWinSet = 6);
	std::pair<unsigned, unsigned> getMatchScore()const;
	Set getSetScore(unsigned uiSetIdx)const;
	void setSetScore(unsigned uiSetIdx, const Set&);
	std::pair<std::string, std::optional<std::string> > getAwayName()const;
	void setAwayName(std::pair<std::string, std::optional<std::string> >);
	MatchWinner WinnerOfTheMatch()const;
	MatchStatus getMatchStatus()const;
private:
	void InitSets();
	void IncrementMatchScore(const Set& ss);
	void DecrementMatchScore(unsigned uiSetIdx);
	bool IsSetPlayed(unsigned uiSetIdx)const;
	unsigned GetMinSetNeededToWin()const;
	const unsigned m_uiMaxSet;
	const unsigned m_uiMinGameToWinSet;
	const MatchStatus m_eMatchStatus{ePlayed};
	unsigned m_uiHomeScore{};
	unsigned m_uiAwayScore{};
	std::vector<std::optional<Set> > m_vecSetScore;
	std::pair<std::string, std::optional<std::string> > m_sAwayName;
	// TODO: Match Date isimli veri elemani eklenecek(ODate).
};

