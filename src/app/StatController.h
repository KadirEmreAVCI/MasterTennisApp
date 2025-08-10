#ifndef STATCONTROLLER_H
#define STATCONTROLLER_H

#include <vector>
#include <QObject>
#include "Profile.h"
constexpr size_t gTotalCareerStat = 3;
constexpr size_t gTotalFinalStat = 4;
class WinLoseStat{
public:
	WinLoseStat(unsigned uiWin = 0, unsigned uiLose = 0) : m_uiWin(uiWin), m_uiLose(uiLose)
	{

	}
	unsigned GetWin()const
	{
		return m_uiWin;
	}
	unsigned GetLose()const
	{
		return m_uiLose;
	}
	float GetWinRatePercentage()const
	{
		return (m_uiWin + m_uiLose != 0) ? static_cast<float>(m_uiWin) / (m_uiWin + m_uiLose) * 100.0f : 0.0f;
	}
private:
	unsigned m_uiWin = 0;
	unsigned m_uiLose = 0;
};
class StatController : public QObject {
	Q_OBJECT
public:
	static void create();
	static StatController& instance();
	StatController(const StatController&) = delete;
	StatController& operator=(const StatController&) = delete;
	~StatController();
	
private:
	StatController();
	static StatController* ms_pStatController;
	std::vector<Tournament> m_vecTournament;
	std::vector<Organization> m_vecOrganization;
	std::array<WinLoseStat, gTotalCareerStat> UpdateCareerStats()const;
	std::array<WinLoseStat, gTotalFinalStat> UpdateFinalsStats()const;
	unsigned GetTotalMatch()const;
	unsigned GetMatchWin()const;
	unsigned GetMatchLose()const;
	std::vector<Match> ConcatanateValidMatches()const;
	std::vector<Set> ConcetanateSets()const;
	unsigned GetTotalSetTB()const;
	unsigned GetSetTBWin()const;
	unsigned GetSetTBLose()const;
	unsigned GetTotalSuperTB()const;
	unsigned GetSuperTBWin()const;
	unsigned GetSuperTBLose()const;
	std::vector<Match> FindMatchesWithStage(const std::string& sStage)const;
	unsigned CountWinsForStage(const std::string& sStage)const;
	unsigned CountLosesForStage(const std::string& sStage)const;
	unsigned CountQualificationFromGroupStages()const;
	std::string GetMaxProgress(const Tournament& t)const;
	std::vector<Tournament> ConcatanateTournaments()const;
public slots:
	void UpdateActiveProfileData(const Profile&);
signals:
	void CareerStatsUpdated(unsigned uiTotalTournament, unsigned uiTotalQualificationFromGroupStages, const std::array<WinLoseStat, gTotalCareerStat>&);
	void FinalsStatsUpdated(const std::array<WinLoseStat, gTotalFinalStat>&);
};

#endif