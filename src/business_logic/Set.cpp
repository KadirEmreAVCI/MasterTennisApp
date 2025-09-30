#include <sstream>
#include <vector>
#include "Set.h"
Set::Set(const Score& MajorScore, std::optional<Score> optTBScore)
	:m_MajorScore{ MajorScore }, m_optTBScore{ optTBScore }
{
	
}
Score Set::GetMajorScore()const
{
	return m_MajorScore;
}
Score Set::GetTBScore()const
{
	return m_optTBScore.value_or(Score(0,0));
}
Outcome Set::GetOutcome()const
{
	return m_MajorScore.GetOutcome();
}
std::string Set::ToString()const
{
	std::ostringstream oss;
	oss << m_MajorScore.ToString();
	if(IsTiebreakPlayed())
		oss << "(" << m_optTBScore.value().ToString() << ")";
	return oss.str();
}
Set Set::FromString(const std::string& sSet)
{	
	std::string sMajorScore{ sSet };
	if(size_t endPos = sSet.find('('); endPos != std::string::npos)
	{
		const size_t begPos = 0;
		sMajorScore = sSet.substr(begPos, endPos);
		size_t endTBPos = sSet.find(')');
		const std::string sTBScore = sSet.substr(endPos + 1, endTBPos);
		return Set(Score::FromString(sMajorScore), std::make_optional<Score>(Score::FromString(sTBScore)));
	}
	else
	{
		return Set(Score::FromString(sMajorScore));
	}
}
bool Set::IsTiebreakPlayed()const
{
	return m_optTBScore.has_value() && m_optTBScore.value() != Score(0,0);
}
bool Set::IsValid()const
{
	return IsUninitialized() || (!IsSetScoreEqual() && IsOutcomeValid());
}
bool Set::IsUninitialized()const
{
	return m_MajorScore == Score{ 0, 0 } && !IsTiebreakPlayed();
}
bool Set::IsSetScoreEqual()const
{
	return (m_MajorScore.GetOutcome() == Outcome::Tied) && (!IsTiebreakPlayed() || (m_optTBScore.value().GetOutcome() == Outcome::Tied));
}
bool Set::IsOutcomeValid()const
{
	const bool blSetConsistentForHomeWin = m_MajorScore.GetOutcome() == Outcome::HomeWin && (!IsTiebreakPlayed() || m_optTBScore.value().GetOutcome() == Outcome::HomeWin);
	const bool blSetConsistentForAwayWin = m_MajorScore.GetOutcome() == Outcome::AwayWin && (!IsTiebreakPlayed() || m_optTBScore.value().GetOutcome() == Outcome::AwayWin);
	return blSetConsistentForHomeWin || blSetConsistentForAwayWin;
}