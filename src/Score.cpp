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
void Score::SetScore(std::pair<unsigned, unsigned> score)
{
	m_Score = score;
}
unsigned Score::GetHomeScore()const
{
	return m_Score.first;
}
unsigned Score::GetAwayScore()const
{
	return m_Score.second;
}
bool Score::operator==(const Score& score)const
{
	return score.GetScore().first == GetScore().first && score.GetScore().second == GetScore().second;
}
bool Score::operator!=(const Score& score)const
{
	return !(*this == score);
}
void Score::Clear()
{
	m_Score.first = 0;
	m_Score.second = 0;
}
Winner Score::GetWinner()const
{
	return (m_Score.first > m_Score.second) ? Winner::Home : Winner::Away;
}
unsigned Score::GetDiff()const
{
	return std::abs(static_cast<int>(m_Score.first) - static_cast<int>(m_Score.second));
}
std::string Score::ToString()const
{
	std::ostringstream oss{};
	oss << *this;
	return oss.str();
}