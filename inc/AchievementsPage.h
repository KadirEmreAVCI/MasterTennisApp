#pragma once

#include <QWidget>
#include "ui_AchievementsPage.h"
#include "IQTComponent.h"
class AchievementsPage : public QWidget, public IQTComponent
{
	Q_OBJECT

public:
	AchievementsPage(QWidget *parent = nullptr);
	~AchievementsPage();
	void InitCustomComponents() override final;
private:
	Ui::AchievementsPageClass ui;
};
