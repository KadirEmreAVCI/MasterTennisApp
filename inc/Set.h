#pragma once
#include <utility>
#include <optional>
enum class MatchStatus {
	eUpcoming,
	ePlayed,
	eWO_W,
	eWO_L,
	eBYE
};
enum class SetWinner {
	eHome = 1, 
	eAway = 2
};
class Set{
public:
	Set(unsigned uiMinGameNeededToWin = 6);
	Set(std::pair<unsigned, std::optional<unsigned> > HomeScore, std::pair<unsigned, std::optional<unsigned> > AwayScore, unsigned uiMinGameNeededToWin = 6);
	std::pair<unsigned, std::optional<unsigned> > getHomeScore()const;
	std::pair<unsigned, std::optional<unsigned> > getAwayScore()const;
	void setHomeScore(std::pair<unsigned, std::optional<unsigned> > HomeScore);
	void setAwayScore(std::pair<unsigned, std::optional<unsigned> > AwayScore);	
	SetWinner WinnerOfTheSet()const;
	bool IsTiebreakPlayed()const;
	void Walkover(MatchStatus);
private:
	unsigned int m_uiMinGameNeededToWin{};
	std::pair<unsigned, std::optional<unsigned> > m_HomeScore;
	std::pair<unsigned, std::optional<unsigned> > m_AwayScore;
};

