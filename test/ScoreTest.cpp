#include "ScoreTest.h"
#include <algorithm>

using enum common::Outcome;

class ScoreOutcomeTest : public ScoreTest, public ::testing::WithParamInterface<std::tuple<size_t, common::Outcome>> {};
TEST_P(ScoreOutcomeTest, DetermineScoreOutcomes)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecScore[idx].GetOutcome(), expected);
}
INSTANTIATE_TEST_SUITE_P(
    DetermineScoreOutcomes,
    ScoreOutcomeTest,
    ::testing::Values(
        std::make_tuple(0, Tied),
        std::make_tuple(1, Tied),
        std::make_tuple(2, HomeWin),
        std::make_tuple(3, HomeWin),
        std::make_tuple(4, AwayWin)
    )
);
class HomeScoreTest : public ScoreTest, public ::testing::WithParamInterface<std::tuple<size_t, unsigned>> {};
TEST_P(HomeScoreTest, DetermineHomeScores)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecScore[idx].GetHomeScore(), expected);
}
INSTANTIATE_TEST_SUITE_P(
    DetermineHomeScores,
    HomeScoreTest,
    ::testing::Values(
        std::make_tuple(0, 0),
        std::make_tuple(1, 1),
        std::make_tuple(2, 2),
        std::make_tuple(3, 2),
        std::make_tuple(4, 1)
    )
);
class AwayScoreTest : public ScoreTest, public ::testing::WithParamInterface<std::tuple<size_t, unsigned>> {};
TEST_P(AwayScoreTest, DetermineAwayScores)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecScore[idx].GetAwayScore(), expected);
}
INSTANTIATE_TEST_SUITE_P(
    DetermineAwayScores,
    AwayScoreTest,
    ::testing::Values(
        std::make_tuple(0, 0),
        std::make_tuple(1, 1),
        std::make_tuple(2, 1),
        std::make_tuple(3, 0),
        std::make_tuple(4, 5)
    )
);
class ScoreToStringTest : public ScoreTest, public ::testing::WithParamInterface<std::tuple<size_t, std::string>> {};
TEST_P(ScoreToStringTest, ScoreToString)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecScore[idx].ToString(), expected);
}
INSTANTIATE_TEST_SUITE_P(
    ScoreToString,
    ScoreToStringTest,
    ::testing::Values(
        std::make_tuple(0, "0-0"),
        std::make_tuple(1, "1-1"),
        std::make_tuple(2, "2-1"),
        std::make_tuple(3, "2-0"),
        std::make_tuple(4, "1-5")
    )
);
class ScoreFromStringTest : public ScoreTest, public ::testing::WithParamInterface<std::tuple<size_t, std::string>> {};
TEST_P(ScoreFromStringTest, ScoreFromString)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecScore[idx], Score::FromString(expected));
}
INSTANTIATE_TEST_SUITE_P(
    ScoreFromString,
    ScoreFromStringTest,
    ::testing::Values(
        std::make_tuple(0, "0-0"),
        std::make_tuple(1, "1-1"),
        std::make_tuple(2, "2-1"),
        std::make_tuple(3, "2-0"),
        std::make_tuple(4, "1-5")
    )
);
class EqualityTest : public ScoreTest, public ::testing::WithParamInterface<std::tuple<size_t, Score, bool>> {};
TEST_P(EqualityTest, DetectEqualities)
{
	auto [idx, comparedScore, expected] = GetParam();
	EXPECT_EQ((m_vecScore[idx] == comparedScore), expected);
}
INSTANTIATE_TEST_SUITE_P(
    DetectEqualities,
    EqualityTest,
    ::testing::Values(
        std::make_tuple<unsigned, Score, bool>(0, Score(0, 0), true),
        std::make_tuple<unsigned, Score, bool>(1, Score(1, 2), false),
		std::make_tuple<unsigned, Score, bool>(2, Score(2, 1), true),
		std::make_tuple<unsigned, Score, bool>(3, Score(2, 1), false),
		std::make_tuple<unsigned, Score, bool>(4, Score(1, 3), false)
    )
);