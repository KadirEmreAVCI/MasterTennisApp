#include "Match.h"
unsigned Match::GetID()const
{
	return m_uiID;
}
void Match::SetID(unsigned uiID)
{
	m_uiID = uiID;
}
unsigned Match::GetTournamentID()const
{
	return m_uiTournamentID;
}
void Match::SetTournamentID(unsigned uiTournamentID)
{
	m_uiTournamentID = uiTournamentID;
}
std::string Match::GetStatu()const
{
	return m_sStatu;
}
void Match::SetStatu(const std::string& sStatu)
{
	m_sStatu = sStatu;
}
std::string Match::GetStage()const
{
	return m_sStage;
}
void Match::SetStage(const std::string& sStage)
{
	m_sStage = sStage;
}
std::string Match::GetOpponent1()const
{
	return m_sOpponent1;
}
std::string Match::GetOpponent2()const
{
	return m_soptOpponent2.value_or("");
}
void Match::SetOpponent1(const std::string& sOpponent1)
{
	m_sOpponent1 = sOpponent1;
}
void Match::SetOpponent2(std::optional<std::string> soptOpponent2)
{
	m_soptOpponent2 = soptOpponent2;
}
QDate Match::GetDate()const
{
	return m_Date;
}
void Match::SetDate(const QDate& date)
{
	m_Date = date;
}
QTime Match::GetTime()const
{
	return m_Time;
}
void Match::SetTime(const QTime& time)
{
	m_Time = time;
}
Score Match::GetScore()const
{
	return m_Score;
}
void Match::SetScore(const Score& s)
{
	m_Score = s;
}
std::vector<Set> Match::GetSets()const
{
	return m_vecSet;
}
void Match::SetSets(std::vector<Set> vecSet)
{
	m_vecSet = vecSet;
}
std::string Match::SetsToString()const
{
	std::ostringstream oss;
	std::copy(m_vecSet.cbegin(), m_vecSet.cend(), std::ostream_iterator<Set>(oss, ","));
	std::string sSets = oss.str();
	if (!sSets.empty())
	{
		sSets.erase(sSets.size() - 1);
	}
	return sSets;
}