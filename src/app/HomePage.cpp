#include <iostream>
#include <QFile>
#include <QMessageBox>
#include "HomePage.h"
#include "UpcomingMatch.h"
#include "OrgParticipation.h"
#include "StatController.h"
#include "AppController.h"
#include "Common.h"
#include "Utility.h"
#include "DatabaseController.h"
#include "Timer.h"	
HomePage::HomePage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &HomePage::UserLoggedIn);
	QObject::connect(&AppController::instance(), &AppController::ChangeInDB, this, &HomePage::ChangeInDB);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedOut, this, &HomePage::UserLoggedOut);
	StartTimer();
	utility::InitLabelWithPicture(ui.label_IconHomePage, ":images/home_page.png", 12.0f);
}

HomePage::~HomePage()
{}
void HomePage::UpcomingMatchStarted()
{
	if(!m_vecpUpcomingMatchCards.empty() && !m_vecUpcomingMatch.empty())
	{
		m_vecpUpcomingMatchCards.erase(m_vecpUpcomingMatchCards.begin());
		utility::DeleteItemFromListWidget(ui.listWidget_UpcomingMatches, 0);
		m_vecUpcomingMatch.erase(m_vecUpcomingMatch.begin());
	}
}
void HomePage::StartTimer()
{
	m_upCountdownTimer = std::make_unique<Timer>(TimerMode::Periodic, std::chrono::seconds(1), [this]() {
		std::for_each(m_vecpUpcomingMatchCards.begin(), m_vecpUpcomingMatchCards.end(), [](UpcomingMatch* pUpcomingMatchCard) {
			pUpcomingMatchCard->PrintCountdown();
			});
		});
	m_upCountdownTimer->Start();
}
void HomePage::UpdateUpcomingMatches()
{
	m_vecpUpcomingMatchCards.clear();
	ui.listWidget_UpcomingMatches->clear();
	FindUpcomingMatches();
	std::sort(m_vecUpcomingMatch.begin(), m_vecUpcomingMatch.end(), [](const Match& m1, const Match& m2) {
		return m1.IsEarlier(m2);
		});
	for (const auto& m : m_vecUpcomingMatch)
	{
		m_vecpUpcomingMatchCards.push_back(new UpcomingMatch(m, this));
		utility::InsertItem2ListWidget(ui.listWidget_UpcomingMatches, m_vecpUpcomingMatchCards.back());
	}
	ui.listWidget_UpcomingMatches->setFixedSize(ui.listWidget_UpcomingMatches->sizeHintForColumn(0) + 15, common::g_uiUpcomingMatchHeight * common::g_uiMaxUpcomingMatch + 10);
	ui.groupBox_UpcomingMatches->setFixedSize(ui.listWidget_UpcomingMatches->width() + 20, ui.listWidget_UpcomingMatches->height() + 50);
}
void HomePage::FindUpcomingMatches()
{
	m_vecUpcomingMatch.clear();
	for (const auto& t : m_vecTournament)
	{
		const auto& vecMatch = t.GetMatches();
		std::copy_if(vecMatch.cbegin(), vecMatch.cend(), std::back_inserter(m_vecUpcomingMatch), [](const Match& m) {
			return m.IsUpcomingMatch();
			});
	}
}	
std::vector<Match> HomePage::FindStartedUpcomingMatches()const
{
	std::vector<Match> vecStartedUpcomingMatches;
	for (const auto& t : m_vecTournament)
	{
		const auto& vecMatch = t.GetMatches();
		std::copy_if(vecMatch.cbegin(), vecMatch.cend(), std::back_inserter(vecStartedUpcomingMatches), [](const Match& m) {
			return m.GetOutcome() == common::Outcome::Tied && !m.IsUpcomingMatch();
			});
	}
	return vecStartedUpcomingMatches;
}
void HomePage::UpdateTopParticipations()
{
	ui.listWidget_TopParticipations->clear();
	const auto vecTopParticipations = FindTopParticipations();
	for(const auto& prParticipation : vecTopParticipations)
	{
		const auto& t = std::find_if(m_vecTournament.cbegin(), m_vecTournament.cend(), [prParticipation](const Tournament& t){
			return prParticipation.first == t.GetOrgID();
		});
		InsertOrgParticipation(new OrgParticipation(DatabaseController::instance().FindRootOrganization(*t), prParticipation.second, this));
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
void HomePage::UserLoggedIn(const Profile& p)
{
	m_uiProfileID = p.GetID();
	UpdateActiveProfileData(p);
	if (!FindStartedUpcomingMatches().empty())
	{
		QMessageBox::warning(this, "Started Upcoming Match", "An upcoming match which is already started has been detected. Please edit this match.");
	}
}
void HomePage::UserLoggedOut()
{
	utility::ClearListWidget(ui.listWidget_TopParticipations);
	utility::ClearListWidget(ui.listWidget_UpcomingMatches);
}
void HomePage::ChangeInDB(const std::vector<Profile>& vecProfile, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&)
{	
	const auto activeProfile = std::find_if(vecProfile.cbegin(), vecProfile.cend(), [this](const Profile& p) {
		return p.GetID() == m_uiProfileID;
		});
	if(activeProfile != vecProfile.cend())
	{
		UpdateActiveProfileData(*activeProfile);
	}
}
void HomePage::UpdateActiveProfileData(const Profile& p)
{
	m_vecTournament = p.GetTournaments();
	UpdateUpcomingMatches();
	UpdateTopParticipations();
}