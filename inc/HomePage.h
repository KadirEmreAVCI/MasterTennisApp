#pragma once
#include <string>
#include <QWidget>
#include "ui_HomePage.h"
#include "IQTComponent.h"
class HomePage : public QWidget, public IQTComponent
{
	Q_OBJECT

public:
	HomePage(QWidget *parent = nullptr);
	~HomePage();
	void InitCustomComponents() override final;
private:
	void InitUpcomingMatches();
	void InsertUpcomingMatch(std::string sTournamentName, std::string sTournamentCategory, std::string sOpponentName, std::string sStage);
	void InitStats();
	void InitStatIcons();
	Ui::HomePageClass ui;
};
