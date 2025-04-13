#include <iostream>
#include <sstream> 
#include <algorithm>
#include <QFile>
#include "Organization.h"
QString Organization::ms_sOrgImageRootDestDir = "";
Organization::Organization():DBItem("Organization", "Name,ImageFileName,Categories")
{
	
}
unsigned Organization::GetID()const
{
	return m_uiID;
}
void Organization::SetID(unsigned uiID)
{
	m_uiID = uiID;
}
std::string Organization::GetName()const
{
	return m_sName;
}
void Organization::SetName(const std::string& sName)
{
	m_sName = sName;
}
std::string Organization::GetOrgPictureAddr()const
{
	return m_sOrgPictureAddr;
}
void Organization::SetOrgPictureAddr(const std::string& sImageFileName)
{
	m_sOrgPictureAddr = sImageFileName;
}
std::vector<std::string> Organization::GetCategories()const
{
	return m_vecCategories;
}
void Organization::SetCategories(const std::vector<std::string>& vecCategories)
{
	m_vecCategories = vecCategories;
}
void Organization::AddCategory(const std::string& sCategory)
{
	m_vecCategories.push_back(sCategory);
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
							"','" + Serialize(m_vecCategories) + "'" };
	return SQLiteDB::instance().InsertItem2Table(m_sDBTable, m_sDBColumns, sDBValues);
}
bool Organization::EditInDB()const
{
	DeletePreviousPP();
	QMap<QString, QVariant> columnValues;
	columnValues["Name"] = QString::fromStdString(m_sName);
	columnValues["ImageFileName"] = QString::fromStdString(m_sOrgPictureAddr);
	columnValues["Categories"] = QString::fromStdString(Serialize(m_vecCategories));
	return SQLiteDB::instance().EditItemInTable(m_sDBTable, columnValues, m_uiID);
}
void Organization::LoadFromDB(unsigned ID)
{
	SQLiteDB& db = SQLiteDB::instance();
	SetID(stoi(db.GetValue(m_sDBTable, "ID", ID)));
	SetName(db.GetValueWithCond(m_sDBTable, "Name", "ID", std::to_string(m_uiID)));
	SetOrgPictureAddr(db.GetValueWithCond(m_sDBTable, "ImageFileName", "ID", std::to_string(m_uiID)));
	SetCategories(Deserialize("Categories"));
}
bool Organization::DeleteFromDB()const
{
	const QString sFullSourceDir = GetOrgImageRootDestDir() + QString::fromStdString(GetOrgPictureAddr());
	if (QFile::exists(sFullSourceDir))
	{
		QFile::remove(sFullSourceDir);
	}
	return SQLiteDB::instance().DeleteItemFromTable(m_sDBTable, "ID", std::to_string(m_uiID));
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
	const std::string sPreviousPPAddr = SQLiteDB::instance().GetValueWithCond(m_sDBTable, "ImageFileName", "ID", std::to_string(m_uiID));
	if (sPreviousPPAddr != m_sOrgPictureAddr)
	{
		const QString sFullsPreviousPPAddr = GetOrgImageRootDestDir() + QString::fromStdString(sPreviousPPAddr);
		if (QFile::exists(sFullsPreviousPPAddr))
		{
			QFile::remove(sFullsPreviousPPAddr);
		}
	}
}
std::string Organization::Serialize(std::vector<std::string> vec)const
{
	std::ostringstream oss{};
	std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<std::string>(oss, ","));
	std::string sSerialized{ oss.str() };
	sSerialized.pop_back();
	return sSerialized;
}
std::vector<std::string> Organization::Deserialize(const std::string& sColumn)const
{
	std::vector<std::string> vecDeserialized;
	std::vector<std::string> vecSerialized = SQLiteDB::instance().GetColumnWithCond(m_sDBTable, sColumn, "ID", std::to_string(m_uiID));
	if (!vecSerialized.empty())
	{
		const auto& sSerialized = vecSerialized.front();	
		vecDeserialized = ExtractSerialized(sSerialized);
	}
	return vecDeserialized;
}
std::vector<std::string> Organization::ExtractSerialized(std::string sSerialized)const
{
	std::vector<std::string> vecDeserialized;
	std::istringstream iss(sSerialized);
	std::string sItem;
	while (std::getline(iss, sItem, ',')) {
		vecDeserialized.push_back(std::move(sItem));
	}
	return vecDeserialized;
}