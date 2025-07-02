#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <QMessageBox>
#include "HistoryPage.h"
#include "AddEditTournamentDialog.h"
#include "MatchesDialog.h"
#include "AppController.h"
#include "Config.h"

HistoryPage::HistoryPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_upAddEditTournamentDialog = std::make_unique<AddEditTournamentDialog>(this);
	std::cout << "HistoryPage::HistoryPage AddEditTournamentDialog constructed successfully\n";
	m_upMatchesDialog = std::make_unique<MatchesDialog>(this);
	std::cout << "HistoryPage::HistoryPage custom components constructed successfully\n";
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &HistoryPage::UserLoggedIn);
	QObject::connect(&AppController::instance(), &AppController::ChangeInActiveProfile, this, &HistoryPage::UpdateActiveProfileData);
	InitCustomComponents();
}

HistoryPage::~HistoryPage()
{}
void HistoryPage::InitCustomComponents()
{
	m_vecColumnNames = { "", " Organization ", " Season ", " Type ", " Category ", " Teammate ", " Participant ", " Max. Progress ", " Trophy ", "", "", "", "" };
	FillColumnNamesOfTable(ui.tableWidget);
	MakeColumnHeaderBold(ui.tableWidget);
}
void HistoryPage::FillTable()
{
	unsigned int uiRowIdx{};
	for (const auto& t : m_vecTournament)
	{
		ui.tableWidget->insertRow(uiRowIdx);
		const auto& iterRootOrg = std::find_if(m_vecOrganization.cbegin(), m_vecOrganization.cend(), [t](const auto& org) {
			return org.GetID() == t.GetOrgID();
			});
		if (iterRootOrg != m_vecOrganization.end())
		{
			InsertTournament2Table(*iterRootOrg, t, uiRowIdx);
		}
		++uiRowIdx;
	}
	ui.tableWidget->resizeRowsToContents();
	ui.tableWidget->resizeColumnsToContents();
}
void HistoryPage::LoadDataToTable()
{
	ClearTable(ui.tableWidget);
	if (!m_vecTournament.empty())
	{
		FillTable();
	}
}
void HistoryPage::InsertTournament2Table(const Organization& rootOrg, const Tournament& t, unsigned uiRowIdx)
{
	unsigned uiColumnIdx{};
	if (rootOrg.GetOrgPictureAddr() != "")
	{
		InsertPic2Cell(ui.tableWidget, (Organization::GetOrgImageRootDestDir() + QString::fromStdString(rootOrg.GetOrgPictureAddr())).toStdString(), 0.07f, uiRowIdx, uiColumnIdx++);
	}
	else
	{
		InsertPic2Cell(ui.tableWidget, (Organization::GetOrgImageRootDestDir() + "default_org.png").toStdString(), 0.07f, uiRowIdx, uiColumnIdx++);
	}
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(rootOrg.GetName()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(t.GetSeason()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(t.GetType()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(t.GetCategory()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(t.GetTeammate()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(std::to_string(t.GetParticipant())), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(t.GetLastMatch().value_or(Match{}).GetStage()), uiRowIdx, uiColumnIdx++);
	InsertTrophyPic(t, uiRowIdx, uiColumnIdx++);
	InsertButton2Cell(std::string(" Match History "), &HistoryPage::ShowMatches, uiRowIdx, uiColumnIdx++);
	InsertButtonWithImage2Cell(g_cpDeleteButtonPNG, 0.4f, &HistoryPage::DeleteTournament, (t.IsLocked()) ? false : true, uiRowIdx, uiColumnIdx++);
	InsertButtonWithImage2Cell(g_cpEditButtonPNG, 0.4f, &HistoryPage::EditTournament, (t.IsLocked()) ? false : true, uiRowIdx, uiColumnIdx++);
	InsertButtonWithImage2Cell((t.IsLocked()) ? ":images/images/lock.png" : ":images/images/unlock.png", 0.04f, &HistoryPage::LockUnlockTournament, true, uiRowIdx, uiColumnIdx++);
}
void HistoryPage::InsertButton2Cell(const std::string& sButtonText, auto func, unsigned uiRowIdx, unsigned uiColumnIdx)
{
	QWidget* pWidget = new QWidget();
	QPushButton* pBtn = new QPushButton();
	pBtn->setText(QString::fromStdString(sButtonText));
	connect(pBtn, &QPushButton::clicked, this, func);
	QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
	pLayout->addWidget(pBtn);
	pLayout->setAlignment(Qt::AlignCenter);
	pLayout->setContentsMargins(0, 0, 0, 0);
	pWidget->setLayout(pLayout);
	ui.tableWidget->setCellWidget(uiRowIdx, uiColumnIdx, pWidget);
}
void HistoryPage::InsertButtonWithImage2Cell(const std::string& sImageAddr, float fScale, auto func, bool blEnabled, unsigned uiRowIdx, unsigned uiColumnIdx)
{
	QWidget* pWidget = new QWidget();
	QPushButton* pBtn = new QPushButton;
	InitButtonWithPicture(pBtn, sImageAddr, fScale);
	connect(pBtn, &QPushButton::clicked, this, func);
	pBtn->setEnabled(blEnabled);
	QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
	pLayout->addWidget(pBtn);
	pLayout->setAlignment(Qt::AlignCenter);
	pLayout->setContentsMargins(0, 0, 0, 0);
	pWidget->setLayout(pLayout);
	ui.tableWidget->setCellWidget(uiRowIdx, uiColumnIdx, pWidget);
}
void HistoryPage::InsertTrophyPic(const Tournament& t, unsigned uiRowIdx, unsigned uiColumnIdx)
{
	if (const auto& lastMatch = t.GetLastMatch(); lastMatch.has_value() && lastMatch.value().IsValid())
	{
		if (lastMatch.value().GetStage() == "Final")
		{
			if (lastMatch.value().GetOutcome() == Outcome::HomeWin)
			{
				InsertPic2Cell(ui.tableWidget, ":images/images/first_place.png", 0.085f, uiRowIdx, uiColumnIdx);
			}
			else if(lastMatch.value().GetOutcome() == Outcome::AwayWin)
			{
				InsertPic2Cell(ui.tableWidget, ":images/images/second_place.png", 0.085f, uiRowIdx, uiColumnIdx);
			}
		}
		else if (lastMatch.value().GetStage() == "3rd Place Game" && lastMatch.value().GetOutcome() == Outcome::HomeWin)
		{
			InsertPic2Cell(ui.tableWidget, ":images/images/third_place.png", 0.085f, uiRowIdx, uiColumnIdx);
		}
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
	Tournament SignalingTournament;
	QWidget* w = qobject_cast<QWidget*>(sender()->parent());
	if (w)
	{
		const unsigned int uiSignalingRow = ui.tableWidget->indexAt(w->pos()).row();
		SignalingTournament = m_vecTournament[uiSignalingRow];
	}
	return SignalingTournament;
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
void HistoryPage::on_NewTournamentButton_clicked()
{
	OpenAddDialog();
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
	LoadDataToTable();
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
	const auto& SignalingTournament = FindSignalingTournament();
	m_upMatchesDialog->setWindowTitle(QString::fromStdString(SignalingTournament.GetName()));
	const auto& vecMatches = SignalingTournament.GetMatches();
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
		const auto& vecMatch = SignalingTournament.GetMatches();
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
	const auto& SignalingTournament = FindSignalingTournament();
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