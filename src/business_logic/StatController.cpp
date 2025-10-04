#include <algorithm>
#include "StatController.h"
StatController::StatController()
{

}
StatController::~StatController()
{

}
std::vector<StatReport> StatController::UpdateCareerStatsByCategory(const Profile& p, const std::string& sCategory)
{
	UpdateActiveProfileData(p, sCategory);
	return CalculateCareerStats();
}
std::vector<Match> StatController::ConcatanateMatchesByCategory(const std::string& sCategory)const
{
	std::vector<Match> vecCompletedMatches;
	std::for_each(m_vecTournament.cbegin(), m_vecTournament.cend(), [&](const auto& t) {
		const auto& vecMatch = t.GetMatches();
		std::copy_if(vecMatch.cbegin(), vecMatch.cend(), std::back_inserter(vecCompletedMatches), [&](const Match&){
			return (sCategory == "") || (sCategory == t.GetCategory());
		});
	});
	return vecCompletedMatches;
}
std::vector<Set> StatController::ConcetanateSets()const
{
	std::vector<Set> vecAllSets;
	std::for_each(m_vecMatch.cbegin(), m_vecMatch.cend(), [&vecAllSets](const auto& m) {
		if(m.IsValid())
		{
			const auto& vecSet = m.GetSets();
			vecAllSets.insert(vecAllSets.cend(), vecSet.cbegin(), vecSet.cend());
		}
	});
	return vecAllSets;
}
void StatController::UpdateActiveProfileData(const Profile& p, const std::string& sCategory)
{
	m_vecTournament = p.GetTournaments();
	m_vecMatch = ConcatanateMatchesByCategory(sCategory); 
	m_vecSet = ConcetanateSets();
}
std::vector<StatReport> StatController::CalculateCareerStats()
{
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