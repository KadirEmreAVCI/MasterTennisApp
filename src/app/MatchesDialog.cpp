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
void MatchesDialog::OpenAddDialog()
{
	m_upAddEditMatchDialog->setModal(true);
	m_upAddEditMatchDialog->PrepareDialog(DialogMode::eAddDialog, m_RootTournament);
	m_upAddEditMatchDialog->exec();
}
void MatchesDialog::OpenEditDialog(const Match& m)
{
	m_upAddEditMatchDialog->setModal(true);
	m_upAddEditMatchDialog->PrepareDialog(DialogMode::eEditDialog, m_RootTournament, m);
	m_upAddEditMatchDialog->exec();
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
	PlacePic2TableCell(ui.tableWidget, m.GetOutcomePic(), 0.04f, uiRowIdx, uiColumnIdx++);
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
	m_vecOrganization = p.GetParticipatedOrgs();
	const auto& vecAllTournaments = ConcatanateTournaments();
	const auto& iterUpdatedRootTournament = std::find_if(vecAllTournaments.cbegin(), vecAllTournaments.cend(), [this](const auto& t) {
		return t.GetID() == m_RootTournament.GetID();
		});
	if (iterUpdatedRootTournament != vecAllTournaments.end())
	{
		m_RootTournament = *iterUpdatedRootTournament;
		DisplayMatches(m_RootTournament);
	}
	else
	{
		std::cout << "MatchesDialog::UpdateActiveProfileData updated tournament could not be found.\n";
	}
}
std::vector<Tournament> MatchesDialog::ConcatanateTournaments()const
{
	std::vector<Tournament> vecAllTournament;
	std::for_each(m_vecOrganization.cbegin(), m_vecOrganization.cend(), [&vecAllTournament](const auto& org) {
		const auto& vecTournament = org.GetTournaments();
		vecAllTournament.insert(vecAllTournament.cend(), vecTournament.cbegin(), vecTournament.cend());
		});
	return vecAllTournament;
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
Match MatchesDialog::FindSignalingMatch()const
{
	return m_vecMatch[utility::FindIndexOfSignalingItem(ui.tableWidget, sender())];
}
void MatchesDialog::EditMatch()
{
	const auto& SignalingMatch = FindSignalingMatch();
	OpenEditDialog(SignalingMatch);
}
void MatchesDialog::DeleteMatch()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want delete this item permanently?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
		const auto& SignalingMatch = FindSignalingMatch();
		AppController::instance().DeleteMatch(SignalingMatch);
		QMessageBox::information(this, "Information", "The match deleted successfully");
	}
}
void MatchesDialog::on_NewMatchButton_clicked()
{
	if (false == m_RootTournament.IsLocked())
	{
		OpenAddDialog();
	}
	else
	{
		QMessageBox::warning(this, "Warning", "A new match cannot be added to the locked tournament.");
	}
}
