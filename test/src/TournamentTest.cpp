// Standar Headers
#include <algorithm>

// Test Headers
#include "TournamentTest.h"
bool TournamentTest::IsMatchStageValid(const Tournament& t, const Match& m)
{
	return t.IsMatchStageValid(m);
}
bool TournamentTest::IsMatchExceedingMaxSet(const Tournament& t, const Match& m)
{
	return t.IsMatchExceedingMaxSet(m);
}
bool TournamentTest::IsMatchValidForTournament(const Tournament& t, const Match& m)
{
	return t.IsMatchValidForTournament(m);
}
TEST_F(TournamentTest, DetectDoubleTournaments)
{
	const std::vector vecTestOutput{ false, true, false, true, false, false };
	for (std::size_t idx = 0; idx < m_vecTournament.size(); ++idx)
	{
		EXPECT_EQ(m_vecTournament[idx].IsDoubleTournament(), vecTestOutput[idx]);
	}
}

TEST_F(TournamentTest, GetAllPossibleStagesForTournament)
{
	const std::vector<std::vector<std::string>> vecTestOutput{ 
		{ "Group Stage", "Final 16", "Quarter Final", "Semi Final", "Final", "3rd Place Game" },
		{ "Group Stage", "Final 32", "Final 16", "Quarter Final", "Semi Final", "Final"},
		{ "Group Stage", "Quarter Final", "Semi Final", "Final", "3rd Place Game" },
		{ "Group Stage", "Final 32", "Final 16", "Quarter Final", "Semi Final", "Final", "3rd Place Game" },
		{ "Group Stage", "Semi Final", "Final", "3rd Place Game" },
		{ "Group Stage", "Final" }
	};
	for (std::size_t idx = 0; idx < m_vecTournament.size(); ++idx)
	{
		EXPECT_EQ(m_vecTournament[idx].GetPossibleStages(), vecTestOutput[idx]);
	}
}

TEST_F(TournamentTest, SortTournamentsByStartTime) 
{
	std::sort(m_vecTournament.begin(), m_vecTournament.end(), [](const Tournament& t1, const Tournament& t2){
		return t1.IsEarlier(t2);
		});
	const std::vector vecTestOutput{0, 1, 2, 4, 3, 5};
	for (std::size_t idx = 0; idx < m_vecTournament.size(); ++idx)
	{
		EXPECT_EQ(m_vecTournament[idx].GetID(), vecTestOutput[idx]);
	}
}

TEST_F(TournamentTest, DetectGroupStageExistence)
{
	const std::vector vecTestOutput{ true, true, true, false, true, false };
	for (std::size_t idx = 0; idx < m_vecTournament.size(); ++idx)
	{
		EXPECT_EQ(m_vecTournament[idx].IsGroupStageExist(), vecTestOutput[idx]);
	}
}

TEST_F(TournamentTest, DetectValidMatchStage) 
{
	const std::vector<std::vector<bool>> vecTestOutput{
		{true, true, false, false},
		{true, true, true, true, true, false },
		{true, true, true, true, true },
		{false, false, false, false, true, true, true, true },
		{true, true, true, false, false, false, true},
		{false, false}
	};
	for (std::size_t idxT = 0; idxT < m_vecTournament.size(); ++idxT)
	{
		const auto& vecMatch = m_vecTournament[idxT].GetMatches();
		for (std::size_t idxM = 0; idxM < vecMatch.size(); ++idxM)
		{
			EXPECT_EQ(IsMatchStageValid(m_vecTournament[idxT], vecMatch[idxM]), vecTestOutput[idxT][idxM]);
		}
	}
}

TEST_F(TournamentTest, DetectMatchesExceedingMaxSet)
{
	const std::vector<std::vector<bool>> vecTestOutput{
		{true, false, false, false},
		{true, false, false, false, false, false },
		{false, false, false, false, false },
		{false, false, false, false, false, false, false, false },
		{true, false, false, false, false, false, false},
		{true, true}
	};
	for (std::size_t idxT = 0; idxT < m_vecTournament.size(); ++idxT)
	{
		const auto& vecMatch = m_vecTournament[idxT].GetMatches();
		for (std::size_t idxM = 0; idxM < vecMatch.size(); ++idxM)
		{
			EXPECT_EQ(IsMatchExceedingMaxSet(m_vecTournament[idxT], vecMatch[idxM]), vecTestOutput[idxT][idxM]);
		}
	}
}

TEST_F(TournamentTest, DetectMatchesValidForTournament)
{
	const std::vector<std::vector<bool>> vecTestOutput{
		{false, true, false, false},
		{false, true, true, true, true, false },
		{true, true, true, true, true },
		{false, false, false, false, true, true, true, true },
		{false, true, true, false, false, false, true},
		{false, false}
	};
	for (std::size_t idxT = 0; idxT < m_vecTournament.size(); ++idxT)
	{
		const auto& vecMatch = m_vecTournament[idxT].GetMatches();
		for (std::size_t idxM = 0; idxM < vecMatch.size(); ++idxM)
		{
			EXPECT_EQ(IsMatchValidForTournament(m_vecTournament[idxT], vecMatch[idxM]), vecTestOutput[idxT][idxM]);
		}
	}
}
