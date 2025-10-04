// Standard Headers
#include <algorithm>

// Test Headers
#include "MatchTest.h"

using enum common::Outcome;

INSTANTIATE_TEST_SUITE_P(
    DetermineMatchOutcomes,
    MatchOutcomeTest,
    ::testing::Values(
        std::make_tuple(0, HomeWin),
        std::make_tuple(1, HomeWin),
        std::make_tuple(2, AwayWin),
        std::make_tuple(3, AwayWin),
        std::make_tuple(4, HomeWin),
		std::make_tuple(5, HomeWin),
		std::make_tuple(6, HomeWin),
		std::make_tuple(7, HomeWin),
		std::make_tuple(8, AwayWin),
		std::make_tuple(9, HomeWin),
		std::make_tuple(10, AwayWin),
		std::make_tuple(11, Tied),
		std::make_tuple(12, Tied),
		std::make_tuple(13, HomeWin),
		std::make_tuple(14, AwayWin),
		std::make_tuple(15, Tied),
		std::make_tuple(16, AwayWin),
		std::make_tuple(17, Tied)
    )
);
INSTANTIATE_TEST_SUITE_P(
    DetectUpcomingMatches,
    UpcomingMatchTest,
    ::testing::Values(
        std::make_tuple(0, false),
        std::make_tuple(1, false),
        std::make_tuple(2, false),
        std::make_tuple(3, false),
        std::make_tuple(4, false),
		std::make_tuple(5, false),
		std::make_tuple(6, false),
		std::make_tuple(7, false),
		std::make_tuple(8, false),
		std::make_tuple(9, false),
		std::make_tuple(10, false),
		std::make_tuple(11, true),
		std::make_tuple(12, true),
		std::make_tuple(13, false),
		std::make_tuple(14, true),
		std::make_tuple(15, true),
		std::make_tuple(16, true),
		std::make_tuple(17, true)
    )
);
INSTANTIATE_TEST_SUITE_P(
    DetectInvalidMatches,
    InvalidMatchTest,
    ::testing::Values(
        std::make_tuple(0, true),
        std::make_tuple(1, true),
        std::make_tuple(2, true),
        std::make_tuple(3, true),
        std::make_tuple(4, true),
		std::make_tuple(5, true),
		std::make_tuple(6, true),
		std::make_tuple(7, true),
		std::make_tuple(8, true),
		std::make_tuple(9, true),
		std::make_tuple(10, true),
		std::make_tuple(11, true),
		std::make_tuple(12, false),
		std::make_tuple(13, false),
		std::make_tuple(14, false),
		std::make_tuple(15, true),
		std::make_tuple(16, false),
		std::make_tuple(17, true)
    )
);
INSTANTIATE_TEST_SUITE_P(
    CheckMatchScores,
    MatchScoreTest,
    ::testing::Values(
        std::make_tuple(0, Score{2, 1}),
        std::make_tuple(1, Score{3, 1}),
        std::make_tuple(2, Score{0, 3}),
        std::make_tuple(3, Score{0, 2}),
        std::make_tuple(4, Score{2, 1}),
		std::make_tuple(5, Score{1, 0}),
		std::make_tuple(6, Score{2, 0}),
		std::make_tuple(7, Score{2, 0}),
		std::make_tuple(8, Score{0, 2}),
		std::make_tuple(9, Score{2, 1}),
		std::make_tuple(10, Score{0, 2}),
		std::make_tuple(11, Score{0, 0}),
		std::make_tuple(12, Score{0, 0}),
		std::make_tuple(13, Score{2, 0}),
		std::make_tuple(14, Score{0, 2}),
		std::make_tuple(15, Score{0, 0}),
		std::make_tuple(16, Score{0, 2}),
		std::make_tuple(17, Score{0, 0})
    )
);
TEST_F(MatchTest, SortMatchesByStartTime)
{
	const std::vector<unsigned> vecTestOutput{ 13, 6, 0, 7, 4, 1, 9, 3, 2, 5, 8, 10, 12, 11, 14, 15, 16, 17 };
	std::sort(m_vecMatch.begin(), m_vecMatch.end(), [](const Match& m1, const Match& m2) {
		return m1.IsEarlier(m2);
		});
	for (std::size_t idx = 0; idx < m_vecMatch.size(); ++idx)
	{
		EXPECT_EQ(m_vecMatch[idx].GetID(), vecTestOutput[idx]);
	}
}
TEST_F(MatchTest, MatchEquality)
{
	Match rComparedMatch{ 5, 1, "U", "Group Stage", "Alper Kagan Aldemir", "Tolunay Bayrakci", QDate{2025, 4, 15}, QTime{19, 30, 0}, {Set{Score(6, 1)}} };
	std::vector<bool> vecTestOutput = { false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false };
	for (std::size_t idx = 0; idx < m_vecMatch.size(); ++idx)
	{
		EXPECT_EQ((m_vecMatch[idx] == rComparedMatch), vecTestOutput[idx]);
	}

	rComparedMatch = Match{ 15,0, "U","Quarter Final", "Unknown2", "", QDate{2300, 1, 3}, QTime{0, 0, 0}, {Set{Score(0, 0)}, Set{Score(0, 0)}} };
	vecTestOutput = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false };
	for (std::size_t idx = 0; idx < m_vecMatch.size(); ++idx)
	{
		EXPECT_EQ((m_vecMatch[idx] == rComparedMatch), vecTestOutput[idx]);
	}
}