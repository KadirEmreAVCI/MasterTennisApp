#include <iostream>
#include <algorithm>
#include "DatabaseController.h"

DatabaseController& DatabaseController::instance()
{
	static DatabaseController obj;
	return obj;
}
void DatabaseController::LoadDataFromDB()
{
	m_vecMatch = LoadDBItems<Match>();
	m_vecTournament = LoadDBItems<Tournament>();
	m_vecOrganization = LoadDBItems<Organization>();
	m_vecProfile = LoadDBItems<Profile>();
}
Profile DatabaseController::GetActiveProfile(unsigned int uiActiveProfileID)
{
	LoadDataFromDB();
	auto iterActiveProfile = std::find_if(m_vecProfile.cbegin(), m_vecProfile.cend(), [uiActiveProfileID](const auto& p) {
		return p.GetID() == uiActiveProfileID;
		});
	if (iterActiveProfile == m_vecProfile.cend())
	{
		std::cerr << "DatabaseController::LoadActiveProfile active profile could not be found!\n";
	}
	return *iterActiveProfile;
}
std::vector<Profile> DatabaseController::GetProfiles()
{
	LoadDataFromDB();
	return m_vecProfile;
}
std::vector<Organization> DatabaseController::GetOrganizations()
{
	LoadDataFromDB();
	return m_vecOrganization;
}
std::vector<Tournament> DatabaseController::GetTournaments()
{
	LoadDataFromDB();
	return m_vecTournament;
}
std::vector<Match> DatabaseController::FindMatchesOfTournament(unsigned uiTournamentID)const
{
	std::vector<Match> vecMatchesOfTournament;
	std::copy_if(m_vecMatch.cbegin(), m_vecMatch.cend(), std::back_inserter(vecMatchesOfTournament), [uiTournamentID](const auto& m) {
		return m.GetTournamentID() == uiTournamentID;
		});
	return vecMatchesOfTournament;
}
std::vector<Tournament> DatabaseController::FindTournamentsOfOrganization(unsigned uiOrgID)const
{
	std::vector<Tournament> vecTournamentsOfOrg;
	std::copy_if(m_vecTournament.cbegin(), m_vecTournament.cend(), std::back_inserter(vecTournamentsOfOrg), [uiOrgID](const auto& t) {
		return t.GetOrgID() == uiOrgID;
		});
	return vecTournamentsOfOrg;
}
std::vector<Tournament> DatabaseController::FindTournamentsOfProfile(unsigned uiProfileID)const
{
	std::vector<Tournament> vecTournamentsOfProfile;
	std::copy_if(m_vecTournament.cbegin(), m_vecTournament.cend(), std::back_inserter(vecTournamentsOfProfile), [uiProfileID](const auto& t) {
		return t.GetProfileID() == uiProfileID;
		});
	return vecTournamentsOfProfile;
}
Tournament DatabaseController::FindRootTournament(const Match& m)
{
	std::cout << "DatabaseController::FindRootTournament m_uiTournamentID: " << m.GetTournamentID() << "\n";
	auto vecTournaments = GetTournaments();
	auto iterRootTournament = std::find_if(m_vecTournament.cbegin(), m_vecTournament.cend(), [m](const auto& t) {
		return m.GetTournamentID() == t.GetID();
		});
	std::cout << "DatabaseController::FindRootTournament iterRootTournament == m_vecTournament.cend(): " << (iterRootTournament == m_vecTournament.cend()) << "\n";	
	return *iterRootTournament;
}
void DatabaseController::InitDatabase(std::shared_ptr<IDatabase> spDatabase)
{
	m_spIDatabase = spDatabase;
	DBItem::SetDatabase(m_spIDatabase);
	LoadDataFromDB();
}
