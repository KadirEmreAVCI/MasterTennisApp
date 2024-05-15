#pragma once
#include <string>

struct Season {
	unsigned m_year;
	std::string m_Period;
	/*bool operator==(const Season& per) {
		return m_year == per.m_year && m_Period == per.m_Period;
	}
	bool operator<(const Season& per) {
		return (m_year < per.m_year) || (m_year == per.m_year && m_Period < per.m_Period);
	}*/
};