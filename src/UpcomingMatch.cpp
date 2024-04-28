#include <iostream>
#include <QTimer>
#include <QDateTime>
#include "UpcomingMatch.h"
UpcomingMatch::UpcomingMatch(QWidget *parent, std::string sTournamentName, std::string sTournamentCategory, std::string sOpponentName, std::string sStage)
	: QWidget(parent), m_sTournamentName{ sTournamentName }, m_sTournamentCategory{ sTournamentCategory }, m_sOpponentName{ sOpponentName }, m_sStage{ sStage }
{
	setupUi(this);
	InitializeCustomComponents();
}

UpcomingMatch::~UpcomingMatch()
{}

void UpcomingMatch::InitializeCustomComponents()
{
	std::cout << "UpcomingMatch::InitializeCustomComponents()\n";
	InitializeTimer();
	InitializeCountdown();
	setTournamentName();
	setTournamentCategory();
	setOpponentName();
	setStage();
}
void UpcomingMatch::InitializeTimer()
{
	m_upTimer = std::make_unique<QTimer>(this);
	connect(m_upTimer.get(), SIGNAL(timeout()), this, SLOT(PrintCountdown()));
	const unsigned int uiTimeoutDurMs = 1000;
	m_upTimer->start(uiTimeoutDurMs);
}
void UpcomingMatch::InitializeCountdown()
{
	Countdown::setDateFormat("yyyy-MM-dd HH:mm:ss");
	// TODO: sMatchDate string'i database'den elde edilecek.
	std::string sMatchDate{ "2024-05-23 19:00:00" };
	m_Countdown.setMatchDate(sMatchDate);
}
void UpcomingMatch::setTournamentName()
{
	label_TournamentName->setText(QString::fromStdString(m_sTournamentName));
}
void UpcomingMatch::setTournamentCategory()
{
	label_TournamentCategory->setText(QString::fromStdString(m_sTournamentCategory));
}
void UpcomingMatch::setOpponentName()
{
	label_Opponent->setText(QString::fromStdString(m_sOpponentName));
}
void UpcomingMatch::setStage()
{
	label_Stage->setText(QString::fromStdString(m_sStage));
}
void UpcomingMatch::PrintCountdown()
{
	label_Countdown->setText(m_Countdown.GetCountdown());
}
// TODO: Gelecek mactan once ayni turnuvada oynanan maclar goruntulenecek. Yine database gerektiriyor.
void UpcomingMatch::on_button_DisplayTournament_clicked()
{
	std::cout << "UpcomingMatch:: button_DisplayTournament()\n";
}