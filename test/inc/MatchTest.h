#pragma once
// Standard Headers
#include <vector>

// External Headers 
#include <gtest/gtest.h>

// Project Headers
#include "Match.h"

class MatchTest : public testing::Test {
protected:
	void SetUp()
	{
		m_vecMatch.insert(m_vecMatch.end(), {
			Match{ 0, 0, "U", "Quarter Final", "Op1", "", QDate{2023, 1, 1}, QTime{9, 0, 0}, {Set{Score(6, 1)}, Set{Score(6, 7), Score(5, 7)}, Set{Score(10, 4)}}},
			Match{ 1, 0, "U", "Final 16", "Mustafa Yavuz Kirli", "", QDate{2024, 2, 11}, QTime{18, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 1)}, Set{Score(1, 6)}, Set{Score(7, 5)}}},
			Match{ 2, 1, "U", "Final", "Ismail Ozaydin", "Bora Deveci", QDate{2024, 7, 10}, QTime{18, 0, 0}, {Set{Score(1, 6)}, Set{Score(1, 6)}, Set{Score(4, 6)}}},
			Match{ 3, 0, "U", "Semi Final", "Ali Oner", "", QDate{2024, 6, 6}, QTime{18, 0, 0}, {Set{Score(1, 6)}, Set{Score(4, 6)}}},
			Match{ 4, 0, "U", "Final 32", "Doruk Orbay", "", QDate{2023, 11, 7}, QTime{21, 0, 0}, {Set{Score(6, 7), Score(3, 7)}, Set{Score(6, 4)}, Set{Score(10, 5)}}},
			Match{ 5, 1, "U", "Group Stage", "Alper Kagan Aldemir", "Tolunay Bayrakci", QDate{2025, 4, 15}, QTime{19, 30, 0}, {Set{Score(6, 1)}}},
			Match{ 6, 0, "WO","Group Stage", "Engin Oz", "", QDate{2022, 10, 11}, QTime{0, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
			Match{ 7, 0, "BYE","Final 32", "", "", QDate{2023, 8, 12}, QTime{0, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
			Match{ 8, 0, "WO","Group Stage", "Oguzhan Bulut", "", QDate{2025, 5, 1}, QTime{0, 0, 0}, {Set{Score(0, 6)}, Set{Score(0, 6)}}},
			Match{ 9, 0, "U", "Final", "Mehmet Efe Uluyurt", "", QDate{2024, 3, 7}, QTime{21, 0, 0}, {Set{Score(4, 6)}, Set{Score(6, 1)}, Set{Score(10, 8)}}},
			Match{ 10,0, "U", "3rd Place Game", "Unknown", "", QDate{2025, 5, 1}, QTime{1, 0, 0}, {Set{Score(0, 6)}, Set{Score(3, 6)}}},
			Match{ 11,0, "U","Final 16", "Unknown5", "", QDate{2300, 1, 1}, QTime{7,0,0}, {Set{Score(0, 0)}, Set{Score(0, 0)}}},
			Match{ 12,0, "U","Group Stage", "Unknown6", "", QDate{2300, 1, 1}, QTime{6,0,0}, {Set{Score(1, 1)}, Set{Score(0, 0)}} },
			Match{ 13,0, "U","Final 16", "Unknown7", "", QDate{2000, 1, 1}, QTime{7,0,0}, {Set{Score(6, 0)}, Set{Score(6, 3)}, Set{Score(2, 2)}}},
			Match{ 14,0, "U","Final", "Unknown1", "", QDate{2300, 1, 2}, QTime{0, 0, 0}, {Set{Score(2, 6)}, Set{Score(3, 6)}}},
			Match{ 15,0, "U","Quarter Final", "Unknown2", "", QDate{2300, 1, 3}, QTime{0, 0, 0}, {Set{Score(0, 0)}, Set{Score(0, 0)}}},
			Match{ 16,0, "U","Semi Final", "Unknown3", "", QDate{2300, 1, 4}, QTime{0, 0, 0}, {Set{Score(2, 6)}, Set{Score(3, 6)}}},
			Match{ 17,0, "U","Final 16", "Unknown4", "", QDate{2300, 1, 5}, QTime{0, 0, 0}, {Set{Score(0, 0)}, Set{Score(0, 0)}}}
		});
	}
	std::vector<Match> m_vecMatch;
};


