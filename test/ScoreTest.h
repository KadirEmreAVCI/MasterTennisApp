#ifndef SCORETEST_H
#define SCORETEST_H

// Standard Headers
#include <vector>

// External Headers 
#include <gtest/gtest.h>

// Project Headers
#include "Score.h"

class ScoreTest : public testing::Test {
protected:
	void SetUp()
	{
		m_vecScore.insert(m_vecScore.end(), {
			Score{0, 0},
			Score{1, 1},
			Score{2, 1},
			Score{2, 0},
			Score{1, 5}
		});
	}
	std::vector<Score> m_vecScore;
};

class ScoreOutcomeTest : public ScoreTest, public ::testing::WithParamInterface<std::tuple<size_t, Outcome>> {};
TEST_P(ScoreOutcomeTest, DetermineScoreOutcomes)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecScore[idx].GetOutcome(), expected);
}

class HomeScoreTest : public ScoreTest, public ::testing::WithParamInterface<std::tuple<size_t, unsigned>> {};
TEST_P(HomeScoreTest, DetermineHomeScores)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecScore[idx].GetHomeScore(), expected);
}

class AwayScoreTest : public ScoreTest, public ::testing::WithParamInterface<std::tuple<size_t, unsigned>> {};
TEST_P(AwayScoreTest, DetermineAwayScores)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecScore[idx].GetAwayScore(), expected);
}

class ScoreToStringTest : public ScoreTest, public ::testing::WithParamInterface<std::tuple<size_t, std::string>> {};
TEST_P(ScoreToStringTest, ScoreToString)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecScore[idx].ToString(), expected);
}

class ScoreFromStringTest : public ScoreTest, public ::testing::WithParamInterface<std::tuple<size_t, std::string>> {};
TEST_P(ScoreFromStringTest, ScoreFromString)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecScore[idx], Score::FromString(expected));
}

class EqualityTest : public ScoreTest, public ::testing::WithParamInterface<std::tuple<size_t, Score, bool>> {};
TEST_P(EqualityTest, DetectEqualities)
{
	auto [idx, comparedScore, expected] = GetParam();
	EXPECT_EQ((m_vecScore[idx] == comparedScore), expected);
}

#endif