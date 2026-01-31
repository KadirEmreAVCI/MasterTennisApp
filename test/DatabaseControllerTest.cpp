// Standard Headers
#include <algorithm>

// Test Headers
#include "DatabaseControllerTest.h"

std::vector<Match> DatabaseControllerTest::GetMatchesFromDB()const
{
	return DatabaseController::instance().m_vecMatch;
}
std::vector<Tournament> DatabaseControllerTest::GetTournamentsFromDB()const
{
	return DatabaseController::instance().m_vecTournament;
}
std::vector<Organization> DatabaseControllerTest::GetOrganizationsFromDB()const
{
	return DatabaseController::instance().m_vecOrganization;
}
std::vector<Profile> DatabaseControllerTest::GetProfilesFromDB()const
{
	return DatabaseController::instance().m_vecProfile;
}
std::vector<Tournament> DatabaseControllerTest::GetTournamentsOFProfile(unsigned uiProfileID)const
{
	return DatabaseController::instance().FindTournamentsOfProfile(uiProfileID);
}
void DatabaseControllerTest::LoadMatchData()
{
	DatabaseController::instance().m_vecMatch = m_vecMatch;
}
void DatabaseControllerTest::LoadTournamentData()
{
	DatabaseController::instance().m_vecTournament = m_vecTournament;
	for (Tournament& t : DatabaseController::instance().m_vecTournament)
	{
		t.SetMatches(DatabaseController::instance().FindMatchesOfTournament(t.GetID()));
	}
}
void DatabaseControllerTest::LoadOrganizationData()
{
	DatabaseController::instance().m_vecOrganization = m_vecOrganization;
	for (Organization& org : DatabaseController::instance().m_vecOrganization)
	{
		org.SetTournaments(DatabaseController::instance().FindTournamentsOfOrganization(org.GetID()));
	}
}
void DatabaseControllerTest::LoadProfileData()
{
	DatabaseController::instance().m_vecProfile = m_vecProfile;
	for (Profile& p : DatabaseController::instance().m_vecProfile)
	{
		p.SetTournaments(DatabaseController::instance().FindTournamentsOfProfile(p.GetID()));
	}
}
class FindMatchesOfTournamentTest : public DatabaseControllerTest, public ::testing::WithParamInterface<std::tuple<size_t, std::vector<unsigned>>> {};
TEST_P(FindMatchesOfTournamentTest, FindMatchesOfTournament)
{
	auto [idx, expected] = GetParam();
	const auto vecMatch = GetTournamentsFromDB()[idx].GetMatches();
	EXPECT_EQ(vecMatch.size(), expected.size());
	for (std::size_t i = 0; i < vecMatch.size(); ++i)
	{
		EXPECT_EQ(expected[i], vecMatch[i].GetID());
	}
}
INSTANTIATE_TEST_SUITE_P(
    FindMatchesOfTournament,
    FindMatchesOfTournamentTest,
    ::testing::Values(
        std::make_tuple(0, std::vector<unsigned>{2, 1, 0}),
        std::make_tuple(1, std::vector<unsigned>{7, 6, 5, 4, 3}),
        std::make_tuple(2, std::vector<unsigned>{10, 9, 8}),
        std::make_tuple(3, std::vector<unsigned>{12, 11}),
        std::make_tuple(4, std::vector<unsigned>{14, 13}),
        std::make_tuple(5, std::vector<unsigned>{17, 16, 15})
    )
);
class FindTournamentsOfOrganizationTest : public DatabaseControllerTest, public ::testing::WithParamInterface<std::tuple<size_t, std::vector<unsigned>>> {};
TEST_P(FindTournamentsOfOrganizationTest, FindTournamentsOfOrganization)
{
	auto [idx, expected] = GetParam();
	const auto vecTournament = GetOrganizationsFromDB()[idx].GetTournaments();
	EXPECT_EQ(vecTournament.size(), expected.size());
	for (std::size_t i = 0; i < vecTournament.size(); ++i)
	{
		EXPECT_EQ(expected[i], vecTournament[i].GetID());
	}
}
INSTANTIATE_TEST_SUITE_P(
    FindTournamentsOfOrganization,
    FindTournamentsOfOrganizationTest,
    ::testing::Values(
        std::make_tuple(0, std::vector<unsigned>{1, 0}),
        std::make_tuple(1, std::vector<unsigned>{2, 5}), // <-- fixed order
        std::make_tuple(2, std::vector<unsigned>{3}),
        std::make_tuple(3, std::vector<unsigned>{4})
    )
);
class FindTournamentsOfProfileTest : public DatabaseControllerTest, public ::testing::WithParamInterface<std::tuple<size_t, std::vector<unsigned>>> {};
TEST_P(FindTournamentsOfProfileTest, FindTournamentsOfProfile)
{
	auto [idx, expected] = GetParam();
	const auto vecProfile = GetProfilesFromDB();
	const auto vecTournamentsOfProfile = GetTournamentsOFProfile(vecProfile[idx].GetID());
	EXPECT_EQ(vecTournamentsOfProfile.size(), expected.size());
	for (std::size_t idxT = 0; idxT < vecTournamentsOfProfile.size(); ++idxT)
	{
		EXPECT_EQ(expected[idxT], vecTournamentsOfProfile[idxT].GetID());
	}
}
INSTANTIATE_TEST_SUITE_P(
    FindTournamentsOfProfile,
    FindTournamentsOfProfileTest,
    ::testing::Values(
        std::make_tuple(0, std::vector<unsigned>{0, 2, 3, 5}),
        std::make_tuple(1, std::vector<unsigned>{1, 4})
	)
);
class FindRootTournamentOfMatchTest : public DatabaseControllerTest, public ::testing::WithParamInterface<std::tuple<size_t, unsigned>> {};
TEST_P(FindRootTournamentOfMatchTest, FindRootTournamentOfMatch)
{
	auto [idx, expected] = GetParam();
	const auto vecMatch = GetMatchesFromDB();
	const auto rootTournament = DatabaseController::instance().FindRootTournament(vecMatch[idx]);
	EXPECT_EQ(expected, rootTournament.GetID());
}
INSTANTIATE_TEST_SUITE_P(
	FindRootTournamentOfMatch,
	FindRootTournamentOfMatchTest,
	::testing::Values(
		std::make_tuple(0, 0),
		std::make_tuple(1, 0),
		std::make_tuple(2, 0),
		std::make_tuple(3, 1),
		std::make_tuple(4, 1),
		std::make_tuple(5, 1),
		std::make_tuple(6, 1),
		std::make_tuple(7, 1),
		std::make_tuple(8, 2),
		std::make_tuple(9, 2),
		std::make_tuple(10,2),
		std::make_tuple(11,3),
		std::make_tuple(12,3),
		std::make_tuple(13,4),
		std::make_tuple(14,4),
		std::make_tuple(15,5),
		std::make_tuple(16,5),
		std::make_tuple(17,5)
	)
);