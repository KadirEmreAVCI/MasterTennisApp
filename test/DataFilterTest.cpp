// Project Headers
#include "DataFilterTest.h"

class OrganizationNameFiltering : public DataFilterTest, public ::testing::WithParamInterface<std::tuple<std::string, bool, std::vector<unsigned>>> {};
TEST_P(OrganizationNameFiltering, OrganizationNameFiltering)
{
	auto [sFilteringWord, blSearchForExactMatch, vecExpectedTournaments] = GetParam();
    DataFilter<Tournament, decltype([](const Tournament& t){return DatabaseController::instance().FindRootOrganization(t).GetName();})> rOrganizationNameFilter{blSearchForExactMatch};    
    EXPECT_EQ(vecExpectedTournaments, GetTournamentIDs(rOrganizationNameFilter.ApplyFilter(m_vecTournament, sFilteringWord)));
}
INSTANTIATE_TEST_SUITE_P(
    OrganizationNameFiltering,
    OrganizationNameFiltering,
    ::testing::Values(
        std::make_tuple("ar", false, std::vector<unsigned>({0, 1, 2, 4, 6, 8, 9, 10})),
        std::make_tuple("ar", true, std::vector<unsigned>({})),
        std::make_tuple("kara", false, std::vector<unsigned>({0, 1, 4, 6, 10})),
        std::make_tuple("kara", true, std::vector<unsigned>({})),
        std::make_tuple("Aselsan", false, std::vector<unsigned>({2, 5, 7, 8, 11})),
        std::make_tuple("Aselsan", true, std::vector<unsigned>({})),
        std::make_tuple("Aselsan Spor Olimpiyatlari", false, std::vector<unsigned>({2, 8})),
        std::make_tuple("Aselsan Spor Olimpiyatlari", true, std::vector<unsigned>({2, 8}))
    )
);
class CategoryFiltering : public DataFilterTest, public ::testing::WithParamInterface<std::tuple<std::string, bool, std::vector<unsigned>>> {};
TEST_P(CategoryFiltering, CategoryFiltering)
{
	auto [sFilteringWord, blSearchForExactMatch, vecExpectedTournaments] = GetParam();
    DataFilter<Tournament, decltype([](const Tournament& t){return t.GetCategory();})> rSeasonFilter{blSearchForExactMatch};    
    EXPECT_EQ(vecExpectedTournaments, GetTournamentIDs(rSeasonFilter.ApplyFilter(m_vecTournament, sFilteringWord)));
}
INSTANTIATE_TEST_SUITE_P(
    CategoryFiltering,
    CategoryFiltering,
    ::testing::Values(
        std::make_tuple("A", false, std::vector<unsigned>({1, 5, 6, 9, 11})),
        std::make_tuple("A", true, std::vector<unsigned>({5, 6, 9})),
        std::make_tuple("c", false, std::vector<unsigned>({2, 7})),
        std::make_tuple("c", true, std::vector<unsigned>({2, 7})),
        std::make_tuple("D", false, std::vector<unsigned>({0, 3, 4, 8, 10})),
        std::make_tuple("D", true, std::vector<unsigned>({0, 3, 4, 8, 10})),
        std::make_tuple("Ilk", false, std::vector<unsigned>({1, 11})),
        std::make_tuple("Ilk", true, std::vector<unsigned>({})),
        std::make_tuple("Ilk Turnuvam", false, std::vector<unsigned>({1, 11}))
    )
);
class TypeFiltering : public DataFilterTest, public ::testing::WithParamInterface<std::tuple<std::string, bool, std::vector<unsigned>>> {};
TEST_P(TypeFiltering, TypeFiltering)
{
	auto [sFilteringWord, blSearchForExactMatch, vecExpectedTournaments] = GetParam();
    DataFilter<Tournament, decltype([](const Tournament& t){return t.GetType();})> rSeasonFilter{blSearchForExactMatch};    
    EXPECT_EQ(vecExpectedTournaments, GetTournamentIDs(rSeasonFilter.ApplyFilter(m_vecTournament, sFilteringWord)));
}
INSTANTIATE_TEST_SUITE_P(
    TypeFiltering,
    TypeFiltering,
    ::testing::Values(
        std::make_tuple("Single", false, std::vector<unsigned>({0, 2, 5, 6, 7, 8, 9, 10, 11})),
        std::make_tuple("Single", true, std::vector<unsigned>({})),
        std::make_tuple("Double", false, std::vector<unsigned>({1, 3, 4})),
        std::make_tuple("Double", true, std::vector<unsigned>({})),
        std::make_tuple("Double Men", false, std::vector<unsigned>({1, 4})),
        std::make_tuple("Double Men", true, std::vector<unsigned>({1, 4})),
        std::make_tuple("Double Mixed", false, std::vector<unsigned>({3})),
        std::make_tuple("Double Mixed", true, std::vector<unsigned>({3}))
    )
);