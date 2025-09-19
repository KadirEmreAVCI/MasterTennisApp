#include <iostream>
#include <algorithm>
#include "AppController.h"
#include "MasterTennisApp.h"
#include "StatController.h"
#include "DatabaseController.h"
#include "SQLiteDB.h"

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

}
AppController::~AppController()
{

}
void AppController::StartApplication()
{
	QApplication::setWindowIcon(QIcon(QString::fromStdString(m_sAppLogoAddr)));
	Organization::SetOrgImageRootDestDir(QCoreApplication::applicationDirPath() + "/../../src/app/resources/organizations/");
	Profile::SetProfileImageRootDestDir(QCoreApplication::applicationDirPath() + "/../../src/app/resources/profiles/");
	DatabaseController::instance().InitDatabase(std::make_shared<SQLiteDB>((QCoreApplication::applicationDirPath() + "/../../database/MasterTennisApp.db").toStdString()));
	m_upMasterTennisApp = std::make_unique<MasterTennisApp>();
	m_upProfileDialog = std::make_unique<ProfileDialog>();
	StatController::create();
	m_upMasterTennisApp->show();
	emit InitProfiles(DatabaseController::instance().GetProfiles());
	emit InitOrganizations(DatabaseController::instance().GetOrganizations());
}
std::string AppController::GetAppName()const
{
	return m_sAppName;
}
std::string AppController::GetAppLogoAddr()const
{
	return m_sAppLogoAddr;
}
void AppController::LogInToProfile(const Profile& profile)
{
	const bool blAlreadyLoggedIn = m_ActiveProfile != Profile{};
	m_ActiveProfile = DatabaseController::instance().GetActiveProfile(profile.GetID());
	emit UserLoggedIn(m_ActiveProfile);
	if (!blAlreadyLoggedIn)
	{
		m_upMasterTennisApp->hide();
		m_upProfileDialog->setModal(true);
		m_upProfileDialog->exec();
	}
}
bool AppController::AddNewProfile(const Profile& p)
{
	const bool blProfileAdded = DatabaseController::instance().AddNewDBItem<Profile>(p);
	if (blProfileAdded)
	{
		emit ChangeInProfiles(DatabaseController::instance().GetProfiles());
	}
	return blProfileAdded;
}
bool AppController::AddNewOrganization(const Organization& org)
{
	const bool blOrgAdded = DatabaseController::instance().AddNewDBItem<Organization>(org);
	if (blOrgAdded)
	{
		emit ChangeInOrganizations(DatabaseController::instance().GetOrganizations());
	}
	return blOrgAdded;
}
bool AppController::AddNewTournament(const Tournament& t)
{
	const bool blTournamentAdded = DatabaseController::instance().AddNewDBItem<Tournament>(t);
	if (blTournamentAdded)
	{
		emit ChangeInActiveProfile(DatabaseController::instance().GetActiveProfile(m_ActiveProfile.GetID()));
	}
	return blTournamentAdded;
}
bool AppController::AddNewMatch(const Match& m)
{
	const bool blNewMatchAdded = DatabaseController::instance().AddNewDBItem<Match>(m);
	if (blNewMatchAdded)
	{
		emit ChangeInActiveProfile(DatabaseController::instance().GetActiveProfile(m_ActiveProfile.GetID()));
	}
	return blNewMatchAdded;
}
bool AppController::DeleteProfile(const Profile& p)
{
	const bool blDeletion = DatabaseController::instance().DeleteProfile(p);
	if (blDeletion)
	{
		emit ChangeInProfiles(DatabaseController::instance().GetProfiles());
	}
	return blDeletion;
}
bool AppController::DeleteOrganization(const Organization& org)
{
	const bool blDeletion = DatabaseController::instance().DeleteOrganization(org);
	if (blDeletion)
	{
		emit ChangeInOrganizations(DatabaseController::instance().GetOrganizations());
	}
	return blDeletion;
}
bool AppController::DeleteTournament(const Tournament& t)
{
	const bool blDeletion = DatabaseController::instance().DeleteTournament(t);
	if (blDeletion)
	{
		emit ChangeInActiveProfile(DatabaseController::instance().GetActiveProfile(m_ActiveProfile.GetID()));
	}
	return blDeletion;
}
bool AppController::DeleteMatch(const Match& m)
{
	const bool blDeletion = DatabaseController::instance().DeleteMatch(m);
	if (blDeletion)
	{
		emit ChangeInActiveProfile(DatabaseController::instance().GetActiveProfile(m_ActiveProfile.GetID()));
	}
	return blDeletion;
}
bool AppController::EditProfile(const Profile& p)
{
	const bool blProfileEdited = DatabaseController::instance().EditDBItem<Profile>(p);
	if (blProfileEdited)
	{
		emit ChangeInProfiles(DatabaseController::instance().GetProfiles());
	}
	return blProfileEdited;
}
bool AppController::EditOrganization(const Organization& org)
{
	const bool blOrganizationEdited = DatabaseController::instance().EditDBItem<Organization>(org);
	if (blOrganizationEdited)
	{
		emit ChangeInOrganizations(DatabaseController::instance().GetOrganizations());
	}
	return blOrganizationEdited;
}
bool AppController::EditTournament(const Tournament& t)
{
	const bool blTournamentEdited = DatabaseController::instance().EditDBItem<Tournament>(t);
	if (blTournamentEdited)
	{
		emit ChangeInActiveProfile(DatabaseController::instance().GetActiveProfile(m_ActiveProfile.GetID()));
	}
	return blTournamentEdited;
}
bool AppController::EditMatch(const Match& m)
{
	const bool blMatchEdited = DatabaseController::instance().EditDBItem<Match>(m);
	if (blMatchEdited)
	{
		emit ChangeInActiveProfile(DatabaseController::instance().GetActiveProfile(m_ActiveProfile.GetID()));
	}
	return blMatchEdited;
}
void AppController::OnLogOutButtonClicked()
{
	emit UserLoggedOut();
	m_ActiveProfile = Profile{};
	m_upProfileDialog->hide();
	m_upMasterTennisApp->show();	
}