#ifndef TOURNAMENTTEST_H
#define TOURNAMENTTEST_H

// External Headers 
#include <gtest/gtest.h>

// Standard Headers
#include <tuple>

// Project Headers
#include "Tournament.h"

class TournamentTest : public testing::Test{
protected:
	void SetUp()
	{
		m_vecTournament.insert(m_vecTournament.end(), {
			Tournament{0, 0, 0, "Karayollari", "2022 Winter", "D", "Single Men", std::nullopt, 24, true, true, 3},
			Tournament{1, 0, 0, "Karayollari", "2023 Summer", "Ilk Turnuvam", "Double Men", "Alp Emre Kamis", 36, false, false, 3},
			Tournament{2, 0, 0, "Aselsan", "2024 Fall", "C", "Single Men", std::nullopt, 15, true, true, 3},
			Tournament{3, 0, 0, "Ahal Teke", "2025 Spring", "D", "Double Mixed", "Hakki Ozdemir", 64, true, true, 3},
			Tournament{4, 0, 0, "Karayollari", "2025 Winter", "D", "Double Men", std::nullopt, 8, true, true, 3},
			Tournament{5, 0, 0, "Aselsan", "2025 Summer", "A", "Single Men", "", 4, true, false, 1}
			});
		InitMatchesOfTournaments();
	}
	bool IsMatchStageValid(const Tournament& t, const Match& m);
	bool IsMatchExceedingMaxSet(const Tournament& t, const Match& m);
	bool IsMatchValidForTournament(const Tournament& t, const Match& m);
private:
	void InitMatchesOfTournaments()
	{
		m_vecTournament[0].SetMatches({
			Match{ 0, 0, "U", "Group Stage", "Op1", "", QDate{2022, 1, 1}, QTime{9, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}, Set{Score(6, 0)}}},
			Match{ 1, 0, "U", "Group Stage", "Op1", "", QDate{2022, 1, 3}, QTime{7, 0, 0}, {Set{Score(6, 3)}, Set{Score(6, 4)}}},
			Match{ 2, 0, "U", "Final 64", "Op1", "", QDate{2022, 1, 5}, QTime{11, 0, 0}, {Set{Score(6, 3)}}},
			Match{ 3, 0, "U", "Final 32", "Op1", "", QDate{2022, 1, 10}, QTime{9, 0, 0}, {Set{Score(6, 1)}, Set{Score(6, 7), Score(5, 7)}, Set{Score(10, 4)}}}
			});
		m_vecTournament[1].SetMatches({
			Match{ 0, 1, "U", "Group Stage", "Op1", "Op2", QDate{2023, 6, 1}, QTime{9, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}, Set{Score(3, 6 )}, Set{Score(6, 0)}}},
			Match{ 1, 1, "U", "Group Stage", "Op1", "Op2", QDate{2023, 6, 3}, QTime{7, 0, 0}, {Set{Score(6, 3)}, Set{Score(6, 4)}}},
			Match{ 2, 1, "WO", "Group Stage", "Op1", "Op2", QDate{2023, 6, 4}, QTime{11, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
			Match{ 3, 1, "U", "Quarter Final", "Op1", "Op2", QDate{2023, 6, 10}, QTime{9, 0, 0}, {Set{Score(6, 1)}, Set{Score(6, 3)}}},
			Match{ 4, 1, "U", "Semi Final", "Op1", "Op2", QDate{2023, 6, 11}, QTime{7, 0, 0}, {Set{Score(1, 6)}, Set{Score(3, 6)}}},
			Match{ 5, 1, "U", "3rd Place Game", "Op1", "Op2", QDate{2023, 6, 12}, QTime{7, 0, 0}, {Set{Score(1, 6)}, Set{Score(3, 6)}}}
			});
		m_vecTournament[2].SetMatches({
			Match{ 0, 2, "U", "Group Stage", "Op1", "", QDate{2024, 10, 1}, QTime{11, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
			Match{ 1, 2, "U", "Group Stage", "Op1", "", QDate{2024, 10, 3}, QTime{7, 0, 0}, {Set{Score(6, 3)}, Set{Score(6, 4)}}},
			Match{ 2, 2, "U", "Group Stage", "Op1", "", QDate{2024, 10, 5}, QTime{9, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
			Match{ 3, 2, "BYE", "Semi Final", "Op1", "", QDate{2024, 10, 15}, QTime{9, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
			Match{ 4, 2, "U", "Final", "Op1", "", QDate{2024, 10, 18}, QTime{7, 0, 0}, {Set{Score(1, 6)}, Set{Score(3, 6)}}}
			});
		m_vecTournament[3].SetMatches({
			Match{ 0, 3, "U", "Group Stage.", "Op1", "Op2", QDate{2025, 4, 1}, QTime{11, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
			Match{ 1, 3, "U", "Group Stage.", "Op1", "Op2", QDate{2025, 4, 3}, QTime{7, 0, 0}, {Set{Score(6, 3)}, Set{Score(6, 4)}}},
			Match{ 2, 3, "U", "Group Stage.", "Op1", "Op2", QDate{2025, 4, 5}, QTime{9, 0, 0}, {Set{Score(6, 1)}, Set{Score(6, 0)}}},
			Match{ 3, 3, "BYE", "Final 32.", "Op1", "Op2", QDate{2025, 4, 13}, QTime{9, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
			Match{ 4, 3, "U", "Final 16", "Op1", "Op2", QDate{2025, 4, 14}, QTime{9, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 3)}}},
			Match{ 5, 3, "U", "Quarter Final", "Op1", "Op2", QDate{2025, 4, 15}, QTime{7, 0, 0}, {Set{Score(6, 3)}, Set{Score(6, 4)}}},
			Match{ 6, 3, "U", "Semi Final", "Op1", "Op2", QDate{2025, 4, 18}, QTime{7, 0, 0}, {Set{Score(1, 6)}, Set{Score(0, 6)}}},
			Match{ 7, 3, "U", "3rd Place Game", "Op1", "Op2", QDate{2025, 4, 21}, QTime{7, 0, 0}, {Set{Score(7, 5)}, Set{Score(6, 2)}}}
			});
		m_vecTournament[4].SetMatches({
			Match{ 0, 4, "U", "Group Stage", "Op1", "Op2", QDate{2025, 2, 1}, QTime{11, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}, Set{Score(3, 6)}, Set{Score(6, 1)}}},
			Match{ 1, 4, "U", "Group Stage", "Op1", "Op2", QDate{2025, 2, 3}, QTime{7, 0, 0}, {Set{Score(6, 3)}, Set{Score(6, 4)}}},
			Match{ 2, 4, "U", "Group Stage", "Op1", "Op2", QDate{2025, 2, 5}, QTime{9, 0, 0}, {Set{Score(6, 1)}, Set{Score(6, 0)}}},
			Match{ 3, 4, "BYE", "Final 32", "Op1", "Op2", QDate{2025, 2, 7}, QTime{9, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 0)}}},
			Match{ 4, 4, "U", "Final 16", "Op1", "Op2", QDate{2025, 2, 9}, QTime{9, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 3)}}},
			Match{ 5, 4, "U", "Quarter Final", "Op1", "Op2", QDate{2025, 2, 11}, QTime{7, 0, 0}, {Set{Score(6, 3)}, Set{Score(6, 4)}}},
			Match{ 6, 4, "U", "Semi Final", "Op1", "Op2", QDate{2025, 2, 13}, QTime{7, 0, 0}, {Set{Score(1, 6)}, Set{Score(0, 6)}}}
			});
		m_vecTournament[5].SetMatches({
			Match{ 1, 5, "U", "Quarter Final", "Op1", "Op2", QDate{2025, 5, 3}, QTime{7, 0, 0}, {Set{Score(6, 3)}, Set{Score(6, 4)}}},
			Match{ 0, 5, "U", "Semi Final", "Op1", "Op2", QDate::currentDate().addMonths(1), QTime{7, 0, 0}, {Set{Score(1, 6)}, Set{Score(0, 6)}}}
			});
	}
protected:
	std::vector<Tournament> m_vecTournament;
};

class DoubleTournamentTest : public TournamentTest, public ::testing::WithParamInterface<std::tuple<size_t, bool>> {};
TEST_P(DoubleTournamentTest, DetectDoubleTournaments)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecTournament[idx].IsDoubleTournament(), expected);
}

class PossibleStagesTest : public TournamentTest, public ::testing::WithParamInterface<std::tuple<size_t, std::vector<std::string>>> {};
TEST_P(PossibleStagesTest, DetectPossibleStages)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecTournament[idx].GetPossibleStages(), expected);
}

