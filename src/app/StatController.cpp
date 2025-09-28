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
std::array<WinLoseStat, gTotalCareerStat> StatController::UpdateCareerStats()
{
	m_StatMatch.AssignDataByFilter(m_vecMatch);
	m_StatMatchTiebreaks.AssignDataByFilter(m_vecMatch);
	m_StatSetTiebreaks.AssignDataByFilter(m_vecSet);
	std::array<WinLoseStat, gTotalCareerStat> arrWLStat;
	size_t arrIdx = 0;
	arrWLStat[arrIdx++] = WinLoseStat(m_StatMatch.GetWins(), m_StatMatch.GetLoses());
	arrWLStat[arrIdx++] = WinLoseStat(m_StatSetTiebreaks.GetWins(), m_StatSetTiebreaks.GetLoses());
	arrWLStat[arrIdx++] = WinLoseStat(m_StatMatchTiebreaks.GetWins(), m_StatMatchTiebreaks.GetLoses());
	return arrWLStat;
}
std::array<WinLoseStat, gTotalFinalStat> StatController::UpdateFinalsStats()
{
	m_StatQuarterFinals.AssignDataByFilter(m_vecMatch);
	m_StatSemiFinals.AssignDataByFilter(m_vecMatch);
	m_Stat3rdPlaceGames.AssignDataByFilter(m_vecMatch);
	m_StatFinals.AssignDataByFilter(m_vecMatch);
	std::array<WinLoseStat, gTotalFinalStat> arrWLStat;
	size_t arrIdx = 0;
	arrWLStat[arrIdx++] = WinLoseStat(m_StatQuarterFinals.GetWins(), m_StatQuarterFinals.GetLoses());
	arrWLStat[arrIdx++] = WinLoseStat(m_StatSemiFinals.GetWins(), m_StatSemiFinals.GetLoses());
	arrWLStat[arrIdx++] = WinLoseStat(m_Stat3rdPlaceGames.GetWins(), m_Stat3rdPlaceGames.GetLoses());
	arrWLStat[arrIdx++] = WinLoseStat(m_StatFinals.GetWins(), m_StatFinals.GetLoses());
	return arrWLStat;
}
std::vector<Match> StatController::ConcatanateValidMatches()const
{
	std::vector<Match> vecCompletedMatches;
	std::for_each(m_vecTournament.cbegin(), m_vecTournament.cend(), [&vecCompletedMatches](const auto& t) {
		const auto& vecMatch = t.GetMatches();
		std::copy_if(vecMatch.cbegin(), vecMatch.cend(), std::back_inserter(vecCompletedMatches), [](const auto& m) {
			return m.IsValid();
			});
		});
	return vecCompletedMatches;
}
std::vector<Set> StatController::ConcetanateSets()const
{
	std::vector<Set> vecAllSets;
	const auto& vecMatch = ConcatanateValidMatches();
	std::for_each(vecMatch.cbegin(), vecMatch.cend(), [&vecAllSets](const auto& m) {
		const auto& vecSet = m.GetSets();
		vecAllSets.insert(vecAllSets.cend(), vecSet.cbegin(), vecSet.cend());
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
	m_vecMatch = ConcatanateValidMatches();
	m_vecSet = ConcetanateSets();
	const auto& vecUpdatedCareerWLStat = UpdateCareerStats();
	emit CareerStatsUpdated(m_vecTournament.size(), CountQualificationFromGroupStages(), vecUpdatedCareerWLStat);
	const auto& vecUpdatedFinalsWLStat = UpdateFinalsStats();
	emit FinalsStatsUpdated(vecUpdatedFinalsWLStat);
}