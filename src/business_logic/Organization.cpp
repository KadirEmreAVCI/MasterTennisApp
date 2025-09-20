#include <iostream>
#include <sstream> 
#include <algorithm>
#include <QFile>
#include "Organization.h"
#include "Utility.h"
#include "DatabaseController.h"

QString Organization::ms_sOrgImageRootDestDir = "";
Organization::Organization(	unsigned uiID, 
							const std::string& sName, 
							const std::string& sOrgPictureAddr,
							const std::vector<std::string>& vecCategories)
							:
							m_sName{ sName },
							m_sOrgPictureAddr{ sOrgPictureAddr },
							m_vecCategories{ vecCategories },
							DBItem(uiID, "Organization", "Name,ImageFileName,Categories")
{}
unsigned Organization::GetID()const
{
	return m_uiID;
}
std::string Organization::GetName()const
{
	return m_sName;
}
std::string Organization::GetOrgPictureAddr()const
{
	return m_sOrgPictureAddr;
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
	m_vecTournament.clear();
	for (auto t : vecTournament)
	{
		t.SetOrgName(m_sName);
		m_vecTournament.push_back(t);
	}
	std::sort(m_vecTournament.begin(), m_vecTournament.end(), [](const Tournament& t1, const Tournament& t2) {
		return t1.IsEarlier(t2);
		});
}
bool Organization::InsertToDB()const
{
	std::cout << "Organization::InsertToDB org = " << *this << "\n";
	std::string sDBValues{ "'" + GetName() +
							"','" + GetOrgPictureAddr() +
							"','" + utility::Serialize(m_vecCategories) + "'" };
	return m_spIDatabase->InsertItem(m_sDBTable, m_sDBColumns, sDBValues);
}
bool Organization::EditInDB()const
{
	DeletePreviousPP();
	QMap<QString, QVariant> columnValues;
	columnValues["Name"] = QString::fromStdString(m_sName);
	columnValues["ImageFileName"] = QString::fromStdString(m_sOrgPictureAddr);
	columnValues["Categories"] = QString::fromStdString(utility::Serialize(m_vecCategories));
	return m_spIDatabase->EditItem(m_sDBTable, columnValues, m_uiID);
}
void Organization::LoadFromDB(unsigned ID)
{
	m_uiID = stoi(m_spIDatabase->RetrieveValue(m_sDBTable, "ID", ID));
	m_sName = m_spIDatabase->RetrieveValue(m_sDBTable, "Name", "ID", std::to_string(m_uiID));
	m_sOrgPictureAddr = m_spIDatabase->RetrieveValue(m_sDBTable, "ImageFileName", "ID", std::to_string(m_uiID));
	m_vecCategories = DeserializeDBColumn("Categories");
	SetTournaments(DatabaseController::instance().FindTournamentsOfOrganization(m_uiID));
}
bool Organization::DeleteFromDB()const
{
	const QString sFullSourceDir = GetOrgImageRootDestDir() + QString::fromStdString(GetOrgPictureAddr());
	if (QFile::exists(sFullSourceDir))
	{
		QFile::remove(sFullSourceDir);
	}
	return DBItem::DeleteFromDB();
}
QString Organization::GetOrgImageRootDestDir()
{
	return ms_sOrgImageRootDestDir;
}
void Organization::SetOrgImageRootDestDir(const QString& sImageRootDestDir)
{
	ms_sOrgImageRootDestDir = sImageRootDestDir;
}
void Organization::DeletePreviousPP()const
{
	const std::string sPreviousPPAddr = m_spIDatabase->RetrieveValue(m_sDBTable, "ImageFileName", "ID", std::to_string(m_uiID));
	if (sPreviousPPAddr != m_sOrgPictureAddr)
	{
		const QString sFullsPreviousPPAddr = GetOrgImageRootDestDir() + QString::fromStdString(sPreviousPPAddr);
		if (QFile::exists(sFullsPreviousPPAddr))
		{
			QFile::remove(sFullsPreviousPPAddr);
		}
	}
}
