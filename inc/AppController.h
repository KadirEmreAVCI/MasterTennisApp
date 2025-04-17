#pragma once
#include <memory>
#include <string>
#include <vector>
#include <QObject>
#include "ProfileDialog.h"
#include "Profile.h"

class GUIConfigurator;
class TennisDesktopApp;
class AppController : public QObject {
	Q_OBJECT
public: 
	static void create();
	static AppController& instance();
	AppController(const AppController&) = delete;
	AppController& operator=(const AppController&) = delete;
	~AppController();
	void StartApplication();
	std::string GetAppName()const; 
	std::string GetAppLogoAddr()const;
	void LogInToProfile(const Profile&);
	bool AddNewProfile(const Profile&);
	bool AddNewOrganization(const Organization&);
	bool AddNewTournament(const Tournament&);
	bool AddNewMatch(const Match&);
	bool DeleteProfile(const Profile&);
	bool DeleteOrganization(const Organization&);
	bool DeleteTournament(const Tournament&);
	bool DeleteMatch(const Match&);
	bool EditProfile(const Profile&);
	bool EditOrganization(const Organization&);
	bool EditTournament(const Tournament&);
	bool EditMatch(const Match&);
private:
	AppController();
	static AppController* ms_pAppController;
	std::unique_ptr<TennisDesktopApp> m_upTennisDesktopApp{ nullptr }; 
	std::unique_ptr<ProfileDialog> m_upProfileDialog{ nullptr };
	std::string m_sAppName{"Master Tennis App"};
	std::string m_sAppLogoAddr{":images/images/Logo1.png"};
	Profile m_ActiveProfile{};
public slots:
	void OnLogOutButtonClicked();
signals:
	// Signal functions are just declared, not defined by programmers!
	void InitProfiles(const std::vector<Profile>&);
	void InitOrganizations(const std::vector<Organization>&);
	void UserLoggedIn(const Profile&);
	void UserLoggedOut();
	void ChangeInActiveProfile(const Profile&);
	void ChangeInProfiles(const std::vector<Profile>&);
	void ChangeInOrganizations(const std::vector<Organization>&);
};

