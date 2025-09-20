#include <iostream>
#include <QMap>
#include <QVariant>
#include <QFile>
#include "Tournament.h"
#include "Profile.h"
#include "DatabaseController.h"

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
std::string Profile::GetFullName()const
{
	return m_sFullName;
}
std::string Profile::GetPPAddr()const
{
	return m_sPPAddr;
}
Gender Profile::GetGender()const
{
	return m_Gender;
}
std::vector<Tournament> Profile::GetTournaments()const
{
	return m_vecTournament;
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
	const std::string sPreviousPPAddr = m_spIDatabase->RetrieveValue(m_sDBTable, "PPAddress", "ID", std::to_string(m_uiID));
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
	std::string sDBValues{ "'" + m_sFullName +
							"','" + ((m_Gender == Gender::Male) ? "Male" : "Female") +
							"','" + m_sPPAddr +
							"'" };
	return m_spIDatabase->InsertItem(m_sDBTable, m_sDBColumns, sDBValues);
}
bool Profile::EditInDB()const
{
	DeletePreviousPP();
	QMap<QString, QVariant> columnValues;
	columnValues["FullName"] = QString::fromStdString(m_sFullName);
	columnValues["Gender"] = ((m_Gender == Gender::Male) ? "Male" : "Female");
	columnValues["PPAddress"] = QString::fromStdString(m_sPPAddr);
	return m_spIDatabase->EditItem(m_sDBTable, columnValues, m_uiID);
}
void Profile::LoadFromDB(unsigned ID)
{
	m_uiID = stoi(m_spIDatabase->RetrieveValue(m_sDBTable, "ID", ID));
	m_sFullName = m_spIDatabase->RetrieveValue(m_sDBTable, "FullName", "ID", std::to_string(m_uiID));
	m_Gender = (m_spIDatabase->RetrieveValue(m_sDBTable, "Gender", "ID", std::to_string(m_uiID))) == "Male" ? Gender::Male : Gender::Female;
	m_sPPAddr = m_spIDatabase->RetrieveValue(m_sDBTable, "PPAddress", "ID", std::to_string(m_uiID));
	SetTournaments(DatabaseController::instance().FindTournamentsOfProfile(m_uiID));
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
void Profile::SetTournaments(const std::vector<Tournament>& vecTournament)
{
	m_vecTournament = vecTournament;
	std::sort(m_vecTournament.begin(), m_vecTournament.end(), [](const Tournament& t1, const Tournament& t2) {
		return t1.IsEarlier(t2);
		});
}