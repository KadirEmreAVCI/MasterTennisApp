#ifndef DATABASECONTROLLERTEST_H
#define DATABASECONTROLLERTEST_H

// External Headers 
#include <gtest/gtest.h>

// Standard Headers
#include <tuple>

// Project Headers
#include "DatabaseController.h"
#include "Profile.h"

class DatabaseControllerTest : public testing::Test {
protected:
	void SetUp()
	{
		m_vecMatch.insert(m_vecMatch.end(), {
			Match{ 0, 0, "U", "Quarter Final", "Op1", "", QDate{2023, 1, 1}, QTime{9, 0, 0}, {Set{Score(6, 1)}, Set{Score(6, 7), Score(5, 7)}, Set{Score(10, 4)}}},
			Match{ 1, 0, "U", "Final 16", "Mustafa Yavuz Kirli", "", QDate{2024, 2, 11}, QTime{18, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 1)}, Set{Score(1, 6)}, Set{Score(7, 5)}}},
			Match{ 2, 0, "U", "Final", "Ismail Ozaydin", "Bora Deveci", QDate{2024, 7, 10}, QTime{18, 0, 0}, {Set{Score(1, 6)}, Set{Score(1, 6)}, Set{Score(4, 6)}}},
			Match{ 3, 1, "U", "Semi Final", "Ali Oner", "", QDate{2021, 6, 6}, QTime{18, 0, 0}, {Set{Score(1, 6)}, Set{Score(4, 6)}}},
			Match{ 4, 1, "U", "Final 32", "Doruk Orbay", "", QDate{2022, 11, 7}, QTime{21, 0, 0}, {Set{Score(6, 7), Score(3, 7)}, Set{Score(6, 4)}, Set{Score(10, 5)}}},
			Match{ 5, 1, "U", "Group Stage", "Alper Kagan Aldemir", "Tolunay Bayrakci", QDate{2023, 4, 15}, QTime{19, 30, 0}, {Set{Score(6, 1)}}},
			Match{ 6, 1, "WO","Group Stage", "Engin Oz", "", QDate{2024, 10, 11}, QTime{0, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
			Match{ 7, 1, "BYE","Final 32", "", "", QDate{2024, 11, 12}, QTime{0, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
			Match{ 8, 2, "WO","Group Stage", "Oguzhan Bulut", "", QDate{2023, 5, 1}, QTime{0, 0, 0}, {Set{Score(0, 6)}, Set{Score(0, 6)}}},
			Match{ 9, 2, "U", "Final", "Mehmet Efe Uluyurt", "", QDate{2024, 3, 7}, QTime{21, 0, 0}, {Set{Score(4, 6)}, Set{Score(6, 1)}, Set{Score(10, 8)}}},
			Match{ 10,2, "U", "3rd Place Game", "Unknown", "", QDate{2025, 5, 1}, QTime{1, 0, 0}, {Set{Score(0, 6)}, Set{Score(3, 6)}}},
			Match{ 11,3, "U","Final 16", "Unknown5", "", QDate{2022, 1, 1}, QTime{7,0,0}, {Set{Score(0, 0)}, Set{Score(0, 0)}}},
			Match{ 12,3, "U","Group Stage", "Unknown6", "", QDate{2023, 1, 1}, QTime{6,0,0}, {Set{Score(1, 1)}, Set{Score(0, 0)}} },
			Match{ 13,4, "U","Final 16", "Unknown7", "", QDate{2000, 1, 1}, QTime{7,0,0}, {Set{Score(6, 0)}, Set{Score(6, 3)}, Set{Score(2, 2)}}},
			Match{ 14,4, "U","Final", "Unknown1", "", QDate{2001, 1, 2}, QTime{0, 0, 0}, {Set{Score(2, 6)}, Set{Score(3, 6)}}},
			Match{ 15,5, "U","Quarter Final", "Unknown2", "", QDate{2020, 1, 3}, QTime{0, 0, 0}, {Set{Score(0, 0)}, Set{Score(0, 0)}}},
			Match{ 16,5, "U","Semi Final", "Unknown3", "", QDate{2021, 1, 4}, QTime{0, 0, 0}, {Set{Score(2, 6)}, Set{Score(3, 6)}}},
			Match{ 17,5, "U","Final 16", "Unknown4", "", QDate{2022, 1, 5}, QTime{0, 0, 0}, {Set{Score(0, 0)}, Set{Score(0, 0)}}}
			});
		m_vecTournament.insert(m_vecTournament.end(), {
			Tournament{0, 0, 0, "Karayollari", "2022 Winter", "D", "Single Men", std::nullopt, 24, true, true, 3},
			Tournament{1, 1, 0, "Karayollari", "2023 Summer", "Ilk Turnuvam", "Double Men", "Alp Emre Kamis", 36, false, false, 3},
			Tournament{2, 0, 1, "Ase3lsan", "2024 Fall", "C", "Single Men", std::nullopt, 15, true, true, 3},
			Tournament{3, 0, 2, "Ahal Teke", "2025 Spring", "D", "Double Mixed", "Hakki Ozdemir", 64, true, true, 3},
			Tournament{4, 1, 3, "PTA", "2025 Winter", "D", "Double Men", std::nullopt, 8, true, true, 3},
			Tournament{5, 0, 1, "Aselsan", "2025 Summer", "A", "Single Men", "", 4, true, false, 1}
			});
		m_vecOrganization.insert(m_vecOrganization.end(), {
			Organization{0, "Karayollari", "", {"Master", "A+", "A", "B", "C", "D", "Ilk Turnuvam"}},
			Organization{1, "Aselsan", "", { "A", "B", "C"}},
			Organization{2, "Ahal Teke", "", {"Master", "A", "B", "C", "D"}},
			Organization{3, "PTA", "", {"Master", "A+", "A", "B", "C", "D", "Ilk Turnuvam"}}
			});
		m_vecProfile.insert(m_vecProfile.end(), {
			Profile{0, "Kadir Emre Avci", "data/pp/", Gender::Male},
			Profile{1, "Ayse Nur Avci", "data/pp/", Gender::Female}
			});
		LoadMatchData();
		LoadTournamentData();
		LoadOrganizationData();
		LoadProfileData();
	}
	std::vector<Match> GetMatchesFromDB()const;
	std::vector<Tournament> GetTournamentsFromDB()const;
	std::vector<Organization> GetOrganizationsFromDB()const;
	std::vector<Profile> GetProfilesFromDB()const;
	std::vector<Tournament> GetTournamentsOFProfile(unsigned uiProfileID)const;
	std::vector<Match> m_vecMatch;
	std::vector<Tournament> m_vecTournament;
	std::vector<Organization> m_vecOrganization;
	std::vector<Profile> m_vecProfile;
private:
	void LoadMatchData();
	void LoadTournamentData();
	void LoadOrganizationData();
	void LoadProfileData();
};

class FindMatchesOfTournamentTest : public DatabaseControllerTest, public ::testing::WithParamInterface<std::tuple<size_t, std::vector<unsigned>>> {};
TEST_P(FindMatchesOfTournamentTest, FindMatchesOfTournament)
{
	auto [idx, expected] = GetParam();
	const auto vecMatch = GetTournamentsFromDB()[idx].GetMatches();
	for (std::size_t i = 0; i < vecMatch.size(); ++i)
	{
		EXPECT_EQ(expected[i], vecMatch[i].GetID());
	}
}

class FindTournamentsOfOrganizationTest : public DatabaseControllerTest, public ::testing::WithParamInterface<std::tuple<size_t, std::vector<unsigned>>> {};
TEST_P(FindTournamentsOfOrganizationTest, FindTournamentsOfOrganization)
{
	auto [idx, expected] = GetParam();
	const auto vecTournament = GetOrganizationsFromDB()[idx].GetTournaments();
	for (std::size_t i = 0; i < vecTournament.size(); ++i)
	{
		EXPECT_EQ(expected[i], vecTournament[i].GetID());
	}
}

class FindTournamentsOfProfileTest : public DatabaseControllerTest, public ::testing::WithParamInterface<std::tuple<size_t, std::vector<unsigned>>> {};
TEST_P(FindTournamentsOfProfileTest, FindTournamentsOfProfile)
{
	auto [idx, expected] = GetParam();
	const auto vecProfile = GetProfilesFromDB();
	const auto vecTournamentsOfProfile = GetTournamentsOFProfile(vecProfile[idx].GetID());
	for (std::size_t idxT = 0; idxT < vecTournamentsOfProfile.size(); ++idxT)
	{
		EXPECT_EQ(expected[idxT], vecTournamentsOfProfile[idxT].GetID());
	}
}

class FindRootTournamentOfMatchTest : public DatabaseControllerTest, public ::testing::WithParamInterface<std::tuple<size_t, unsigned>> {};
TEST_P(FindRootTournamentOfMatchTest, FindRootTournamentOfMatch)
{
	auto [idx, expected] = GetParam();
	const auto vecMatch = GetMatchesFromDB();
	const auto rootTournament = DatabaseController::instance().FindRootTournament(vecMatch[idx]);
	EXPECT_EQ(expected, rootTournament.GetID());
}

#endif