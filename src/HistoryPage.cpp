#include <iostream>
#include "HistoryPage.h"
#include "SQLiteDB.h"
#include "AddTournamentDialog.h"
HistoryPage::HistoryPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	InitializeCustomComponents();
}

HistoryPage::~HistoryPage()
{}

void HistoryPage::InitializeCustomComponents()
{
	if (SQLiteDB::instance().OpenConn())
	{
		SQLiteDB::instance().SetTableContentByColumn(ui.tableView_Tournaments, "Tournament", "Name,Type,Category,TotalCategory,Season,Participant,Completion,Progress");
		SQLiteDB::instance().CloseConn();
	}
}
void HistoryPage::on_AddButton_clicked()
{
	std::cout << "Continue button clicked\n";
	m_upAddTournamentDialog = std::make_unique<AddTournamentDialog>(this);
	m_upAddTournamentDialog->setModal(true);
	m_upAddTournamentDialog->exec();
}