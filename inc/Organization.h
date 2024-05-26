#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ostream>
#include "Tournament.h"
class Organization{
public:
	Organization();
	unsigned GetID()const;
	void SetID(unsigned);
	std::string GetName()const;
	void SetName(const std::string&);
	std::string GetType()const;
	void SetType(const std::string&);
	std::vector<std::string> GetCategories()const;
	void SetCategories(const std::vector<std::string>&);
	void AddCategory(const std::string&);
	friend std::ostream& operator<<(std::ostream& os, const Organization& org)
	{
		os << "-- ORGANIZATION --\n";
		os << "\tID: " << org.GetID() << "\n";
		os << "\tNAME: " << org.m_sName << "\n";
		os << "\tTYPE: " << org.m_sType << '\n';
		os << "\tCATEGORIES: ";
		std::copy(org.m_vecCategories.cbegin(), org.m_vecCategories.cend(), std::ostream_iterator<std::string>(os, " "));
		return os;
	}
private:
	unsigned m_uiID;
	std::string m_sName;
	std::string m_sType;
	std::vector<std::string> m_vecCategories;
};

