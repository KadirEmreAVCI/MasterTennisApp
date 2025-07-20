#pragma once
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

