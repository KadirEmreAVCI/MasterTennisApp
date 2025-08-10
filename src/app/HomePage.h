#pragma once
#include <string>
#include <memory>
#include <QWidget>
#include <QObject>
#include "ui_HomePage.h"
#include "IQTComponent.h"
#include "Profile.h"
class HomePage : public QWidget, public IQTComponent
{
	Q_OBJECT

public:
	HomePage(QWidget *parent = nullptr);
	~HomePage();
	void InitCustomComponents() override final;
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
