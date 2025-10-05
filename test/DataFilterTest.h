#ifndef DATAFILTERTEST_H
#define DATAFILTERTEST_H

// External Headers 
#include <gtest/gtest.h>

// Standard Headers
#include <tuple>

// Project Headers
#include "DataFilter.h"
#include "Organization.h"
#include "DatabaseController.h"

class DataFilterTest : public testing::Test{
protected:
	void SetUp()
	{
        std::vector<Organization> vecOrganization;
        vecOrganization.insert(vecOrganization.end(), {
            Organization{0, "Karayollari Tenis Kulubu"},
            Organization{1, "Aselsan Spor Olimpiyatlari"},
            Organization{2, "Ahal Teke Atlispor Tenis Kulubu"},
            Organization{3, "Aselsan Tenis Toplulugu"},
            Organization{4, "Pars Tenis Akademisi"}
        });
		m_vecTournament.insert(m_vecTournament.end(), {
			Tournament{0, 0, 0, "",  "2022 Winter",  "D",            "Single Men", std::nullopt,         24, true, true, 3},
			Tournament{1, 0, 0, "",  "2023 Summer",  "Ilk Turnuvam", "Double Men", "Alp Emre Kamis",     36, false, false, 3},
			Tournament{2, 0, 1, "",  "2024 Fall",    "C",            "Single Men", std::nullopt,         15, true, true, 3},
			Tournament{3, 0, 2, "",  "2025 Spring",  "D",            "Double Mixed", "Hakki Ozdemir",    64, true, true, 3},
			Tournament{4, 0, 0, "",  "2025 Winter",  "D",            "Double Men", std::nullopt,         8, true, true, 3},
			Tournament{5, 0, 3, "",  "2025 Summer",  "A",            "Single Men", std::nullopt,         4, true, false, 1},
            Tournament{6, 0, 0, "",  "2024 Winter",  "A",            "Single Men", std::nullopt,         4, true, false, 1},
            Tournament{7, 0, 3, "",  "2023 Fall",    "C",            "Single Men", std::nullopt,         4, true, false, 1},
            Tournament{8, 0, 1, "",  "2025 Summer",  "D",            "Single Men", std::nullopt,         4, true, false, 1},
            Tournament{9, 0, 4, "",  "2023 Spring",  "A",            "Single Men", std::nullopt,         4, true, false, 1},
            Tournament{10, 0, 0, "", "2023 Spring",  "D",            "Single Men", std::nullopt,         4, true, false, 1},
            Tournament{11, 0, 3, "", "2025 Summer",  "Ilk Turnuvam", "Single Men", std::nullopt,         4, true, false, 1}
			});
        DatabaseController::instance().m_vecOrganization = vecOrganization;
	}
protected:
    std::vector<unsigned> GetTournamentIDs(const std::vector<Tournament>& vecTournament)const
    {
        std::vector<unsigned> vecTournamentIDs;
        vecTournamentIDs.reserve(vecTournament.size());
        std::transform(vecTournament.cbegin(), vecTournament.cend(), std::back_inserter(vecTournamentIDs), [](const Tournament& t){
            return t.GetID();
        });
        return vecTournamentIDs;
    }
	std::vector<Tournament> m_vecTournament;
};

class OrganizationNameFiltering : public DataFilterTest, public ::testing::WithParamInterface<std::tuple<std::string, bool, std::vector<unsigned>>> {};
TEST_P(OrganizationNameFiltering, OrganizationNameFiltering)
{
	auto [sFilteringWord, blSearchForExactMatch, vecExpectedTournaments] = GetParam();
    DataFilter<Tournament, decltype([](const Tournament& t){return DatabaseController::instance().FindRootOrganization(t).GetName();})> rOrganizationNameFilter{blSearchForExactMatch};    
    EXPECT_EQ(vecExpectedTournaments, GetTournamentIDs(rOrganizationNameFilter.ApplyFilter(m_vecTournament, sFilteringWord)));
}

class CategoryFiltering : public DataFilterTest, public ::testing::WithParamInterface<std::tuple<std::string, bool, std::vector<unsigned>>> {};
TEST_P(CategoryFiltering, CategoryFiltering)
{
	auto [sFilteringWord, blSearchForExactMatch, vecExpectedTournaments] = GetParam();
    DataFilter<Tournament, decltype([](const Tournament& t){return t.GetCategory();})> rSeasonFilter{blSearchForExactMatch};    
    EXPECT_EQ(vecExpectedTournaments, GetTournamentIDs(rSeasonFilter.ApplyFilter(m_vecTournament, sFilteringWord)));
}

class TypeFiltering : public DataFilterTest, public ::testing::WithParamInterface<std::tuple<std::string, bool, std::vector<unsigned>>> {};
TEST_P(TypeFiltering, TypeFiltering)
{
	auto [sFilteringWord, blSearchForExactMatch, vecExpectedTournaments] = GetParam();
    DataFilter<Tournament, decltype([](const Tournament& t){return t.GetType();})> rSeasonFilter{blSearchForExactMatch};    
    EXPECT_EQ(vecExpectedTournaments, GetTournamentIDs(rSeasonFilter.ApplyFilter(m_vecTournament, sFilteringWord)));
}

#endif  // DATAFILTERTEST_H