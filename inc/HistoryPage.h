#pragma once
#include <memory>
#include <QWidget>
#include "ui_HistoryPage.h"
#include "IQTComponent.h"
class AddTournamentDialog;
class CreateTournamentDialog;
class HistoryPage : public QWidget, public IQTComponent
{
	Q_OBJECT

public:
	HistoryPage(QWidget *parent = nullptr);
	~HistoryPage();
	void InitCustomComponents() override final;
private:
	/*void LoadOrgNames();
	void LoadColumn(std::string sColumn);*/
	void LoadTournamentData();
	Ui::HistoryPageClass ui;
	std::unique_ptr<AddTournamentDialog> m_upAddTournamentDialog{ nullptr };
	std::unique_ptr<CreateTournamentDialog> m_upCreateTournamentDialog{ nullptr };
	
private slots:
	void on_AddButton_clicked();
	void on_CreateButton_clicked();
};
