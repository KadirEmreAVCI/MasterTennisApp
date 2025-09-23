#include <QMessageBox>
#include <QScrollBar>
#include "AppController.h"
#include "AddEditMatchDialog.h"
#include "MatchesDialog.h"
#include "Config.h"
#include "Utility.h"

MatchesDialog::MatchesDialog(QWidget *parent)
	: 
	QDialog(parent),
	TableWidgetUser{{ " Statu ", " Outcome ", " Stage ", " Score ", " Sets ", " Opponent 1 ", " Opponent 2 ", " Date ", " Time ", "", "" }}
{
	ui.setupUi(this);
	m_upAddEditMatchDialog = std::make_unique<AddEditMatchDialog>(this);
	QObject::connect(&AppController::instance(), &AppController::ChangeInActiveProfile, this, &MatchesDialog::UpdateActiveProfileData);
	setFixedSize(750, 600);
	InitTable(ui.tableWidget);
}
MatchesDialog::~MatchesDialog()
{

}
void MatchesDialog::FillTable()
{
	unsigned int uiRowIdx{};
	for (const auto& m : m_vecMatch)
	{
		ui.tableWidget->insertRow(uiRowIdx);
		PlaceMatch2Table(m, uiRowIdx);
		++uiRowIdx;
	}
	ui.tableWidget->resizeRowsToContents();
	ui.tableWidget->resizeColumnsToContents();
}
void MatchesDialog::DisplayMatches(const Tournament& rootTournament)
{
	m_RootTournament = rootTournament;
	m_vecMatch = m_RootTournament.GetMatches();
	std::sort(m_vecMatch.begin(), m_vecMatch.end(), [](const auto& m1, const auto& m2) {
		return !m1.IsEarlier(m2);
		});
	if (m_RootTournament.IsLocked())
	{
		ui.NewMatchButton->setEnabled(false);
	}
	else
	{
		ui.NewMatchButton->setEnabled(true);
	}
	LoadDataToTable();
}
void MatchesDialog::PlaceMatch2Table(const Match& m, unsigned uiRowIdx)
{
	using namespace utility;
	unsigned uiColumnIdx{};
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(m.GetStatu()), uiRowIdx, uiColumnIdx++);
	PlaceLabel2TableCellWithImage(ui.tableWidget, m.GetOutcomePic(), 0.04f, uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(m.GetStage()), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(m.GetScore().ToString()), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(m.SetsToString()), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(m.GetOpponent1()), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(m.GetOpponent2()), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, m.GetDate().toString("dd.MM.yyyy"), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, m.GetTime().toString("hh:mm"), uiRowIdx, uiColumnIdx++);
	QObject::connect(PlaceButton2TableCellWithImage(ui.tableWidget, uiRowIdx, uiColumnIdx++, g_cpDeleteButtonPNG,  0.4f, (m_RootTournament.IsLocked()) ? false : true), &QPushButton::clicked, this, &MatchesDialog::DeleteMatch);
	QObject::connect(PlaceButton2TableCellWithImage(ui.tableWidget, uiRowIdx, uiColumnIdx++, g_cpEditButtonPNG,  0.4f, (m_RootTournament.IsLocked()) ? false : true), &QPushButton::clicked, this, &MatchesDialog::EditMatch);
}
void MatchesDialog::UpdateActiveProfileData(const Profile& p)
{
	const auto& vecTournamentsOfTheProfile = p.GetTournaments();
	const auto& iterUpdatedRootTournament = std::find_if(vecTournamentsOfTheProfile.cbegin(), vecTournamentsOfTheProfile.cend(), [this](const auto& t) {
		return t.GetID() == m_RootTournament.GetID();
		});
	if (iterUpdatedRootTournament != vecTournamentsOfTheProfile.end())
	{
		m_RootTournament = *iterUpdatedRootTournament;
		DisplayMatches(m_RootTournament);
	}
	else
	{
		std::cout << "MatchesDialog::UpdateActiveProfileData updated tournament could not be found.\n";
	}
}
void MatchesDialog::LoadDataToTable()
{
	ClearTable();
	FillTable();
	if (m_RootTournament.IsLocked())
	{
		ui.NewMatchButton->setEnabled(false);
	}
	else 
	{
		ui.NewMatchButton->setEnabled(true);
	}
}
void MatchesDialog::EditMatch()
{
	const auto& SignalingMatch = utility::GetSignalingItem<Match>(m_vecMatch, ui.tableWidget, sender());
	m_upAddEditMatchDialog->SetRootTournament(m_RootTournament);
	m_upAddEditMatchDialog->OpenEditDialog(SignalingMatch);
}
void MatchesDialog::DeleteMatch()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want delete this item permanently?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
		const auto& SignalingMatch = utility::GetSignalingItem<Match>(m_vecMatch, ui.tableWidget, sender());
		AppController::instance().DeleteMatch(SignalingMatch);
		QMessageBox::information(this, "Information", "The match deleted successfully");
	}
}
void MatchesDialog::on_NewMatchButton_clicked()
{
	if (false == m_RootTournament.IsLocked())
	{
		m_upAddEditMatchDialog->SetRootTournament(m_RootTournament);
		m_upAddEditMatchDialog->OpenAddDialog();
	}
	else
	{
		QMessageBox::warning(this, "Warning", "A new match cannot be added to the locked tournament.");
	}
}
