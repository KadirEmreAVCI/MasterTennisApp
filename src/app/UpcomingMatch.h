#ifndef UPCOMINGMATCH_H
#define UPCOMINGMATCH_H

#include <string>
#include <memory>
#include <QWidget>
#include <QDateTime>
#include "ui_UpcomingMatch.h"
//#include "Countdown.h"
#include "Organization.h"
//class QTimer;
class MatchesDialog;
class UpcomingMatch : public QWidget, public Ui::UpcomingMatchClass{
	Q_OBJECT

public:
	UpcomingMatch(const Match& m, QWidget* parent = nullptr);
	~UpcomingMatch();
	void PrintCountdown();
private:
	//void InitializeTimer();
	//void InitializeCountdown();
	void FillUpcomingMatchButton();
	QString SecondsToString(int seconds) const;
	//std::unique_ptr<QTimer> m_upTimer{ nullptr };
	//Countdown m_Countdown;
	Organization m_RootOrganization;
	Tournament m_RootTournament;
	Match m_Match;
	std::unique_ptr<MatchesDialog> m_upMatchesDialog;
	const QString m_sFormat = "yyyy-MM-dd HH:mm:ss";
private slots:
	void on_UpcomingMatchButton_clicked();
public slots:
	void MatchStarted();
signals:
	void UpcomingMatchStarted(const Tournament& t, const Match& m);
};

#endif