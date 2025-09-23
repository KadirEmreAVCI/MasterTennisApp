#include <iostream>
#include <algorithm>
#include <Qlabel>
#include <QMessageBox>
#include "HomePage.h"
#include "AchievementsPage.h"
#include "HistoryPage.h"
#include "ProfileDialog.h"
#include "AppController.h"
#include "Utility.h"

ProfileDialog::ProfileDialog(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(&AppController::instance(), &AppController::DBInitialized, this, &ProfileDialog::DBInitialized);
	QObject::connect(&AppController::instance(), &AppController::ChangeInDB, this, &ProfileDialog::ChangeInDB);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &ProfileDialog::UserLoggedIn);
	CreateTabWidget();
	setFixedSize(1150, 800);
	ui.labelPP->setFixedSize(30, 30);
	ui.comboBoxProfiles->setFixedWidth(150);
	setWindowTitle(QString::fromStdString(AppController::instance().GetAppName()));
}

ProfileDialog::~ProfileDialog()
{}
void ProfileDialog::CreateTabWidget()
{
	while (ui.tabWidget->count() > 0) 
	{
		ui.tabWidget->removeTab(0);
	}
	ui.tabWidget->addTab(new HomePage(), QString("Home"));
	ui.tabWidget->addTab(new AchievementsPage(), QString("Achievements"));
	ui.tabWidget->addTab(new HistoryPage(), QString("History"));
}
void ProfileDialog::UpdateProfileAlternatives(const std::vector<Profile>& vecProfiles)
{
	m_vecProfile = vecProfiles;
	if (!m_vecProfile.empty())
	{
		std::vector<std::string> vecProfileNames;
		std::transform(m_vecProfile.cbegin(), m_vecProfile.cend(), std::back_inserter(vecProfileNames), [](const Profile& p) {
			return p.GetFullName();
			});
		if (!vecProfileNames.empty())
		{
			utility::SetComboBoxAlternatives(ui.comboBoxProfiles, vecProfileNames, false);
		}
	}
}
void ProfileDialog::UserLoggedIn(const Profile& p)
{
	m_ActiveProfile = p; 
	ui.tabWidget->setCurrentIndex(0);
	utility::InitComboBox(ui.comboBoxProfiles, QString::fromStdString(m_ActiveProfile.GetFullName()));
	utility::InitLabelWithPicture(ui.labelPP, (m_ActiveProfile.GetPPAddr() != "") ? (Profile::GetProfileImageRootDestDir().toStdString() + m_ActiveProfile.GetPPAddr()) : (Profile::GetProfileImageRootDestDir() + "default_profile.png").toStdString());
}
void ProfileDialog::DBInitialized(const std::vector<Profile>& vecProfiles, const std::vector<Organization>&)
{
	UpdateProfileAlternatives(vecProfiles);
}
void ProfileDialog::ChangeInDB(const std::vector<Profile>& vecProfile, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&)
{
	if(vecProfile != m_vecProfile)
	{
		UpdateProfileAlternatives(m_vecProfile);
	}
}
void ProfileDialog::on_LogOutButton_clicked()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Logging out", "Are you sure you want log out?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
		AppController::instance().OnLogOutButtonClicked();
		m_ActiveProfile = Profile{};
	}
}
void ProfileDialog::on_comboBoxProfiles_currentTextChanged(const QString& sProfileName)
{
	if (m_ActiveProfile.GetFullName() != "" && sProfileName.toStdString() != m_ActiveProfile.GetFullName())
	{
		utility::InitComboBox(ui.comboBoxProfiles, QString::fromStdString(m_ActiveProfile.GetFullName()));
		QMessageBox::StandardButton reply = QMessageBox::question(this, "Profile Switch", "Are you sure you want to switch the profile?", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			const auto& iterSwitchedProfile = std::find_if(m_vecProfile.cbegin(), m_vecProfile.cend(), [sProfileName](const Profile& p) {
				return p.GetFullName() == sProfileName.toStdString();
				});
			if (iterSwitchedProfile != m_vecProfile.end())
			{
				AppController::instance().LogInToProfile(*iterSwitchedProfile);
			}
		}
	}
}
