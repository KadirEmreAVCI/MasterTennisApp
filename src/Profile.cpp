#include <iostream>
#include <QMap>
#include <QVariant>
#include <QFile>
#include "Tournament.h"
#include "Profile.h"

QString Profile::ms_sProfileImageRootDestDir = "";
Profile::Profile(	unsigned uiID, 
					const std::string& sFullName, 
					const std::string& sPPAddr, 
					Gender gen) 
					:
					m_sFullName{sFullName},
					m_sPPAddr{sPPAddr},
					m_Gender{gen},
					DBItem(uiID, "Profile", "FullName,Gender,PPAddress")
{}
unsigned int Profile::GetID()const
{
	return m_uiID;
}
//void Profile::SetID(unsigned int uiID)
//{
//	m_uiID = uiID;
//}
std::string Profile::GetFullName()const
{
	return m_sFullName;
}
//void Profile::SetFullName(const std::string& sNameSurname)
//{
//	m_sFullName = sNameSurname;
//}
std::string Profile::GetPPAddr()const
{
	return m_sPPAddr;
}
//void Profile::SetPPAddr(const std::string& sPPAddr)
//{
//	m_sPPAddr = sPPAddr;
//}
Gender Profile::GetGender()const
{
	return m_Gender;
}
//void Profile::SetGender(Gender gender)
//{
//	m_Gender = gender;
//}
std::vector<Organization> Profile::GetParticipatedOrgs()const
{
	return m_vecParticipatedOrg;
}
void Profile::SetParticipatedOrgs(const std::vector<Organization>& vecOrganization)
{
	m_vecParticipatedOrg = vecOrganization;
}
QString Profile::GetProfileImageRootDestDir()
{
	return ms_sProfileImageRootDestDir;
}
void Profile::SetProfileImageRootDestDir(const QString& sProfileImageRootDestDir)
{
	ms_sProfileImageRootDestDir = sProfileImageRootDestDir;
}
void Profile::DeletePreviousPP()const
{
	const std::string sPreviousPPAddr = SQLiteDB::instance().GetValueWithCond(m_sDBTable, "PPAddress", "ID", std::to_string(m_uiID));
	if (sPreviousPPAddr != m_sPPAddr)
	{
		const QString sFullsPreviousPPAddr = GetProfileImageRootDestDir() + QString::fromStdString(sPreviousPPAddr);
		if (QFile::exists(sFullsPreviousPPAddr))
		{
			QFile::remove(sFullsPreviousPPAddr);
		}
	}
}
bool Profile::InsertToDB()const
{
	std::cout << "Profile::InsertToDB p = " << *this << "\n";
	std::string sDBValues{ "'" + m_sFullName +
							"','" + ((m_Gender == Gender::Male) ? "Male" : "Female") +
							"','" + m_sPPAddr +
							"'" };
	return SQLiteDB::instance().InsertItem2Table(m_sDBTable, m_sDBColumns, sDBValues);
}
bool Profile::EditInDB()const
{
	std::cout << "Profile::EditInDB p = " << *this << "\n";
	DeletePreviousPP();
	QMap<QString, QVariant> columnValues;
	columnValues["FullName"] = QString::fromStdString(m_sFullName);
	columnValues["Gender"] = ((m_Gender == Gender::Male) ? "Male" : "Female");
	columnValues["PPAddress"] = QString::fromStdString(m_sPPAddr);
	return SQLiteDB::instance().EditItemInTable(m_sDBTable, columnValues, m_uiID);
}
void Profile::LoadFromDB(unsigned ID)
{
	const SQLiteDB& db = SQLiteDB::instance();
	m_uiID = stoi(db.GetValue(m_sDBTable, "ID", ID));
	m_sFullName = db.GetValueWithCond(m_sDBTable, "FullName", "ID", std::to_string(m_uiID));
	m_Gender = (db.GetValueWithCond(m_sDBTable, "Gender", "ID", std::to_string(m_uiID))) == "Male" ? Gender::Male : Gender::Female;
	m_sPPAddr = db.GetValueWithCond(m_sDBTable, "PPAddress", "ID", std::to_string(m_uiID));
}
bool Profile::DeleteFromDB()const
{
	const QString sFullSourceDir = GetProfileImageRootDestDir() + QString::fromStdString(GetPPAddr());
	if (QFile::exists(sFullSourceDir))
	{
		QFile::remove(sFullSourceDir);
	}
	return DBItem::DeleteFromDB();
}