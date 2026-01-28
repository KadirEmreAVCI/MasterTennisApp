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
private:
	void UpcomingMatchStarted();
	void UpdateUpcomingMatches();
	void FindUpcomingMatches();
	std::vector<Match> FindStartedUpcomingMatches()const;
	void InsertUpcomingMatch(UpcomingMatch*);
	void InsertNoUpcomingMatch(NoUpcomingMatch*);
	void FillWithNoUpcomingMatches();
	void UpdateTopParticipations();
	std::vector<std::pair<unsigned, unsigned>> FindTopParticipations()const;
	void InsertOrgParticipation(OrgParticipation* pOrgParticipation);
	void UserLoggedIn(const Profile& p);
	void UserLoggedOut();
	void ChangeInDB(const std::vector<Profile>&, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&);
	void UpdateActiveProfileData(const Profile&);
	Ui::HomePageClass ui;
	std::vector<Tournament> m_vecTournament;
	std::vector<Match> m_vecUpcomingMatch;
	std::vector<UpcomingMatch*> m_vecpUpcomingMatchCards;
	std::unique_ptr<Timer> m_upRefreshTimer{ nullptr };
	unsigned m_uiProfileID = 0;	
};

#endif
