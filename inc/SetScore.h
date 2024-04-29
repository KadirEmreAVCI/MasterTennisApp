#pragma once
#include <utility>
#include <optional>
enum class SetWinner {
	eHome = 1, 
	eAway = 2
};
class SetScore{
public:
	SetScore(std::pair<unsigned int, std::optional<unsigned int> > HomeScore, std::pair<unsigned int, std::optional<unsigned int> > AwayScore);
	std::pair<unsigned int, std::optional<unsigned int> > getHomeScore()const;
	std::pair<unsigned int, std::optional<unsigned int> > getAwayScore()const;
	void setHomeScore(std::pair<unsigned int, std::optional<unsigned int> > HomeScore);
	void setAwayScore(std::pair<unsigned int, std::optional<unsigned int> > AwayScore);
	SetWinner WinnerOfTheSet()const;
	bool IsTiebreakPlayed()const;
private:
	std::pair<unsigned int, std::optional<unsigned int> > m_HomeScore;
	std::pair<unsigned int, std::optional<unsigned int> > m_AwayScore;
};

