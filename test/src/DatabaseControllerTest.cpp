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
	DatabaseController::instance().m_vecProfile = m_vecProfile;
	for (Profile& p : DatabaseController::instance().m_vecProfile)
	{
		p.SetParticipatedOrgs(DatabaseController::instance().FindParticipatedOrgsOfProfile(p.GetID()));
	}
}
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
			EXPECT_EQ(vecTestOutput[idxT][idxM], vecMatch[idxM].GetID());
		}
	}
}
TEST_F(DatabaseControllerTest, FindTournamentsOfOrganization)
{
	const std::vector<std::vector<unsigned>> vecTestOutput{
		{1, 0},
		{5, 2},
		{3},
		{4}
	};
	const auto vecOrganization = GetOrganizationsFromDB();
	for (std::size_t idxO = 0; idxO < vecOrganization.size(); ++idxO)
	{
		const auto vecTournament = vecOrganization[idxO].GetTournaments();
		for (std::size_t idxT = 0; idxT < vecTournament.size(); ++idxT)
		{
			EXPECT_EQ(vecTestOutput[idxO][idxT], vecTournament[idxT].GetID());
		}
	}
}
TEST_F(DatabaseControllerTest, FindTournamentsOfProfile)
{
	const std::vector<std::vector<unsigned>> vecTestOutput{
		{0, 2, 3, 5},
		{1, 4}
	};
	const auto vecProfile = GetProfilesFromDB();
	for (std::size_t idxP = 0; idxP < vecProfile.size(); ++idxP)
	{
		const auto vecTournamentsOfProfile = GetTournamentsOFProfile(vecProfile[idxP].GetID());
		for (std::size_t idxT = 0; idxT < vecTournamentsOfProfile.size(); ++idxT)
		{
			EXPECT_EQ(vecTestOutput[idxP][idxT], vecTournamentsOfProfile[idxT].GetID());
		}
	}
}
TEST_F(DatabaseControllerTest, FindParticipatedOrgsOfProfile)
{
	const std::vector<std::vector<unsigned>> vecTestOutput{
		{0, 1, 2},
		{0, 3}
	};
	const auto vecProfile = GetProfilesFromDB();
	for (std::size_t idxP = 0; idxP < vecProfile.size(); ++idxP)
	{
		const auto vecParticipateOrg= vecProfile[idxP].GetParticipatedOrgs();
		for (std::size_t idxO = 0; idxO < vecParticipateOrg.size(); ++idxO)
		{
			EXPECT_EQ(vecTestOutput[idxP][idxO],  vecParticipateOrg[idxO].GetID());
		}
	}
}
