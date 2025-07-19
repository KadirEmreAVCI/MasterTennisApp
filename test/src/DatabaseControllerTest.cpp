// Standard Headers
#include <algorithm>

// Test Headers
#include "DatabaseControllerTest.h"

TEST_F(DatabaseControllerTest, FindMatchesOfTournament)
{
	const std::vector<std::vector<unsigned>> vecTestOutput{ 
		{0, 1, 2},
		{3, 4, 5, 6, 7}, 
		{8, 9, 10}, 
		{11, 12}, 
		{13, 14}, 
		{15, 16, 17}
	};
	const auto vecTournaments = GetTournamentsFromDB();
	for (std::size_t idxT = 0; idxT < vecTournaments.size(); ++idxT)
	{
		const auto vecMatch = vecTournaments[idxT].GetMatches();
		for (std::size_t idxM = 0; idxM < vecMatch.size(); ++idxM)
		{
			EXPECT_TRUE(std::any_of(vecMatch.cbegin(), vecMatch.cend(), [=](const Match& m){
				return vecTestOutput[idxT][idxM] == m.GetID();
				}));
		}
	}
}
TEST_F(DatabaseControllerTest, FindTournamentsOfOrganization)
{
	const std::vector<std::vector<unsigned>> vecTestOutput{
		{0, 1},
		{2, 5},
		{3},
		{4}
	};
	const auto vecOrganization = GetOrganizationsFromDB();
	for (std::size_t idxO = 0; idxO < vecOrganization.size(); ++idxO)
	{
		const auto vecTournament = vecOrganization[idxO].GetTournaments();
		for (std::size_t idxT = 0; idxT < vecTournament.size(); ++idxT)
		{
			EXPECT_TRUE(std::any_of(vecTournament.cbegin(), vecTournament.cend(), [=](const Tournament& t) {
				return vecTestOutput[idxO][idxT] == t.GetID();
				}));
		}
	}
}
