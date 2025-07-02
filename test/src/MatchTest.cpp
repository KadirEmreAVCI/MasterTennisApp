// Standard Headers
#include <vector>
#include <algorithm>

// Test Headers
#include "MatchTest.h"

TEST_F(MatchTest, GetMatchOutcomesCorrectly)
{
	using enum Outcome;
	const std::vector vecTestOutput{ HomeWin, HomeWin, AwayWin, AwayWin, HomeWin, HomeWin, HomeWin, HomeWin, AwayWin, HomeWin, AwayWin, Tied, Tied, HomeWin, AwayWin, Tied, AwayWin, Tied };
	for (std::size_t idx = 0; idx < m_vecMatch.size(); ++idx)
	{
		EXPECT_EQ(m_vecMatch[idx].GetOutcome(), vecTestOutput[idx]);
	}
}
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
TEST_F(MatchTest, DetectUpcomingMatches)
{
	const std::vector<bool> vecTestOutput = { false, false, false, false, false, false, false, false, false, false, false, true, true, false, true, true, true, true };
	for (std::size_t idx = 0; idx < m_vecMatch.size(); ++idx)
	{
		EXPECT_EQ(m_vecMatch[idx].IsUpcomingMatch(), vecTestOutput[idx]);
	}
}
TEST_F(MatchTest, DetectInvalidMatches)
{
	const std::vector<bool> vecTestOutput = { true, true, true, true, true, true, true, true, true, true, true, true, false, false, false, true, false, true, false };
	for (std::size_t idx = 0; idx < m_vecMatch.size(); ++idx)
	{
		EXPECT_EQ(m_vecMatch[idx].IsValid(), vecTestOutput[idx]);
	}
}
TEST_F(MatchTest, SettingMatchScoreAfterSetsAreAssigned)
{
	const std::vector vecTestOutput{	Score{2, 1}, 
										Score{3, 1}, 
										Score{0, 3}, 
										Score{0, 2}, 
										Score{2, 1}, 
										Score{1, 0}, 
										Score{2, 0}, 
										Score{2, 0}, 
										Score{0, 2}, 
										Score{2, 1},
										Score{0, 2},
										Score{0, 0},
										Score{0, 0},
										Score{2, 0},
										Score{0, 2},
										Score{0, 0},
										Score{0, 2},
										Score{0, 0}
	};
	for (std::size_t idx = 0; idx < m_vecMatch.size(); ++idx)
	{
		EXPECT_EQ(m_vecMatch[idx].GetScore(), vecTestOutput[idx]);
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