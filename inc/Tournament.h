#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <optional>
class Organization;
class Tournament{
public:
	Tournament();
	unsigned GetID()const;
	void SetID(unsigned);
	unsigned GetOrgID()const;
	void SetOrgID(unsigned);
	std::string GetOrgName()const;
	void SetOrgName(std::string);
	std::string GetType()const;
	void SetType(std::string);
	std::string GetTeammate()const;
	void SetTeammate(std::string);
	std::string GetCategory()const;
	void SetCategory(std::string);
	std::string GetSeason()const;
	void SetSeason(std::string);
	unsigned GetParticipant()const;
	void SetParticipant(unsigned);
	bool GetCompleted()const;
	void SetCompleted(bool);
	std::string GetProgress()const;
	friend std::ostream& operator<<(std::ostream& os, const Tournament& t)
	{
		os << "\tID: " << t.m_uiID <<
			", ORG ID: " << t.m_uiOrgID <<
			", ORG NAME: " << t.m_sOrgName <<
			", TYPE: " << t.m_sType <<
			", TEAMMATE: " << t.m_sTeammate.value_or("NA") <<
			", CATEGORY: " << t.m_sCategory <<
			", SEASON: " << t.m_sSeason <<
			", PARTICIPANT: " << t.m_uiParticipant << std::boolalpha <<
			", COMPLETED: " << t.m_blCompleted <<
			", PROGRESS: " << t.m_sProgress;
		return os;
	}
private:
	unsigned m_uiID{};
	unsigned m_uiOrgID;
	std::string m_sOrgName;
	std::string m_sType; 
	std::optional<std::string> m_sTeammate;
	std::string m_sCategory;
	std::string m_sSeason;
	unsigned m_uiParticipant;
	bool m_blCompleted{ false };
	std::string m_sProgress; 
};

