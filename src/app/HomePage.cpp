#include <iostream>
#include <QFile>
#include <set>
#include <QMessageBox>
#include "HomePage.h"
#include "UpcomingMatchCard.h"
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
	utility::InitLabelWithPicture(ui.label_IconHomePage, ":images/home_page.png", 12.0f);
	UpcomingMatchCard::SetHomePage(this);
	m_upCountdownTimer = std::make_unique<Timer>(TimerMode::Periodic, std::chrono::seconds(1), [this]() {
		QMetaObject::invokeMethod(this, [this]() { DecrementCountdowns(); }, Qt::QueuedConnection);
	});
	m_upCountdownTimer->Start();
}
HomePage::~HomePage()
{
	if(m_upCountdownTimer)
	{
		m_upCountdownTimer->Stop();
	}
}
void HomePage::UpcomingMatchStarted()
{
	if(ui.listWidget_UpcomingMatchCards->count() > 0)
	{
		utility::DeleteItemFromListWidget(ui.listWidget_UpcomingMatchCards, 0);
	}
}
void HomePage::DecrementCountdowns()
{
    for(int idx = 0; idx < ui.listWidget_UpcomingMatchCards->count(); ++idx)
    {
        if(auto* pUpcomingMatchCard = qobject_cast<UpcomingMatchCard*>(ui.listWidget_UpcomingMatchCards->itemWidget(ui.listWidget_UpcomingMatchCards->item(idx))))
        {
            pUpcomingMatchCard->DecrementCountdown();
        }
    }
}
void HomePage::UpdateUpcomingMatchCards()
{
	utility::ClearListWidget(ui.listWidget_UpcomingMatchCards);
	std::multiset<Match, decltype([](const Match& m1, const Match& m2) {return m1.IsEarlier(m2);})> setUpcomingMatchCards;
	for(const auto& t : m_vecTournament)
	{
		const auto vecMatches = t.GetMatches();
		std::copy_if(vecMatches.cbegin(), vecMatches.cend(), std::inserter(setUpcomingMatchCards, setUpcomingMatchCards.end()), [](const Match& m) {
			return m.IsUpcomingMatch();
			});
	}
	if(setUpcomingMatchCards.empty())
	{
		utility::InsertItem2ListWidget(ui.listWidget_UpcomingMatchCards, new UpcomingMatchCard());
	}
	else
	{
		for(const auto& m : setUpcomingMatchCards)
		{
			utility::InsertItem2ListWidget(ui.listWidget_UpcomingMatchCards, new UpcomingMatchCard(m));
		}
	}
	ui.listWidget_UpcomingMatchCards->setFixedSize(ui.listWidget_UpcomingMatchCards->sizeHintForColumn(0) + 15, common::g_uiUpcomingMatchCardHeight * common::g_uiMaxUpcomingMatchCards + 10);
	ui.groupBox_UpcomingMatchCards->setFixedSize(ui.listWidget_UpcomingMatchCards->width() + 20, ui.listWidget_UpcomingMatchCards->height() + 50);
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
		utility::InsertItem2ListWidget(ui.listWidget_TopParticipations, new OrgParticipation(DatabaseController::instance().FindRootOrganization(*t), prParticipation.second, this));
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
void HomePage::UserLoggedIn(const Profile& p)
{
	m_uiProfileID = p.GetID();
	UpdateActiveProfileData(p);
	bool blOngoingMatchExist = false;
	for (const auto& t : m_vecTournament)
	{
		const auto& vecMatch = t.GetMatches();
		blOngoingMatchExist = std::any_of(vecMatch.cbegin(), vecMatch.cend(), [](const Match& m) {
			return m.GetOutcome() == common::Outcome::Tied && !m.IsUpcomingMatch();
			});
		if (blOngoingMatchExist)
		{
			break;
		}
	}
	if (blOngoingMatchExist)
	{
		QMessageBox::warning(this, "Started Upcoming Match", "An upcoming match which is already started has been detected. Please edit this match.");
	}
}
void HomePage::UserLoggedOut()
{
	utility::ClearListWidget(ui.listWidget_TopParticipations);
	utility::ClearListWidget(ui.listWidget_UpcomingMatchCards);
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
	UpdateUpcomingMatchCards();
	UpdateTopParticipations();
}