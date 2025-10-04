#include "AchievementsPage.h"
#include "AppController.h"
#include "StatController.h"
#include "Utility.h"
AchievementsPage::AchievementsPage(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &AchievementsPage::UserLoggedIn);
	QObject::connect(&AppController::instance(), &AppController::ChangeInDB, this, &AchievementsPage::ChangeInDB);
	InitPictures();
	InitStatWidgets();
}
AchievementsPage::~AchievementsPage()
{}
void AchievementsPage::TournamentCategoryChanged(const std::string& sTournamentCategory)
{
	m_sTournamentCategory = sTournamentCategory;
}
void AchievementsPage::TournamentCategoryCleared()
{
	m_sTournamentCategory = "";
}
void AchievementsPage::InitStatWidgets()
{
	const float fStatPictureScale = 1.1f;
	m_upMatchesStatWidget->InitWidget("Matches:", ":images/crossed_swords.png", fStatPictureScale);
	m_upMatchTiebreaksStatWidget->InitWidget("Match Tiebreaks:", ":images/clutchness.png", fStatPictureScale);
	m_upSetTiebreaksStatWidget->InitWidget("Set Tiebreaks:", ":images/setTB.png", fStatPictureScale);
	m_upQuarterFinalsStatWidget->InitWidget("Quarter Finals:", ":images/trophy.png", fStatPictureScale);
	m_upSemiFinalsStatWidget->InitWidget("Semi Finals:", ":images/trophy.png", fStatPictureScale);
	m_up3rdPlaceGamesStatWidget->InitWidget("3rd Place Games:", ":images/trophy.png", fStatPictureScale);
	m_upFinalsStatWidget->InitWidget("Finals:", ":images/trophy.png", fStatPictureScale);
	size_t idxRow = 0;
	AddStatWidget(m_upMatchesStatWidget, idxRow++);
	AddStatWidget(m_upMatchTiebreaksStatWidget, idxRow++);
	AddStatWidget(m_upSetTiebreaksStatWidget, idxRow++);
	AddStatWidget(m_upQuarterFinalsStatWidget, idxRow++);
	AddStatWidget(m_upSemiFinalsStatWidget, idxRow++);
	AddStatWidget(m_up3rdPlaceGamesStatWidget, idxRow++);
	AddStatWidget(m_upFinalsStatWidget, idxRow++);
}
void AchievementsPage::InitPictures()
{
	using namespace utility;
	const float fMedalPictureScale = 3.0f;
	InitLabelWithPicture(ui.label_Icon1stPlace, ":images/first_place.png", fMedalPictureScale);
	InitLabelWithPicture(ui.label_Icon2ndPlace, ":images/second_place.png", fMedalPictureScale);
	InitLabelWithPicture(ui.label_Icon3rdPlace, ":images/third_place.png", fMedalPictureScale);
	InitLabelWithPicture(ui.label_IconAchievements, ":images/achievements_page.png", 12.0f);
}
void AchievementsPage::UpdateCareerStats(const std::vector<StatReport>& vecStatReport)
{
	size_t idx = 0;
	m_upMatchesStatWidget->FillWidget(vecStatReport[idx++]);
	m_upMatchTiebreaksStatWidget->FillWidget(vecStatReport[idx++]);
	m_upSetTiebreaksStatWidget->FillWidget(vecStatReport[idx++]);
	m_upQuarterFinalsStatWidget->FillWidget(vecStatReport[idx++]);
	m_upSemiFinalsStatWidget->FillWidget(vecStatReport[idx++]);
	const StatReport r3rdPlaceGameStatReport = vecStatReport[idx];
	m_up3rdPlaceGamesStatWidget->FillWidget(vecStatReport[idx++]);
	const StatReport rFinalStatReport = vecStatReport[idx];
	m_upFinalsStatWidget->FillWidget(vecStatReport[idx++]);
	UpdateMedalsAndTrophies(rFinalStatReport, r3rdPlaceGameStatReport);
}
void AchievementsPage::UpdateMedalsAndTrophies(const StatReport& rFinalStatReport, const StatReport& r3rdPlaceGameStatReport)
{
	ui.label_1stPlace->setText(QString::fromStdString(std::to_string(rFinalStatReport.m_uiWin)));
	ui.label_2ndPlace->setText(QString::fromStdString(std::to_string(rFinalStatReport.m_uiLose)));
	ui.label_3rdPlace->setText(QString::fromStdString(std::to_string(r3rdPlaceGameStatReport.m_uiWin)));
}
void AchievementsPage::AddStatWidget(const std::unique_ptr<StatWidget>& upStatWidget, unsigned idxRow)
{
	size_t idxColumn = 0;
	ui.gridLayout_CareerStats->addWidget(upStatWidget->GetLabelIcon(), 			idxRow, idxColumn++);
	ui.gridLayout_CareerStats->addWidget(upStatWidget->GetLabelStatName(), 		idxRow, idxColumn++);
	ui.gridLayout_CareerStats->addItem(new QSpacerItem(60, 0, QSizePolicy::Expanding, QSizePolicy::Minimum), 0, idxColumn++);
	ui.gridLayout_CareerStats->addWidget(upStatWidget->GetLabelWinText(), 		idxRow, idxColumn++);
	ui.gridLayout_CareerStats->addWidget(upStatWidget->GetLabelWin(), 			idxRow, idxColumn++);
	ui.gridLayout_CareerStats->addItem(new QSpacerItem(15, 0, QSizePolicy::Expanding, QSizePolicy::Minimum), 0, idxColumn++);
	ui.gridLayout_CareerStats->addWidget(upStatWidget->GetLabelLoseText(), 		idxRow, idxColumn++);
	ui.gridLayout_CareerStats->addWidget(upStatWidget->GetLabelLose(), 			idxRow, idxColumn++);
	ui.gridLayout_CareerStats->addItem(new QSpacerItem(15, 0, QSizePolicy::Expanding, QSizePolicy::Minimum), 0, idxColumn++);
	ui.gridLayout_CareerStats->addWidget(upStatWidget->GetLabelWinRateText(), 	idxRow, idxColumn++);
	ui.gridLayout_CareerStats->addWidget(upStatWidget->GetLabelWinRate(), 		idxRow, idxColumn++);
	ui.gridLayout_CareerStats->addItem(new QSpacerItem(15, 0, QSizePolicy::Expanding, QSizePolicy::Minimum), 0, idxColumn++);
}
void AchievementsPage::ChangeInDB(const std::vector<Profile>& vecProfile, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&)
{
	const auto activeProfile = std::find_if(vecProfile.cbegin(), vecProfile.cend(), [this](const Profile& p) {
		return p.GetID() == m_uiProfileID;
		});
	if (activeProfile != vecProfile.cend())
	{
		UpdateCareerStats(m_upStatController->GetUpdatedCareerStats(*activeProfile));
	}
}
void AchievementsPage::UserLoggedIn(const Profile& p)
{
	m_uiProfileID = p.GetID();
	UpdateCareerStats(m_upStatController->GetUpdatedCareerStats(p));
}