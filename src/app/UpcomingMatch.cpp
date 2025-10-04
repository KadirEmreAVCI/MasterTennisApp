#include <iostream>
#include <QTimer>
#include <QDateTime>
#include "Common.h"
#include "Organization.h"
#include "UpcomingMatch.h"
#include "MatchesDialog.h"
#include "Utility.h"
#include "DatabaseController.h"

UpcomingMatch::UpcomingMatch(const Match& m, QWidget* parent) : m_Match{m}, QWidget(parent) 
{
	setupUi(this);
	m_upMatchesDialog = std::make_unique<MatchesDialog>(this);
	m_RootTournament = DatabaseController::instance().FindRootTournament(m_Match);
	m_RootOrganization = DatabaseController::instance().FindRootOrganization(m_RootTournament);
	QObject::connect(&m_Countdown, &Countdown::TimeIsUp, this, &UpcomingMatch::MatchStarted);
	setFixedSize(common::g_uiUpcomingMatchWidth, common::g_uiUpcomingMatchHeight);
	InitializeTimer();
	InitializeCountdown();
	FillUpcomingMatchButton();
	utility::InitLabelWithPicture(label_OrgImage, m_RootOrganization.GetFullPicturePath(), 1.90f);
}
UpcomingMatch::~UpcomingMatch()
{}
void UpcomingMatch::InitializeTimer()
{
	m_upTimer = std::make_unique<QTimer>(this);
	connect(m_upTimer.get(), SIGNAL(timeout()), this, SLOT(PrintCountdown()));
	const unsigned int uiTimeoutDurMs = 1000;
	m_upTimer->start(uiTimeoutDurMs);
}
void UpcomingMatch::InitializeCountdown()
{
	m_Countdown.setMatchDate(m_Match.GetDate(), m_Match.GetTime());
}
void UpcomingMatch::FillUpcomingMatchButton()
{
	UpcomingMatchButton->setFixedSize(common::g_uiUpcomingMatchWidth - 200, common::g_uiUpcomingMatchHeight - 20);

	QWidget* container = new QWidget(UpcomingMatchButton);
	QVBoxLayout* layout = new QVBoxLayout(container);
	layout->setContentsMargins(5, 5, 5, 5);

	QLabel* TournamentNameLabel = new QLabel(QString::fromStdString(m_RootOrganization.GetName() + ", " + m_RootTournament.GetType() + ", " + m_RootTournament.GetCategory()));

	QLabel* StageLabel = new QLabel(QString::fromStdString(m_Match.GetStage()));
	std::string sOpponent = m_Match.GetOpponent1();
	if(m_RootTournament.IsDoubleTournament())
	{
		sOpponent += ("/" + m_Match.GetOpponent2());
	}
	QLabel* OpponentLabel = new QLabel(QString::fromStdString(sOpponent));

	QHBoxLayout* hLayout = new QHBoxLayout;
	QLabel* MatchDateLabel = new QLabel(m_Match.GetDate().toString("dd.MM.yyyy"));
	QLabel* SeperatorLabel = new QLabel("|");
	QLabel* MatchTimeLabel = new QLabel(m_Match.GetTime().toString("hh:mm AP"));

	hLayout->addWidget(MatchDateLabel);
	hLayout->addWidget(SeperatorLabel);
	hLayout->addWidget(MatchTimeLabel);
	hLayout->addStretch();

	QFont font;
	font.setPointSize(10);
	font.setBold(false);
	
	TournamentNameLabel->setFont(font);
	MatchDateLabel->setFont(font);
	SeperatorLabel->setFont(font);
	MatchTimeLabel->setFont(font);
	StageLabel->setFont(font);
	OpponentLabel->setFont(font);

	layout->addWidget(TournamentNameLabel);
	layout->addWidget(StageLabel);
	layout->addWidget(OpponentLabel);
	layout->addLayout(hLayout);
	layout->addStretch();
}
void UpcomingMatch::PrintCountdown()
{
	label_Countdown->setText(m_Countdown.GetCountdown());
}
void UpcomingMatch::MatchStarted()
{
	emit UpcomingMatchStarted(m_RootTournament, m_Match);
}
void UpcomingMatch::on_UpcomingMatchButton_clicked()
{
	m_upMatchesDialog->setWindowTitle(QString::fromStdString(m_RootTournament.GetName()));
	const auto& vecMatches = m_RootTournament.GetMatches();
	m_upMatchesDialog->DisplayMatches(m_RootTournament);
	m_upMatchesDialog->setModal(true);
	m_upMatchesDialog->exec();
}