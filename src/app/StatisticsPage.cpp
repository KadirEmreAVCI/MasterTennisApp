#include "StatisticsPage.h"
#include "AppController.h"
#include "Utility.h"
StatisticsPage::StatisticsPage(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(&StatController::instance(), &StatController::CareerStatsUpdated, this, &StatisticsPage::UpdateCareerStats);
	QObject::connect(&StatController::instance(), &StatController::FinalsStatsUpdated, this, &StatisticsPage::UpdateFinalsStats);
	InitStatIcons();
	InitWinLoseLabels();
	ClearCareerStats();
	ClearFinalsStats();
	ClearMedalsAndTrophies();
}

StatisticsPage::~StatisticsPage()
{}
void StatisticsPage::InitStatIcons()
{
	std::cout << "StatisticsPage::InitStatIcons\n";
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
void StatisticsPage::InitWinLoseLabels()
{
	m_MatchLabels = WinLoseLabel{ ui.label_MatchWin, ui.label_MatchLose, ui.label_MatchWinRate };
	m_SetTBLabels = WinLoseLabel{ ui.label_SetTBWin, ui.label_SetTBLose, ui.label_SetTBWinRate };
	m_SuperTBLabels = WinLoseLabel{ ui.label_SuperTBWin, ui.label_SuperTBLose, ui.label_SuperTBWinRate };
	m_QuarterFinalsLabels = WinLoseLabel{ ui.label_QuarterFinalWin, ui.label_QuarterFinalLose, ui.label_QuarterFinalWinRate };
	m_SemiFinalsLabels = WinLoseLabel{ ui.label_SemiFinalsWin, ui.label_SemiFinalsLose, ui.label_SemiFinalsWinRate };
	m_3rdPlaceMatchLabels = WinLoseLabel{ ui.label_3rdPlaceMatchWin, ui.label_3rdPlaceMatchLose, ui.label_3rdPlaceMatchWinRate };
	m_FinalsLabels = WinLoseLabel{ ui.label_FinalsWin, ui.label_FinalsLose, ui.label_FinalsWinRate };
}
void StatisticsPage::ClearCareerStats()
{
	SetTournamentStats(0, 0);
	SetWLStat(m_MatchLabels);
	SetWLStat(m_SetTBLabels);
	SetWLStat(m_SuperTBLabels);
}
void StatisticsPage::ClearFinalsStats()
{
	SetWLStat(m_QuarterFinalsLabels);
	SetWLStat(m_SemiFinalsLabels);
	SetWLStat(m_3rdPlaceMatchLabels);
	SetWLStat(m_FinalsLabels);
}
void StatisticsPage::ClearMedalsAndTrophies()
{
	UpdateMedalsAndTrophies(StatReport{0, 0, 0.0f}, StatReport{0, 0, 0.0f});
}
void StatisticsPage::UpdateCareerStats(unsigned uiTotalTournament, unsigned uiTotalQualificationFromGroupStages, const std::vector<StatReport>& vecStatReport)
{
	ClearCareerStats();
	SetTournamentStats(uiTotalTournament, uiTotalQualificationFromGroupStages);
	size_t szIdx = 0;
	SetWLStat(m_MatchLabels, vecStatReport[szIdx++]);
	SetWLStat(m_SetTBLabels, vecStatReport[szIdx++]);
	SetWLStat(m_SuperTBLabels, vecStatReport[szIdx++]);
}
void StatisticsPage::UpdateFinalsStats(const std::vector<StatReport>& vecStatReport)
{
	constexpr size_t gTotalCareerStat = 3;
	constexpr size_t gTotalFinalStat = 4;
	ClearFinalsStats();
	size_t szIdx = 0;
	SetWLStat(m_QuarterFinalsLabels, vecStatReport[szIdx++]);
	SetWLStat(m_SemiFinalsLabels, vecStatReport[szIdx++]);
	SetWLStat(m_3rdPlaceMatchLabels, vecStatReport[szIdx++]);
	SetWLStat(m_FinalsLabels, vecStatReport[szIdx++]);
	UpdateMedalsAndTrophies(vecStatReport[gTotalFinalStat - 1], vecStatReport[gTotalFinalStat - 2]);
}
void StatisticsPage::UpdateMedalsAndTrophies(const StatReport& rFinalStatReport, const StatReport& r3rdPlaceGameStatReport)
{
	ui.label_1stPlace->setText(QString::fromStdString(std::to_string(rFinalStatReport.m_uiWin)));
	ui.label_2ndPlace->setText(QString::fromStdString(std::to_string(rFinalStatReport.m_uiLose)));
	ui.label_3rdPlace->setText(QString::fromStdString(std::to_string(r3rdPlaceGameStatReport.m_uiWin)));
}
void StatisticsPage::SetTournamentStats(unsigned uiTotalTournament, unsigned uiTotalQualificationFromGroupStages)
{
	ui.label_TotalTournament->setText(QString::fromStdString(std::to_string(uiTotalTournament)));
	ui.label_QualifiedFromGroupStage->setText(QString::fromStdString(std::to_string(uiTotalQualificationFromGroupStages)));
}
void StatisticsPage::SetWLStat(WinLoseLabel wlLabels, StatReport rStatReport)
{
	wlLabels.m_lblWin->setText(QString::fromStdString(std::to_string(rStatReport.m_uiWin)));
	wlLabels.m_lblLose->setText(QString::fromStdString(std::to_string(rStatReport.m_uiLose)));
	wlLabels.m_lblWinRate->setText("(" + QString::fromStdString(std::format("{:.1f}", rStatReport.m_fWinRatePercentage)) + "% Win Rate)");
}