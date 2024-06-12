#include <sstream>
#include "Set.h"
Set::Set(bool blSuperTB, const Score& MajorScore, std::optional<Score> optTBScore, unsigned uiGameToWinSet, unsigned uiPointToWinSetTB, unsigned uiPointToWinSuperTB)
	: m_blSuperTB{ blSuperTB }, m_MajorScore{ MajorScore }, m_optTBScore{ optTBScore }, m_uiGameToWinSet{ uiGameToWinSet }, m_uiPointToWinSetTB{ uiPointToWinSetTB }, m_uiPointToWinSuperTB{ uiPointToWinSuperTB }
{
	
}
Score Set::GetMajorScore()const
{
	return m_MajorScore;
}
void Set::SetSetScore(const Score& ss, std::optional<Score> ts)
{
	m_MajorScore = ss;
	m_optTBScore = ts;
}
Score Set::GetTBScore()const
{
	return m_optTBScore.value_or(Score(0,0));
}
void Set::SetTBScore(const Score& score)
{
	m_optTBScore = score;
}
void Set::Clear()
{
	m_MajorScore.Clear();
	if(m_optTBScore.has_value())
		m_optTBScore.value().Clear();
}
Winner Set::GetWinner()const
{
	return m_MajorScore.GetWinner();
}
bool Set::IsValid()const
{
	bool blValid = false;
	if (IsSuperTB())
	{
		blValid = (m_MajorScore.GetHomeScore() >= m_uiPointToWinSuperTB || m_MajorScore.GetAwayScore() >= m_uiPointToWinSuperTB) 
				&& m_MajorScore.GetDiff() >= 2 
				&& !IsSetTBPlayed();
	}
	else
	{
		if (IsSetTBPlayed())
		{
			blValid = (m_MajorScore == Score(m_uiGameToWinSet, m_uiGameToWinSet + 1) || m_MajorScore == Score(m_uiGameToWinSet + 1, m_uiGameToWinSet))
					&& ((m_optTBScore.value().GetHomeScore() >= m_uiPointToWinSetTB || m_optTBScore.value().GetAwayScore() >= m_uiPointToWinSetTB) && m_optTBScore.value().GetDiff() >= 2);
		}
		else
		{
			blValid = ((m_MajorScore.GetHomeScore() == m_uiGameToWinSet || m_MajorScore.GetHomeScore() == m_uiGameToWinSet + 1) || (m_MajorScore.GetAwayScore() == m_uiGameToWinSet || m_MajorScore.GetAwayScore() == m_uiGameToWinSet + 1))
					&& m_MajorScore.GetDiff() >= 2;
		}
	}
	return blValid;
}
bool Set::IsSuperTB()const
{
	return m_blSuperTB;
}
void Set::SetSuperTB(bool blSuperTB)
{
	m_blSuperTB = blSuperTB;
}
std::string Set::ToString()const
{
	std::ostringstream oss;
	oss << m_MajorScore.ToString();
	if(IsSetTBPlayed())
		oss << "(" << m_optTBScore.value().ToString() << ")";
	return oss.str();
}
bool Set::IsSetTBPlayed()const
{
	return m_optTBScore.has_value();
}
