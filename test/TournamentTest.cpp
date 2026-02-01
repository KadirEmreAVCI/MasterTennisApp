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
class DoubleTournamentTest : public TournamentTest, public ::testing::WithParamInterface<std::tuple<size_t, bool>> {};
TEST_P(DoubleTournamentTest, DetectDoubleTournaments)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecTournament[idx].IsDoubleTournament(), expected);
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
class PossibleStagesTest : public TournamentTest, public ::testing::WithParamInterface<std::tuple<size_t, std::vector<std::string>>> {};
TEST_P(PossibleStagesTest, DetectPossibleStages)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecTournament[idx].GetPossibleStages(), expected);
}
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
class GroupStageExistenceTest : public TournamentTest, public ::testing::WithParamInterface<std::tuple<size_t, bool>> {};
TEST_P(GroupStageExistenceTest, DetectExistenceOfGroupStage)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecTournament[idx].IsGroupStageExist(), expected);
}
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
INSTANTIATE_TEST_SUITE_P(
    DetectValidMatchStages,
    ValidMatchStageTest,
    ::testing::Values(
        std::make_tuple(0, std::vector<bool>{false, false, true, true}),
        std::make_tuple(1, std::vector<bool>{false, true, true, true, true, true}),
        std::make_tuple(2, std::vector<bool>{true, true, true, true, true}),
        std::make_tuple(3, std::vector<bool>{true, true, true, true, false, false, false, false}),
        std::make_tuple(4, std::vector<bool>{true, false, false, false, true, true, true}),
        std::make_tuple(5, std::vector<bool>{false, false})
    )
);
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
INSTANTIATE_TEST_SUITE_P(
    DetectMatchesExceedingMaxSet,
    MatchExceedingMaxSetTest,
    ::testing::Values(
        std::make_tuple(0, std::vector<bool>{false, false, false, true}),
        std::make_tuple(1, std::vector<bool>{false, false, false, false, false, true}),
        std::make_tuple(2, std::vector<bool>{false, false, false, false, false}),
        std::make_tuple(3, std::vector<bool>{false, false, false, false, false, false, false, false}),
        std::make_tuple(4, std::vector<bool>{false, false, false, false, false, false, true}),
        std::make_tuple(5, std::vector<bool>{true, true})
    )
);
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
INSTANTIATE_TEST_SUITE_P(
    DetectValidMatchesForTournament,
    ValidMatchForTournamentTest,
    ::testing::Values(
        std::make_tuple(0, std::vector<bool>{false, false, true, false}),
        std::make_tuple(1, std::vector<bool>{false, true, true, true, true, false}),
        std::make_tuple(2, std::vector<bool>{true, true, true, true, true}),
        std::make_tuple(3, std::vector<bool>{true, true, true, true, false, false, false, false}),
        std::make_tuple(4, std::vector<bool>{true, false, false, false, true, true, false}),
        std::make_tuple(5, std::vector<bool>{false, false})
    )
);
TEST_F(TournamentTest, SortTournamentsByStartTime) 
{
	std::sort(m_vecTournament.begin(), m_vecTournament.end());
	const std::vector vecExpected{0, 1, 2, 4, 3, 5};
	for (std::size_t idx = 0; idx < m_vecTournament.size(); ++idx)
	{
		EXPECT_EQ(m_vecTournament[idx].GetID(), vecExpected[idx]);
	}
}
class MostRecentMatchTest : public TournamentTest, public ::testing::WithParamInterface<std::tuple<size_t, Match>> {};
TEST_P(MostRecentMatchTest, DetectMostRecentMatch)
{
    auto [idx, expected] = GetParam();
    const auto optMostRecentMatch = m_vecTournament[idx].GetMostRecentMatch();
    ASSERT_TRUE(optMostRecentMatch.has_value());
    EXPECT_EQ(optMostRecentMatch.value(), expected);
}
INSTANTIATE_TEST_SUITE_P(
    DetectMostRecentMatches,
    MostRecentMatchTest,
    ::testing::Values(
        std::make_tuple(0, Match{ 3, 0, "U", "Final 32", "Op1", "", QDate{2022, 1, 10}, QTime{9, 0, 0}, {Set{Score(6, 1)}, Set{Score(6, 7), Score(5, 7)}, Set{Score(10, 4)}}}),
        std::make_tuple(1, Match{ 5, 1, "U", "3rd Place Game", "Op1", "Op2", QDate{2023, 6, 12}, QTime{7, 0, 0}, {Set{Score(1, 6)}, Set{Score(3, 6)}}}),
        std::make_tuple(2, Match{ 4, 2, "U", "Final", "Op1", "", QDate{2024, 10, 18}, QTime{7, 0, 0}, {Set{Score(1, 6)}, Set{Score(3, 6)}}}),
        std::make_tuple(3, Match{ 7, 3, "U", "3rd Place Game", "Op1", "Op2", QDate{2025, 4, 21}, QTime{7, 0, 0}, {Set{Score(7, 5)}, Set{Score(6, 2)}}}),
        std::make_tuple(4, Match{ 6, 4, "U", "Semi Final", "Op1", "Op2", QDate{2025, 2, 13}, QTime{7, 0, 0}, {Set{Score(1, 6)}, Set{Score(0, 6)}}})
    )
);