#include <algorithm>
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
}
StatController::~StatController()
{

}
std::vector<StatReport> StatController::GetUpdatedCareerStats(const Profile& p)
{
	UpdateActiveProfileData(p);
	m_StatMatch.AssignDataByFilter(m_vecMatch);
	m_StatMatchTiebreaks.AssignDataByFilter(m_vecMatch);
	m_StatSetTiebreaks.AssignDataByFilter(m_vecSet);
	m_StatQuarterFinals.AssignDataByFilter(m_vecMatch);
	m_StatSemiFinals.AssignDataByFilter(m_vecMatch);
	m_Stat3rdPlaceGames.AssignDataByFilter(m_vecMatch);
	m_StatFinals.AssignDataByFilter(m_vecMatch);
	std::vector<StatReport> vecStatReport;
	vecStatReport.emplace_back(m_StatMatch.GetStatReport());
	vecStatReport.emplace_back(m_StatMatchTiebreaks.GetStatReport());
	vecStatReport.emplace_back(m_StatSetTiebreaks.GetStatReport());
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
void StatController::UpdateActiveProfileData(const Profile& p)
{
	m_vecTournament = p.GetTournaments();
	m_vecMatch = ConcatanateMatches(); 
	m_vecSet = ConcetanateSets();
}