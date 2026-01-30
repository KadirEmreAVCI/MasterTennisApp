#ifndef UPCOMINGMATCH_H
#define UPCOMINGMATCH_H

#include <string>
#include <memory>
#include <QWidget>
#include <QDateTime>
#include "ui_UpcomingMatch.h"
#include "Organization.h"

class Timer;
class MatchesDialog;
class HomePage;
class UpcomingMatch : public QWidget, public Ui::UpcomingMatchClass{
	Q_OBJECT

public:
	UpcomingMatch();
	UpcomingMatch(const Match& m);
	~UpcomingMatch();
	void DecrementCountdown();
	static void SetHomePage(HomePage* pHomePage);
private:
	void ConfigureForMatch(const Match& m);
	void FillUpcomingMatchButton();
	QString SecondsToString(int iSeconds) const;
	Organization m_RootOrganization;
	Tournament m_RootTournament;
	Match m_Match;
	std::unique_ptr<MatchesDialog> m_upMatchesDialog;
	const QString m_sFormat = "yyyy-MM-dd HH:mm:ss";
	std::unique_ptr<Timer> m_upTimer;
	static HomePage* ms_pHomePage;
private slots:
	void on_UpcomingMatchButton_clicked();
};

#endif