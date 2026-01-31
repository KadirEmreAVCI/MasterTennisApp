#include <cmath>
#include <iterator>
#include <algorithm>
#include <QMap>
#include <QVariant>
#include "Tournament.h"
#include "DatabaseController.h"

using namespace common;

Tournament::Tournament(	unsigned uiID,
						unsigned uiProfileID ,
						unsigned uiOrgID,
						const std::string& sOrgName,
						const std::string& sSeason,
						const std::string& sCategory,
						const std::string& sType,
						std::optional<std::string> soptTeammate,
						unsigned uiParticipant,
						bool blIsLocked,
						bool bl3rdPlaceGameAvailable,
						unsigned uiBestOfSets)
						: 
						m_uiProfileID{ uiProfileID },
						m_uiOrgID{ uiOrgID },
						m_sSeason{ sSeason },
						m_sCategory{ sCategory },
						m_sType{ sType },
						m_soptTeammate{ soptTeammate },
						m_uiParticipant{ uiParticipant },
						m_blIsLocked{ blIsLocked },
						m_bl3rdPlaceGameAvailable{ bl3rdPlaceGameAvailable },
						m_uiBestOfSets{ uiBestOfSets },
						DBItem(uiID, "Tournament", "ProfileID,OrganizationID,Season,Category,Type,Teammate,Participant,Locked,ThirdPlaceGameAvailable,SetsBestOf")
{}

std::vector<std::string> Tournament::ms_vecPossiblePlayoffStages{"Final", "Semi Final", "Quarter Final", "Final 16", "Final 32", "Final 64"};

