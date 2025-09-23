#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <memory>
#include <string>
#include <vector>
#include <QObject>
#include "ProfileDialog.h"
#include "DatabaseController.h"

class GUIConfigurator;
class MasterTennisApp;
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
	template<typename T>
	bool AddNewItem(const T& item)
	{
		const bool bItemAdded = DatabaseController::instance().AddNewDBItem<T>(item);
		if (bItemAdded)
		{
			emit ChangeInDB(DatabaseController::instance().GetProfiles(), 
							DatabaseController::instance().GetOrganizations(), 
							DatabaseController::instance().GetTournaments(), 
							DatabaseController::instance().GetMatches());
		}
		return bItemAdded;
	}
	template<typename T>
	bool DeleteItem(const T& item)
	{
		const bool bItemDeleted = DatabaseController::instance().DeleteDBItem<T>(item);
		if (bItemDeleted)
		{
			emit ChangeInDB(DatabaseController::instance().GetProfiles(), 
							DatabaseController::instance().GetOrganizations(), 
							DatabaseController::instance().GetTournaments(), 
							DatabaseController::instance().GetMatches());
		}
		return bItemDeleted;
	}
	template<typename T>
	bool EditItem(const T& item)
	{
		const bool bItemEdited = DatabaseController::instance().EditDBItem<T>(item);
		if (bItemEdited)
		{
			emit ChangeInDB(DatabaseController::instance().GetProfiles(), 
							DatabaseController::instance().GetOrganizations(), 
							DatabaseController::instance().GetTournaments(), 
							DatabaseController::instance().GetMatches());
		}
		return bItemEdited;
	}
private:
	AppController();
	static AppController* ms_pAppController;
	std::unique_ptr<MasterTennisApp> m_upMasterTennisApp{ nullptr }; 
	std::unique_ptr<ProfileDialog> m_upProfileDialog{ nullptr };
	std::string m_sAppName{"Master Tennis App"};
	std::string m_sAppLogoAddr{":images/Logo1.png"};
	Profile m_ActiveProfile;
public slots:
	void OnLogOutButtonClicked();
signals:
	// Signal functions are just declared, not defined by programmers!
	void DBInitialized(const std::vector<Profile>&, const std::vector<Organization>&);
	void UserLoggedIn(const Profile&);
	void UserLoggedOut();
	void ChangeInDB(const std::vector<Profile>&, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&);
};

#endif