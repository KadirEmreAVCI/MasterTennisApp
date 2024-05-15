#include "Tournament.h"

Tournament::Tournament(std::string sOrganizationName, std::string sType, std::string sCategory, std::string sSeason, unsigned uiParticipant, bool blCompleted, std::string sProgress)
	: m_sOrganizationName{ sOrganizationName }, m_sType{ sType }, m_sCategory{ sCategory }, m_sSeason{ sSeason }, m_uiParticipant{ uiParticipant }, m_blCompleted{ blCompleted }, m_sProgress{ sProgress } {}

std::string Tournament::GetOrganizationName()const
{
	return m_sOrganizationName;
}

void Tournament::SetOrganizationName(std::string sName)
{
	m_sOrganizationName = sName;
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
	return m_sTeammate;
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
	return m_sProgress;
}

void Tournament::SetProgress(std::string sProgress)
{
	m_sProgress = sProgress;
}

