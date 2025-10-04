#ifndef STATCONTROLLER_H
#define STATCONTROLLER_H

#include <vector>
#include "Profile.h"
#include "Stat.h"

class StatController{
public:
	static void create();
	static StatController& instance();
	StatController(const StatController&) = delete;
	StatController& operator=(const StatController&) = delete;
	~StatController();
	std::vector<StatReport> GetUpdatedCareerStats(const Profile&);
private:
	StatController();
	static StatController* ms_pStatController;
	std::vector<Tournament> m_vecTournament;
	std::vector<Match> m_vecMatch;
	std::vector<Set> m_vecSet;
	unsigned m_uiProfileID = 0;
	std::vector<Match> ConcatanateMatches()const;
	std::vector<Set> ConcetanateSets()const;
	void UpdateActiveProfileData(const Profile&);
	Stat<Set, 	decltype([](const Set& s)  {return s.IsTiebreakPlayed();})> m_StatSetTiebreaks;
	Stat<Match, decltype([](const Match& m){return m.IsValid() && !m.IsUpcomingMatch();})> m_StatMatch;
	Stat<Match, decltype([](const Match& m){return m.IsValid() && !m.IsUpcomingMatch() && m.IsTiebreakPlayed();})> m_StatMatchTiebreaks;
	Stat<Match, decltype([](const Match& m){return m.IsValid() && !m.IsUpcomingMatch() && m.GetStage() == "Quarter Final";})> m_StatQuarterFinals;
	Stat<Match, decltype([](const Match& m){return m.IsValid() && !m.IsUpcomingMatch() && m.GetStage() == "Semi Final";})> m_StatSemiFinals;
	Stat<Match, decltype([](const Match& m){return m.IsValid() && !m.IsUpcomingMatch() && m.GetStage() == "3rd Place Game";})> m_Stat3rdPlaceGames;
	Stat<Match, decltype([](const Match& m){return m.IsValid() && !m.IsUpcomingMatch() && m.GetStage() == "Final";})> m_StatFinals;
};

#endif