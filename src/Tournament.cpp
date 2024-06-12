#include <cmath>
#include <iterator>
#include "Tournament.h"
#include "Organization.h"
Tournament::Tournament()
{
	
}

std::vector<std::string> Tournament::ms_vecPlayoffStages{"Final", "Semi-Final", "Quarter Final", "Final 16", "Final 32", "Final 64"};

unsigned Tournament::GetID()const
{
	return m_uiID;
}

void Tournament::SetID(unsigned uiID)
{
	m_uiID = uiID;
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

std::string Tournament::GetTeammate()const
{
	return m_sTeammate.value_or("None");
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

bool Tournament::GetCompleted()const
{
	return m_blCompleted;
}

void Tournament::SetCompleted(bool blCompleted)
{
	m_blCompleted = blCompleted;
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
unsigned Tournament::GetGamesToWin()const
{
	return m_uiGamesToWin;
}
void Tournament::SetGamesToWin(unsigned uiGamesToWin)
{
	m_uiGamesToWin = uiGamesToWin;
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
	std::cout << "Tournament::GetStages iStageNum = " << iStageNum << '\n';
	std::vector<std::string> vecStages;
	if (iStageNum > 2)
	{
		vecStages.push_back("Group Stage");
		--iStageNum;
	}
	for (int iStageIdx{ iStageNum - 1 }; iStageIdx >= 0; --iStageIdx)
	{
		vecStages.push_back(ms_vecPlayoffStages.at(iStageIdx));
		--iStageNum;
	}
	if (Get3rdPlaceGameAvailable())
	{
		vecStages.push_back("3rd Place Game");
	}
	std::copy(vecStages.cbegin(), vecStages.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
	return vecStages;
}

std::string Tournament::GetProgress()const
{
	// TODO: Son maca gore set edilecek.
	return m_sProgress;
}

