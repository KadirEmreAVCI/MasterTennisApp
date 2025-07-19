#pragma once
#include <vector>
#include <string>
#include <map>
#include <QObject>
#include "Profile.h"

class DatabaseController : public QObject{
	Q_OBJECT
public:
	friend class DatabaseControllerTest;

	static DatabaseController& instance();
	DatabaseController(const DatabaseController&) = delete;
	DatabaseController& operator=(const DatabaseController&) = delete;
	bool DeleteProfile(const Profile&)const;
	bool DeleteOrganization(const Organization&)const;
	bool DeleteTournament(const Tournament&)const;
	bool DeleteMatch(const Match&)const;
	bool AddNewProfile(const Profile&)const;
	bool AddNewOrganization(const Organization&)const;
	bool AddNewTournament(const Tournament&)const;
	bool AddNewMatch(const Match&)const;
	bool EditProfile(const Profile&)const;
	bool EditOrganization(const Organization&)const;
	bool EditTournament(const Tournament&)const;
	bool EditMatch(const Match&)const;
	Profile GetActiveProfile(unsigned int uiActiveProfileID);
	std::vector<Profile> GetProfiles();
	std::vector<Organization> GetOrganizations();
private:
	DatabaseController();
	void LoadDataFromDB();
	void PrepareActiveProfile(unsigned int uiActiveProfileID);
	void LoadProfiles();
	void LoadOrganizations();
	void LoadTournaments();
	void LoadMatches();
	std::vector<Match> FindMatchesOfTournament(unsigned uiTournamentID)const;
	std::vector<Tournament> FindTournamentsOfOrganization(unsigned uiOrgID)const;
	std::vector<Tournament> FindTournamentsOfProfile(unsigned uiProfileID)const;
	std::vector<Organization> FindParticipatedOrgsOfProfile(unsigned uiProfileID)const;
	Profile m_ActiveProfile{};
	std::vector<Profile> m_vecProfile;
	std::vector<Organization> m_vecOrganization;
	std::vector<Tournament> m_vecTournament;
	std::vector<Match> m_vecMatch;
};

