#include <iostream>
#include <QTimer>
#include <QDateTime>
#include "Common.h"
#include "Organization.h"
#include "UpcomingMatchCard.h"
#include "MatchesDialog.h"
#include "Utility.h"
#include "DatabaseController.h"
#include "Timer.h"
#include "HomePage.h"

UpcomingMatchCard::UpcomingMatchCard()
{
	setupUi(this);
	setFixedSize(common::g_uiUpcomingMatchCardWidth, common::g_uiUpcomingMatchCardHeight);
	CardButton->hide();
	label_Countdown->hide();
	label_OrgImage->hide();
}
UpcomingMatchCard::UpcomingMatchCard(const Match& m) : UpcomingMatchCard()
{
	ConfigureForMatch(m);
}
UpcomingMatchCard::~UpcomingMatchCard()
{
	if(m_upTimer)
	{
		m_upTimer->Stop();
	}
}
void UpcomingMatchCard::ConfigureForMatch(const Match& m)
{
	m_Match = m;
    m_RootTournament = DatabaseController::instance().FindRootTournament(m_Match);
    m_RootOrganization = DatabaseController::instance().FindRootOrganization(m_RootTournament);
    FillCardButton();
    utility::InitLabelWithPicture(label_OrgImage, m_RootOrganization.GetFullPicturePath(), 1.90f);
	m_upTimer = std::make_unique<Timer>(TimerMode::OneShot, std::chrono::seconds(QDateTime::currentDateTime().secsTo(QDateTime{m_Match.GetDate(), m_Match.GetTime()}) + 1),
		[this]() {
			QMetaObject::invokeMethod(&HomePage::instance(), [this]() { HomePage::instance().UpcomingMatchStarted(); }, Qt::QueuedConnection);
		});
	m_upTimer->Start();
	CardButton->show();
	label_Countdown->show();
	label_OrgImage->show();
}
void UpcomingMatchCard::FillCardButton()
{
	CardButton->setFixedSize(common::g_uiUpcomingMatchCardWidth - 200, common::g_uiUpcomingMatchCardHeight - 20);

	QWidget* container = new QWidget(CardButton);
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
QString UpcomingMatchCard::SecondsToString(int iSeconds) const
{
	constexpr int SEC_PER_DAY = 86400;
	const int iDays = iSeconds / SEC_PER_DAY;
	const QTime t = QTime(0, 0).addSecs(iSeconds % SEC_PER_DAY);
	return QString("%1 Days %2:%3:%4").arg(iDays, 3).arg(t.hour(), 2, 10, QChar('0')).arg(t.minute(), 2, 10, QChar('0')).arg(t.second(), 2, 10, QChar('0'));
}
void UpcomingMatchCard::DecrementCountdown()
{
	if(m_Match.IsUpcomingMatch())
	{
		label_Countdown->setText(SecondsToString(QDateTime::currentDateTime().secsTo(QDateTime{m_Match.GetDate(), m_Match.GetTime()})));
	}
}
void UpcomingMatchCard::on_CardButton_clicked()
{
	emit UpcomingMatchCardClicked(m_RootTournament);
}