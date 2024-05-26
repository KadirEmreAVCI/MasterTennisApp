#pragma once
#include <memory>
#include <QWidget>
#include "ui_HistoryPage.h"
#include "IQTComponent.h"
#include "Tournament.h"
class AddEditTournamentDialog;
class CreateTournamentDialog;
class HistoryPage : public QWidget, public IQTComponent
{
	Q_OBJECT
public:
	HistoryPage(QWidget *parent = nullptr);
	~HistoryPage();
	void InitCustomComponents() override final;
private:
	void LoadTournamentData();
	void InsertTournament2Table(const Tournament& t, unsigned uiRowIdx);
	void InsertValue2Cell(QString sVal, unsigned uiRowIdx, unsigned uiColumnIdx);
	void InsertCompletionPic2Cell(bool blCompletion, unsigned uiRowIdx, unsigned uiColumnIdx);
	std::vector<unsigned> FindSelectedRows()const;
	std::vector<Tournament> FindSelectedTournaments()const;
	Ui::HistoryPageClass ui;
	std::unique_ptr<AddEditTournamentDialog> m_upAddEditTournamentDialog{ nullptr };
	std::unique_ptr<CreateTournamentDialog> m_upCreateTournamentDialog{ nullptr };
	std::vector<Tournament> m_vecTournament;
private slots:
	void on_AddButton_clicked();
	void on_CreateButton_clicked();
	void on_DeleteButton_clicked();
	void on_EditButton_clicked();
public slots:	
	void UpdateTournaments();
};
