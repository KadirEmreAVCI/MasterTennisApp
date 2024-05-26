#include "Tournament.h"
#include "Organization.h"
Tournament::Tournament()
{
	
}

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

std::string Tournament::GetProgress()const
{
	// TODO: Son maca gore set edilecek.
	return m_sProgress;
}

