#include <cmath>
#include <iterator>
#include <algorithm>
#include <QMap>
#include <QVariant>
#include "Tournament.h"
Tournament::Tournament(): DBItem("Tournament", "ProfileID,OrganizationID,Season,Category,Type,Teammate,Participant,Locked,ThirdPlaceGameAvailable,SetsBestOf")
{
	
}

std::vector<std::string> Tournament::ms_vecPossiblePlayoffStages{"Final", "Semi Final", "Quarter Final", "Final 16", "Final 32", "Final 64"};

std::string Tournament::GetName()const
{
	return GetOrgName() + ", " + GetSeason() + ", " + GetType() + ", " + GetCategory();
}

unsigned Tournament::GetID()const
{
	return m_uiID;
}

void Tournament::SetID(unsigned uiID)
{
	m_uiID = uiID;
}

unsigned Tournament::GetProfileID()const
{
	return m_uiProfileID;
}

void Tournament::SetProfileID(unsigned uiProfileID)
{
	m_uiProfileID = uiProfileID;
}

unsigned Tournament::GetOrgID()const
{
	return m_uiOrgID;
}

void Tournament::SetOrgID(unsigned uiOrgID)
{
	m_uiOrgID = uiOrgID;
}

std::string Tournament::GetOrgName()const
{
	return m_sOrgName;
}

void Tournament::SetOrgName(std::string sName)
{
	m_sOrgName = sName;
}

std::string Tournament::GetType()const
{
	return m_sType;
}

void Tournament::SetType(std::string sType)
{
	m_sType = sType;
}

bool Tournament::IsDoubleTournament()const
{
	return m_sType.find("Double") != std::string::npos;
}

std::string Tournament::GetTeammate()const
{
	return m_sTeammate.value_or("-");
}

void Tournament::SetTeammate(std::string sTeammate)
{
	m_sTeammate = sTeammate;
}

std::string Tournament::GetCategory()const
{
	return m_sCategory;
}

void Tournament::SetCategory(std::string sCategory)
{
	m_sCategory = sCategory;
}

std::string Tournament::GetSeason()const
{
	return m_sSeason;
}

void Tournament::SetSeason(std::string sSeason)
{
	m_sSeason = sSeason;
}

unsigned Tournament::GetParticipant()const
{
	return m_uiParticipant;
}

void Tournament::SetParticipant(unsigned uiParticipant)
{
	m_uiParticipant = uiParticipant;
}

bool Tournament::IsLocked()const
{
	return m_blIsLocked;
}

void Tournament::SetLocked(bool blIsLocked)
{
	m_blIsLocked = blIsLocked;
}

bool Tournament::Get3rdPlaceGameAvailable()const
{
	return m_bl3rdPlaceGameAvailable;
}

void Tournament::Set3rdPlaceGameAvailable(bool bl3rdPlaceGameAvailable)
{
	m_bl3rdPlaceGameAvailable = bl3rdPlaceGameAvailable;
}

unsigned Tournament::GetSetsBestOf()const
{
	return m_uiBestOfSets;
}

