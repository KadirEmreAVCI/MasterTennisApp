#pragma once
#include <iostream>
#include <vector>
#include <optional>
#include <utility>
#include <string>
#include "SetScore.h"
enum class MaxSetInMatch {
	eBest_of_1 = 1,
	eBest_of_3 = 3, 
	eBest_of_5 = 5
};
enum class MatchStatus {
	ePlayed = 0,
	eWO = 1,
	eBYE = 2
};
enum class MatchResult {
	eLose = 0,
	eWin = 1,
	eNA = 2
};
class Match {
public:
	using enum MatchStatus;
	Match(MatchStatus eMatchStatus, MaxSetInMatch eMaxSetInMatch);
	std::pair<unsigned int, unsigned int> getMatchScore()const;
	SetScore getSetScore(unsigned int uiSetIdx)const;
	void setSetScore(unsigned int uiSetIdx, const SetScore&);
	std::pair<std::string, std::optional<std::string> > getHomeName()const;
	std::pair<std::string, std::optional<std::string> > getAwayName()const;

	// TODO: setHomeName ve setAwayName fonksiyonlari yazilacak.
	void setHomeName(std::pair<std::string, std::optional<std::string> >);
	void setAwayName(std::pair<std::string, std::optional<std::string> >);

private:
	void InitSets();
	void UpdateMatchScore(const SetScore& ss);
	bool IsSetPlayed(unsigned int uiSetIdx)const;
	void ClearSetScore(unsigned int uiSetIdx);
	const unsigned int m_uiMaxSet;
	// TODO: m_eMatchStatus get ve set fonksiyonlari yazilabilir
	const MatchStatus m_eMatchStatus{ePlayed};
	unsigned int m_uiHomeScore{};
	unsigned int m_uiAwayScore{};
	std::vector<std::optional<SetScore> > m_vecSetScore;
	std::pair<std::string, std::optional<std::string> > m_sHomeName;
	std::pair<std::string, std::optional<std::string> > m_sAwayName;
	// TODO: Match Date isimli veri elemani eklenecek(ODate).
};

