#ifndef UPCOMINGMATCHCARD_H
#define UPCOMINGMATCHCARD_H

#include <string>
#include <memory>
#include <QWidget>
#include <QDateTime>
#include "ui_UpcomingMatchCard.h"
#include "Organization.h"

class Timer;
class MatchesDialog;
class HomePage;
class UpcomingMatchCard : public QWidget, public Ui::UpcomingMatchCardClass{
	Q_OBJECT

public:
	UpcomingMatchCard();
	UpcomingMatchCard(const Match& m);
	~UpcomingMatchCard();
	void DecrementCountdown();
	static void SetHomePage(HomePage* pHomePage);
private:
	void ConfigureForMatch(const Match& m);
	void FillCardButton();
	QString SecondsToString(int iSeconds) const;
	Organization m_RootOrganization;
	Tournament m_RootTournament;
	Match m_Match;
	std::unique_ptr<MatchesDialog> m_upMatchesDialog;
	const QString m_sFormat = "yyyy-MM-dd HH:mm:ss";
	std::unique_ptr<Timer> m_upTimer;
	static HomePage* ms_pHomePage;
private slots:
	void on_CardButton_clicked();
};

#endif // UPCOMINGMATCHCARD_H