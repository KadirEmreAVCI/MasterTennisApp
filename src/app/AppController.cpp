#include <iostream>
#include <algorithm>
#include "AppController.h"
#include "MasterTennisApp.h"
#include "StatController.h"
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
	emit DBInitialized(DatabaseController::instance().GetProfiles(), DatabaseController::instance().GetOrganizations());
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
	const bool blAlreadyLoggedIn = (m_ActiveProfile != Profile{});
	auto vecProfile = DatabaseController::instance().GetProfiles();
	auto iterActiveProfile = std::find_if(vecProfile.cbegin(), vecProfile.cend(), [profile](const auto& p) {
		return p.GetID() == profile.GetID();
		});
	if (iterActiveProfile == vecProfile.cend())
	{
		std::cerr << "AppController::LoadActiveProfile active profile could not be found!\n";
	}
	else
	{
		m_ActiveProfile = *iterActiveProfile;
	}
	emit UserLoggedIn(m_ActiveProfile);
	if (!blAlreadyLoggedIn)
	{
		m_upMasterTennisApp->hide();
		m_upProfileDialog->setModal(true);
		m_upProfileDialog->exec();
	}
}
void AppController::OnLogOutButtonClicked()
{
	emit UserLoggedOut();
	m_ActiveProfile = Profile{};
	m_upProfileDialog->hide();
	m_upMasterTennisApp->show();	
}