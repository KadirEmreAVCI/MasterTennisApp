#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <string>
#include <memory>
#include <map>
#include <QWidget>
#include <QObject>
#include "ui_HomePage.h"
#include "Profile.h"
class OrgParticipation;
class HomePage : public QWidget
{
	Q_OBJECT

public:
	HomePage(QWidget *parent = nullptr);
	~HomePage();
private:
	void UpcomingMatchStarted();
	void UpdateUpcomingMatches();
	std::vector<Match> FindUpcomingMatches()const;
	std::vector<Match> FindStartedUpcomingMatches()const;
	void StartedUpcomingMatchesDetected();
	void InsertUpcomingMatch(const std::string& sOrgImageFile, const Tournament& t, const Match& m);
	void InsertNoUpcomingMatch();
	void DeleteUpcomingMatches();
	void FillWithNoUpcomingMatches();
	void UpdateTopParticipations();
	std::vector<std::pair<unsigned, unsigned>> FindTopParticipations()const;
	void InsertOrgParticipation(OrgParticipation* pOrgParticipation);
	void DeleteTopParticipations();
	std::vector<Tournament> ConcatanateTournaments()const;
	Tournament FindRootTournament(const Match& m)const;
	void UserLoggedIn(const Profile& p);
	void UserLoggedOut();
	Ui::HomePageClass ui;
	std::vector<Tournament> m_vecTournament;
	std::vector<Organization> m_vecOrganization;
public slots:
	void UpdateActiveProfileData(const Profile&);
};

#endif
