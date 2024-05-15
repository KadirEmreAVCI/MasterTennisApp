#pragma once
#include <string>
#include <vector>
#include "Match.h"
class Tournament{
public:
	Tournament(std::string sOrganizationName = "", std::string sType = "", std::string sCategory = "", std::string sSeason = "", unsigned uiParticipant = 0, bool blCompleted = false, std::string sProgress = "");
	std::string GetOrganizationName()const;
	void SetOrganizationName(std::string);
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
	void SetProgress(std::string);
	friend std::ostream& operator<<(std::ostream& os, const Tournament& t)
	{
		os << "(Organization Name: " << t.m_sOrganizationName <<
			", Type: " << t.m_sType <<
			", Teammate: " << t.m_sTeammate <<
			", Category: " << t.m_sCategory <<
			", Season: " << t.m_sSeason <<
			", Participant: " << t.m_uiParticipant << std::boolalpha <<
			", Completed: " << t.m_blCompleted <<
			", Progress: " << t.m_sProgress;
		return os;
	}
private:
	std::string m_sOrganizationName;
	std::string m_sType; std::string m_sTeammate;
	std::string m_sCategory;
	std::string m_sSeason;
	unsigned m_uiParticipant;
	bool m_blCompleted{ false };
	std::string m_sProgress;
	std::vector<Match> m_vecMatch;
};