std::string Tournament::GetName()const
{
	return DatabaseController::instance().FindRootOrganization(*this).GetName() + ", " + GetSeason() + ", " + GetType() + ", " + GetCategory();
}
unsigned Tournament::GetID()const
{
	return m_uiID;
}
unsigned Tournament::GetProfileID()const
{
	return m_uiProfileID;
}
unsigned Tournament::GetOrgID()const
{
	return m_uiOrgID;
}
std::string Tournament::GetType()const
{
	return m_sType;
}
bool Tournament::IsDoubleTournament()const
{
	return m_soptTeammate.has_value() && m_soptTeammate.value() != "";
}
std::string Tournament::GetTeammate()const
{
	return m_soptTeammate.value_or("");
}
std::string Tournament::GetCategory()const
{
	return m_sCategory;
}
std::string Tournament::GetSeason()const
{
	return m_sSeason;
}
unsigned Tournament::GetParticipant()const
{
	return m_uiParticipant;
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
std::string Tournament::GetTrophyPic()const
{
	std::string sTrophyPic = "";
	if (const auto& lastMatch = GetLastMatch(); lastMatch.has_value() && lastMatch.value().IsValid())
	{
		if (lastMatch.value().GetStage() == "Final")
		{
			if (lastMatch.value().GetOutcome() == Outcome::HomeWin)
			{
				sTrophyPic = ":images/first_place.png";
			}
			else if(lastMatch.value().GetOutcome() == Outcome::AwayWin)
			{
				sTrophyPic = ":images/second_place.png";
			}
		}
		else if (lastMatch.value().GetStage() == "3rd Place Game" && lastMatch.value().GetOutcome() == Outcome::HomeWin)
		{
			sTrophyPic = ":images/third_place.png";
		}
	}
	return sTrophyPic;
}
unsigned Tournament::GetSetsBestOf()const
{
	return m_uiBestOfSets;
}
/*  
	GetStages function adds all possible stages for the tournament. 
	If there are more than 4 players in the tournament, group stage option will be available, else there will be only playoff stages.
	Supports up to 128 players. 
*/
std::vector<std::string> Tournament::GetPossibleStages()const
{
	unsigned int uiParticipant = m_uiParticipant;
	int iStageNum = (log2(uiParticipant) == floor(log2(uiParticipant))) ? log2(uiParticipant) : floor(log2(uiParticipant)) + 1;
	std::vector<std::string> vecStages;
	if (iStageNum >= 2)
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
	return std::vector<Match>(m_setMatch.begin(), m_setMatch.end());
}
void Tournament::SetMatches(const std::vector<Match>& vecMatch)
{
	m_setMatch.clear();
	for(const auto& m : vecMatch)
	{
		m_setMatch.insert(m);
	}
}
bool Tournament::IsGroupStageExist()const
{
	return std::any_of(m_setMatch.cbegin(), m_setMatch.cend(), [](const auto& m) {
		return m.GetStage() == "Group Stage";
		});
}
std::optional<Match> Tournament::GetLastMatch()const
{
	if(m_setMatch.empty())
	{
		return std::nullopt;
	}
	else
	{
		return *std::prev(m_setMatch.end());
	}
}
bool Tournament::IsMatchValidForTournament(const Match& m)const
{
	return m.IsValid() && IsMatchStageValid(m) && !IsMatchExceedingMaxSet(m);
}
bool Tournament::IsValid()const
{
	bool blAllMatchesAreValid = true;
	if (!m_setMatch.empty())
	{
		blAllMatchesAreValid = std::all_of(m_setMatch.cbegin(), m_setMatch.cend(), [this](const Match& m){
			return IsMatchValidForTournament(m);
			});
	}
	const bool blTournamentTypeCompatible = ((m_sType.find("Double") != std::string::npos) == IsDoubleTournament());
	return blAllMatchesAreValid && blTournamentTypeCompatible;
}
bool Tournament::operator<(const Tournament& other)const
{
	if(!m_setMatch.empty() && !other.m_setMatch.empty())
	{
		return *m_setMatch.begin() < *other.m_setMatch.begin();
	}
	else if(!other.m_setMatch.empty())
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Tournament::operator>(const Tournament& other)const
{
	return other < *this;
}
bool Tournament::operator<=(const Tournament& other)const
{
	return !(*this > other);
}
bool Tournament::operator>=(const Tournament& other)const
{
	return !(*this < other);
}
bool Tournament::IsMatchStageValid(const Match& m)const
{
	const auto& vecPossibleStages = GetPossibleStages();
	const bool blMatchStageIsValid = std::any_of(vecPossibleStages.cbegin(), vecPossibleStages.cend(), [m](const std::string& sStage) {
		return sStage == m.GetStage();
		});
	return blMatchStageIsValid;	
}
bool Tournament::IsMatchExceedingMaxSet(const Match& m)const
{
	const unsigned uiMaxScoreForWinner = (m_uiBestOfSets + 1) / 2;
	return (m.GetSets().size() > m_uiBestOfSets) || (m.GetScore().GetHomeScore() > uiMaxScoreForWinner || m.GetScore().GetAwayScore() > uiMaxScoreForWinner);
}
bool Tournament::DeleteFromDB()const
{
	for(const auto& m : m_setMatch)
	{
		if (!m.DeleteFromDB())
		{
			return false;
		}
	}
	return DBItem::DeleteFromDB();
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
	return m_spIDatabase->InsertItem(m_sDBTable, m_sDBColumns, sDBValues);;
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
	return m_spIDatabase->EditItem(m_sDBTable, columnValues, m_uiID);
}
void Tournament::LoadFromDB(unsigned ID)
{
	m_uiID = stoi(m_spIDatabase->RetrieveValue(m_sDBTable, "ID", ID));
	m_uiProfileID = stoi(m_spIDatabase->RetrieveValue(m_sDBTable, "ProfileID", "ID", std::to_string(m_uiID)));
	m_uiOrgID = stoi(m_spIDatabase->RetrieveValue(m_sDBTable, "OrganizationID", "ID", std::to_string(m_uiID)));
	m_sSeason = m_spIDatabase->RetrieveValue(m_sDBTable, "Season", "ID", std::to_string(m_uiID));
	m_sCategory = m_spIDatabase->RetrieveValue(m_sDBTable, "Category", "ID", std::to_string(m_uiID));
	m_sType = m_spIDatabase->RetrieveValue(m_sDBTable, "Type", "ID", std::to_string(m_uiID));
	const std::string sTeammate = m_spIDatabase->RetrieveValue(m_sDBTable, "Teammate", "ID", std::to_string(m_uiID));
	m_soptTeammate = (sTeammate != "") ? std::optional<std::string>(sTeammate) : std::nullopt;
	m_uiParticipant = stoi(m_spIDatabase->RetrieveValue(m_sDBTable, "Participant", "ID", std::to_string(m_uiID)));
	m_blIsLocked = stoi(m_spIDatabase->RetrieveValue(m_sDBTable, "Locked", "ID", std::to_string(m_uiID)));
	m_bl3rdPlaceGameAvailable = stoi(m_spIDatabase->RetrieveValue(m_sDBTable, "ThirdPlaceGameAvailable", "ID", std::to_string(m_uiID)));
	m_uiBestOfSets = stoi(m_spIDatabase->RetrieveValue(m_sDBTable, "SetsBestOf", "ID", std::to_string(m_uiID)));
	SetMatches(DatabaseController::instance().FindMatchesOfTournament(m_uiID));
}
