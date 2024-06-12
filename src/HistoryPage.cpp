#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <QMessageBox>
#include "HistoryPage.h"
#include "AddDialog.h"
#include "AddEditTournamentDialog.h"
#include "AddEditMatchDialog.h"
#include "CreateTournamentDialog.h"
#include "AppController.h"

HistoryPage::HistoryPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_upAddDialog = std::make_unique<AddDialog>(this);
	m_upAddEditTournamentDialog = std::make_unique<AddEditTournamentDialog>(this);
	std::cout << "HistoryPage::HistoryPage AddEditTournamentDialog constructed successfully\n";
	m_upAddEditMatchDialog = std::make_unique<AddEditMatchDialog>(this);
	std::cout << "HistoryPage::HistoryPage AddEditMatchDialog constructed successfully\n";
	m_upCreateTournamentDialog = std::make_unique<CreateTournamentDialog>(this);
	std::cout << "HistoryPage::HistoryPage CreateTournamentDialog constructed successfully\n";
	InitCustomComponents();
	std::cout << "HistoryPage::HistoryPage custom components constructed successfully\n";
	QObject::connect(&AppController::instance(), &AppController::TournamentAdded, this, &HistoryPage::UpdateTournaments);
	QObject::connect(&AppController::instance(), &AppController::TournamentsDeleted, this, &HistoryPage::UpdateTournaments);
	QObject::connect(&AppController::instance(), &AppController::TournamentEdited, this, &HistoryPage::UpdateTournaments);
	QObject::connect(&*m_upAddDialog, &AddDialog::AddTournamentRequest, this, &HistoryPage::AddTournament);
	QObject::connect(&*m_upAddDialog, &AddDialog::AddMatchRequest, this, &HistoryPage::AddMatch);
}

HistoryPage::~HistoryPage()
{}

void HistoryPage::InitCustomComponents()
{
	LoadTournamentData();
}

void HistoryPage::AddOrganization()
{

}
void HistoryPage::AddMatch()
{
	auto vecSelectedTournament = FindSelectedTournaments();
	if (vecSelectedTournament.empty())
	{
		QMessageBox::warning(this, "Warning", "Select a tournament to add a match.");
	}
	else if (vecSelectedTournament.size() == 1)
	{
		if (false == vecSelectedTournament.front().GetCompleted())
		{
			m_upAddEditMatchDialog->setModal(true);
			m_upAddEditMatchDialog->SetDialogMode(DialogMode::eAddDialog, vecSelectedTournament.front());
			m_upAddEditMatchDialog->exec();
		}
		else
		{
			QMessageBox::warning(this, "Warning", "A new match cannot be added to the completed tournament.");
		}
	}
	else
	{
		QMessageBox::critical(this, "Error", "Only one tournament can be selected as the root of a match.");
	}
	ClearSelectedRows();
}
void HistoryPage::AddTournament()
{
	m_upAddEditTournamentDialog->setModal(true);
	m_upAddEditTournamentDialog->SetDialogMode(DialogMode::eAddDialog);
	m_upAddEditTournamentDialog->exec();
}

void HistoryPage::LoadTournamentData()
{
	std::cout << "HistoryPage::LoadTournamentData\n";
	m_vecTournament = AppController::instance().GetTournaments();
	//std::cout << "HistoryPage::LoadTournamentData m_vecTournament.size() = " << m_vecTournament.size() << '\n';
	if (!m_vecTournament.empty())
	{
		unsigned int uiRowIdx{};
		std::for_each(m_vecTournament.cbegin(), m_vecTournament.cend(), [&](const auto& tournament) {
			ui.tableWidget->insertRow(uiRowIdx);
			InsertTournament2Table(tournament, uiRowIdx);
			++uiRowIdx;
		});
		ui.tableWidget->resizeColumnsToContents();
	}
	else
	{
		std::cout << "HistoryPage::LoadTournamentData m_vecTournament is empty!\n";
	}
}

