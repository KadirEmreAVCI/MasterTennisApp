#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include "DBItem.h"
#include "Match.h"
class Organization;
class Tournament : public DBItem {
public:
	Tournament();
	std::string GetName()const;
	unsigned GetID()const;
	void SetID(unsigned);
	unsigned GetProfileID()const;
	void SetProfileID(unsigned);
	unsigned GetOrgID()const;
	void SetOrgID(unsigned);
	std::string GetOrgName()const;
	void SetOrgName(std::string);
	std::string GetType()const;
	void SetType(std::string);
	bool IsDoubleTournament()const;
	std::string GetTeammate()const;
	void SetTeammate(std::string);
	std::string GetCategory()const;
	void SetCategory(std::string);
	std::string GetSeason()const;
	void SetSeason(std::string);
	unsigned GetParticipant()const;
	void SetParticipant(unsigned);
	bool IsLocked()const;
	void SetLocked(bool);
	bool Get3rdPlaceGameAvailable()const;
	void Set3rdPlaceGameAvailable(bool bl3rdPlaceGameAvailable);
	unsigned GetSetsBestOf()const;
	void SetSetsBestOf(unsigned uiBestOfSets);
	std::vector<std::string> GetStages()const;
	std::vector<Match> GetMatches()const;
	void SetMatches(const std::vector<Match>&);
	bool IsGroupStageExist()const;
	std::optional<Match> GetLastMatch()const;
	bool IsEarlier(const Tournament& other)const;
	friend std::ostream& operator<<(std::ostream& os, const Tournament& t)
	{
		os << "\tID: " << t.m_uiID <<
			", PROFILE ID: " << t.m_uiProfileID <<
			", ORG ID: " << t.m_uiOrgID <<
			", ORG NAME: " << t.m_sOrgName <<
			", TYPE: " << t.m_sType <<
			", TEAMMATE: " << t.m_sTeammate.value_or("NA") <<
			", CATEGORY: " << t.m_sCategory <<
			", SEASON: " << t.m_sSeason <<
			", PARTICIPANT: " << t.m_uiParticipant << std::boolalpha <<
			", LOCKED: " << t.m_blIsLocked <<
			", 3RD PLACE GAME AVAILABLE: " << std::boolalpha << t.m_bl3rdPlaceGameAvailable <<
			", BEST OF(SET): " << t.m_uiBestOfSets;
		return os;
	}
	virtual bool InsertToDB()const override;
	virtual bool EditInDB()const override;
	virtual void LoadFromDB(unsigned ID)override;
private:
	unsigned m_uiProfileID{};
	unsigned m_uiOrgID{};
	std::string m_sOrgName;
	std::string m_sType{};
	std::optional<std::string> m_sTeammate{};
	std::string m_sCategory{};
	std::string m_sSeason{};
	unsigned m_uiParticipant{};
	bool m_blIsLocked{ false };
	bool m_bl3rdPlaceGameAvailable{};
	unsigned m_uiBestOfSets{};
	std::vector<Match> m_vecMatch;
	static std::vector<std::string> ms_vecPossiblePlayoffStages;
};

