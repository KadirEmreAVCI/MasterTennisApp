#pragma once
#include <string>
#include <memory>
#include <QWidget>
#include "ui_UpcomingMatch.h"
#include "IQTComponent.h"
class QTimer;
class UpcomingMatch : public QWidget, public Ui::UpcomingMatchClass, public IQTComponent
{
	Q_OBJECT

public:
	UpcomingMatch(QWidget* parent = nullptr, std::string sTournamentName = {}, std::string sTournamentCategory = {}, std::string sOpponentName = {}, std::string sStage = {});
	~UpcomingMatch();
	void InitializeCustomComponents() override final;
private:
	void InitializeTimer();
	void setTournamentName();
	void setTournamentCategory();
	void setOpponentName();
	void setStage();
	std::unique_ptr<QTimer> m_upTimer{ nullptr };
	std::string m_sTournamentName{};
	std::string m_sTournamentCategory{};
	std::string m_sOpponentName{};
	std::string m_sStage{};
private slots:
	void PrintTime() const;
	void on_button_DisplayTournament_clicked();
};
