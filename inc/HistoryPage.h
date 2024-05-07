#pragma once
#include <memory>
#include <QWidget>
#include "ui_HistoryPage.h"
#include "IQTComponent.h"
class AddTournamentDialog;
class HistoryPage : public QWidget, public IQTComponent
{
	Q_OBJECT

public:
	HistoryPage(QWidget *parent = nullptr);
	~HistoryPage();
	void InitializeCustomComponents() override final;
private:
	Ui::HistoryPageClass ui;
	std::unique_ptr<AddTournamentDialog> m_upAddTournamentDialog{ nullptr };
private slots:
	void on_AddButton_clicked();
};
