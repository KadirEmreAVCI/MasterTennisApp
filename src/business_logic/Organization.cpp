#include <iostream>
#include <sstream> 
#include <algorithm>
#include <QFile>
#include "Organization.h"
#include "Utility.h"
#include "DatabaseController.h"

Organization::Organization(	unsigned uiID, 
							const std::string& sName, 
							const std::string& sPictureFileName,
							const std::vector<std::string>& vecCategories)
							:
							m_sName{ sName },
							m_vecCategories{ vecCategories },
							DBItemWithPicture(uiID, "Organization", "Name,PictureFileName,Categories", "../../src/app/resources/organizations/", sPictureFileName)
{}
unsigned Organization::GetID()const
{
	return m_uiID;
}
std::string Organization::GetName()const
{
	return m_sName;
}
std::vector<std::string> Organization::GetCategories()const
{
	return m_vecCategories;
}
std::vector<Tournament> Organization::GetTournaments()const
{
	return m_vecTournament;
}
void Organization::SetTournaments(const std::vector<Tournament>& vecTournament)
{
	m_vecTournament = vecTournament;
	std::sort(m_vecTournament.begin(), m_vecTournament.end(), [](const Tournament& t1, const Tournament& t2) {
		return t1.IsEarlier(t2);
		});
}
bool Organization::InsertToDB()const
{
	std::cout << "Organization::InsertToDB org = " << *this << "\n";
	std::string sDBValues{ "'" + GetName() +
							"','" + GetPictureFileName() +
							"','" + utility::Serialize(m_vecCategories) + "'" };
	return m_spIDatabase->InsertItem(m_sDBTable, m_sDBColumns, sDBValues);
}
bool Organization::EditInDB()const
{
	DeleteCurrentPicture();
	QMap<QString, QVariant> columnValues;
	columnValues["Name"] = QString::fromStdString(m_sName);
	columnValues["PictureFileName"] = QString::fromStdString(GetPictureFileName());
	columnValues["Categories"] = QString::fromStdString(utility::Serialize(m_vecCategories));
	return m_spIDatabase->EditItem(m_sDBTable, columnValues, m_uiID);
}
void Organization::LoadFromDB(unsigned ID)
{
	m_uiID = stoi(m_spIDatabase->RetrieveValue(m_sDBTable, "ID", ID));
	m_sName = m_spIDatabase->RetrieveValue(m_sDBTable, "Name", "ID", std::to_string(m_uiID));
	LoadPictureFileName();
	m_vecCategories = DeserializeDBColumn("Categories");
	SetTournaments(DatabaseController::instance().FindTournamentsOfOrganization(m_uiID));
}
bool Organization::DeleteFromDB()const
{
	for(const auto& t : m_vecTournament)
	{
		if (!t.DeleteFromDB())
		{
			return false;
		}
	}
	DeleteCurrentPicture();
	return DBItem::DeleteFromDB();
}
