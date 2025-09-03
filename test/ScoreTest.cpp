#include "ScoreTest.h"
#include <algorithm>

INSTANTIATE_TEST_SUITE_P(
    DetermineScoreOutcomes,
    ScoreOutcomeTest,
    ::testing::Values(
        std::make_tuple(0, Outcome::Tied),
        std::make_tuple(1, Outcome::Tied),
        std::make_tuple(2, Outcome::HomeWin),
        std::make_tuple(3, Outcome::HomeWin),
        std::make_tuple(4, Outcome::AwayWin)
    )
);
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