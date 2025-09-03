#ifndef SETTEST_H
#define SETTEST_H

// Standard Headers
#include <vector>

// External Headers 
#include <gtest/gtest.h>

// Project Headers
#include "Set.h"

class SetTest : public testing::Test {
protected:
	void SetUp()
	{
		m_vecSet.insert(m_vecSet.end(), {
			Set{Score{0, 0}},
			Set{Score{0, 0}, Score{0, 0} },
			Set{Score{0, 0}, Score{7, 3}},
			Set{Score{6, 3}},
			Set{Score{2, 6}},
			Set{Score{7, 6}, Score{7, 4}},
			Set{Score{6, 7}, Score{0, 7}},
			Set{Score{1, 1}},
			Set{Score{7, 6}, Score{5, 7}},
			Set{Score{6, 7}, Score{2, 2}},
			Set{Score{6, 7}, Score{7, 2}}
			});
	}
	std::vector<Set> m_vecSet;
};

class OutcomeTest : public SetTest, public ::testing::WithParamInterface<std::tuple<size_t, Outcome>> {};
TEST_P(OutcomeTest, DetermineOutcomes)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecSet[idx].GetOutcome(), expected);
}

class PlayedTiebreakTest : public SetTest, public ::testing::WithParamInterface<std::tuple<size_t, bool>> {};
TEST_P(PlayedTiebreakTest, DetectTiebreakPlayed)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecSet[idx].IsSetTBPlayed(), expected);
}

class InvalidSetTest : public SetTest, public ::testing::WithParamInterface<std::tuple<size_t, bool>> {};
TEST_P(InvalidSetTest, DetectInvalidSets)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecSet[idx].IsValid(), expected);
}

class SetToStringTest : public SetTest, public ::testing::WithParamInterface<std::tuple<size_t, std::string>> {};
TEST_P(SetToStringTest, SetToString)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecSet[idx].ToString(), expected);
}

class SetFromStringTest : public SetTest, public ::testing::WithParamInterface<std::tuple<size_t, std::string>> {};
TEST_P(SetFromStringTest, SetFromString)
{
	auto [idx, expected] = GetParam();
	EXPECT_EQ(m_vecSet[idx], Set::FromString(expected));
}
#endif