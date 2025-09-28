#include "AchievementsPage.h"
#include "AppController.h"
#include "Utility.h"
AchievementsPage::AchievementsPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(&StatController::instance(), &StatController::CareerStatsUpdated, this, &AchievementsPage::UpdateCareerStats);
	QObject::connect(&StatController::instance(), &StatController::FinalsStatsUpdated, this, &AchievementsPage::UpdateFinalsStats);
	InitStatIcons();
	InitWinLoseLabels();
	ClearCareerStats();
	ClearFinalsStats();
	ClearMedalsAndTrophies();
}

AchievementsPage::~AchievementsPage()
{}
void AchievementsPage::InitStatIcons()
{
	std::cout << "AchievementsPage::InitStatIcons\n";
	using namespace utility;
	InitLabelWithPicture(ui.label_IconTournament, ":images/crossed_swords.png", 1.0f);
	InitLabelWithPicture(ui.label_IconMatches, ":images/games.png", 1.0f);
	InitLabelWithPicture(ui.label_IconSetTB, ":images/setTB.png", 1.0f);
	InitLabelWithPicture(ui.label_IconSuperTB, ":images/clutchness.png", 1.0f);
	InitLabelWithPicture(ui.label_IconQuarterFinals, ":images/trophy.png", 0.9f);
	InitLabelWithPicture(ui.label_IconSemiFinals, ":images/trophy.png", 0.9f);
	InitLabelWithPicture(ui.label_Icon3rdPlaceMatch, ":images/trophy.png", 0.9f);
	InitLabelWithPicture(ui.label_IconFinals, ":images/trophy.png", 0.9f);
	InitLabelWithPicture(ui.label_Icon1stPlace, ":images/first_place.png", 3.0f);
	InitLabelWithPicture(ui.label_Icon2ndPlace, ":images/second_place.png", 3.0f);
	InitLabelWithPicture(ui.label_Icon3rdPlace, ":images/third_place.png", 3.0f);
	InitLabelWithPicture(ui.label_IconAchievements, ":images/achievements_page.png", 12.0f);
}
void AchievementsPage::InitWinLoseLabels()
{
	m_MatchLabels = WinLoseLabels{ ui.label_MatchWin, ui.label_MatchLose, ui.label_MatchWinRate };
	m_SetTBLabels = WinLoseLabels{ ui.label_SetTBWin, ui.label_SetTBLose, ui.label_SetTBWinRate };
	m_SuperTBLabels = WinLoseLabels{ ui.label_SuperTBWin, ui.label_SuperTBLose, ui.label_SuperTBWinRate };
	m_QuarterFinalsLabels = WinLoseLabels{ ui.label_QuarterFinalWin, ui.label_QuarterFinalLose, ui.label_QuarterFinalWinRate };
	m_SemiFinalsLabels = WinLoseLabels{ ui.label_SemiFinalsWin, ui.label_SemiFinalsLose, ui.label_SemiFinalsWinRate };
	m_3rdPlaceMatchLabels = WinLoseLabels{ ui.label_3rdPlaceMatchWin, ui.label_3rdPlaceMatchLose, ui.label_3rdPlaceMatchWinRate };
	m_FinalsLabels = WinLoseLabels{ ui.label_FinalsWin, ui.label_FinalsLose, ui.label_FinalsWinRate };
}
void AchievementsPage::ClearCareerStats()
{
	SetTournamentStats(0,0);
	SetStatReport(m_MatchLabels);
	SetStatReport(m_SetTBLabels);
	SetStatReport(m_SuperTBLabels);
}
void AchievementsPage::ClearFinalsStats()
{
	SetStatReport(m_QuarterFinalsLabels);
	SetStatReport(m_SemiFinalsLabels);
	SetStatReport(m_3rdPlaceMatchLabels);
	SetStatReport(m_FinalsLabels);
}
void AchievementsPage::ClearMedalsAndTrophies()
{
	UpdateMedalsAndTrophies(StatReport{0, 0, 0.0f}, StatReport{0, 0, 0.0f});
}
void AchievementsPage::UpdateCareerStats(unsigned uiTotalTournament, unsigned uiTotalQualificationFromGroupStages, const std::vector<StatReport>& vecStatReport)
{
	ClearCareerStats();
	SetTournamentStats(uiTotalTournament, uiTotalQualificationFromGroupStages);
	size_t szIdx = 0;
	SetStatReport(m_MatchLabels, vecStatReport[szIdx++]);
	SetStatReport(m_SetTBLabels, vecStatReport[szIdx++]);
	SetStatReport(m_SuperTBLabels, vecStatReport[szIdx++]);
}
void AchievementsPage::UpdateFinalsStats(const std::vector<StatReport>& vecStatReport)
{
	constexpr size_t gTotalCareerStat = 3;
	constexpr size_t gTotalFinalStat = 4;
	ClearFinalsStats();
	size_t szIdx = 0;
	SetStatReport(m_QuarterFinalsLabels, vecStatReport[szIdx++]);
	SetStatReport(m_SemiFinalsLabels, vecStatReport[szIdx++]);
	SetStatReport(m_3rdPlaceMatchLabels, vecStatReport[szIdx++]);
	SetStatReport(m_FinalsLabels, vecStatReport[szIdx++]);
	UpdateMedalsAndTrophies(vecStatReport[gTotalFinalStat -1], vecStatReport[gTotalFinalStat - 2]);
}
void AchievementsPage::UpdateMedalsAndTrophies(const StatReport& rFinalStatReport, const StatReport& r3rdPlaceGameStatReport)
{
	ui.label_1stPlace->setText(QString::fromStdString(std::to_string(rFinalStatReport.m_uiWin)));
	ui.label_2ndPlace->setText(QString::fromStdString(std::to_string(rFinalStatReport.m_uiLose)));
	ui.label_3rdPlace->setText(QString::fromStdString(std::to_string(r3rdPlaceGameStatReport.m_uiWin)));
}
void AchievementsPage::SetTournamentStats(unsigned uiTotalTournament, unsigned uiTotalQualificationFromGroupStages)
{
	ui.label_TotalTournament->setText(QString::fromStdString(std::to_string(uiTotalTournament)));
	ui.label_QualifiedFromGroupStage->setText(QString::fromStdString(std::to_string(uiTotalQualificationFromGroupStages)));
}
void AchievementsPage::SetStatReport(WinLoseLabels wlLabels, StatReport rStatReport)
{
	wlLabels.m_lblWin->setText(QString::fromStdString(std::to_string(rStatReport.m_uiWin)));
	wlLabels.m_lblLose->setText(QString::fromStdString(std::to_string(rStatReport.m_uiLose)));
	wlLabels.m_lblWinRate->setText("(" + QString::fromStdString(std::format("{:.1f}", rStatReport.m_fWinRatePercentage)) + "% Win Rate)");
}