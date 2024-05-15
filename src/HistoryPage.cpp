#include <iostream>
#include <vector>
#include <string>
#include "HistoryPage.h"
#include "AddTournamentDialog.h"
#include "CreateTournamentDialog.h"
#include "DatabaseController.h"
#include "Tournament.h"

HistoryPage::HistoryPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	InitCustomComponents();
}

HistoryPage::~HistoryPage()
{}

void HistoryPage::InitCustomComponents()
{
	LoadTournamentData();
	
}

void HistoryPage::LoadTournamentData()
{
	std::vector<Tournament> vecTournament = DatabaseController::instance().GetTournaments();
	unsigned int uiRowIdx{};
	std::for_each(vecTournament.cbegin(), vecTournament.cend(), [&](const auto& tournament) {
		ui.tableWidget->insertRow(uiRowIdx);
		QTableWidgetItem* const name = new QTableWidgetItem;
		name->setText(QString::fromStdString(tournament.GetOrganizationName()));
		ui.tableWidget->setItem(uiRowIdx, 0, name);
		QTableWidgetItem* const type = new QTableWidgetItem;
		type->setText(QString::fromStdString(tournament.GetType()));
		ui.tableWidget->setItem(uiRowIdx, 1, type);
		QTableWidgetItem* const teammate = new QTableWidgetItem;
		teammate->setText(QString::fromStdString(tournament.GetTeammate()));
		ui.tableWidget->setItem(uiRowIdx, 2, teammate);
		QTableWidgetItem* const category = new QTableWidgetItem;
		category->setText(QString::fromStdString(tournament.GetCategory()));
		ui.tableWidget->setItem(uiRowIdx, 3, category);
		QTableWidgetItem* const season = new QTableWidgetItem;
		season->setText(QString::fromStdString(tournament.GetSeason()));
		ui.tableWidget->setItem(uiRowIdx, 4, season);
		QTableWidgetItem* const participant = new QTableWidgetItem;
		participant->setText(QString::fromStdString(std::to_string(tournament.GetParticipant())));
		ui.tableWidget->setItem(uiRowIdx, 5, participant);
		QTableWidgetItem* const completed = new QTableWidgetItem;
		completed->setText(QString::fromStdString(std::to_string(tournament.GetCompleted())));
		ui.tableWidget->setItem(uiRowIdx, 6, completed);
		QTableWidgetItem* const progress = new QTableWidgetItem;
		progress->setText(QString::fromStdString(tournament.GetProgress()));
		ui.tableWidget->setItem(uiRowIdx, 7, progress);
		++uiRowIdx;
	});
	std::cout << "HistoryPage::LoadTournamentData Tournaments loaded successfully from database\n";
}

void HistoryPage::on_AddButton_clicked()
{
	std::cout << "HistoryPage::Add button clicked\n";
	m_upAddTournamentDialog = std::make_unique<AddTournamentDialog>(this);
	m_upAddTournamentDialog->setModal(true);
	m_upAddTournamentDialog->exec();
}
void HistoryPage::on_CreateButton_clicked()
{
	std::cout << "HistoryPage::Create button clicked\n";
	m_upCreateTournamentDialog = std::make_unique<CreateTournamentDialog>(this);
	m_upCreateTournamentDialog->setModal(true);
	m_upCreateTournamentDialog->exec();
}