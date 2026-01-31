#include <iostream>
#include <QMap>
#include <QVariant>
#include <QFile>
#include "Tournament.h"
#include "Profile.h"
#include "DatabaseController.h"

Profile::Profile(	unsigned uiID, 
					const std::string& sFullName, 
					const std::string& sPictureFileName,
					Gender gen) 
					:
					m_sFullName{sFullName},
					m_Gender{gen},
					DBItemWithPicture(uiID, "Profile", "FullName,Gender,PictureFileName", "../../src/app/resources/profiles/", sPictureFileName)
{}
unsigned int Profile::GetID()const
{
	return m_uiID;
}
std::string Profile::GetFullName()const
{
	return m_sFullName;
}
Gender Profile::GetGender()const
{
	return m_Gender;
}
std::vector<Tournament> Profile::GetTournaments()const
{
	return std::vector<Tournament>(m_setTournament.begin(), m_setTournament.end());
}
bool Profile::InsertToDB()const
{
	std::string sDBValues{ "'" + m_sFullName +
							"','" + ((m_Gender == Gender::Male) ? "Male" : "Female") +
							"','" + GetPictureFileName() +
							"'" };
	return m_spIDatabase->InsertItem(m_sDBTable, m_sDBColumns, sDBValues);
}
bool Profile::EditInDB()const
{
	if(IsPictureChanged())
	{
		DeletePreviousPicture();
	}
	QMap<QString, QVariant> mapColumnValues;
	mapColumnValues["FullName"] = QString::fromStdString(m_sFullName);
	mapColumnValues["Gender"] = ((m_Gender == Gender::Male) ? "Male" : "Female");
	mapColumnValues["PictureFileName"] = QString::fromStdString(GetPictureFileName());
	return m_spIDatabase->EditItem(m_sDBTable, mapColumnValues, m_uiID);
}
void Profile::LoadFromDB(unsigned ID)
{
	m_uiID = stoi(m_spIDatabase->RetrieveValue(m_sDBTable, "ID", ID));
	m_sFullName = m_spIDatabase->RetrieveValue(m_sDBTable, "FullName", "ID", std::to_string(m_uiID));
	m_Gender = (m_spIDatabase->RetrieveValue(m_sDBTable, "Gender", "ID", std::to_string(m_uiID))) == "Male" ? Gender::Male : Gender::Female;
	LoadPictureFileName();
	SetTournaments(DatabaseController::instance().FindTournamentsOfProfile(m_uiID));
}
bool Profile::DeleteFromDB()const
{
	for(const auto& t : m_setTournament)
	{
		if (!t.DeleteFromDB())
		{
			return false;
		}
	}
	return DBItemWithPicture::DeleteFromDB();
}
void Profile::SetTournaments(const std::vector<Tournament>& vecTournament)
{
	m_setTournament.clear();
	for(const auto& t : vecTournament)
	{
		m_setTournament.insert(t);
	}
}