class GroupStageExistenceTest : public TournamentTest, public ::testing::WithParamInterface<std::tuple<size_t, bool>> {};
TEST_P(GroupStageExistenceTest, DetectExistenceOfGroupStage)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecTournament[idx].IsGroupStageExist(), expected);
}

class ValidMatchStageTest : public TournamentTest, public ::testing::WithParamInterface<std::tuple<size_t, std::vector<bool>>> {};
TEST_P(ValidMatchStageTest, DetectValidMatchStages)
{
	auto [idx, expected] = GetParam();
	const auto& vecMatch = m_vecTournament[idx].GetMatches();
	for (std::size_t i = 0; i < vecMatch.size(); ++i)
	{
		EXPECT_EQ(IsMatchStageValid(m_vecTournament[idx], vecMatch[i]), expected[i]);
	}
}

class MatchExceedingMaxSetTest : public TournamentTest, public ::testing::WithParamInterface<std::tuple<size_t, std::vector<bool>>> {};
TEST_P(MatchExceedingMaxSetTest, DetectMatchesExceedingMaxSet)
{
	auto [idx, expected] = GetParam();
	const auto& vecMatch = m_vecTournament[idx].GetMatches();
	for (std::size_t i = 0; i < vecMatch.size(); ++i)
	{
		EXPECT_EQ(IsMatchExceedingMaxSet(m_vecTournament[idx], vecMatch[i]), expected[i]);
	}
}

class ValidMatchForTournamentTest : public TournamentTest, public ::testing::WithParamInterface<std::tuple<size_t, std::vector<bool>>> {};
TEST_P(ValidMatchForTournamentTest, DetectValidMatchesForTournament)
{
	auto [idx, expected] = GetParam();
	const auto& vecMatch = m_vecTournament[idx].GetMatches();
	for (std::size_t i = 0; i < vecMatch.size(); ++i)
	{
		EXPECT_EQ(IsMatchValidForTournament(m_vecTournament[idx], vecMatch[i]), expected[i]);
	}
}
#endif