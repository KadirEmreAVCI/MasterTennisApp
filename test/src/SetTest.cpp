#include "SetTest.h"

TEST_F(SetTest, GetSetOutcomeCorrectly)
{
	using enum Outcome;
	const std::vector vecTestOutput{ Tied, Tied, Tied, HomeWin, AwayWin, HomeWin, AwayWin, Tied, HomeWin, AwayWin, AwayWin };
	for (std::size_t idx = 0; idx < m_vecSet.size(); ++idx)
	{
		EXPECT_EQ(m_vecSet[idx].GetOutcome(), vecTestOutput[idx]);
	}
}
TEST_F(SetTest, TiebreakPlayed)
{
	const std::vector vecTestOutput{ false, false, true, false, false, true, true, false, true, true, true };
	for (std::size_t idx = 0; idx < m_vecSet.size(); ++idx)
	{
		EXPECT_EQ(m_vecSet[idx].IsSetTBPlayed(), vecTestOutput[idx]);
	}
}
TEST_F(SetTest, DetectInvalidSets)
{
	const std::vector vecTestOutput{ true, true, false, true, true, true, true, false, false, false, false };
	for (std::size_t idx = 0; idx < m_vecSet.size(); ++idx)
	{
		EXPECT_EQ(m_vecSet[idx].IsValid(), vecTestOutput[idx]);
	}
}
TEST_F(SetTest, SetToString)
{
	const std::vector vecTestOutput{ "0-0", "0-0", "0-0(7-3)", "6-3", "2-6", "7-6(7-4)", "6-7(0-7)", "1-1", "7-6(5-7)", "6-7(2-2)", "6-7(7-2)"};
	for (std::size_t idx = 0; idx < m_vecSet.size(); ++idx)
	{
		EXPECT_EQ(m_vecSet[idx].ToString(), vecTestOutput[idx]);
	}
}
TEST_F(SetTest, SetFromString)
{
	const std::vector vecTestOutput{ "0-0", "0-0", "0-0(7-3)", "6-3", "2-6", "7-6(7-4)", "6-7(0-7)", "1-1", "7-6(5-7)", "6-7(2-2)", "6-7(7-2)" };
	for (std::size_t idx = 0; idx < m_vecSet.size(); ++idx)
	{
		EXPECT_EQ(m_vecSet[idx], Set::FromString(vecTestOutput[idx]));
	}
}
