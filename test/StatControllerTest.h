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
        t.SetMatches({  Match{ 0, 0, "U", "Quarter Final", "Op", "", QDate{2023, 1, 1}, QTime{9, 0, 0}, {Set{Score(6, 1)}, Set{Score(6, 7), Score(5, 7)}, Set{Score(10, 4)}}},
                        Match{ 1, 0, "U", "Final 16", "Op", "", QDate{2224, 2, 11}, QTime{18, 0, 0}, {Set{Score(6, 0)}, Set{Score(7, 5)}}},
                        Match{ 2, 0, "U", "Final", "Op", "", QDate{2024, 7, 10}, QTime{18, 0, 0}, {Set{Score(1, 6)}, Set{Score(1, 6)}}},
                        Match{ 3, 0, "U", "Semi Final", "Op", "", QDate{2024, 7, 10}, QTime{18, 0, 0}, {Set{Score(7, 6), Score(7,2)}, Set{Score(6, 3)}}}
                    });
        vecTournament.push_back(std::move(t));

        t = Tournament{1, 0, 0, "Karayollari", "2023 Summer", "Ilk Turnuvam", "Double Men", "Alp Emre Kamis", 36, false, false, 3};
        t.SetMatches({  Match{ 4, 1, "U", "Semi Final", "Op1", "Op2", QDate{2021, 6, 6}, QTime{18, 0, 0}, {Set{Score(1, 6)}, Set{Score(4, 6)}}},
                        Match{ 5, 1, "U", "Final 32", "Op1", "Op2", QDate{2022, 11, 7}, QTime{21, 0, 0}, {Set{Score(6, 7), Score(3, 7)}, Set{Score(6, 4)}, Set{Score(10, 5)}}},
                        Match{ 6, 1, "U", "Group Stage", "Op1", "Op2", QDate{2023, 4, 15}, QTime{19, 30, 0}, {Set{Score(6, 1)}, Set{Score(6, 2)}}},
                        Match{ 7, 1, "WO","Group Stage", "Op1", "Op2", QDate{2024, 10, 11}, QTime{0, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
                        Match{ 8, 1, "BYE","Final 32", "Op1", "Op2", QDate{2024, 11, 12}, QTime{0, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}}
                    });
        vecTournament.push_back(std::move(t));

        t = Tournament{2, 0, 1, "Aselsan", "2024 Fall", "C", "Single Men", std::nullopt, 15, true, true, 3};
        t.SetMatches({  Match{ 9, 2, "WO","Group Stage", "Op", "", QDate{2023, 5, 1}, QTime{0, 0, 0}, {Set{Score(0, 6)}, Set{Score(0, 6)}}},
                        Match{ 10, 2, "U", "Quarter Final", "Op", "", QDate{2024, 3, 7}, QTime{21, 0, 0}, {Set{Score(6, 2)}, Set{Score(1, 6)}, Set{Score(5, 10)}}},
                        Match{ 11, 2, "U", "Semi Final", "Op", "", QDate{2024, 3, 7}, QTime{21, 0, 0}, {Set{Score(4, 6)}, Set{Score(6, 1)}, Set{Score(10, 8)}}},
                        Match{ 12,2, "U", "3rd Place Game", "Op", "", QDate{2025, 5, 1}, QTime{1, 0, 0}, {Set{Score(0, 6)}, Set{Score(3, 6)}}}
                    });
        vecTournament.push_back(std::move(t));

        t = Tournament{3, 0, 2, "Ahal Teke", "2025 Spring", "D", "Double Mixed", "Hakki Ozdemir", 64, true, true, 3};
        t.SetMatches({  Match{ 13,3, "U","Quarter Final", "Op1", "Op2", QDate{2022, 1, 1}, QTime{7,0,0}, {Set{Score(0, 0)}, Set{Score(0, 0)}}},
			            Match{ 14,3, "U","Semi Final", "Op1", "Op2", QDate{2023, 1, 1}, QTime{6,0,0}, {Set{Score(1, 1)}, Set{Score(0, 0)}}},
                        Match{ 15,3, "U","Quarter Final", "Op1", "Op2", QDate{2023, 1, 1}, QTime{6,0,0}, {Set{Score(6, 1)}, Set{Score(7, 6), Score(8, 6)}}},
                        Match{ 16,3, "U","Semi Final", "Op1", "Op2", QDate{2023, 1, 1}, QTime{6,0,0}, {Set{Score(6, 1)}, Set{Score(7, 5)}}},
                        Match{ 17,3, "U","Final", "Op1", "Op2", QDate{2023, 1, 1}, QTime{6,0,0}, {Set{Score(6, 3)}, Set{Score(1, 6)}, Set{Score(10, 5)}}}
                    });
        vecTournament.push_back(std::move(t));

        t = Tournament{4, 0, 3, "PTA", "2025 Winter", "D", "Single Men", std::nullopt, 8, true, true, 3};
        t.SetMatches({  Match{ 18,4, "U","Final 32", "Op", "", QDate{2000, 1, 1}, QTime{7,0,0}, {Set{Score(6, 0)}, Set{Score(6, 3)}, Set{Score(2, 2)}}},
			            Match{ 19,4, "U","Final 16", "Op", "", QDate{2001, 1, 2}, QTime{0, 0, 0}, {Set{Score(2, 6)}, Set{Score(3, 6)}}},
                        Match{ 20,4, "U","Quarter Final", "Op", "", QDate{2001, 1, 2}, QTime{0, 0, 0}, {Set{Score(2, 6)}, Set{Score(6, 7), Score(3, 7)}}}
                    });
        vecTournament.push_back(std::move(t));

        t = Tournament{5, 0, 1, "Aselsan", "2025 Summer", "C", "Single Men", "", 4, true, false, 1};
        t.SetMatches({  Match{ 21,5, "U","Quarter Final", "Op", "", QDate{2220, 1, 3}, QTime{0, 0, 0}, {Set{Score(0, 0)}}},
                        Match{ 22,5, "U","Final 16", "Op", "", QDate{2022, 1, 5}, QTime{0, 0, 0}, {Set{Score(0, 0)}, Set{Score(0, 0)}}},
                        Match{ 23,5, "U","Semi Final", "Op", "", QDate{2021, 1, 4}, QTime{0, 0, 0}, {Set{Score(2, 6)}}},
                        Match{ 24,5, "U","3rd Place Game", "Op", "", QDate{2021, 1, 4}, QTime{0, 0, 0}, {Set{Score(6, 2)}}}
                    });
        vecTournament.push_back(std::move(t));

        m_rActiveProfile = Profile{0, "Kadir Emre Avci", "/data/user-profile-picture", Gender::Male};
        m_rActiveProfile.SetTournaments(vecTournament);

        DatabaseController::instance().m_vecTournament = vecTournament;
    }
	Profile m_rActiveProfile;
    std::vector<StatReport> m_vecStatReport;
    std::unique_ptr<StatController> m_upStatController{std::make_unique<StatController>()};
};

#endif