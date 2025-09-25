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
							const std::string& sPictureAddr = "", 
							const std::vector<std::string>& vecCategories = {});
	unsigned GetID()const;
	std::string GetName()const;
	std::string GetPictureAddr()const;
	std::vector<std::string> GetCategories()const;
	std::vector<Tournament> GetTournaments()const;
	static QString GetPictureRootDestDir();
	static void SetPictureRootDestDir(const QString& sPictureRootDestDir);
	void DeletePreviousPP()const;
	void SetTournaments(const std::vector<Tournament>&);
	friend bool operator==(const Organization& lhs, const Organization& rhs)
	{
		return lhs.m_uiID == rhs.m_uiID && lhs.m_sName == rhs.m_sName && lhs.m_sPictureAddr == rhs.m_sPictureAddr && lhs.m_vecCategories == rhs.m_vecCategories;
	}
	friend std::ostream& operator<<(std::ostream& os, const Organization& org)
	{
		os << "-- ORGANIZATION --\n";
		os << "\tID: " << org.GetID() << "\n";
		os << "\tNAME: " << org.m_sName << "\n";
		os << "\tIMAGE FILE NAME: " << org.m_sPictureAddr << "\n";
		os << "\tCATEGORIES: ";
		std::copy(org.m_vecCategories.cbegin(), org.m_vecCategories.cend(), std::ostream_iterator<std::string>(os, " "));
		return os;
	}
	virtual bool InsertToDB()const override;
	virtual bool EditInDB() const override;
	virtual void LoadFromDB(unsigned ID)override;
	virtual bool DeleteFromDB()const override;
private:
	static QString ms_sPictureRootDestDir;
	std::string m_sName;
	std::vector<std::string> m_vecCategories;
	std::string m_sPictureAddr;
	std::vector<Tournament> m_vecTournament;
};

#endif