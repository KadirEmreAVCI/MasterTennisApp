// Standard Headers
#include <algorithm>

// Test Headers
#include "DatabaseControllerTest.h"

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
	// DatabaseController::instance().m_vecProfile = m_vecProfile;
	// for (Profile& p : DatabaseController::instance().m_vecProfile)
	// {
	// 	p.SetParticipatedOrgs(DatabaseController::instance().FindParticipatedOrgsOfProfile(p.GetID()));
	// }
}
INSTANTIATE_TEST_SUITE_P(
    FindMatchesOfTournament,
    FindMatchesOfTournamentTest,
    ::testing::Values(
        std::make_tuple(0, std::vector<unsigned>{0, 1, 2}),
        std::make_tuple(1, std::vector<unsigned>{3, 4, 5, 6, 7}),
        std::make_tuple(2, std::vector<unsigned>{8, 9, 10}),
        std::make_tuple(3, std::vector<unsigned>{11, 12}),
        std::make_tuple(4, std::vector<unsigned>{13, 14}),
		std::make_tuple(5, std::vector<unsigned>{15, 16, 17})
	)
);
INSTANTIATE_TEST_SUITE_P(
    FindTournamentsOfOrganization,
    FindTournamentsOfOrganizationTest,
    ::testing::Values(
        std::make_tuple(0, std::vector<unsigned>{1, 0}),
        std::make_tuple(1, std::vector<unsigned>{5, 2}),
        std::make_tuple(2, std::vector<unsigned>{3}),
        std::make_tuple(3, std::vector<unsigned>{4})
	)
);
// INSTANTIATE_TEST_SUITE_P(
//     FindTournamentsOfProfile,
//     FindTournamentsOfProfileTest,
//     ::testing::Values(
//         std::make_tuple(0, std::vector<unsigned>{0, 2, 3, 5}),
//         std::make_tuple(1, std::vector<unsigned>{1, 4})
// 	)
// );
// INSTANTIATE_TEST_SUITE_P(
//     FindParticipatedOrgsOfProfile,
//     FindParticipatedOrgsOfProfileTest,
//     ::testing::Values(
//         std::make_tuple(0, std::vector<unsigned>{0, 1, 2}),
//         std::make_tuple(1, std::vector<unsigned>{0, 3})
// 	)
// );