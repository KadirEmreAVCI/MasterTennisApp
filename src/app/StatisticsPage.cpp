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
	InitPicture(ui.label_IconTournament, ":images/crossed_swords.png", 1.0f);
	InitPicture(ui.label_IconMatches, ":images/games.png", 1.0f);
	InitPicture(ui.label_IconSetTB, ":images/setTB.png", 1.0f);
	InitPicture(ui.label_IconSuperTB, ":images/clutchness.png", 1.0f);
	InitPicture(ui.label_IconQuarterFinals, ":images/trophy.png", 0.9f);
	InitPicture(ui.label_IconSemiFinals, ":images/trophy.png", 0.9f);
	InitPicture(ui.label_Icon3rdPlaceMatch, ":images/trophy.png", 0.9f);
	InitPicture(ui.label_IconFinals, ":images/trophy.png", 0.9f);
	InitPicture(ui.label_Icon1stPlace, ":images/first_place.png", 3.0f);
	InitPicture(ui.label_Icon2ndPlace, ":images/second_place.png", 3.0f);
	InitPicture(ui.label_Icon3rdPlace, ":images/third_place.png", 3.0f);
	InitPicture(ui.label_IconAchievements, ":images/achievements_page.png", 12.0f);
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
	SetWLStat(m_MatchLabels, WinLoseStat{});
	SetWLStat(m_SetTBLabels, WinLoseStat{});
	SetWLStat(m_SuperTBLabels, WinLoseStat{});
}
void StatisticsPage::ClearFinalsStats()
{
	SetWLStat(m_QuarterFinalsLabels, WinLoseStat{});
	SetWLStat(m_SemiFinalsLabels, WinLoseStat{});
	SetWLStat(m_3rdPlaceMatchLabels, WinLoseStat{});
	SetWLStat(m_FinalsLabels, WinLoseStat{});
}
void StatisticsPage::ClearMedalsAndTrophies()
{
	UpdateMedalsAndTrophies(WinLoseStat{}, WinLoseStat{});
}
void StatisticsPage::UpdateCareerStats(unsigned uiTotalTournament, unsigned uiTotalQualificationFromGroupStages, const std::array<WinLoseStat, gTotalCareerStat>& arrWLStats)
{
	ClearCareerStats();
	SetTournamentStats(uiTotalTournament, uiTotalQualificationFromGroupStages);
	size_t szIdx = 0;
	SetWLStat(m_MatchLabels, arrWLStats[szIdx++]);
	SetWLStat(m_SetTBLabels, arrWLStats[szIdx++]);
	SetWLStat(m_SuperTBLabels, arrWLStats[szIdx++]);
}
void StatisticsPage::UpdateFinalsStats(const std::array<WinLoseStat, gTotalFinalStat>& arrWLStats)
{
	ClearFinalsStats();
	size_t szIdx = 0;
	SetWLStat(m_QuarterFinalsLabels, arrWLStats[szIdx++]);
	SetWLStat(m_SemiFinalsLabels, arrWLStats[szIdx++]);
	SetWLStat(m_3rdPlaceMatchLabels, arrWLStats[szIdx++]);
	SetWLStat(m_FinalsLabels, arrWLStats[szIdx++]);
	UpdateMedalsAndTrophies(arrWLStats[gTotalFinalStat - 1], arrWLStats[gTotalFinalStat - 2]);
}
void StatisticsPage::UpdateMedalsAndTrophies(const WinLoseStat& wlFinalStat, const WinLoseStat& wl3rdPlaceGameStat)
{
	ui.label_1stPlace->setText(QString::fromStdString(std::to_string(wlFinalStat.GetWin())));
	ui.label_2ndPlace->setText(QString::fromStdString(std::to_string(wlFinalStat.GetLose())));
	ui.label_3rdPlace->setText(QString::fromStdString(std::to_string(wl3rdPlaceGameStat.GetWin())));
}
void StatisticsPage::SetTournamentStats(unsigned uiTotalTournament, unsigned uiTotalQualificationFromGroupStages)
{
	ui.label_TotalTournament->setText(QString::fromStdString(std::to_string(uiTotalTournament)));
	ui.label_QualifiedFromGroupStage->setText(QString::fromStdString(std::to_string(uiTotalQualificationFromGroupStages)));
}
void StatisticsPage::SetWLStat(WinLoseLabel wlLabels, WinLoseStat wlstat)
{
	wlLabels.m_lblWin->setText(QString::fromStdString(std::to_string(wlstat.GetWin())));
	wlLabels.m_lblLose->setText(QString::fromStdString(std::to_string(wlstat.GetLose())));
	wlLabels.m_lblWinRate->setText("(" + QString::fromStdString(std::format("{:.1f}", wlstat.GetWinRatePercentage())) + "% Win Rate)");
}