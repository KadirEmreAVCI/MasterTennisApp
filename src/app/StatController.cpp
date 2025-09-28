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
std::array<WinLoseStat, gTotalCareerStat> StatController::UpdateCareerStats()const
{
	std::array<WinLoseStat, gTotalCareerStat> arrWLStat;
	size_t arrIdx = 0;
	arrWLStat[arrIdx++] = WinLoseStat(GetMatchWin(), GetMatchLose());
	arrWLStat[arrIdx++] = WinLoseStat(GetSetTBWin(), GetSetTBLose());
	arrWLStat[arrIdx++] = WinLoseStat(GetSuperTBWin(), GetSuperTBLose());
	return arrWLStat;
}
std::array<WinLoseStat, gTotalFinalStat> StatController::UpdateFinalsStats()const
{
	std::array<WinLoseStat, gTotalFinalStat> arrWLStat;
	size_t arrIdx = 0;
	arrWLStat[arrIdx++] = WinLoseStat(CountWinsForStage("Quarter Final"), CountLosesForStage("Quarter Final"));
	arrWLStat[arrIdx++] = WinLoseStat(CountWinsForStage("Semi Final"), CountLosesForStage("Semi Final"));
	arrWLStat[arrIdx++] = WinLoseStat(CountWinsForStage("3rd Place Game"), CountLosesForStage("3rd Place Game"));
	arrWLStat[arrIdx++] = WinLoseStat(CountWinsForStage("Final"), CountLosesForStage("Final"));
	return arrWLStat;
}
unsigned StatController::GetTotalMatch()const
{
	const auto& vecMatch = ConcatanateValidMatches();
	return std::count_if(vecMatch.cbegin(), vecMatch.cend(), [](const auto& m) {
		return m.GetOutcome() != Outcome::Tied; 
		});
}
unsigned StatController::GetMatchWin()const
{
	const auto& vecMatch = ConcatanateValidMatches();
	return std::count_if(vecMatch.cbegin(), vecMatch.cend(), [](const auto& m) {
		return m.GetOutcome() == Outcome::HomeWin;
		});
}
unsigned StatController::GetMatchLose()const
{
	return GetTotalMatch() - GetMatchWin();
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
unsigned StatController::GetTotalSetTB()const
{
	const auto& vecAllSet = ConcetanateSets();
	return std::count_if(vecAllSet.cbegin(), vecAllSet.cend(), [](const auto& set) {
		return set.IsTiebreakPlayed();
		});
}
unsigned StatController::GetSetTBWin()const
{
	const auto& vecAllSet = ConcetanateSets();
	return std::count_if(vecAllSet.cbegin(), vecAllSet.cend(), [](const auto& set) {
		return set.IsTiebreakPlayed() && set.GetOutcome() == Outcome::HomeWin;
		});
}
unsigned StatController::GetSetTBLose()const
{
	return GetTotalSetTB() - GetSetTBWin();
}
unsigned StatController::GetTotalSuperTB()const
{
	unsigned uiTotalSuperTB = 0;
	for (const auto& t : m_vecTournament)
	{
		const auto& vecMatch = t.GetMatches();
		uiTotalSuperTB += std::count_if(vecMatch.cbegin(), vecMatch.cend(), [t](const auto& m) {
			return m.IsTiebreakPlayed();
			});
	}
	return uiTotalSuperTB;
}
unsigned StatController::GetSuperTBWin()const
{
	unsigned uiSuperTBWin = 0;
	for (const auto& t : m_vecTournament)
	{
		const auto& vecMatch = t.GetMatches();
		uiSuperTBWin += std::count_if(vecMatch.cbegin(), vecMatch.cend(), [t](const auto& m) {
			return (t.GetSetsBestOf() == m.GetSets().size() && t.GetSetsBestOf() != 1) && m.GetOutcome() == Outcome::HomeWin;
			});
	}
	return uiSuperTBWin;
}
unsigned StatController::GetSuperTBLose()const
{
	return GetTotalSuperTB() - GetSuperTBWin();
}
std::vector<Match> StatController::FindMatchesWithStage(const std::string& sStage)const
{
	std::vector<Match> vecMatchesWithStage;
	const auto& vecMatch = ConcatanateValidMatches();
	std::copy_if(vecMatch.cbegin(), vecMatch.cend(), std::back_inserter(vecMatchesWithStage), [sStage](const auto& m) {
		return m.GetStage() == sStage;
		});
	return vecMatchesWithStage;
}
unsigned StatController::CountWinsForStage(const std::string& sStage)const
{
	unsigned uiWinsForStage{};
	const auto& vecMatchesWithStage = FindMatchesWithStage(sStage);
	if (!vecMatchesWithStage.empty())
	{
		uiWinsForStage = std::count_if(vecMatchesWithStage.cbegin(), vecMatchesWithStage.cend(), [](const auto& m) {
			return m.GetOutcome() == Outcome::HomeWin;
			});
	}
	return uiWinsForStage;
}
unsigned StatController::CountLosesForStage(const std::string& sStage)const
{
	return FindMatchesWithStage(sStage).size() - CountWinsForStage(sStage);
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
	const auto& vecUpdatedCareerWLStat = UpdateCareerStats();
	emit CareerStatsUpdated(m_vecTournament.size(), CountQualificationFromGroupStages(), vecUpdatedCareerWLStat);
	const auto& vecUpdatedFinalsWLStat = UpdateFinalsStats();
	emit FinalsStatsUpdated(vecUpdatedFinalsWLStat);
}