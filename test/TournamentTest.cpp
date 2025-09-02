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

INSTANTIATE_TEST_SUITE_P(
    DetectDoubleTournaments,
    DoubleTournamentTest,
    ::testing::Values(
        std::make_tuple(0, false),
        std::make_tuple(1, true),
        std::make_tuple(2, false),
        std::make_tuple(3, true),
        std::make_tuple(4, false),
        std::make_tuple(5, false)
    )
);

INSTANTIATE_TEST_SUITE_P(
    DetectPossibleStages,
    PossibleStagesTest,
    ::testing::Values(
        std::make_tuple(0, std::vector<std::string>{ "Group Stage", "Final 16", "Quarter Final", "Semi Final", "Final", "3rd Place Game" }),
        std::make_tuple(1, std::vector<std::string>{ "Group Stage", "Final 32", "Final 16", "Quarter Final", "Semi Final", "Final"}),
        std::make_tuple(2, std::vector<std::string>{ "Group Stage", "Quarter Final", "Semi Final", "Final", "3rd Place Game" }),
        std::make_tuple(3, std::vector<std::string>{ "Group Stage", "Final 32", "Final 16", "Quarter Final", "Semi Final", "Final", "3rd Place Game" }),
        std::make_tuple(4, std::vector<std::string>{ "Group Stage", "Semi Final", "Final", "3rd Place Game" }),
        std::make_tuple(5, std::vector<std::string>{ "Group Stage", "Final" })
    )
);

INSTANTIATE_TEST_SUITE_P(
    DetectExistenceOfGroupStage,
    GroupStageExistenceTest,
    ::testing::Values(
        std::make_tuple(0, true),
        std::make_tuple(1, true),
        std::make_tuple(2, true),
        std::make_tuple(3, false),
        std::make_tuple(4, true),
        std::make_tuple(5, false)
    )
);

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
