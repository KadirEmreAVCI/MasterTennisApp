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
	UpcomingMatch(const Match& m, QWidget* parent = nullptr);
	~UpcomingMatch();
	void PrintCountdown();
private:
	void FillUpcomingMatchButton();
	QString SecondsToString(int seconds) const;
	Organization m_RootOrganization;
	Tournament m_RootTournament;
	Match m_Match;
	QDateTime m_MatchStartTime;
	std::unique_ptr<MatchesDialog> m_upMatchesDialog;
	const QString m_sFormat = "yyyy-MM-dd HH:mm:ss";
	std::unique_ptr<Timer> m_upTimer;
	HomePage* m_pHomePage{ nullptr };
private slots:
	void on_UpcomingMatchButton_clicked();
};

#endif