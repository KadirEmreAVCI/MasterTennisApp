#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ostream>
#include "Tournament.h"
#include "DBItemWithPicture.h"

class Organization : public DBItemWithPicture {
public:
	explicit Organization(	unsigned uiID = 0, 
							const std::string& sName = "", 
							const std::string& sPictureFileName = "", 
							const std::vector<std::string>& vecCategories = {});
	unsigned GetID()const;
	std::string GetName()const;
	std::vector<std::string> GetCategories()const;
	std::vector<Tournament> GetTournaments()const;
	void SetTournaments(const std::vector<Tournament>&);
	friend bool operator==(const Organization& lhs, const Organization& rhs)
	{
		return lhs.m_uiID == rhs.m_uiID && lhs.m_sName == rhs.m_sName && lhs.GetPictureFileName() == rhs.GetPictureFileName() && lhs.m_vecCategories == rhs.m_vecCategories;
	}
	friend std::ostream& operator<<(std::ostream& os, const Organization& org)
	{
		os << "-- ORGANIZATION --\n";
		os << "\tID: " << org.GetID() << "\n";
		os << "\tNAME: " << org.m_sName << "\n";
		os << "\tPICTURE FILE NAME: " << org.GetPictureFileName() << "\n";
		os << "\tCATEGORIES: ";
		std::copy(org.m_vecCategories.cbegin(), org.m_vecCategories.cend(), std::ostream_iterator<std::string>(os, " "));
		return os;
	}
	virtual bool InsertToDB()const override;
	virtual bool EditInDB() const override;
	virtual void LoadFromDB(unsigned ID)override;
	virtual bool DeleteFromDB()const override;
private:
	std::string m_sName;
	std::vector<std::string> m_vecCategories;
	std::set<Tournament, std::greater<Tournament>> m_setTournament;
};

#endif