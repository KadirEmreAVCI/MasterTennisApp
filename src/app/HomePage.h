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

class HomePage : public QWidget{
	Q_OBJECT

public:
	HomePage(QWidget *parent = nullptr);
	~HomePage();
private:
	void UpcomingMatchStarted();
	void UpdateUpcomingMatches();
	std::vector<Match> FindUpcomingMatches()const;
	std::vector<Match> FindStartedUpcomingMatches()const;
	void InsertUpcomingMatch(UpcomingMatch*);
	void InsertNoUpcomingMatch(NoUpcomingMatch*);
	void FillWithNoUpcomingMatches();
	void UpdateTopParticipations();
	std::vector<std::pair<unsigned, unsigned>> FindTopParticipations()const;
	void InsertOrgParticipation(OrgParticipation* pOrgParticipation);
	void UserLoggedIn(const Profile& p);
	void UserLoggedOut();
	Ui::HomePageClass ui;
	std::vector<Tournament> m_vecTournament;
public slots:
	void UpdateActiveProfileData(const Profile&);
};

#endif
