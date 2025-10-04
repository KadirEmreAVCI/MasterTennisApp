#ifndef STATCONTROLLERTEST_H
#define STATCONTROLLERTEST_H

// External Headers 
#include <gtest/gtest.h>

// Standard Headers

// Project Headers
#include "StatController.h"
#include "Profile.h"
#include "DatabaseController.h"

class StatControllerTest : public testing::Test {
protected:
	void SetUp()
	{
		std::vector<Tournament> vecTournament;
        Tournament t;
        
        t = Tournament{0, 0, 0, "Karayollari", "2022 Winter", "D", "Single Men", std::nullopt, 24, true, true, 3};
        t.SetMatches({  Match{ 0, 0, "U", "Quarter Final", "Op1", "", QDate{2023, 1, 1}, QTime{9, 0, 0}, {Set{Score(6, 1)}, Set{Score(6, 7), Score(5, 7)}, Set{Score(10, 4)}}},
                        Match{ 1, 0, "U", "Final 16", "Mustafa Yavuz Kirli", "", QDate{2224, 2, 11}, QTime{18, 0, 0}, {Set{Score(6, 0)}, Set{Score(7, 5)}}},
                        Match{ 2, 0, "U", "Final", "Ismail Ozaydin", "Bora Deveci", QDate{2024, 7, 10}, QTime{18, 0, 0}, {Set{Score(1, 6)}, Set{Score(1, 6)}}}});
        vecTournament.push_back(std::move(t));

        t = Tournament{1, 0, 0, "Karayollari", "2023 Summer", "Ilk Turnuvam", "Double Men", "Alp Emre Kamis", 36, false, false, 3};
        t.SetMatches({  Match{ 3, 1, "U", "Semi Final", "Ali Oner", "", QDate{2021, 6, 6}, QTime{18, 0, 0}, {Set{Score(1, 6)}, Set{Score(4, 6)}}},
                        Match{ 4, 1, "U", "Final 32", "Doruk Orbay", "", QDate{2022, 11, 7}, QTime{21, 0, 0}, {Set{Score(6, 7), Score(3, 7)}, Set{Score(6, 4)}, Set{Score(10, 5)}}},
                        Match{ 5, 1, "U", "Group Stage", "Alper Kagan Aldemir", "Tolunay Bayrakci", QDate{2023, 4, 15}, QTime{19, 30, 0}, {Set{Score(6, 1)}, Set{Score(6, 2)}}},
                        Match{ 6, 1, "WO","Group Stage", "Engin Oz", "", QDate{2024, 10, 11}, QTime{0, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
                        Match{ 7, 1, "BYE","Final 32", "", "", QDate{2024, 11, 12}, QTime{0, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}}});
        vecTournament.push_back(std::move(t));

        t = Tournament{2, 0, 1, "Aselsan", "2024 Fall", "C", "Single Men", std::nullopt, 15, true, true, 3};
        t.SetMatches({  Match{ 8, 2, "WO","Group Stage", "Oguzhan Bulut", "", QDate{2023, 5, 1}, QTime{0, 0, 0}, {Set{Score(0, 6)}, Set{Score(0, 6)}}},
                        Match{ 9, 2, "U", "Final", "Mehmet Efe Uluyurt", "", QDate{2024, 3, 7}, QTime{21, 0, 0}, {Set{Score(4, 6)}, Set{Score(6, 1)}, Set{Score(10, 8)}}},
                        Match{ 10,2, "U", "3rd Place Game", "Unknown", "", QDate{2025, 5, 1}, QTime{1, 0, 0}, {Set{Score(0, 6)}, Set{Score(3, 6)}}}});
        vecTournament.push_back(std::move(t));

        t = Tournament{3, 0, 2, "Ahal Teke", "2025 Spring", "D", "Double Mixed", "Hakki Ozdemir", 64, true, true, 3};
        t.SetMatches({  Match{ 11,3, "U","Final 16", "Unknown5", "", QDate{2022, 1, 1}, QTime{7,0,0}, {Set{Score(0, 0)}, Set{Score(0, 0)}}},
			            Match{ 12,3, "U","Group Stage", "Unknown6", "", QDate{2023, 1, 1}, QTime{6,0,0}, {Set{Score(1, 1)}, Set{Score(0, 0)}}}});
        vecTournament.push_back(std::move(t));

        t = Tournament{4, 0, 3, "PTA", "2025 Winter", "D", "Single Men", std::nullopt, 8, true, true, 3};
        t.SetMatches({  Match{ 13,4, "U","Final 16", "Unknown7", "", QDate{2000, 1, 1}, QTime{7,0,0}, {Set{Score(6, 0)}, Set{Score(6, 3)}, Set{Score(2, 2)}}},
			            Match{ 14,4, "U","Final", "Unknown1", "", QDate{2001, 1, 2}, QTime{0, 0, 0}, {Set{Score(2, 6)}, Set{Score(3, 6)}}}});
        vecTournament.push_back(std::move(t));

        t = Tournament{5, 0, 1, "Aselsan", "2025 Summer", "A", "Single Men", "", 4, true, false, 1};
        t.SetMatches({  Match{ 15,5, "U","Quarter Final", "Unknown2", "", QDate{2020, 1, 3}, QTime{0, 0, 0}, {Set{Score(0, 0)}}},
                        Match{ 16,5, "U","Semi Final", "Unknown3", "", QDate{2021, 1, 4}, QTime{0, 0, 0}, {Set{Score(2, 6)}}},
                        Match{ 17,5, "U","Final 16", "Unknown4", "", QDate{2022, 1, 5}, QTime{0, 0, 0}, {Set{Score(0, 0)}, Set{Score(0, 0)}}}});
        vecTournament.push_back(std::move(t));

        m_rActiveProfile = Profile{0, "Kadir Emre Avci", "/data/user-profile-picture", Gender::Male};
        m_rActiveProfile.SetTournaments(vecTournament);

        DatabaseController::instance().m_vecTournament = vecTournament;
        m_vecStatReport = StatController::instance().GetUpdatedCareerStats(m_rActiveProfile);
    }
	Profile m_rActiveProfile;
    std::vector<StatReport> m_vecStatReport;
    float GetWinRatePercentage(size_t szWin, size_t szLose)const;
};

#endif