#ifndef UPCOMINGMATCH_H
#define UPCOMINGMATCH_H

#include <string>
#include <memory>
#include <QWidget>
#include <QDateTime>
#include "ui_UpcomingMatch.h"
#include "IQTComponent.h"
#include "Countdown.h"
#include "Organization.h"
class QTimer;
class MatchesDialog;
class UpcomingMatch : public QWidget, public Ui::UpcomingMatchClass, public IQTComponent
{
	Q_OBJECT

public:
	UpcomingMatch(QWidget* parent = nullptr, const std::string& sOrgImageFile = {}, const Tournament& t = Tournament{}, const Match& m = Match{});
	~UpcomingMatch();
private:
	void InitCustomComponents() override final;
	void InitializeTimer();
	void InitializeCountdown();
	void SetOrganizationImage();
	void FillUpcomingMatchButton();
	std::unique_ptr<QTimer> m_upTimer{ nullptr };
	Countdown m_Countdown;
	std::string m_sOrgImageFile;
	Tournament m_Tournament{};
	Match m_Match;
	std::unique_ptr<MatchesDialog> m_upMatchesDialog;
private slots:
	void PrintCountdown();
	void on_UpcomingMatchButton_clicked();
public slots:
	void MatchStarted();
signals:
	void UpcomingMatchStarted(const Tournament& t, const Match& m);
};

#endif