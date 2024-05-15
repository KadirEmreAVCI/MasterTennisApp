#pragma once

#include <QWidget>
#include "ui_StatisticsPage.h"
#include "IQTComponent.h"
class StatisticsPage : public QWidget, public IQTComponent
{
	Q_OBJECT

public:
	StatisticsPage(QWidget *parent = nullptr);
	~StatisticsPage();
	void InitCustomComponents() override final;
private:
	Ui::StatisticsPageClass ui;
};
