#include "ScoreTest.h"
#include <algorithm>

TEST_F(ScoreTest, GetOutcomesCorrectly)
{
	using enum Outcome;
	const std::vector vecTestOutput{ Tied, Tied, HomeWin, HomeWin, AwayWin };
	for (std::size_t idx = 0; idx < m_vecScore.size(); ++idx)
	{
		EXPECT_EQ(m_vecScore[idx].GetOutcome(), vecTestOutput[idx]);
	}
}
TEST_F(ScoreTest, GetHomeScoreCorrectly)
{
	const std::vector vecTestOutput{ 0, 1, 2, 2, 1};
	for (std::size_t idx = 0; idx < m_vecScore.size(); ++idx)
	{
		EXPECT_EQ(m_vecScore[idx].GetHomeScore(), vecTestOutput[idx]);
	}
}
TEST_F(ScoreTest, GetAwayScoreCorrectly)
{
	const std::vector vecTestOutput{ 0, 1, 1, 0, 5 };
	for (std::size_t idx = 0; idx < m_vecScore.size(); ++idx)
	{
		EXPECT_EQ(m_vecScore[idx].GetAwayScore(), vecTestOutput[idx]);
	}
}
TEST_F(ScoreTest, ScoreToString)
{
	const std::vector vecTestOutput{ "0-0", "1-1", "2-1", "2-0", "1-5" };
	for (std::size_t idx = 0; idx < m_vecScore.size(); ++idx)
	{
		EXPECT_EQ(m_vecScore[idx].ToString(), vecTestOutput[idx]);
	}
}
TEST_F(ScoreTest, ScoreFromString)
{
	const std::vector vecTestOutput{ "0-0", "1-1", "2-1", "2-0", "1-5" };
	for (std::size_t idx = 0; idx < m_vecScore.size(); ++idx)
	{
		EXPECT_EQ(m_vecScore[idx], Score::FromString(vecTestOutput[idx]));
	}
}
TEST_F(ScoreTest, ScoreEquality)
{
	Score rComparedScore{2, 1};
	const std::vector vecTestOutput{ false, false, true, false, false };
	for (std::size_t idx = 0; idx < m_vecScore.size(); ++idx)
	{
		EXPECT_EQ((m_vecScore[idx] == rComparedScore), vecTestOutput[idx]);
	}
}
