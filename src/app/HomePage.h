#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <string>
#include <memory>
#include <map>
#include <QWidget>
#include <QObject>
#include "ui_HomePage.h"
#include "Profile.h"

class UpcomingMatch;
class NoUpcomingMatch;
class OrgParticipation;
class Timer;

class HomePage : public QWidget{
	Q_OBJECT

public:
	HomePage(QWidget *parent = nullptr);
	~HomePage();
	void UpcomingMatchStarted();
private:
	void UpdateCountdowns();
	void UpdateUpcomingMatches();
	void FindUpcomingMatches();
	std::vector<Match> FindStartedUpcomingMatches()const;
	void UpdateTopParticipations();
	std::vector<std::pair<unsigned, unsigned>> FindTopParticipations()const;
	void InsertOrgParticipation(OrgParticipation* pOrgParticipation);
	void UserLoggedIn(const Profile& p);
	void UserLoggedOut();
	void ChangeInDB(const std::vector<Profile>&, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&);
	void UpdateActiveProfileData(const Profile&);
	Ui::HomePageClass ui;
	std::vector<Tournament> m_vecTournament;
	std::unique_ptr<Timer> m_upCountdownTimer{ nullptr };
	unsigned m_uiProfileID = 0;	
};

#endif
