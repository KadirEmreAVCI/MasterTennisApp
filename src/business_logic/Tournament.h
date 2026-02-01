#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <optional>
#include "DBItem.h"
#include "Match.h"
class Organization;
class Tournament : public DBItem {
friend class TournamentTest;
friend class DatabaseControllerTest;
friend class StatControllerTest;
public:
	explicit Tournament(	unsigned uiID = 0, 
							unsigned uiProfileID = 0, 
							unsigned uiOrgID = 0, 
							const std::string & sOrgName = "",
							const std::string& sSeason = "", 
							const std::string& sCategory = "", 
							const std::string& sType = "", 
							std::optional<std::string> soptTeammate = std::nullopt,
							unsigned uiParticipant = 0, 
							bool blIsLocked = false,
							bool bl3rdPlaceGameAvailable = false, 
							unsigned uiBestOfSets = 0);
	std::string GetName()const;
	unsigned GetID()const;
	unsigned GetProfileID()const;
	unsigned GetOrgID()const;
	std::string GetType()const;
	std::string GetTeammate()const;
	std::string GetCategory()const;
	std::string GetSeason()const;
	unsigned GetParticipant()const;
	bool IsLocked()const;
	void SetLocked(bool);
	bool Get3rdPlaceGameAvailable()const;
	std::string GetTrophyPic()const;
	unsigned GetSetsBestOf()const;
	std::vector<std::string> GetPossibleStages()const;
	bool IsDoubleTournament()const;
	std::vector<Match> GetMatches()const;
	bool IsGroupStageExist()const;
	std::optional<Match> GetMostRecentMatch()const;
	bool IsMatchValidForTournament(const Match&)const;
	bool IsValid()const;
	bool operator<(const Tournament& other)const;
	bool operator>(const Tournament& other)const;
	bool operator<=(const Tournament& other)const;
	bool operator>=(const Tournament& other)const;
	friend bool operator==(const Tournament& lhs, const Tournament& rhs)
	{
		return	lhs.m_uiID == rhs.m_uiID &&
				lhs.m_uiProfileID == rhs.m_uiProfileID &&
				lhs.m_uiOrgID == rhs.m_uiOrgID &&
				lhs.m_sSeason == rhs.m_sSeason &&
				lhs.m_sCategory == rhs.m_sCategory &&
				lhs.m_sType == rhs.m_sType &&
				lhs.m_soptTeammate == rhs.m_soptTeammate &&
				lhs.m_uiParticipant == rhs.m_uiParticipant &&
				lhs.m_blIsLocked == rhs.m_blIsLocked &&
				lhs.m_bl3rdPlaceGameAvailable == rhs.m_bl3rdPlaceGameAvailable &&
				lhs.m_uiBestOfSets == rhs.m_uiBestOfSets;
	}
	friend std::ostream& operator<<(std::ostream& os, const Tournament& t)
	{
		os << "\tID: " << t.m_uiID <<
			", PROFILE ID: " << t.m_uiProfileID <<
			", ORG ID: " << t.m_uiOrgID <<
			", TYPE: " << t.m_sType <<
			", TEAMMATE: " << t.m_soptTeammate.value_or("NA") <<
			", CATEGORY: " << t.m_sCategory <<
			", SEASON: " << t.m_sSeason <<
			", PARTICIPANT: " << t.m_uiParticipant << std::boolalpha <<
			", LOCKED: " << t.m_blIsLocked <<
			", 3RD PLACE GAME AVAILABLE: " << std::boolalpha << t.m_bl3rdPlaceGameAvailable <<
			", BEST OF(SET): " << t.m_uiBestOfSets;
		return os;
	}
	virtual bool DeleteFromDB()const override;
	virtual bool InsertToDB()const override;
	virtual bool EditInDB()const override;
	virtual void LoadFromDB(unsigned ID)override;
private:
	void SetMatches(const std::vector<Match>&);
	bool IsMatchStageValid(const Match&)const;
	bool IsMatchExceedingMaxSet(const Match&)const;
	unsigned m_uiProfileID{};
	unsigned m_uiOrgID{};
	std::string m_sType{};
	std::optional<std::string> m_soptTeammate{};
	std::string m_sCategory{};
	std::string m_sSeason{};
	unsigned m_uiParticipant{};
	bool m_blIsLocked{ false };
	bool m_bl3rdPlaceGameAvailable{};
	unsigned m_uiBestOfSets{};
	std::set<Match, std::greater<Match>> m_setMatch;
	static std::vector<std::string> ms_vecPossiblePlayoffStages;
};

#endif