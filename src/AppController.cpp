#include <iostream>
#include <algorithm>
#include "AppController.h"
#include "GUIController.h"
#include "GUIConfigurator.h"
#include "DatabaseController.h"
AppController* AppController::ms_pAppController = nullptr;
void AppController::create()
{
	static AppController obj;
	ms_pAppController = &obj;
}
AppController& AppController::instance()
{
	if (ms_pAppController == nullptr)
		create();
	return *ms_pAppController;
}
AppController::AppController() 
{
	m_pGUIConfigurator = new GUIConfigurator();
	LoadOrganizations();
	LoadTournaments();
}
AppController::~AppController()
{
	delete m_pGUIConfigurator;
}
void AppController::StartApplication()
{
	GUIController::create();
	m_pGUIConfigurator->ConfigureGUI();
}
std::string AppController::getAppName()
{
	return m_sAppName;
}
std::vector<Organization> AppController::GetOrganizations()const
{
	return m_vecOrganizations;
}
std::vector<Tournament> AppController::GetTournaments()const
{
	return m_vecTournament;
}
void AppController::LoadOrganizations()
{
	m_vecOrganizations.clear();
	m_vecOrganizations = DatabaseController::instance().GetOrganizations();
}
void AppController::LoadTournaments()
{
	m_vecTournament.clear();
	m_vecTournament = DatabaseController::instance().GetTournaments();
}
std::vector<std::string> AppController::GetOrgNames()const
{
	std::vector<std::string> vecOrgName;
	std::transform(m_vecOrganizations.cbegin(), m_vecOrganizations.cend(), std::back_inserter(vecOrgName), [](const auto& org) {
		return org.GetName();
	});
	return vecOrgName;
}
std::vector<std::string> AppController::GetCategories(const std::string& sOrg) const
{
	std::vector<std::string> vecCategories = GetOrg(sOrg).GetCategories();
	return vecCategories;
}
void AppController::AddNewOrganization(const Organization& org)
{
	if (DatabaseController::instance().AddNewOrganization(org))
	{
		LoadOrganizations();
		emit OrganizationAdded();
	}
	else
	{
		std::cout << "AppController::AddNewOrganization failed\n";
	}
}
bool AppController::AddNewTournament(Tournament t)
{
	const bool blTournamentAdded = DatabaseController::instance().AddNewTournament(t);
	if (blTournamentAdded)
	{
		LoadTournaments();
		emit TournamentAdded();
	}
	else
	{
		std::cout << "AppController::AddNewTournament failed\n";
	}
	return blTournamentAdded;
}
void AppController::DeleteTournaments(std::vector<Tournament> vecTournament)
{
	if (DatabaseController::instance().DeleteTournaments(vecTournament))
	{
		LoadTournaments();
		emit TournamentsDeleted();
	}
	else
	{
		std::cout << "AppController::DeleteTournaments failed\n";
	}
}
bool AppController::EditTournament(Tournament t)
{
	const bool blTournamentEdited = DatabaseController::instance().EditTournament(t);
	if (blTournamentEdited)
	{
		LoadTournaments();
		emit TournamentEdited();
	}
	else
	{
		std::cout << "AppController::EditTournament failed\n";
	}
	return blTournamentEdited;
}
bool AppController::AddNewMatch(const Match& m)
{
	const bool blNewMatchAdded = DatabaseController::instance().AddNewMatch(m);
	if (blNewMatchAdded)
	{
		/*LoadMatches();
		emit MatchAdded();*/
	}
	else
	{
		std::cout << "AppController::AddNewMatch failed\n";
	}
	return blNewMatchAdded;
}
const Organization& AppController::GetOrg(const std::string& sOrg)const
{
	auto iterOrg = std::find_if(m_vecOrganizations.begin(), m_vecOrganizations.end(), [sOrg](const auto& org) {
		return org.GetName() == sOrg;
		});
	if (iterOrg == m_vecOrganizations.end())
	{
		std::cerr << "AppController::GetOrg Organization could not be found!\n";
	}
	return *iterOrg;
}