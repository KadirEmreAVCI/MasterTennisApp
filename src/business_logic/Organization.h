#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ostream>
#include "Tournament.h"
#include "DBItem.h"
class Organization : public DBItem {
public:
	explicit Organization(	unsigned uiID = 0, 
							const std::string& sName = "", 
							const std::string& sOrgPictureAddr = "", 
							const std::vector<std::string>& vecCategories = {});
	unsigned GetID()const;
	std::string GetName()const;
	std::string GetOrgPictureAddr()const;
	std::vector<std::string> GetCategories()const;
	std::vector<Tournament> GetTournaments()const;
	void SetTournaments(const std::vector<Tournament>&);
	static QString GetOrgImageRootDestDir();
	static void SetOrgImageRootDestDir(const QString& sOrgImageRootDestDir);
	void DeletePreviousPP()const;
	friend bool operator==(const Organization& lhs, const Organization& rhs)
	{
		return lhs.m_uiID == rhs.m_uiID && lhs.m_sName == rhs.m_sName && lhs.m_sOrgPictureAddr == rhs.m_sOrgPictureAddr && lhs.m_vecCategories == rhs.m_vecCategories;
	}
	friend std::ostream& operator<<(std::ostream& os, const Organization& org)
	{
		os << "-- ORGANIZATION --\n";
		os << "\tID: " << org.GetID() << "\n";
		os << "\tNAME: " << org.m_sName << "\n";
		os << "\tIMAGE FILE NAME: " << org.m_sOrgPictureAddr << "\n";
		os << "\tCATEGORIES: ";
		std::copy(org.m_vecCategories.cbegin(), org.m_vecCategories.cend(), std::ostream_iterator<std::string>(os, " "));
		return os;
	}
	virtual bool InsertToDB()const override;
	virtual bool EditInDB() const override;
	virtual void LoadFromDB(unsigned ID)override;
	virtual bool DeleteFromDB()const override;
private:
	static QString ms_sOrgImageRootDestDir;
	std::string m_sName;
	std::vector<std::string> m_vecCategories;
	std::string m_sOrgPictureAddr;
	std::vector<Tournament> m_vecTournament;
};

#endif