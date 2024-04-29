#include "Set.h"
Set::Set(unsigned uiMinGameNeededToWin) : m_uiMinGameNeededToWin{ uiMinGameNeededToWin }
{

}
Set::Set(std::pair<unsigned int, std::optional<unsigned int> > HomeScore, std::pair<unsigned int, std::optional<unsigned int> > AwayScore, unsigned uiMinGameNeededToWin)
	: m_HomeScore{ HomeScore }, m_AwayScore{ AwayScore }, m_uiMinGameNeededToWin{ uiMinGameNeededToWin }
{
	
}
std::pair<unsigned int, std::optional<unsigned int> > Set::getHomeScore()const
{
	return m_HomeScore;
}
std::pair<unsigned int, std::optional<unsigned int> > Set::getAwayScore()const
{
	return m_AwayScore;
}
void Set::setHomeScore(std::pair<unsigned int, std::optional<unsigned int> > Score)
{
	m_HomeScore = Score;
}
void Set::setAwayScore(std::pair<unsigned int, std::optional<unsigned int> > Score)
{
	m_AwayScore = Score;
}
SetWinner Set::WinnerOfTheSet()const
{
	return m_HomeScore.first > m_AwayScore.first ? SetWinner::eHome : SetWinner::eAway;
}
bool Set::IsTiebreakPlayed()const
{
	return m_HomeScore.second.has_value() && m_AwayScore.second.has_value();
}
void Set::Walkover(MatchStatus eMatchStatus)
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
