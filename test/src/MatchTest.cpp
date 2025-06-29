// Standard Headers
#include <vector>
#include <algorithm>

// Test Headers
#include "MatchTest.h"

// TODO: SetSets çaðýrýldýðýnda SetScore fonksiyonunun doðru çalýþýp çalýþmadýðýna dair test yazýlacak.
TEST_F(MatchTestFixture, GetMatchOutcomesCorrectly)
{
	using enum Outcome;
	const std::vector vecTestOutput{ HomeWin, HomeWin, AwayWin, AwayWin, HomeWin, HomeWin, HomeWin, HomeWin, AwayWin, HomeWin, AwayWin, Tied, Tied, HomeWin, AwayWin, Tied, AwayWin, Tied };
	for (std::size_t idx = 0; idx < m_vecMatch.size(); ++idx)
	{
		EXPECT_EQ(m_vecMatch[idx].GetOutcome(), vecTestOutput[idx]);
	}
}
TEST_F(MatchTestFixture, SortMatchesByStartTime)
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
TEST_F(MatchTestFixture, DetectUpcomingMatches)
{
	const std::vector<bool> vecTestOutput = { false, false, false, false, false, false, false, false, false, false, false, true, true, false, true, true, true, true };
	for (std::size_t idx = 0; idx < m_vecMatch.size(); ++idx)
	{
		EXPECT_EQ(m_vecMatch[idx].IsUpcomingMatch(), vecTestOutput[idx]);
	}
}
TEST_F(MatchTestFixture, DetectInvalidMatches)
{
	const std::vector<bool> vecTestOutput = { true, true, true, true, true, true, true, true, true, true, true, true, false, false, false, true, false, true, false };
	for (std::size_t idx = 0; idx < m_vecMatch.size(); ++idx)
	{
		EXPECT_EQ(m_vecMatch[idx].IsMatchValid(), vecTestOutput[idx]);
	}
}