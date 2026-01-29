#include <iostream>
#include <QTimer>
#include <QDateTime>
#include "Common.h"
#include "Organization.h"
#include "UpcomingMatch.h"
#include "MatchesDialog.h"
#include "Utility.h"
#include "DatabaseController.h"
#include "Timer.h"
#include "HomePage.h"

UpcomingMatch::UpcomingMatch(const Match& m, QWidget* parent) : m_Match{m}, m_pHomePage{reinterpret_cast<HomePage*>(parent)} 
{
	setupUi(this);
	m_upMatchesDialog = std::make_unique<MatchesDialog>(this);
	m_RootTournament = DatabaseController::instance().FindRootTournament(m_Match);
	m_RootOrganization = DatabaseController::instance().FindRootOrganization(m_RootTournament);
	m_MatchStartTime = QDateTime{m_Match.GetDate(), m_Match.GetTime()};
	setFixedSize(common::g_uiUpcomingMatchWidth, common::g_uiUpcomingMatchHeight);
	FillUpcomingMatchButton();
	utility::InitLabelWithPicture(label_OrgImage, m_RootOrganization.GetFullPicturePath(), 1.90f);
	if(m_pHomePage)
	{
		m_upTimer = std::make_unique<Timer>(TimerMode::OneShot, std::chrono::seconds(QDateTime::currentDateTime().secsTo(m_MatchStartTime) + 1), [this]() {
			QMetaObject::invokeMethod(m_pHomePage, [this]() {m_pHomePage->UpcomingMatchStarted();}, Qt::QueuedConnection);	// Use QueuedConnection to avoid cross-thread issues
		});
		m_upTimer->Start();
	}
	else
	{
		std::cout << "UpcomingMatch::UpcomingMatch m_pHomePage is nullptr!";
	}
}
UpcomingMatch::~UpcomingMatch()
{
	m_upTimer->Stop();
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
QString UpcomingMatch::SecondsToString(int seconds) const
{
	constexpr int SEC_PER_DAY = 86400;
	int days = seconds / SEC_PER_DAY;
	QTime t = QTime(0, 0).addSecs(seconds % SEC_PER_DAY);
	return QString("%1 Days %2:%3:%4").arg(days, 3).arg(t.hour(), 2, 10, QChar('0')).arg(t.minute(), 2, 10, QChar('0')).arg(t.second(), 2, 10, QChar('0'));
}
void UpcomingMatch::PrintCountdown()
{
	label_Countdown->setText(SecondsToString(QDateTime::currentDateTime().secsTo(m_MatchStartTime)));
}
void UpcomingMatch::on_UpcomingMatchButton_clicked()
{
	m_upMatchesDialog->setWindowTitle(QString::fromStdString(m_RootTournament.GetName()));
	const auto& vecMatches = m_RootTournament.GetMatches();
	m_upMatchesDialog->DisplayMatches(m_RootTournament);
	m_upMatchesDialog->setModal(true);
	m_upMatchesDialog->exec();
}