void Tournament::SetSetsBestOf(unsigned uiBestOfSets)
{
	m_uiBestOfSets = uiBestOfSets;
}
/*  
	GetStages function adds all possible stages for the tournament. 
	If there are more than 4 players in the tournament, group stage option will be available, else there will be only playoff stages.
	Supports up to 128 players. 
*/
std::vector<std::string> Tournament::GetStages()const
{
	unsigned int uiParticipant = m_uiParticipant;
	int iStageNum = (log2(uiParticipant) == floor(log2(uiParticipant))) ? log2(uiParticipant) : floor(log2(uiParticipant)) + 1;
	std::vector<std::string> vecStages;
	if (iStageNum > 2)
	{
		vecStages.push_back("Group Stage");
		--iStageNum;
	}
	for (int iStageIdx{ iStageNum - 1 }; iStageIdx >= 0; --iStageIdx)
	{
		vecStages.push_back(ms_vecPossiblePlayoffStages.at(iStageIdx));
		--iStageNum;
	}
	if (Get3rdPlaceGameAvailable())
	{
		vecStages.push_back("3rd Place Game");
	}
	return vecStages;
}
std::vector<Match> Tournament::GetMatches()const
{
	return m_vecMatch;
}
void Tournament::SetMatches(const std::vector<Match>& vecMatch)
{
	m_vecMatch = vecMatch;
	std::sort(m_vecMatch.begin(), m_vecMatch.end(), [](const Match& m1, const Match& m2) {
		return m1.IsEarlier(m2);
		});
}
bool Tournament::IsGroupStageExist()const
{
	return std::any_of(m_vecMatch.cbegin(), m_vecMatch.cend(), [](const auto& m) {
		return m.GetStage() == "Group Stage";
		});
}
std::optional<Match> Tournament::GetLastMatch()const
{
	return !m_vecMatch.empty() ? std::optional<Match>(m_vecMatch.back()) : std::nullopt;
}
bool Tournament::IsEarlier(const Tournament& other)const
{
	if (!m_vecMatch.empty() && !other.m_vecMatch.empty())
	{
		return m_vecMatch.front().IsEarlier(other.m_vecMatch.front());
	}
	else if (!other.m_vecMatch.empty())
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Tournament::InsertToDB()const
{
	std::string sDBValues{	"'" + std::to_string(m_uiProfileID) +
							"','" + std::to_string(m_uiOrgID) +
							"','" + m_sSeason +
							"','" + m_sCategory +
							"','" + m_sType +
							"','" + GetTeammate() +
							"','" + std::to_string(m_uiParticipant) +
							"','" + std::to_string(m_blIsLocked) +
							"','" + std::to_string(m_bl3rdPlaceGameAvailable) +
							"','" + std::to_string(m_uiBestOfSets) +
							"'" };
	return SQLiteDB::instance().InsertItem2Table(m_sDBTable, m_sDBColumns, sDBValues);;
}
bool Tournament::EditInDB()const
{
	QMap<QString, QVariant> columnValues;
	columnValues["ProfileID"] = QString::fromStdString(std::to_string(m_uiProfileID));
	columnValues["OrganizationID"] = QString::fromStdString(std::to_string(m_uiOrgID));
	columnValues["Season"] = QString::fromStdString(m_sSeason);
	columnValues["Category"] = QString::fromStdString(m_sCategory);
	columnValues["Type"] = QString::fromStdString(m_sType);
	columnValues["Teammate"] = QString::fromStdString(GetTeammate());
	columnValues["Participant"] = QString::fromStdString(std::to_string(m_uiParticipant));
	columnValues["Locked"] = QString::fromStdString(std::to_string(m_blIsLocked));
	columnValues["ThirdPlaceGameAvailable"] = QString::fromStdString(std::to_string(m_bl3rdPlaceGameAvailable));
	columnValues["SetsBestOf"] = QString::fromStdString(std::to_string(m_uiBestOfSets));
	return SQLiteDB::instance().EditItemInTable(m_sDBTable, columnValues, m_uiID);
}
void Tournament::LoadFromDB(unsigned ID)
{
	SQLiteDB& db = SQLiteDB::instance();
	SetID(stoi(db.GetValue(m_sDBTable, "ID", ID)));
	SetProfileID(stoi(db.GetValueWithCond(m_sDBTable, "ProfileID", "ID", std::to_string(m_uiID))));
	SetOrgID(stoi(db.GetValueWithCond(m_sDBTable, "OrganizationID", "ID", std::to_string(m_uiID))));
	SetSeason(db.GetValueWithCond(m_sDBTable, "Season", "ID", std::to_string(m_uiID)));
	SetCategory(db.GetValueWithCond(m_sDBTable, "Category", "ID", std::to_string(m_uiID)));
	SetType(db.GetValueWithCond(m_sDBTable, "Type", "ID", std::to_string(m_uiID)));
	SetTeammate(db.GetValueWithCond(m_sDBTable, "Teammate", "ID", std::to_string(m_uiID)));
	SetParticipant(stoi(db.GetValueWithCond(m_sDBTable, "Participant", "ID", std::to_string(m_uiID))));
	SetLocked(stoi(db.GetValueWithCond(m_sDBTable, "Locked", "ID", std::to_string(m_uiID))));
	Set3rdPlaceGameAvailable(stoi(db.GetValueWithCond(m_sDBTable, "ThirdPlaceGameAvailable", "ID", std::to_string(m_uiID))));
	SetSetsBestOf(stoi(db.GetValueWithCond(m_sDBTable, "SetsBestOf", "ID", std::to_string(m_uiID))));
}



