#ifndef STATCONTROLLER_H
#define STATCONTROLLER_H

#include <vector>
#include <QObject>
#include "Profile.h"
#include "Stat.h"


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
	std::vector<Match> m_vecMatch;
	std::vector<Set> m_vecSet;
	std::vector<StatReport> UpdateCareerStats();
	std::vector<StatReport> UpdateFinalsStats();
	unsigned m_uiProfileID = 0;
	std::vector<Match> ConcatanateMatches()const;
	std::vector<Set> ConcetanateSets()const;
	unsigned CountQualificationFromGroupStages()const;
	std::string GetMaxProgress(const Tournament& t)const;
	Stat<Set, 	decltype([](const Set& s)  {return s.IsTiebreakPlayed();})> m_StatSetTiebreaks;
	Stat<Match, decltype([](const Match& m){return m.IsValid();})> m_StatMatch;
	Stat<Match, decltype([](const Match& m){return m.IsValid() && m.IsTiebreakPlayed();})> m_StatMatchTiebreaks;
	Stat<Match, decltype([](const Match& m){return m.IsValid() && m.GetStage() == "Quarter Final";})> m_StatQuarterFinals;
	Stat<Match, decltype([](const Match& m){return m.IsValid() && m.GetStage() == "Semi Final";})> m_StatSemiFinals;
	Stat<Match, decltype([](const Match& m){return m.IsValid() && m.GetStage() == "3rd Place Game";})> m_Stat3rdPlaceGames;
	Stat<Match, decltype([](const Match& m){return m.IsValid() && m.GetStage() == "Final";})> m_StatFinals;
	void ChangeInDB(const std::vector<Profile>&, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&);
public slots:
	void UpdateActiveProfileData(const Profile&);
signals:
	void CareerStatsUpdated(unsigned uiTotalTournament, unsigned uiTotalQualificationFromGroupStages, const std::vector<StatReport>&);
	void FinalsStatsUpdated(const std::vector<StatReport>&);
};

#endif