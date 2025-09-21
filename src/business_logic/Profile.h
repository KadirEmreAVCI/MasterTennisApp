#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <vector>
#include "DBItem.h"
#include "Organization.h"
enum class Gender
{
	Male,
	Female
};
class Profile : public DBItem {
public:
	explicit Profile(	unsigned uiID = 0, 
						const std::string& sFullName = "", 
						const std::string& sPPAddr = "", 
						Gender gen = Gender::Male);
	unsigned int GetID()const;
	std::string GetFullName()const;
	std::string GetPPAddr()const;
	Gender GetGender()const;
	std::vector<Tournament> GetTournaments()const;
	static QString GetProfileImageRootDestDir();
	static void SetProfileImageRootDestDir(const QString& sProfileImageRootDestDir);
	void DeletePreviousPP()const;
	friend bool operator==(const Profile& lhs, const Profile& rhs)
	{
		return	lhs.m_uiID == rhs.m_uiID &&
			lhs.m_sFullName == rhs.m_sFullName &&
			lhs.m_sPPAddr == rhs.m_sPPAddr &&
			lhs.m_Gender == rhs.m_Gender;
	}
	friend std::ostream& operator<<(std::ostream& os, const Profile& p)
	{
		os << "\tID: " << p.m_uiID <<
			", NAME & SURNAME: " << p.m_sFullName <<
			", GENDER: " << ((p.m_Gender == Gender::Male) ? "Male" : "Female") <<
			", PP ADDRESS: " << p.m_sPPAddr;
		return os;
	}
	virtual bool InsertToDB()const override;
	virtual bool EditInDB()const override;
	virtual void LoadFromDB(unsigned ID)override;
	virtual bool DeleteFromDB()const override;
private:
	void SetTournaments(const std::vector<Tournament>&);
	std::vector<Tournament> m_vecTournament;
	static QString ms_sProfileImageRootDestDir;
	std::string m_sFullName{};
	std::string m_sPPAddr{};
	Gender m_Gender{};
};

#endif