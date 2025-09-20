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
	LoadMatches();
	LoadTournaments();
	LoadOrganizations();
	LoadProfiles();
}
void DatabaseController::LoadMatches()
{
	m_vecMatch.clear();
	if (const unsigned uiMatchSize = m_spIDatabase->GetItemCount(Match{}.GetDBTable()); uiMatchSize != 0)
	{
		m_vecMatch.resize(uiMatchSize);
		unsigned uiRowIdx{};
		std::for_each(m_vecMatch.begin(), m_vecMatch.end(), [&](auto& m) {
			m.LoadFromDB(uiRowIdx++);
			});
	}
}
void DatabaseController::LoadTournaments()
{
	m_vecTournament.clear();
	if (const unsigned uiTournamentSize = m_spIDatabase->GetItemCount(Tournament{}.GetDBTable()); uiTournamentSize != 0)
	{
		m_vecTournament.resize(uiTournamentSize);
		unsigned uiRowIdx{};
		std::for_each(m_vecTournament.begin(), m_vecTournament.end(), [&](auto& t) {
			t.LoadFromDB(uiRowIdx++);
			});
	}
}
void DatabaseController::LoadOrganizations()
{
	m_vecOrganization.clear();
	if (const unsigned uiOrgSize = m_spIDatabase->GetItemCount(Organization{}.GetDBTable()); uiOrgSize != 0)
	{
		m_vecOrganization.resize(uiOrgSize);
		unsigned uiRowIdx{};
		std::for_each(m_vecOrganization.begin(), m_vecOrganization.end(), [&](auto& org) {
			org.LoadFromDB(uiRowIdx++);
			});
	}
}
void DatabaseController::LoadProfiles()
{
	m_vecProfile.clear();
	if (const unsigned uiProfileSize = m_spIDatabase->GetItemCount(Profile{}.GetDBTable()); uiProfileSize != 0)
	{
		m_vecProfile.resize(uiProfileSize);
		unsigned uiRowIdx{};
		std::for_each(m_vecProfile.begin(), m_vecProfile.end(), [&](auto& p) {
			p.LoadFromDB(uiRowIdx++);
			});
	}
}
void DatabaseController::PrepareActiveProfile(unsigned int uiActiveProfileID)
{
	auto vecProfile = m_vecProfile;
	auto iterActiveProfile = std::find_if(vecProfile.begin(), vecProfile.end(), [uiActiveProfileID](const auto& p) {
		return p.GetID() == uiActiveProfileID;
		});
	if (iterActiveProfile != vecProfile.cend())
	{
		iterActiveProfile->SetParticipatedOrgs(FindParticipatedOrgsOfProfile(uiActiveProfileID));
	}
	else
	{
		std::cerr << "DatabaseController::LoadActiveProfile active profile could not be found!\n";
	}
	m_ActiveProfile = *iterActiveProfile;
}
Profile DatabaseController::GetActiveProfile(unsigned int uiActiveProfileID)
{
	LoadDataFromDB();
	PrepareActiveProfile(uiActiveProfileID);
	return m_ActiveProfile;
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
std::vector<Organization> DatabaseController::FindParticipatedOrgsOfProfile(unsigned uiProfileID)const
{
	std::vector<Organization> vecOrgsOfProfile;
	std::vector<Organization> vecOrganization = m_vecOrganization;
	for (auto& org : vecOrganization)
	{
		auto vecTournament = org.GetTournaments();
		std::erase_if(vecTournament, [uiProfileID](const auto& t) {
			return t.GetProfileID() != uiProfileID;
			});
		if (!vecTournament.empty())
		{
			org.SetTournaments(vecTournament);
			vecOrgsOfProfile.push_back(org);
		}
	}
	return vecOrgsOfProfile;
}
void DatabaseController::InitDatabase(std::shared_ptr<IDatabase> spDatabase)
{
	m_spIDatabase = spDatabase;
	DBItem::SetDatabase(m_spIDatabase);
	LoadDataFromDB();
}
bool DatabaseController::DeleteProfile(const Profile& p)const
{
	bool blDeletion = true;
	const auto& vecTournamentsOfProfile = FindTournamentsOfProfile(p.GetID());
	for (const auto& t : vecTournamentsOfProfile)
	{
		blDeletion &= DeleteTournament(t);
	}
	blDeletion &= p.DeleteFromDB();
	return blDeletion;
}
bool DatabaseController::DeleteOrganization(const Organization& org)const
{
	bool blDeletion = true;
	const auto& vecTournamentsOfOrganization = FindTournamentsOfOrganization(org.GetID());
	for (const auto& t : vecTournamentsOfOrganization)
	{
		blDeletion &= DeleteTournament(t);
	}
	blDeletion &= org.DeleteFromDB();
	return blDeletion;
}
bool DatabaseController::DeleteTournament(const Tournament& t)const
{
	bool blDeletion = true;
	const auto& vecMatchesOfTournament = FindMatchesOfTournament(t.GetID());
	for (const auto& m : vecMatchesOfTournament)
	{
		blDeletion &= DeleteMatch(m);
	}
	blDeletion &= t.DeleteFromDB();
	return blDeletion;
}
bool DatabaseController::DeleteMatch(const Match& m)const
{
	return m.DeleteFromDB();
}
