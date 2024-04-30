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
	Match(MatchStatus eMatchStatus, std::string sStage, std::pair<std::string, std::optional<std::string> > sAwayName, unsigned uiMaxSetInMatch = 3, unsigned uiMinGameToWinSet = 6);
	std::pair<unsigned, unsigned> getScore()const;
	Set GetSet(unsigned uiSetIdx)const;
	void AddSet(unsigned uiSetIdx, const Set&);
	std::pair<std::string, std::optional<std::string> > getAwayName()const;
	void setAwayName(std::pair<std::string, std::optional<std::string> >);
	MatchWinner WinnerOfTheMatch()const;
	MatchStatus GetMatchStatus()const;
	void SetMatchStatus(MatchStatus);
	std::string GetStage()const;
private:
	void InitSets();
	void Walkover();
	void IncrementScore(const Set& ss);
	void DecrementScore(unsigned uiSetIdx);
	bool IsSetPlayed(unsigned uiSetIdx)const;
	unsigned GetMinSetNeededToWin()const;
	unsigned m_uiMaxSet;
	unsigned m_uiMinGameToWinSet;
	MatchStatus m_eMatchStatus{ePlayed};
	const std::string m_sStage;
	unsigned m_uiHomeScore{};
	unsigned m_uiAwayScore{};
	std::vector<std::optional<Set> > m_vecSetScore;
	std::pair<std::string, std::optional<std::string> > m_sAwayName;
	// TODO: Match Date isimli veri elemani eklenecek(QDate).
};

