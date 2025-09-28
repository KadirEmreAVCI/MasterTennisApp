#ifndef STATISTICS_PAGE_H
#define STATISTICS_PAGE_H

#include <QWidget>
#include "ui_StatisticsPage.h"
#include "StatController.h"
struct WinLoseLabel {
	WinLoseLabel() = default;
	WinLoseLabel(QLabel* lblWin, QLabel* lblLose, QLabel* lblWinRate) : m_lblWin{ lblWin }, m_lblLose{ lblLose }, m_lblWinRate{ lblWinRate }
	{}
	QLabel* m_lblWin = nullptr;
	QLabel* m_lblLose = nullptr;
	QLabel* m_lblWinRate = nullptr;
};
class StatisticsPage : public QWidget{
	Q_OBJECT

public:
	StatisticsPage(QWidget* parent = nullptr);
	~StatisticsPage();
private:
	void InitStatIcons();
	void InitWinLoseLabels();
	void ClearCareerStats();
	void ClearFinalsStats();
	void ClearMedalsAndTrophies();
	void UpdateCareerStats(unsigned uiTotalTournament, unsigned uiTotalQualificationFromGroupStages, const std::vector<StatReport>&);
	void UpdateFinalsStats(const std::vector<StatReport>&);
	void UpdateMedalsAndTrophies(const StatReport& rFinalStatReport, const StatReport& r3rdPlaceGameStatReport);
	void SetTournamentStats(unsigned uiTotalTournament, unsigned uiTotalQualificationFromGroupStages);
	void SetWLStat(WinLoseLabel, StatReport = {0, 0, 0.0f});
	Ui::StatisticsPageClass ui;
	WinLoseLabel m_MatchLabels;
	WinLoseLabel m_SetTBLabels;
	WinLoseLabel m_SuperTBLabels;
	WinLoseLabel m_QuarterFinalsLabels;
	WinLoseLabel m_SemiFinalsLabels;
	WinLoseLabel m_3rdPlaceMatchLabels;
	WinLoseLabel m_FinalsLabels;
};

#endif 