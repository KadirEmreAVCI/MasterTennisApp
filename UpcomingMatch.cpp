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
	setTournamentName();
	setTournamentCategory();
	setOpponentName();
	setStage();
}
void UpcomingMatch::InitializeTimer()
{
	m_upTimer = std::make_unique<QTimer>(this);
	connect(m_upTimer.get(), SIGNAL(timeout()), this, SLOT(PrintTime()));
	const unsigned int uiTimeoutDurMs = 1000;
	m_upTimer->start(uiTimeoutDurMs);
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
void UpcomingMatch::PrintTime() const
{
	//std::cout << "UpcomingMatch::PrintTime()\n";
	QTime currentTime = QTime::currentTime();
	label_TimeLeft->setText(currentTime.toString("dd : hh : mm : ss"));
}
void UpcomingMatch::on_button_DisplayTournament_clicked()
{
	std::cout << "UpcomingMatch:: button_DisplayTournament()\n";
}