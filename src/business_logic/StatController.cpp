#include <algorithm>
#include <memory>
#include "StatController.h"
#include "DataFilter.h"
#include "DatabaseController.h"

StatController::StatController()
{

}
StatController::~StatController()
{

}
std::vector<StatReport> StatController::UpdateCareerStats(const Profile& p, const std::string& sFilterType, const std::string& sFilteringItem)
{
	UpdateActiveProfileData(p, sFilterType, sFilteringItem);
	return CalculateCareerStats();
}
std::vector<Match> StatController::ConcatanateMatches()const
{
	std::vector<Match> vecMatches;
	std::for_each(m_vecTournament.cbegin(), m_vecTournament.cend(), [&](const auto& t) {
		const auto& vecMatch = t.GetMatches();
		std::copy(vecMatch.cbegin(), vecMatch.cend(), std::back_inserter(vecMatches));
	});
	return vecMatches;
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
void StatController::UpdateActiveProfileData(const Profile& p, const std::string& sFilterType, const std::string& sFilteringItem)
{
	if(sFilterType == "")
	{
		m_vecTournament = p.GetTournaments();
	}
	else
	{
		std::unique_ptr<IDataFilter<Tournament>> upActiveFilter{ nullptr };
		if(sFilterType == "Organization")
		{
			const bool blSearchForExactMatch = true;
			upActiveFilter = std::make_unique<DataFilter<Tournament, decltype([](const Tournament& t){return DatabaseController::instance().FindRootOrganization(t).GetName();})>>(blSearchForExactMatch);
		}
		else if(sFilterType == "Type")
		{   
			const bool blSearchForExactMatch = false;
			upActiveFilter = std::make_unique<DataFilter<Tournament, decltype([](const Tournament& t){return t.GetType();})>>(blSearchForExactMatch);
		}
		else if(sFilterType == "Category")
		{
			const bool blSearchForExactMatch = true;
			upActiveFilter = std::make_unique<DataFilter<Tournament, decltype([](const Tournament& t){return t.GetCategory();})>>(blSearchForExactMatch);
		}
		else
		{
			std::cerr << "StatController::UpdateActiveProfileData::Error! Unknown filter type = " << sFilterType << "\n";
		}
		m_vecTournament = upActiveFilter->ApplyFilter(p.GetTournaments(), sFilteringItem);
	} 
	m_vecMatch = ConcatanateMatches(); 
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