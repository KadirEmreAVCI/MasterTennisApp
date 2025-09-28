#ifndef ACHIEVEMENTS_PAGE_H
#define ACHIEVEMENTS_PAGE_H

#include <QWidget>
#include "ui_AchievementsPage.h"
#include "StatController.h"
struct WinLoseLabels {
	WinLoseLabels() = default;
	WinLoseLabels(QLabel* lblWin, QLabel* lblLose, QLabel* lblWinRate) : m_lblWin{ lblWin }, m_lblLose{ lblLose }, m_lblWinRate{ lblWinRate }
	{}
	QLabel* m_lblWin = nullptr;
	QLabel* m_lblLose = nullptr;
	QLabel* m_lblWinRate = nullptr;
};
class AchievementsPage : public QWidget{
	Q_OBJECT

public:
	AchievementsPage(QWidget *parent = nullptr);
	~AchievementsPage();
private:
	void InitStatIcons();
	void InitWinLoseLabels();
	void ClearCareerStats();
	void ClearFinalsStats();
	void ClearMedalsAndTrophies();
	void UpdateCareerStats(unsigned uiTotalTournament, unsigned uiTotalQualificationFromGroupStages, const std::vector<StatReport>&);
	void UpdateFinalsStats(const std::vector<StatReport>&); 
	void UpdateMedalsAndTrophies(const StatReport& rFinalStat, const StatReport& r3rdPlaceGameStat);
	void SetTournamentStats(unsigned uiTotalTournament, unsigned uiTotalQualificationFromGroupStages);
	void SetStatReport(WinLoseLabels, StatReport = {0, 0, 0.0f});
	Ui::AchievementsPageClass ui;
	WinLoseLabels m_MatchLabels;
	WinLoseLabels m_SetTBLabels;
	WinLoseLabels m_SuperTBLabels;
	WinLoseLabels m_QuarterFinalsLabels;
	WinLoseLabels m_SemiFinalsLabels;
	WinLoseLabels m_3rdPlaceMatchLabels;
	WinLoseLabels m_FinalsLabels;
};

#endif