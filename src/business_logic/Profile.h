#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <vector>
#include "DBItemWithPicture.h"
#include "Organization.h"
enum class Gender
{
	Male,
	Female
};
class Profile : public DBItemWithPicture {
friend class DatabaseControllerTest;
friend class StatControllerTest;
public:
	explicit Profile(	unsigned uiID = 0, 
						const std::string& sFullName = "", 
						const std::string& sPictureFileName = "", 
						Gender gen = Gender::Male);
	unsigned int GetID()const;
	const std::string& GetFullName()const;
	Gender GetGender()const;
	std::vector<Tournament> GetTournaments()const;
	friend bool operator==(const Profile& lhs, const Profile& rhs)
	{
		return	lhs.m_uiID == rhs.m_uiID &&
			lhs.m_sFullName == rhs.m_sFullName &&
			lhs.GetPictureFileName() == rhs.GetPictureFileName() &&
			lhs.m_Gender == rhs.m_Gender;
	}
	friend std::ostream& operator<<(std::ostream& os, const Profile& p)
	{
		os << "\tID: " << p.m_uiID <<
			", NAME & SURNAME: " << p.m_sFullName <<
			", GENDER: " << ((p.m_Gender == Gender::Male) ? "Male" : "Female") <<
			", PICTURE FILE NAME: " << p.GetPictureFileName();
		return os;
	}
	virtual bool InsertToDB()const override;
	virtual bool EditInDB()const override;
	virtual void LoadFromDB(unsigned ID)override;
	virtual bool DeleteFromDB()const override;
private:
	void SetTournaments(const std::vector<Tournament>&);
	std::set<Tournament, std::greater<Tournament>> m_setTournament;
	std::string m_sFullName{};
	Gender m_Gender{};
};

#endif