#include <iostream>
#include <QFile>
#include <QMessageBox>
#include "HomePage.h"
#include "UpcomingMatch.h"
#include "NoUpcomingMatch.h"
#include "OrgParticipation.h"
#include "StatController.h"
#include "AppController.h"
#include "Config.h"
#include "Utility.h"
HomePage::HomePage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &HomePage::UserLoggedIn);
	QObject::connect(&AppController::instance(), &AppController::ChangeInActiveProfile, this, &HomePage::UpdateActiveProfileData);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedOut, this, &HomePage::UserLoggedOut);
	Countdown::setDateFormat("yyyy-MM-dd HH:mm:ss");
	utility::InitLabelWithPicture(ui.label_IconHomePage, ":images/home_page.png", 12.0f);
}

HomePage::~HomePage()
{}
void HomePage::UpcomingMatchStarted()
{
	StartedUpcomingMatchesDetected();
	UpdateUpcomingMatches();
}
void HomePage::UpdateUpcomingMatches()
{
	ui.listWidget_UpcomingMatches->clear();
	auto vecUpcomingMatches = FindUpcomingMatches();
	std::sort(vecUpcomingMatches.begin(), vecUpcomingMatches.end(), [](const Match& m1, const Match& m2) {
		return m1.IsEarlier(m2);
		});
	for (const auto& m : vecUpcomingMatches)
	{
		const Tournament rootTournament = FindRootTournament(m);
		const auto& iterOrg = std::find_if(m_vecOrganization.cbegin(), m_vecOrganization.cend(), [rootTournament](const auto& org) {
			return rootTournament.GetOrgID() == org.GetID();
			});
		InsertUpcomingMatch(new UpcomingMatch(this, (iterOrg->GetOrgPictureAddr() != "") ? iterOrg->GetOrgPictureAddr() : "default_org.png", rootTournament, m));
	}
	FillWithNoUpcomingMatches();
	ui.listWidget_UpcomingMatches->setFixedSize(ui.listWidget_UpcomingMatches->sizeHintForColumn(0) + 15, g_uiUpcomingMatchHeight * g_uiMaxUpcomingMatch + 10);
	ui.groupBox_UpcomingMatches->setFixedSize(ui.listWidget_UpcomingMatches->width() + 20, ui.listWidget_UpcomingMatches->height() + 50);
}
std::vector<Match> HomePage::FindUpcomingMatches()const
{
	std::vector<Match> vecUpcomingMatches;
	for (const auto& t : m_vecTournament)
	{
		const auto& vecMatch = t.GetMatches();
		std::copy_if(vecMatch.cbegin(), vecMatch.cend(), std::back_inserter(vecUpcomingMatches), [](const Match& m) {
			return m.IsUpcomingMatch();
			});
	}
	return vecUpcomingMatches;
}
std::vector<Match> HomePage::FindStartedUpcomingMatches()const
{
	std::vector<Match> vecStartedUpcomingMatches;
	for (const auto& t : m_vecTournament)
	{
		const auto& vecMatch = t.GetMatches();
		std::copy_if(vecMatch.cbegin(), vecMatch.cend(), std::back_inserter(vecStartedUpcomingMatches), [](const Match& m) {
			return m.GetOutcome() == Outcome::Tied && !m.IsUpcomingMatch();
			});
	}
	return vecStartedUpcomingMatches;
}
void HomePage::StartedUpcomingMatchesDetected()
{
	QMessageBox::warning(this, "Started Upcoming Match", "An upcoming match which is already started has been detected. Please edit this match.");
}
void HomePage::InsertUpcomingMatch(UpcomingMatch* pUpcomingMatch)
{
	auto pInsertedUpcomingMatch = utility::InsertItem2ListWidget(ui.listWidget_UpcomingMatches, pUpcomingMatch);
	QObject::connect(&*reinterpret_cast<UpcomingMatch*>(pInsertedUpcomingMatch), &UpcomingMatch::UpcomingMatchStarted, this, &HomePage::UpcomingMatchStarted);
}
void HomePage::InsertNoUpcomingMatch(NoUpcomingMatch* pNoUpcomingMatch)
{
	utility::InsertItem2ListWidget(ui.listWidget_UpcomingMatches, pNoUpcomingMatch);
}
void HomePage::FillWithNoUpcomingMatches()
{
	const auto& vecUpcomingMatches = FindUpcomingMatches();
	const int iNoUpcomingMatch = g_uiMaxUpcomingMatch - vecUpcomingMatches.size();
	for (int i = 0; i < iNoUpcomingMatch; ++i)
	{
		InsertNoUpcomingMatch(new NoUpcomingMatch(this));
	}
}
void HomePage::UpdateTopParticipations()
{
	ui.listWidget_TopParticipations->clear();
	const auto vecTopParticipations = FindTopParticipations();
	for(const auto& prParticipation : vecTopParticipations)
	{
		const auto& org = std::find_if(m_vecOrganization.cbegin(), m_vecOrganization.cend(), [prParticipation](const Organization& org){
			return prParticipation.first == org.GetID();
		});
		InsertOrgParticipation(new OrgParticipation(this, org->GetOrgPictureAddr(), org->GetName(), prParticipation.second));
	}
	ui.listWidget_TopParticipations->setFixedHeight(280);
}
std::vector<std::pair<unsigned, unsigned>> HomePage::FindTopParticipations()const
{	
	std::map<unsigned, unsigned> mapParticipationCount;
	std::ranges::for_each(m_vecTournament, [this, &mapParticipationCount](const Tournament& t){
		mapParticipationCount[t.GetOrgID()]++;
	});
	std::vector<std::pair<unsigned, unsigned>> vecTopParticipations{mapParticipationCount.cbegin(), mapParticipationCount.cend()};
	std::sort(vecTopParticipations.begin(), vecTopParticipations.end(), [this](const auto& p1, const auto& p2){
		return p1.second > p2.second;
	});
	return vecTopParticipations;
}
void HomePage::InsertOrgParticipation(OrgParticipation* pOrgParticipation)
{
	utility::InsertItem2ListWidget(ui.listWidget_TopParticipations, pOrgParticipation);
}
std::vector<Tournament> HomePage::ConcatanateTournaments()const
{
	std::vector<Tournament> vecAllTournament;
	std::for_each(m_vecOrganization.cbegin(), m_vecOrganization.cend(), [&vecAllTournament](const auto& org) {
		const auto& vecTournament = org.GetTournaments();
		vecAllTournament.insert(vecAllTournament.cend(), vecTournament.cbegin(), vecTournament.cend());
		});
	return vecAllTournament;
}
Tournament HomePage::FindRootTournament(const Match& m)const
{
	const auto& iterRooutTournament = std::find_if(m_vecTournament.cbegin(), m_vecTournament.cend(), [m](const auto& t) {
		return m.GetTournamentID() == t.GetID();
		});
	return *iterRooutTournament;
}
void HomePage::UserLoggedIn(const Profile& p)
{
	UpdateActiveProfileData(p);
	if (!FindStartedUpcomingMatches().empty())
	{
		StartedUpcomingMatchesDetected();
	}
}
void HomePage::UserLoggedOut()
{
	utility::ClearListWidget(ui.listWidget_TopParticipations);
	utility::ClearListWidget(ui.listWidget_UpcomingMatches);
}
void HomePage::UpdateActiveProfileData(const Profile& p)
{
	std::cout << "HomePage::UpdateOrganizations!!!!!!!!!!!!!!!\n";
	m_vecOrganization = p.GetParticipatedOrgs();
	m_vecTournament = ConcatanateTournaments();
	UpdateUpcomingMatches();
	UpdateTopParticipations();
}