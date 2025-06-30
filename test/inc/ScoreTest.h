#pragma once
// Standard Headers
#include <vector>

// External Headers 
#include <gtest/gtest.h>

// Project Headers
#include "Score.h"

class ScoreTest : public testing::Test {
protected:
	void SetUp()
	{
		m_vecScore.insert(m_vecScore.end(), {
			Score{0, 0},
			Score{1, 1},
			Score{2, 1},
			Score{2, 0},
			Score{1, 5}
		});
	}
	std::vector<Score> m_vecScore;
};

