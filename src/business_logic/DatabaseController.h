#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <vector>
#include <string>
#include <map>
#include <QObject>
#include "Profile.h"
class IDatabase;
class DatabaseController : public QObject{
	Q_OBJECT
public:
	friend class DatabaseControllerTest;

	static DatabaseController& instance();
	DatabaseController(const DatabaseController&) = delete;
	DatabaseController& operator=(const DatabaseController&) = delete;
	void InitDatabase(std::shared_ptr<IDatabase> spDatabase);
	bool DeleteProfile(const Profile&)const;
	bool DeleteOrganization(const Organization&)const;
	bool DeleteTournament(const Tournament&)const;
	bool DeleteMatch(const Match&)const;
	Profile GetActiveProfile(unsigned int uiActiveProfileID);
	std::vector<Profile> GetProfiles();
	std::vector<Organization> GetOrganizations();
	std::vector<Match> FindMatchesOfTournament(unsigned uiTournamentID)const;
	std::vector<Tournament> FindTournamentsOfOrganization(unsigned uiOrgID)const;
	std::vector<Tournament> FindTournamentsOfProfile(unsigned uiProfileID)const;
	template<typename T>
	bool AddNewDBItem(const T& item)const
	{
		return item.InsertToDB();
	}
	template<typename T>
	bool EditDBItem(const T& item)const
	{
		return item.EditInDB();
	}
private:
	DatabaseController() = default;
	void LoadDataFromDB();
	Profile PrepareActiveProfile(unsigned int uiActiveProfileID)const;
	void LoadProfiles();
	void LoadOrganizations();
	void LoadTournaments();
	void LoadMatches();
	std::vector<Organization> FindParticipatedOrgsOfProfile(unsigned uiProfileID)const;
	std::vector<Profile> m_vecProfile;
	std::vector<Organization> m_vecOrganization;
	std::vector<Tournament> m_vecTournament;
	std::vector<Match> m_vecMatch;
	std::shared_ptr<IDatabase> m_spIDatabase{ nullptr };
};

#endif