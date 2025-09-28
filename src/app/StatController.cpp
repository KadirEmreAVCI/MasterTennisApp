#include <algorithm>
#include "AppController.h"
#include "StatController.h"
StatController* StatController::ms_pStatController = nullptr;
void StatController::create()
{
	static StatController obj;
	ms_pStatController = &obj;
}
StatController& StatController::instance()
{
	if (ms_pStatController == nullptr)
		create();
	return *ms_pStatController;
}
StatController::StatController()
{
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &StatController::UpdateActiveProfileData);
	QObject::connect(&AppController::instance(), &AppController::ChangeInDB, this, &StatController::ChangeInDB);
}
StatController::~StatController()
{

}
std::vector<StatReport> StatController::UpdateCareerStats()
{
	m_StatMatch.AssignDataByFilter(m_vecMatch);
	m_StatMatchTiebreaks.AssignDataByFilter(m_vecMatch);
	m_StatSetTiebreaks.AssignDataByFilter(m_vecSet);
	std::vector<StatReport> vecStatReport;
	vecStatReport.emplace_back(m_StatMatch.GetStatReport());
	vecStatReport.emplace_back(m_StatSetTiebreaks.GetStatReport());
	vecStatReport.emplace_back(m_StatMatchTiebreaks.GetStatReport());
	return vecStatReport;
}
std::vector<StatReport> StatController::UpdateFinalsStats()
{
	m_StatQuarterFinals.AssignDataByFilter(m_vecMatch);
	m_StatSemiFinals.AssignDataByFilter(m_vecMatch);
	m_Stat3rdPlaceGames.AssignDataByFilter(m_vecMatch);
	m_StatFinals.AssignDataByFilter(m_vecMatch);
	std::vector<StatReport> vecStatReport;
	vecStatReport.emplace_back(m_StatQuarterFinals.GetStatReport());
	vecStatReport.emplace_back(m_StatSemiFinals.GetStatReport());
	vecStatReport.emplace_back(m_Stat3rdPlaceGames.GetStatReport());
	vecStatReport.emplace_back(m_StatFinals.GetStatReport());
	return vecStatReport;
}
std::vector<Match> StatController::ConcatanateMatches()const
{
	std::vector<Match> vecCompletedMatches;
	std::for_each(m_vecTournament.cbegin(), m_vecTournament.cend(), [&vecCompletedMatches](const auto& t) {
		const auto& vecMatch = t.GetMatches();
		std::copy(vecMatch.cbegin(), vecMatch.cend(), std::back_inserter(vecCompletedMatches));
	});
	return vecCompletedMatches;
}
std::vector<Set> StatController::ConcetanateSets()const
{
	std::vector<Set> vecAllSets;
	const auto& vecMatch = ConcatanateMatches();
	std::for_each(vecMatch.cbegin(), vecMatch.cend(), [&vecAllSets](const auto& m) {
		if(m.IsValid())
		{
			const auto& vecSet = m.GetSets();
			vecAllSets.insert(vecAllSets.cend(), vecSet.cbegin(), vecSet.cend());
		}
	});
	return vecAllSets;
}
unsigned StatController::CountQualificationFromGroupStages()const
{
	return std::count_if(m_vecTournament.cbegin(), m_vecTournament.cend(), [this](const auto& t) {
		return t.IsGroupStageExist() && GetMaxProgress(t) != "Group Stage";
		});
}
std::string StatController::GetMaxProgress(const Tournament& t)const
{
	return t.GetLastMatch().value_or(Match{}).GetStage();
}
void StatController::ChangeInDB(const std::vector<Profile>& vecProfile, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&)
{
	const auto activeProfile = std::find_if(vecProfile.cbegin(), vecProfile.cend(), [this](const Profile& p) {
		return p.GetID() == m_uiProfileID;
		});
	if (activeProfile != vecProfile.cend())
	{
		UpdateActiveProfileData(*activeProfile);
	}
}
void StatController::UpdateActiveProfileData(const Profile& p)
{
	std::cout << "StatController::UpdateTournaments\n";
	m_uiProfileID = p.GetID();
	m_vecTournament = p.GetTournaments();
	m_vecMatch = ConcatanateMatches(); 
	m_vecSet = ConcetanateSets();
	const auto& vecUpdatedCareerWLStat = UpdateCareerStats();
	emit CareerStatsUpdated(m_vecTournament.size(), CountQualificationFromGroupStages(), vecUpdatedCareerWLStat);
	const auto& vecUpdatedFinalsWLStat = UpdateFinalsStats();
	emit FinalsStatsUpdated(vecUpdatedFinalsWLStat);
}