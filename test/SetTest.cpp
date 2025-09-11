#include "SetTest.h"

INSTANTIATE_TEST_SUITE_P(
    DetermineSetOutcomes,
    SetOutcomeTest,
    ::testing::Values(
        std::make_tuple(0, Outcome::Tied),
        std::make_tuple(1, Outcome::Tied),
        std::make_tuple(2, Outcome::Tied),
        std::make_tuple(3, Outcome::HomeWin),
        std::make_tuple(4, Outcome::AwayWin),
        std::make_tuple(5, Outcome::HomeWin),
		std::make_tuple(6, Outcome::AwayWin),
		std::make_tuple(7, Outcome::Tied),
		std::make_tuple(8, Outcome::HomeWin),
		std::make_tuple(9, Outcome::AwayWin),
		std::make_tuple(10, Outcome::AwayWin)
    )
);
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