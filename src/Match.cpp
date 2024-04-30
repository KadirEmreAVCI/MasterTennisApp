#include "Match.h"
Match::Match(MatchStatus eMatchStatus, std::string sStage, std::pair<std::string, std::optional<std::string> > sAwayName, unsigned uiMaxSetInMatch, unsigned uiMinGameToWinSet) : m_eMatchStatus{ eMatchStatus }, m_sStage{ sStage }, m_sAwayName { sAwayName }, m_uiMaxSet{ uiMaxSetInMatch }, m_uiMinGameToWinSet{ uiMinGameToWinSet }
{
	InitSets();
	if (eMatchStatus == eWO_W || eMatchStatus == eWO_L)
	{
		Walkover();
	}
}
std::pair<unsigned int, unsigned int> Match::getScore()const
{
	return std::make_pair(m_uiHomeScore, m_uiAwayScore);
}
void Match::InitSets()
{
	for (int iSetIdx{}; iSetIdx < m_uiMaxSet; ++iSetIdx)
	{
		m_vecSetScore.push_back(std::optional<Set>());
	}
}
void Match::Walkover()
{
	for (unsigned uiSetIdx{}; uiSetIdx < GetMinSetNeededToWin(); ++uiSetIdx)
	{
		Set ss{ m_uiMinGameToWinSet };
		ss.Walkover(m_eMatchStatus);
		AddSet(uiSetIdx, ss);
	}
}
void Match::IncrementScore(const Set& ss)
{
	if (ss.WinnerOfTheSet() == SetWinner::eHome)
		++m_uiHomeScore;
	else
		++m_uiAwayScore;
}
void Match::DecrementScore(unsigned uiSetIdx)
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
Set Match::GetSet(unsigned int uiSetIdx)const
{
	if (uiSetIdx < m_uiMaxSet)
		return m_vecSetScore[uiSetIdx].value_or(Set{std::make_pair(99, 0), std::make_pair(99, 0)});
	else
		std::cerr << "Match::getSetScore::Error! Out of index!\n";
}
void Match::AddSet(unsigned int uiSetIdx, const Set& ss)
{
	if (uiSetIdx < m_uiMaxSet) {
		if (IsSetPlayed(uiSetIdx))
			DecrementScore(uiSetIdx);
		m_vecSetScore[uiSetIdx] = std::make_optional(ss);
		IncrementScore(ss);
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
	return (GetMatchStatus() == eWO_W || GetMatchStatus() == eBYE || (GetMatchStatus() == ePlayed) && m_uiHomeScore > m_uiAwayScore) ? MatchWinner::eHome : MatchWinner::eAway;
}
MatchStatus Match::GetMatchStatus()const
{
	return m_eMatchStatus;
}
void Match::SetMatchStatus(MatchStatus eMatchStatus)
{
	m_eMatchStatus = eMatchStatus;
	if (eMatchStatus == eWO_W || eMatchStatus == eWO_L)
	{
		Walkover();
	}
}
std::string Match::GetStage()const
{
	return m_sStage;
}
std::pair<std::string, std::optional<std::string> > Match::getAwayName()const
{
	return m_sAwayName;
}