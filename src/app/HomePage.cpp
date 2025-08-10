#include <iostream>
#include <QFile>
#include <QMessageBox>
#include "HomePage.h"
#include "UpcomingMatch.h"
#include "NoUpcomingMatch.h"
#include "StatController.h"
#include "AppController.h"
#include "Config.h"
HomePage::HomePage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &HomePage::UserLoggedIn);
	QObject::connect(&AppController::instance(), &AppController::ChangeInActiveProfile, this, &HomePage::UpdateActiveProfileData);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedOut, this, &HomePage::UserLoggedOut);
	InitCustomComponents();
}

HomePage::~HomePage()
{}
void HomePage::InitCustomComponents()
{
	Countdown::setDateFormat("yyyy-MM-dd HH:mm:ss");
	InitPicture(ui.label_IconHomePage, ":images/home_page.png", 12.0f);
}
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
		InsertUpcomingMatch((iterOrg->GetOrgPictureAddr() != "") ? iterOrg->GetOrgPictureAddr() : "default_org.png", rootTournament, m);
	}
	FillWithNoUpcomingMatches();
	ui.listWidget_UpcomingMatches->setFixedSize(ui.listWidget_UpcomingMatches->sizeHintForColumn(0) + 25, g_uiUpcomingMatchHeight * g_uiMaxUpcomingMatch + 10);
	ui.groupBox_UpcomingMatches->setFixedSize(ui.listWidget_UpcomingMatches->width() + 30, ui.listWidget_UpcomingMatches->height() + 50);
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
void HomePage::InsertUpcomingMatch(const std::string& sOrgImageFile, const Tournament& t, const Match& m)
{
	auto item = new QListWidgetItem(ui.listWidget_UpcomingMatches);
	auto upcomingMatch = new UpcomingMatch(this, sOrgImageFile, t, m);
	QObject::connect(&*upcomingMatch, &UpcomingMatch::UpcomingMatchStarted, this, &HomePage::UpcomingMatchStarted);
	item->setSizeHint(QSize(upcomingMatch->width(), upcomingMatch->height()));
	ui.listWidget_UpcomingMatches->addItem(item);
	ui.listWidget_UpcomingMatches->setItemWidget(item, upcomingMatch);
}
void HomePage::InsertNoUpcomingMatch()
{
	auto item = new QListWidgetItem(ui.listWidget_UpcomingMatches);
	auto noUpcomingMatch = new NoUpcomingMatch(this);
	item->setSizeHint(QSize(noUpcomingMatch->width(), noUpcomingMatch->height()));
	ui.listWidget_UpcomingMatches->addItem(item);
	ui.listWidget_UpcomingMatches->setItemWidget(item, noUpcomingMatch);
}
void HomePage::DeleteUpcomingMatches()
{
	for (int i = 0; i < ui.listWidget_UpcomingMatches->count(); ++i) {
		QListWidgetItem* item = ui.listWidget_UpcomingMatches->item(i);
		QWidget* widget = ui.listWidget_UpcomingMatches->itemWidget(item);
		delete widget;
	}
	ui.listWidget_UpcomingMatches->clear();
}
void HomePage::FillWithNoUpcomingMatches()
{
	const auto& vecUpcomingMatches = FindUpcomingMatches();
	const int iNoUpcomingMatch = g_uiMaxUpcomingMatch - vecUpcomingMatches.size();
	for (int i = 0; i < iNoUpcomingMatch; ++i)
	{
		InsertNoUpcomingMatch();
	}
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
	DeleteUpcomingMatches();
}
void HomePage::UpdateActiveProfileData(const Profile& p)
{
	std::cout << "HomePage::UpdateOrganizations!!!!!!!!!!!!!!!\n";
	m_vecOrganization = p.GetParticipatedOrgs();
	m_vecTournament = ConcatanateTournaments();
	UpdateUpcomingMatches();
}