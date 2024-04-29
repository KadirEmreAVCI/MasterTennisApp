#include "SetScore.h"
SetScore::SetScore(std::pair<unsigned int, std::optional<unsigned int> > HomeScore, std::pair<unsigned int, std::optional<unsigned int> > AwayScore)
{
	m_HomeScore = HomeScore;
	AwayScore = AwayScore;
}
std::pair<unsigned int, std::optional<unsigned int> > SetScore::getHomeScore()const
{
	return m_HomeScore;
}
std::pair<unsigned int, std::optional<unsigned int> > SetScore::getAwayScore()const
{
	return m_AwayScore;
}
void SetScore::setHomeScore(std::pair<unsigned int, std::optional<unsigned int> > Score)
{
	m_HomeScore = Score;
}
void SetScore::setAwayScore(std::pair<unsigned int, std::optional<unsigned int> > Score)
{
	m_AwayScore = Score;
}
SetWinner SetScore::WinnerOfTheSet()const
{
	return m_HomeScore.first > m_AwayScore.first ? SetWinner::eHome : SetWinner::eAway;
}
bool SetScore::IsTiebreakPlayed()const
{
	return m_HomeScore.second.has_value() && m_AwayScore.second.has_value();
}
