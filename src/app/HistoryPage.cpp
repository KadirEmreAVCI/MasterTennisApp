#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <QMessageBox>
#include <QStandardItemModel>
#include "HistoryPage.h"
#include "AddEditTournamentDialog.h"
#include "MatchesDialog.h"
#include "AppController.h"
#include "Common.h"
#include "Utility.h"

HistoryPage::HistoryPage(QWidget *parent)
	: 
	QWidget(parent),
	TableWidgetUser{{ "", "Organization", "Season", "Type", "Category", "Teammate", "Participant", "Max. Progress", "Trophy", "", "", "", "" }}
{
	ui.setupUi(this);
	m_upAddEditTournamentDialog = std::make_unique<AddEditTournamentDialog>(this);
	m_upMatchesDialog = std::make_unique<MatchesDialog>(this);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &HistoryPage::UserLoggedIn);
	QObject::connect(&AppController::instance(), &AppController::ChangeInDB, this, &HistoryPage::ChangeInDB);
	InitFilterComponents();
	InitTable(ui.tableWidget);
}
HistoryPage::~HistoryPage()
{}
void HistoryPage::FillTable()
{
	unsigned int uiRowIdx{};
	for (const auto& t : m_vecDisplayedTournament)
	{
		PlaceTournament2Table(t, uiRowIdx);
		++uiRowIdx;
	}
	ui.tableWidget->resizeRowsToContents();
	ui.tableWidget->resizeColumnsToContents();
}
void HistoryPage::LoadDataToTable()
{
	ClearTable();
	if (!m_vecDisplayedTournament.empty())
	{
		FillTable();
	}
}
void HistoryPage::PlaceTournament2Table(const Tournament& t, unsigned uiRowIdx)
{
	using namespace utility;
	ui.tableWidget->insertRow(uiRowIdx);
	unsigned uiColumnIdx{};
	auto rRootOrganization = DatabaseController::instance().FindRootOrganization(t);
	PlaceLabel2TableCellWithImage(ui.tableWidget, rRootOrganization.GetFullPicturePath(), 0.07f, uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(rRootOrganization.GetName()), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(t.GetSeason()), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(t.GetType()), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(t.GetCategory()), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(t.GetTeammate()), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(std::to_string(t.GetParticipant())), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(t.GetLastMatch().value_or(Match{}).GetStage()), uiRowIdx, uiColumnIdx++);
	PlaceLabel2TableCellWithImage(ui.tableWidget, t.GetTrophyPic(), 0.085f, uiRowIdx, uiColumnIdx++);
	QObject::connect(PlaceButton2TableCell(ui.tableWidget, uiRowIdx, uiColumnIdx++, std::string(" Match History ")), &QPushButton::clicked, this, &HistoryPage::ShowMatches);
	QObject::connect(PlaceButton2TableCellWithImage(ui.tableWidget, uiRowIdx, uiColumnIdx++, common::g_cpDeleteButtonPNG,  0.4f, (t.IsLocked()) ? false : true), &QPushButton::clicked, this, &HistoryPage::DeleteTournament);
	QObject::connect(PlaceButton2TableCellWithImage(ui.tableWidget, uiRowIdx, uiColumnIdx++, common::g_cpEditButtonPNG,  0.4f, (t.IsLocked()) ? false : true), &QPushButton::clicked, this, &HistoryPage::EditTournament);
	QObject::connect(PlaceButton2TableCellWithImage(ui.tableWidget, uiRowIdx, uiColumnIdx++, (t.IsLocked()) ? ":images/lock.png" : ":images/unlock.png",  0.04f, true), &QPushButton::clicked, this, &HistoryPage::LockUnlockTournament);
}
void HistoryPage::InitFilterComponents()
{
	utility::SetComboBoxItems(ui.comboBoxFilter, {"Organization", "Season", "Type", "Category", "Teammate", "Max. Progress", "Opponent"}, true);
	utility::DisableFirstItemOfComboBox(ui.comboBoxFilter);
	ui.comboBoxFilter->setCurrentIndex(0);
	ui.ClearButton->setVisible(false);
	ui.lineEditSearchBar->clear();
	ui.lineEditSearchBar->setEnabled(false);
	ui.tableWidget->clearSelection();
}
void HistoryPage::HighlightFilteredColumn()
{
	int idx = -1;
	if(auto it = std::find(m_vecColumnNames.begin(), m_vecColumnNames.end(), m_sFilter); it != m_vecColumnNames.end()) 
	{
        idx = std::distance(m_vecColumnNames.begin(), it);
	}
	else if(m_sFilter == "Opponent")
	{
		idx = 9;
	}
	ui.tableWidget->clearSelection();
	ui.tableWidget->selectColumn(idx);
}
void HistoryPage::on_NewButton_clicked()
{
	m_upAddEditTournamentDialog->OpenAddDialog();
}
void HistoryPage::on_ClearButton_clicked()
{
	if(nullptr != m_upActiveFilter)
	{
		m_upActiveFilter.reset();
	}
	InitFilterComponents();
	m_vecDisplayedTournament = m_vecTournament;
	LoadDataToTable();
}
void HistoryPage::on_comboBoxFilter_currentTextChanged(const QString& sFilter)
{
	ui.lineEditSearchBar->setEnabled(true);
	ui.ClearButton->setVisible(true);
	m_sFilter = sFilter.toStdString();
	HighlightFilteredColumn();
	const bool blSearchForExactMatch = false;
	if(m_sFilter == "Organization")
	{
		m_upActiveFilter = std::make_unique<DataFilter<Tournament, decltype([](const Tournament& t){return DatabaseController::instance().FindRootOrganization(t).GetName();})>>(blSearchForExactMatch);
	}
	else if(m_sFilter == "Season")
	{
		m_upActiveFilter = std::make_unique<DataFilter<Tournament, decltype([](const Tournament& t){return t.GetSeason();})>>(blSearchForExactMatch);
	}
	else if(m_sFilter == "Type")
	{
		m_upActiveFilter = std::make_unique<DataFilter<Tournament, decltype([](const Tournament& t){return t.GetType();})>>(blSearchForExactMatch);
	}
	else if(m_sFilter == "Category")
	{
		m_upActiveFilter = std::make_unique<DataFilter<Tournament, decltype([](const Tournament& t){return t.GetCategory();})>>(blSearchForExactMatch);
	}
	else if(m_sFilter == "Teammate")
	{
		m_upActiveFilter = std::make_unique<DataFilter<Tournament, decltype([](const Tournament& t){return t.IsDoubleTournament() ? t.GetTeammate() : "";})>>(blSearchForExactMatch);
	}
	else if(m_sFilter == "Progress")
	{
		m_upActiveFilter = std::make_unique<DataFilter<Tournament, decltype([](const Tournament& t){return t.GetLastMatch().has_value() ? t.GetLastMatch().value().GetStage() : "";})>>(blSearchForExactMatch);
	}
	else if(m_sFilter == "Opponent")
	{
		m_upActiveFilter = std::make_unique<DataFilter<Tournament, decltype([](const Tournament& t){
			std::string sConcatanatedOpponents;
			for(const Match& m : t.GetMatches())
			{
				sConcatanatedOpponents += m.GetOpponent1() + " ";
				if(t.IsDoubleTournament())
				{
					sConcatanatedOpponents += m.GetOpponent2() + " ";
				}
			}
			return sConcatanatedOpponents;}
		)>>(blSearchForExactMatch);
	}
	else if(m_sFilter != "")
	{
		std::cerr << "on_comboBoxFilter_currentTextChanged Unknown filter!\n"; 
	}
	if(ui.lineEditSearchBar->text() != "")
	{
		on_lineEditSearchBar_textChanged(ui.lineEditSearchBar->text());
	}
}
void HistoryPage::on_lineEditSearchBar_textChanged(const QString& sFilterWord)
{
	if(m_upActiveFilter)
	{
		m_vecDisplayedTournament = m_upActiveFilter->ApplyFilter(m_vecTournament, sFilterWord.toStdString());	
		LoadDataToTable();
		HighlightFilteredColumn();
	}
	else
	{
		std::cerr << "on_lineEditSearchBar_textChanged m_upActiveFilter is nullptr!\n";
	}
}
void HistoryPage::ChangeInDB(const std::vector<Profile>& vecProfile, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&)
{
	const auto activeProfile = std::find_if(vecProfile.cbegin(), vecProfile.cend(), [this](const Profile& p) {
		return p.GetID() == m_uiProfileID;
		});
	if(activeProfile != vecProfile.cend())
	{
		UpdateActiveProfileData(*activeProfile);
	}
}
void HistoryPage::UpdateActiveProfileData(const Profile& p)
{
	m_vecTournament = p.GetTournaments();
	if (m_vecTournament.size() > 1)
	{
		std::sort(m_vecTournament.begin(), m_vecTournament.end(), [](const auto& t1, const auto& t2) {
			return !t1.IsEarlier(t2);
			});
	}
	on_ClearButton_clicked();
}
void HistoryPage::UserLoggedIn(const Profile& p)
{
	m_uiProfileID = p.GetID();
	if (m_blFirstLoadOfData)
	{
		UpdateActiveProfileData(p);		// To adjust the height of the rows properly.
		m_blFirstLoadOfData = false;
	}
	UpdateActiveProfileData(p);
}
void HistoryPage::ShowMatches()
{
	const auto SignalingTournament = utility::GetSignalingItem<Tournament>(m_vecDisplayedTournament, ui.tableWidget, sender());
	m_upMatchesDialog->setWindowTitle(QString::fromStdString(SignalingTournament.GetName()));
	const auto vecMatches = SignalingTournament.GetMatches();
	m_upMatchesDialog->DisplayMatches(SignalingTournament);
	m_upMatchesDialog->setModal(true);
	m_upMatchesDialog->exec();
}
void HistoryPage::LockUnlockTournament()
{
	auto SignalingTournament = utility::GetSignalingItem<Tournament>(m_vecDisplayedTournament, ui.tableWidget, sender());
	if (SignalingTournament.IsLocked())
	{
		QMessageBox::StandardButton reply = QMessageBox::question(this, "Unlock Tournament", "Are you sure you want to unlock this tournament? The match history of unlocked tournaments can be changed.", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			SignalingTournament.SetLocked(false);
			if(AppController::instance().EditItem(SignalingTournament))
			{
				QMessageBox::information(this, "Information", "The tournament unlocked.");
			}
		}
	}
	else
	{
		const auto vecMatch = SignalingTournament.GetMatches();
		const bool blUpcomingMatchExist = std::any_of(vecMatch.cbegin(), vecMatch.cend(), [](const Match& m) {
			return m.IsUpcomingMatch();
			});
		if (!blUpcomingMatchExist)
		{
			QMessageBox::StandardButton reply = QMessageBox::question(this, "Lock Tournament", "Are you sure you want to lock this tournament? The match history of locked tournaments can not be changed.", QMessageBox::Yes | QMessageBox::No);
			if (reply == QMessageBox::Yes)
			{
				SignalingTournament.SetLocked(true);
				if(AppController::instance().EditItem(SignalingTournament))
				{
					QMessageBox::information(this, "Information", "The tournament locked.");
				}
			}
		}
		else
		{
			QMessageBox::critical(this, "Error", "Tournaments with upcoming matches cannot be locked.");
		}
	}
}
void HistoryPage::EditTournament()
{
	const auto SignalingTournament = utility::GetSignalingItem<Tournament>(m_vecDisplayedTournament, ui.tableWidget, sender());
	m_upAddEditTournamentDialog->OpenEditDialog(SignalingTournament);
}
void HistoryPage::DeleteTournament()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want delete this item permanently?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
		const auto& SignalingTournament = utility::GetSignalingItem<Tournament>(m_vecDisplayedTournament, ui.tableWidget, sender());
		if(AppController::instance().DeleteItem(SignalingTournament))
		{
			QMessageBox::information(this, "Information", "The tournament deleted successfully");
		}
	}
}