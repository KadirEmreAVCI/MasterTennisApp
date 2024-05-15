#pragma once
#include <string>
#include <memory>
#include <QWidget>
#include <QDateTime>
#include "ui_UpcomingMatch.h"
#include "IQTComponent.h"
#include "Countdown.h"
class QTimer;
class UpcomingMatch : public QWidget, public Ui::UpcomingMatchClass, public IQTComponent
{
	Q_OBJECT

public:
	UpcomingMatch(QWidget* parent = nullptr, std::string sTournamentName = {}, std::string sTournamentCategory = {}, std::string sOpponentName = {}, std::string sStage = {});
	~UpcomingMatch();
	void InitCustomComponents() override final;
private:
	void InitializeTimer();
	void InitializeCountdown();
	void setTournamentName();
	void setTournamentCategory();
	void setOpponentName();
	void setStage();
	std::unique_ptr<QTimer> m_upTimer{ nullptr };
	Countdown m_Countdown;
	std::string m_sTournamentName{};
	std::string m_sTournamentCategory{};
	std::string m_sOpponentName{};
	std::string m_sStage{};
private slots:
	void PrintCountdown();
	void on_button_DisplayTournament_clicked();
};
