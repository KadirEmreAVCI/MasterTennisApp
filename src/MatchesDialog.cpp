#include <QMessageBox>
#include <QScrollBar>
#include "AppController.h"
#include "AddEditMatchDialog.h"
#include "MatchesDialog.h"
#include "Config.h"

MatchesDialog::MatchesDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	m_upAddEditMatchDialog = std::make_unique<AddEditMatchDialog>(this);
	QObject::connect(&AppController::instance(), &AppController::ChangeInActiveProfile, this, &MatchesDialog::UpdateActiveProfileData);
	InitCustomComponents();
}
MatchesDialog::~MatchesDialog()
{

}
void MatchesDialog::InitCustomComponents()
{
	m_vecColumnNames = { " Statu ", " Outcome ", " Stage ", " Score ", " Sets ", " Opponent 1 ", " Opponent 2 ", " Date ", " Time ", "", "" };
	FillColumnNamesOfTable(ui.tableWidget);
	MakeColumnHeaderBold(ui.tableWidget);
	setFixedSize(750, 600);
}
void MatchesDialog::FillTable()
{
	unsigned int uiRowIdx{};
	for (const auto& m : m_vecMatch)
	{
		ui.tableWidget->insertRow(uiRowIdx);
		InsertMatch2Table(m, uiRowIdx);
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
void MatchesDialog::InsertMatch2Table(const Match& m, unsigned uiRowIdx)
{
	unsigned uiColumnIdx{};
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(m.GetStatu()), uiRowIdx, uiColumnIdx++);
	InsertOutcomePic(m, uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(m.GetStage()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(m.GetScore().ToString()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(m.SetsToString()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(m.GetOpponent1()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(m.GetOpponent2()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, m.GetDate().toString("dd.MM.yyyy"), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, m.GetTime().toString("hh:mm"), uiRowIdx, uiColumnIdx++);
	InsertButtonWithImage2Cell(g_cpDeleteButtonPNG, 0.4f, &MatchesDialog::DeleteMatch, (m_RootTournament.IsLocked()) ? false : true, uiRowIdx, uiColumnIdx++);
	InsertButtonWithImage2Cell(g_cpEditButtonPNG, 0.4f, &MatchesDialog::EditMatch, (m_RootTournament.IsLocked()) ? false : true, uiRowIdx, uiColumnIdx++);
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
	ClearTable(ui.tableWidget);
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
void MatchesDialog::InsertOutcomePic(const Match& m, unsigned uiRowIdx, unsigned uiColumnIdx)
{
	if (m.GetOutcome() == Outcome::HomeWin)
	{
		InsertPic2Cell(ui.tableWidget, ":images/images/win2.png", 0.04f, uiRowIdx, uiColumnIdx);
	}
	else if (m.GetOutcome() == Outcome::AwayWin)
	{
		InsertPic2Cell(ui.tableWidget, ":images/images/lose2.png", 0.04f, uiRowIdx, uiColumnIdx);
	}
	else if(m.GetOutcome() == Outcome::Tied && m.IsUpcomingMatch())
	{
		InsertPic2Cell(ui.tableWidget, ":images/images/hourglass.png", 0.04f, uiRowIdx, uiColumnIdx);
	}
	else
	{
		InsertPic2Cell(ui.tableWidget, ":images/images/Warning.png", 0.04f, uiRowIdx, uiColumnIdx);
	}
}
void MatchesDialog::InsertButtonWithImage2Cell(const std::string& sImageAddr, float fScale, auto func, bool blEnabled, unsigned uiRowIdx, unsigned uiColumnIdx)
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
Match MatchesDialog::FindSignalingMatch()const
{
	Match SignalingMatch;
	QWidget* w = qobject_cast<QWidget*>(sender()->parent());
	if (w)
	{
		const unsigned int uiSignalingRow = ui.tableWidget->indexAt(w->pos()).row();
		SignalingMatch = m_vecMatch[uiSignalingRow];
	}
	return SignalingMatch;
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
