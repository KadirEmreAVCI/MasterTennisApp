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
#include "Config.h"
#include "FilterByOrganization.h"
#include "FilterBySeason.h"
#include "FilterByType.h"
#include "FilterByCategory.h"
#include "FilterByTeammate.h"
#include "FilterByProgress.h"	
#include "FilterByOpponent.h"
#include "Utility.h"

HistoryPage::HistoryPage(QWidget *parent)
	: 
	QWidget(parent),
	TableWidgetUser{{ "", " Organization ", " Season ", " Type ", " Category ", " Teammate ", " Participant ", " Max. Progress ", " Trophy ", "", "", "", "" }}
{
	ui.setupUi(this);
	m_upAddEditTournamentDialog = std::make_unique<AddEditTournamentDialog>(this);
	m_upMatchesDialog = std::make_unique<MatchesDialog>(this);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &HistoryPage::UserLoggedIn);
	QObject::connect(&AppController::instance(), &AppController::ChangeInActiveProfile, this, &HistoryPage::UpdateActiveProfileData);
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
	const auto& iterRootOrg = std::find_if(m_vecOrganization.cbegin(), m_vecOrganization.cend(), [t](const auto& org) {
		return org.GetID() == t.GetOrgID();
		});
	if (iterRootOrg != m_vecOrganization.end())
	{
		unsigned uiColumnIdx{};
		if (iterRootOrg->GetOrgPictureAddr() != "")
		{
			PlacePic2TableCell(ui.tableWidget, (Organization::GetOrgImageRootDestDir() + QString::fromStdString(iterRootOrg->GetOrgPictureAddr())).toStdString(), 0.07f, uiRowIdx, uiColumnIdx++);
		}
		else
		{
			PlacePic2TableCell(ui.tableWidget, (Organization::GetOrgImageRootDestDir() + "default_org.png").toStdString(), 0.07f, uiRowIdx, uiColumnIdx++);
		}
		PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(iterRootOrg->GetName()), uiRowIdx, uiColumnIdx++);
		PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(t.GetSeason()), uiRowIdx, uiColumnIdx++);
		PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(t.GetType()), uiRowIdx, uiColumnIdx++);
		PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(t.GetCategory()), uiRowIdx, uiColumnIdx++);
		PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(t.GetTeammate()), uiRowIdx, uiColumnIdx++);
		PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(std::to_string(t.GetParticipant())), uiRowIdx, uiColumnIdx++);
		PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(t.GetLastMatch().value_or(Match{}).GetStage()), uiRowIdx, uiColumnIdx++);
		PlacePic2TableCell(ui.tableWidget, t.GetTrophyPic(), 0.085f, uiRowIdx, uiColumnIdx++);
		QObject::connect(PlaceButton2TableCell(ui.tableWidget, uiRowIdx, uiColumnIdx++, std::string(" Match History ")), &QPushButton::clicked, this, &HistoryPage::ShowMatches);
		QObject::connect(PlaceButton2TableCellWithImage(ui.tableWidget, uiRowIdx, uiColumnIdx++, g_cpDeleteButtonPNG,  0.4f, (t.IsLocked()) ? false : true), &QPushButton::clicked, this, &HistoryPage::DeleteTournament);
		QObject::connect(PlaceButton2TableCellWithImage(ui.tableWidget, uiRowIdx, uiColumnIdx++, g_cpEditButtonPNG,  0.4f, (t.IsLocked()) ? false : true), &QPushButton::clicked, this, &HistoryPage::EditTournament);
		QObject::connect(PlaceButton2TableCellWithImage(ui.tableWidget, uiRowIdx, uiColumnIdx++, (t.IsLocked()) ? ":images/lock.png" : ":images/unlock.png",  0.04f, true), &QPushButton::clicked, this, &HistoryPage::LockUnlockTournament);
	}
}
std::vector<Tournament> HistoryPage::ConcatanateTournaments()const
{
	std::vector<Tournament> vecAllTournament;
	std::for_each(m_vecOrganization.cbegin(), m_vecOrganization.cend(), [&vecAllTournament](const auto& org) {
		const auto& vecTournament = org.GetTournaments();
		vecAllTournament.insert(vecAllTournament.cend(), vecTournament.cbegin(), vecTournament.cend());
		});
	return vecAllTournament;
}
Tournament HistoryPage::FindSignalingTournament()const
{
	return m_vecDisplayedTournament[utility::FindIndexOfSignalingItem(ui.tableWidget, sender())];
}
void HistoryPage::OpenAddDialog()
{
	m_upAddEditTournamentDialog->setModal(true);
	m_upAddEditTournamentDialog->PrepareDialog(DialogMode::eAddDialog);
	m_upAddEditTournamentDialog->exec();
}
void HistoryPage::OpenEditDialog(const Tournament& t)
{
	m_upAddEditTournamentDialog->setModal(true);
	m_upAddEditTournamentDialog->PrepareDialog(DialogMode::eEditDialog, t);
	m_upAddEditTournamentDialog->exec();
}
void HistoryPage::InitFilterComponents()
{
	utility::SetComboBoxAlternatives(ui.comboBoxFilter, {"Organization", "Season", "Type", "Category", "Teammate", "Progress", "Opponent"}, true);
	if(auto* pModel = qobject_cast<QStandardItemModel*>(ui.comboBoxFilter->model()); pModel != nullptr)
	{
		if(auto* pItem = pModel->item(0); pItem != nullptr)
		{
			pItem->setFlags(pItem->flags() & ~Qt::ItemIsEnabled);
		}
	} 
	ui.comboBoxFilter->setCurrentIndex(0);
	ui.RemoveFilterButton->setVisible(false);
	ui.lineEditSearchBar->clear();
	ui.lineEditSearchBar->setEnabled(false);
	ui.tableWidget->clearSelection();
}
void HistoryPage::on_NewTournamentButton_clicked()
{
	OpenAddDialog();
}
void HistoryPage::on_RemoveFilterButton_clicked()
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
	ui.RemoveFilterButton->setVisible(true);
	if(sFilter == "Organization")
	{
		m_upActiveFilter = std::make_unique<FilterByOrganization>();
	}
	else if(sFilter == "Season")
	{
		m_upActiveFilter = std::make_unique<FilterBySeason>();
	}
	else if(sFilter == "Type")
	{
		m_upActiveFilter = std::make_unique<FilterByType>();
	}
	else if(sFilter == "Category")
	{
		m_upActiveFilter = std::make_unique<FilterByCategory>();
	}
	else if(sFilter == "Teammate")
	{
		m_upActiveFilter = std::make_unique<FilterByTeammate>();
	}
	else if(sFilter == "Progress")
	{
		m_upActiveFilter = std::make_unique<FilterByProgress>();
	}
	else if(sFilter == "Opponent")
	{
		m_upActiveFilter = std::make_unique<FilterByOpponent>();
	}
	else if(sFilter != "")
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
		m_vecDisplayedTournament = m_upActiveFilter->ApplyFilter(sFilterWord.toStdString());	
		LoadDataToTable();
		m_upActiveFilter->HighlightFilteredColumn(ui.tableWidget);
	}
	else
	{
		std::cerr << "on_lineEditSearchBar_textChanged m_upActiveFilter is nullptr!\n";
	}
}
void HistoryPage::UpdateActiveProfileData(const Profile& p)
{
	m_vecOrganization = p.GetParticipatedOrgs();
	m_vecTournament = ConcatanateTournaments();
	if (m_vecTournament.size() > 1)
	{
		std::sort(m_vecTournament.begin(), m_vecTournament.end(), [](const auto& t1, const auto& t2) {
			return !t1.IsEarlier(t2);
			});
	}
	TournamentFilter::SetUnfilteredTournaments(m_vecTournament);
	on_RemoveFilterButton_clicked();
}
void HistoryPage::UserLoggedIn(const Profile& p)
{
	if (m_blFirstLoadOfData)
	{
		UpdateActiveProfileData(p);		// To adjust the height of the rows properly.
		m_blFirstLoadOfData = false;
	}
	UpdateActiveProfileData(p);
}
void HistoryPage::ShowMatches()
{
	const auto SignalingTournament = FindSignalingTournament();
	m_upMatchesDialog->setWindowTitle(QString::fromStdString(SignalingTournament.GetName()));
	const auto vecMatches = SignalingTournament.GetMatches();
	m_upMatchesDialog->DisplayMatches(SignalingTournament);
	m_upMatchesDialog->setModal(true);
	m_upMatchesDialog->exec();
}
void HistoryPage::LockUnlockTournament()
{
	auto SignalingTournament = FindSignalingTournament();
	if (SignalingTournament.IsLocked())
	{
		QMessageBox::StandardButton reply = QMessageBox::question(this, "Unlock Tournament", "Are you sure you want to unlock this tournament? The match history of unlocked tournaments can be changed.", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			SignalingTournament.SetLocked(false);
			QMessageBox::information(this, "Information", "The tournament unlocked.");
			AppController::instance().EditTournament(SignalingTournament);
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
				QMessageBox::information(this, "Information", "The tournament locked.");
				AppController::instance().EditTournament(SignalingTournament);
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
	const auto SignalingTournament = FindSignalingTournament();
	OpenEditDialog(SignalingTournament);
}
void HistoryPage::DeleteTournament()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want delete this item permanently?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
		const auto& SignalingTournament = FindSignalingTournament();
		AppController::instance().DeleteTournament(SignalingTournament);
		QMessageBox::information(this, "Information", "The tournament deleted successfully");
	}
}