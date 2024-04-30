#pragma once
#include <string>
enum class Season {
	eWinter = 0,
	eSpring = 1, 
	eSummer = 2,
	eFall = 3
};
struct Period {
	unsigned m_year;
	Season m_Season;
	bool operator==(const Period& per) {
		return m_year == per.m_year && m_Season == per.m_Season;
	}
	bool operator<(const Period& per) {
		return (m_year < per.m_year) || (m_year == per.m_year && m_Season < per.m_Season);
	}
};