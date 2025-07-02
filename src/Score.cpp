#include <cmath>
#include <sstream>
#include "Score.h"
Score::Score(unsigned uiHomeScore, unsigned uiAwayScore) : m_Score{std::pair<unsigned, unsigned>(uiHomeScore, uiAwayScore)}
{
	
}
std::pair<unsigned, unsigned> Score::GetScore()const
{
	return m_Score;
}
unsigned Score::GetHomeScore()const
{
	return m_Score.first;
}
unsigned Score::GetAwayScore()const
{
	return m_Score.second;
}
Outcome Score::GetOutcome()const
{
	if (m_Score.first > m_Score.second)
		return Outcome::HomeWin;
	else if (m_Score.first < m_Score.second)
		return Outcome::AwayWin;
	else
		return Outcome::Tied;
}
std::string Score::ToString()const
{
	std::ostringstream oss{};
	oss << *this;
	return oss.str();
}
Score Score::FromString(const std::string& sScore)
{
	size_t pos = sScore.find('-');
	if (pos != std::string::npos)
	{
		return Score(std::stoi(sScore.substr(0, pos)), std::stoi(sScore.substr(pos + 1)));
	}
	else
	{
		std::cerr << "Error! Illegal string to convert Score!\n";
		return Score{};
	}
}