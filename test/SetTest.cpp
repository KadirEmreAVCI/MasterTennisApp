#include "SetTest.h"

using enum common::Outcome;;

class SetOutcomeTest : public SetTest, public ::testing::WithParamInterface<std::tuple<size_t, common::Outcome>> {};
TEST_P(SetOutcomeTest, DetermineSetOutcomes)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecSet[idx].GetOutcome(), expected);
}
INSTANTIATE_TEST_SUITE_P(
    DetermineSetOutcomes,
    SetOutcomeTest,
    ::testing::Values(
        std::make_tuple(0, Tied),
        std::make_tuple(1, Tied),
        std::make_tuple(2, Tied),
        std::make_tuple(3, HomeWin),
        std::make_tuple(4, AwayWin),
        std::make_tuple(5, HomeWin),
		std::make_tuple(6, AwayWin),
		std::make_tuple(7, Tied),
		std::make_tuple(8, HomeWin),
		std::make_tuple(9, AwayWin),
		std::make_tuple(10, AwayWin)
    )
);
class PlayedTiebreakTest : public SetTest, public ::testing::WithParamInterface<std::tuple<size_t, bool>> {};
TEST_P(PlayedTiebreakTest, DetectTiebreakPlayed)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecSet[idx].IsTiebreakPlayed(), expected);
}
INSTANTIATE_TEST_SUITE_P(
    DetectTiebreakPlayed,
    PlayedTiebreakTest,
    ::testing::Values(
        std::make_tuple(0, false),
        std::make_tuple(1, false),
        std::make_tuple(2, true),
        std::make_tuple(3, false),
        std::make_tuple(4, false),
        std::make_tuple(5, true),
		std::make_tuple(6, true),
		std::make_tuple(7, false),
		std::make_tuple(8, true),
		std::make_tuple(9, true),
		std::make_tuple(10, true)
    )
);
class InvalidSetTest : public SetTest, public ::testing::WithParamInterface<std::tuple<size_t, bool>> {};
TEST_P(InvalidSetTest, DetectInvalidSets)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecSet[idx].IsValid(), expected);
}
INSTANTIATE_TEST_SUITE_P(
    DetectInvalidSets,
    InvalidSetTest,
    ::testing::Values(
        std::make_tuple(0, true),
        std::make_tuple(1, true),
        std::make_tuple(2, false),
        std::make_tuple(3, true),
        std::make_tuple(4, true),
        std::make_tuple(5, true),
		std::make_tuple(6, true),
		std::make_tuple(7, false),
		std::make_tuple(8, false),
		std::make_tuple(9, false),
		std::make_tuple(10, false)
    )
);
class SetToStringTest : public SetTest, public ::testing::WithParamInterface<std::tuple<size_t, std::string>> {};
TEST_P(SetToStringTest, SetToString)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecSet[idx].ToString(), expected);
}
INSTANTIATE_TEST_SUITE_P(
    SetToString,
    SetToStringTest,
    ::testing::Values(
        std::make_tuple(0, "0-0"),
        std::make_tuple(1, "0-0"),
        std::make_tuple(2, "0-0(7-3)"),
        std::make_tuple(3, "6-3"),
        std::make_tuple(4, "2-6"),
        std::make_tuple(5, "7-6(7-4)"),
		std::make_tuple(6, "6-7(0-7)"),
		std::make_tuple(7, "1-1"),
		std::make_tuple(8, "7-6(5-7)"),
		std::make_tuple(9, "6-7(2-2)"),
		std::make_tuple(10, "6-7(7-2)")
    )
);
class SetFromStringTest : public SetTest, public ::testing::WithParamInterface<std::tuple<size_t, std::string>> {};
TEST_P(SetFromStringTest, SetFromString)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecSet[idx], Set::FromString(expected));
}
INSTANTIATE_TEST_SUITE_P(
    SetFromString,
    SetFromStringTest,
    ::testing::Values(
        std::make_tuple(0, "0-0"),
        std::make_tuple(1, "0-0"),
        std::make_tuple(2, "0-0(7-3)"),
        std::make_tuple(3, "6-3"),
        std::make_tuple(4, "2-6"),
        std::make_tuple(5, "7-6(7-4)"),
		std::make_tuple(6, "6-7(0-7)"),
		std::make_tuple(7, "1-1"),
		std::make_tuple(8, "7-6(5-7)"),
		std::make_tuple(9, "6-7(2-2)"),
		std::make_tuple(10, "6-7(7-2)")
    )
);