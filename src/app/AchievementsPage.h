#ifndef ACHIEVEMENTS_PAGE_H
#define ACHIEVEMENTS_PAGE_H

// Project Headers
#include "StatController.h"
#include "StatWidget.h"

// Standard Headers
#include <memory>

#include <QWidget>
#include "ui_AchievementsPage.h"

class AchievementsPage : public QWidget{
	Q_OBJECT

public:
	AchievementsPage(QWidget *parent = nullptr);
	~AchievementsPage();
private:
	void InitStatWidgets();
	void InitPictures();
	void UpdateCareerStats(const std::vector<StatReport>&);
	void UpdateMedalsAndTrophies(const StatReport& rFinalStat, const StatReport& r3rdPlaceGameStat);
	void AddStatWidget(const std::unique_ptr<StatWidget>& upStatWidget, unsigned idx);
	Ui::AchievementsPageClass ui;
	std::unique_ptr<StatWidget> m_upMatchesStatWidget{std::make_unique<StatWidget>(this)};
	std::unique_ptr<StatWidget> m_upMatchTiebreaksStatWidget{std::make_unique<StatWidget>(this)};
	std::unique_ptr<StatWidget> m_upSetTiebreaksStatWidget{std::make_unique<StatWidget>(this)};
	std::unique_ptr<StatWidget> m_upQuarterFinalsStatWidget{std::make_unique<StatWidget>(this)};
	std::unique_ptr<StatWidget> m_upSemiFinalsStatWidget{std::make_unique<StatWidget>(this)};
	std::unique_ptr<StatWidget> m_up3rdPlaceGamesStatWidget{std::make_unique<StatWidget>(this)};
	std::unique_ptr<StatWidget> m_upFinalsStatWidget{std::make_unique<StatWidget>(this)};
};

#endif