#include "SetScore.h"
SetScore::SetScore(unsigned uiMinGameNeededToWin) : m_uiMinGameNeededToWin{ uiMinGameNeededToWin }
{

}
SetScore::SetScore(std::pair<unsigned int, std::optional<unsigned int> > HomeScore, std::pair<unsigned int, std::optional<unsigned int> > AwayScore, unsigned uiMinGameNeededToWin)
	: m_HomeScore{ HomeScore }, m_AwayScore{ AwayScore }, m_uiMinGameNeededToWin{ uiMinGameNeededToWin }
{
	
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
void SetScore::Walkover(MatchStatus eMatchStatus)
{
	if (eMatchStatus == MatchStatus::eWO_W)
	{
		setHomeScore(std::make_pair(m_uiMinGameNeededToWin, 0));
		setAwayScore(std::make_pair(0, 0));
	}
	else if (eMatchStatus == MatchStatus::eWO_L)
	{
		setHomeScore(std::make_pair(0, 0));
		setAwayScore(std::make_pair(m_uiMinGameNeededToWin, 0));
	}
}
