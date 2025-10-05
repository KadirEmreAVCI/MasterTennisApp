// Project Headers
#include "StatControllerTest.h"

INSTANTIATE_TEST_SUITE_P(
    MatchStatTest,
    MatchStatTest,
    ::testing::Values(
        std::make_tuple("", "", StatReport{11, 8}),
        std::make_tuple("Category", "", StatReport{11, 8}),
        std::make_tuple("Category", "Ilk Turnuvam", StatReport{4, 1}),
        std::make_tuple("Category", "D", StatReport{5, 3}),
        std::make_tuple("Category", "C", StatReport{2, 4}),
        std::make_tuple("Type", "", StatReport{11, 8}),
        std::make_tuple("Type", "Single", StatReport{4, 7}),
        std::make_tuple("Type", "Double", StatReport{7, 1})
    )
);
INSTANTIATE_TEST_SUITE_P(
    MatchTiebreakStatTest,
    MatchTiebreakStatTest,
    ::testing::Values(
        std::make_tuple("", "", StatReport{4, 1}),
        std::make_tuple("Category", "", StatReport{4, 1}),
        std::make_tuple("Category", "Ilk Turnuvam", StatReport{1, 0}),
        std::make_tuple("Category", "D", StatReport{2, 0}),
        std::make_tuple("Category", "C", StatReport{1, 1}),
        std::make_tuple("Type", "", StatReport{4, 1}),
        std::make_tuple("Type", "Single", StatReport{2, 1}),
        std::make_tuple("Type", "Double", StatReport{2, 0})
    )
);
INSTANTIATE_TEST_SUITE_P(
    SetTiebreakStatTest,
    SetTiebreakStatTest,
    ::testing::Values(
        std::make_tuple("", "", StatReport{2, 3}),
        std::make_tuple("Category", "", StatReport{2, 3}),
        std::make_tuple("Category", "Ilk Turnuvam", StatReport{0, 1}),
        std::make_tuple("Category", "D", StatReport{2, 2}),
        std::make_tuple("Category", "C", StatReport{0, 0}),
        std::make_tuple("Type", "", StatReport{2, 3}),
        std::make_tuple("Type", "Single", StatReport{1, 2}),
        std::make_tuple("Type", "Double", StatReport{1, 1})
    )
);
INSTANTIATE_TEST_SUITE_P(
    QuarterFinalStatTest,
    QuarterFinalStatTest,
    ::testing::Values(
        std::make_tuple("", "", StatReport{2, 2}),
        std::make_tuple("Category", "", StatReport{2, 2}),
        std::make_tuple("Category", "Ilk Turnuvam", StatReport{0, 0}),
        std::make_tuple("Category", "D", StatReport{2, 1}),
        std::make_tuple("Category", "C", StatReport{0, 1}),
        std::make_tuple("Type", "", StatReport{2, 2}),
        std::make_tuple("Type", "Single", StatReport{1, 2}),
        std::make_tuple("Type", "Double", StatReport{1, 0})
    )
);
INSTANTIATE_TEST_SUITE_P(
    SemiFinalStatTest,
    SemiFinalStatTest,
    ::testing::Values(
        std::make_tuple("", "", StatReport{3, 2}),
        std::make_tuple("Category", "", StatReport{3, 2}),
        std::make_tuple("Category", "Ilk Turnuvam", StatReport{0, 1}),
        std::make_tuple("Category", "D", StatReport{2, 0}),
        std::make_tuple("Category", "C", StatReport{1, 1}),
        std::make_tuple("Type", "", StatReport{3, 2}),
        std::make_tuple("Type", "Single", StatReport{2, 1}),
        std::make_tuple("Type", "Double", StatReport{1, 1})
    )
);
INSTANTIATE_TEST_SUITE_P(
    ThirdPlaceGameStatTest,
    ThirdPlaceGameStatTest,
    ::testing::Values(
        std::make_tuple("", "", StatReport{1, 1}),
        std::make_tuple("Category", "", StatReport{1, 1}),
        std::make_tuple("Category", "Ilk Turnuvam", StatReport{0, 0}),
        std::make_tuple("Category", "D", StatReport{0, 0}),
        std::make_tuple("Category", "C", StatReport{1, 1}),
        std::make_tuple("Type", "", StatReport{1, 1}),
        std::make_tuple("Type", "Single", StatReport{1, 1}),
        std::make_tuple("Type", "Double", StatReport{0, 0})
    )
);
INSTANTIATE_TEST_SUITE_P(
    FinalStatTest,
    FinalStatTest,
    ::testing::Values(
        std::make_tuple("", "", StatReport{1, 1}),
        std::make_tuple("Category", "", StatReport{1, 1}),
        std::make_tuple("Category", "Ilk Turnuvam", StatReport{0, 0}),
        std::make_tuple("Category", "D", StatReport{1, 1}),
        std::make_tuple("Category", "C", StatReport{0, 0}),
        std::make_tuple("Type", "", StatReport{1, 1}),
        std::make_tuple("Type", "Single", StatReport{0, 1}),
        std::make_tuple("Type", "Double", StatReport{1, 0})
    )
);
