#ifndef ACHIEVEMENTS_PAGE_H
#define ACHIEVEMENTS_PAGE_H

// Project Headers
#include "StatController.h"
#include "StatWidget.h"

// Standard Headers
#include <memory>

#include <QWidget>
#include "ui_AchievementsPage.h"

class StatController;

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
	void UserLoggedIn(const Profile&);
	void ChangeInDB(const std::vector<Profile>&, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&);
	Ui::AchievementsPageClass ui;
	unsigned m_uiProfileID = 0;
	std::unique_ptr<StatController> m_upStatController{std::make_unique<StatController>()};
	std::unique_ptr<StatWidget> m_upMatchesStatWidget{std::make_unique<StatWidget>(this)};
	std::unique_ptr<StatWidget> m_upMatchTiebreaksStatWidget{std::make_unique<StatWidget>(this)};
	std::unique_ptr<StatWidget> m_upSetTiebreaksStatWidget{std::make_unique<StatWidget>(this)};
	std::unique_ptr<StatWidget> m_upQuarterFinalsStatWidget{std::make_unique<StatWidget>(this)};
	std::unique_ptr<StatWidget> m_upSemiFinalsStatWidget{std::make_unique<StatWidget>(this)};
	std::unique_ptr<StatWidget> m_up3rdPlaceGamesStatWidget{std::make_unique<StatWidget>(this)};
	std::unique_ptr<StatWidget> m_upFinalsStatWidget{std::make_unique<StatWidget>(this)};
};

#endif