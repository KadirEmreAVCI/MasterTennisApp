#include "Match.h"
Match::Match(MatchStatus eMatchStatus, std::pair<std::string, std::optional<std::string> > sAwayName, unsigned uiMaxSetInMatch, unsigned uiMinGameToWinSet) : m_eMatchStatus{ eMatchStatus }, m_sAwayName{ sAwayName },  m_uiMaxSet { uiMaxSetInMatch }, m_uiMinGameToWinSet{ uiMinGameToWinSet }
{
	InitSets();
	if (eMatchStatus == eWO_W || eMatchStatus == eWO_L)
	{
		for (unsigned uiSetIdx{}; uiSetIdx < GetMinSetNeededToWin(); ++uiSetIdx)
		{
			SetScore ss{ m_uiMinGameToWinSet };
			ss.Walkover(eMatchStatus);
			setSetScore(uiSetIdx, ss);
		}
	}
}
std::pair<unsigned int, unsigned int> Match::getMatchScore()const
{
	return std::make_pair(m_uiHomeScore, m_uiAwayScore);
}
void Match::InitSets()
{
	for (int iSetIdx{}; iSetIdx < m_uiMaxSet; ++iSetIdx)
	{
		m_vecSetScore.push_back(std::optional<SetScore>());
	}
}
void Match::IncrementMatchScore(const SetScore& ss)
{
	if (ss.WinnerOfTheSet() == SetWinner::eHome)
		++m_uiHomeScore;
	else
		++m_uiAwayScore;
}
void Match::DecrementMatchScore(unsigned uiSetIdx)
{
	if (IsSetPlayed(uiSetIdx))
	{
		if (m_vecSetScore[uiSetIdx].value().WinnerOfTheSet() == SetWinner::eHome)
			--m_uiHomeScore;
		else
			--m_uiAwayScore;
	}
}
bool Match::IsSetPlayed(unsigned int uiSetIdx)const
{
	return m_vecSetScore[uiSetIdx].has_value();
}
unsigned Match::GetMinSetNeededToWin()const
{
	return (m_uiMaxSet + 1) / 2;
}
SetScore Match::getSetScore(unsigned int uiSetIdx)const
{
	if (uiSetIdx < m_uiMaxSet)
		return m_vecSetScore[uiSetIdx].value_or(SetScore{std::make_pair(99, 0), std::make_pair(99, 0)});
	else
		std::cerr << "Match::getSetScore::Error! Out of index!\n";
}
void Match::setSetScore(unsigned int uiSetIdx, const SetScore& ss)
{
	if (uiSetIdx < m_uiMaxSet) {
		if (IsSetPlayed(uiSetIdx))
			DecrementMatchScore(uiSetIdx);
		m_vecSetScore[uiSetIdx] = std::make_optional(ss);
		IncrementMatchScore(ss);
	}
	else
		std::cerr << "Match::setSetScore::Error! Out of index!\n";
}
void Match::setAwayName(std::pair<std::string, std::optional<std::string> > sAwayName)
{
	m_sAwayName = sAwayName;
}
MatchWinner Match::WinnerOfTheMatch()const
{
	return (getMatchStatus() == eWO_W || getMatchStatus() == eBYE || (getMatchStatus() == ePlayed) && m_uiHomeScore > m_uiAwayScore) ? MatchWinner::eHome : MatchWinner::eAway;
}
MatchStatus Match::getMatchStatus()const
{
	return m_eMatchStatus;
}
std::pair<std::string, std::optional<std::string> > Match::getAwayName()const
{
	return m_sAwayName;
}