void HistoryPage::InsertTournament2Table(const Tournament& t, unsigned uiRowIdx)
{
	unsigned uiColumnIdx{};
	QTableWidgetItem* pCheckBox = new QTableWidgetItem();
	pCheckBox->setCheckState(Qt::Unchecked);
	ui.tableWidget->setItem(uiRowIdx, uiColumnIdx++, pCheckBox);
	InsertValue2Cell(QString::fromStdString(t.GetOrgName()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(QString::fromStdString(t.GetSeason()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(QString::fromStdString(t.GetCategory()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(QString::fromStdString(t.GetType()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(QString::fromStdString(t.GetTeammate()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(QString::fromStdString(std::to_string(t.GetParticipant())), uiRowIdx, uiColumnIdx++);
	InsertCompletionPic2Cell(t.GetCompleted(), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(QString::fromStdString(t.GetProgress()), uiRowIdx, uiColumnIdx++);
}

void HistoryPage::InsertValue2Cell(QString sVal, unsigned uiRowIdx, unsigned uiColumnIdx)
{
	QTableWidgetItem* const pVal = new QTableWidgetItem;
	pVal->setText(sVal);
	ui.tableWidget->setItem(uiRowIdx, uiColumnIdx++, pVal);
}

void HistoryPage::InsertCompletionPic2Cell(bool blCompletion, unsigned uiRowIdx, unsigned uiColumnIdx)
{
	const float fCompletionScale{ 0.04f };
	QLabel* pCompletionLabel = new QLabel;
	std::string sPicAddress = blCompletion ? ":images/images/win.png" : ":images/images/hourglass.png";
	InitPicture(pCompletionLabel, sPicAddress, fCompletionScale);
	ui.tableWidget->setCellWidget(uiRowIdx, uiColumnIdx++, pCompletionLabel);
}

std::vector<unsigned> HistoryPage::FindSelectedRows()const
{
	std::vector<unsigned> vecCheckedTournamentIDs;
	const unsigned int uiCheckBoxColumnIdx{0};
	for (unsigned uiRow{}; uiRow < ui.tableWidget->rowCount(); ++uiRow)
	{
		QTableWidgetItem* pCheckBox = ui.tableWidget->item(uiRow, uiCheckBoxColumnIdx); 
		if (pCheckBox && pCheckBox->checkState() == Qt::Checked) {
			vecCheckedTournamentIDs.push_back(uiRow);
		}
	}
	return vecCheckedTournamentIDs;
}

void HistoryPage::ClearSelectedRows()
{
	const unsigned int uiCheckBoxColumnIdx{ 0 };
	for (unsigned uiRow{}; uiRow < ui.tableWidget->rowCount(); ++uiRow)
	{
		QTableWidgetItem* pCheckBox = ui.tableWidget->item(uiRow, uiCheckBoxColumnIdx);
		if (pCheckBox && pCheckBox->checkState() == Qt::Checked) {
			pCheckBox->setCheckState(Qt::Unchecked);
		}
	}
}

std::vector<Tournament> HistoryPage::FindSelectedTournaments()const
{
	std::vector<unsigned> vecSelectedTournamentRows = FindSelectedRows();
	std::vector<Tournament> vecSelectedTournament;
	for (size_t idx{}; idx < vecSelectedTournamentRows.size(); ++idx)
	{
		vecSelectedTournament.push_back(m_vecTournament[vecSelectedTournamentRows[idx]]);
	}
	return vecSelectedTournament;
}

void HistoryPage::on_AddButton_clicked()
{
	m_upAddDialog->setModal(true);
	m_upAddDialog->exec();
	ClearSelectedRows();
}
void HistoryPage::on_CreateButton_clicked()
{
	m_upCreateTournamentDialog->setModal(true);
	m_upCreateTournamentDialog->exec();
}

void HistoryPage::on_DeleteButton_clicked()
{
	auto vecSelectedTournament = FindSelectedTournaments();
	if (vecSelectedTournament.empty())
	{
		QMessageBox::warning(this, "Warning", "Select tournament(s) first.");
	}
	else
	{
		AppController::instance().DeleteTournaments(vecSelectedTournament);
		QMessageBox::information(this, "Information", "Tournament(s) deleted successfully");
	}
	ClearSelectedRows();
}

void HistoryPage::on_EditButton_clicked()
{
	auto vecSelectedTournament = FindSelectedTournaments();
	if (vecSelectedTournament.empty())
	{
		QMessageBox::warning(this, "Warning", "Select a tournament first.");
	}
	else if (vecSelectedTournament.size() == 1)
	{
		m_upAddEditTournamentDialog->setModal(true);
		m_upAddEditTournamentDialog->SetDialogMode(DialogMode::eEditDialog, vecSelectedTournament.front());
		m_upAddEditTournamentDialog->exec();
	}
	else
	{
		QMessageBox::critical(this, "Error", "Only one tournament can be edited at once.");
	}
	ClearSelectedRows();
}

void HistoryPage::UpdateTournaments()
{
	std::cout << "HistoryPage::UpdateTournaments!!!!!!!!!!!!!!!\n";
	ui.tableWidget->clearContents();
	ui.tableWidget->setRowCount(0);
	LoadTournamentData();
}