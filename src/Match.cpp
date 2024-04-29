#include "Match.h"
Match::Match(MatchStatus eMatchStatus, MaxSetInMatch eMaxSetInMatch) : m_eMatchStatus{ eMatchStatus }, m_uiMaxSet { static_cast<unsigned int>(eMaxSetInMatch)}
{
	InitSets();
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
void Match::UpdateMatchScore(const SetScore& ss)
{
	if (ss.WinnerOfTheSet() == SetWinner::eHome)
		++m_uiHomeScore;
	else
		++m_uiAwayScore;
}
bool Match::IsSetPlayed(unsigned int uiSetIdx)const
{
	return m_vecSetScore[uiSetIdx].has_value();
}
void Match::ClearSetScore(unsigned int uiSetIdx)
{
	m_vecSetScore[uiSetIdx].reset();
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
			ClearSetScore(uiSetIdx);	
		m_vecSetScore[uiSetIdx] = std::make_optional(ss);
		UpdateMatchScore(ss);
	}
	else
		std::cerr << "Match::setSetScore::Error! Out of index!\n";
}
std::pair<std::string, std::optional<std::string> > Match::getHomeName()const
{
	return m_sHomeName;
}
std::pair<std::string, std::optional<std::string> > Match::getAwayName()const
{
	return m_sAwayName;
}