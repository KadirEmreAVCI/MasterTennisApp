#pragma once
#include <vector>
#include <string>
#include <map>
#include "Tournament.h"
class DatabaseController{
public:
	static DatabaseController& instance();
	
	DatabaseController(const DatabaseController&) = delete;
	
	DatabaseController& operator=(const DatabaseController&) = delete;
	
	std::vector<Tournament> GetTournaments() const;

	// Returns all possible organization names in table "Organization"
	std::vector<std::string> GetOrganizations()const;

	// Returns all organization IDs in table "Organization"
	std::vector<unsigned> GetOrganizationIDs()const;

	unsigned GetOrgID(std::string sOrgName)const;

	// Returns alternative categories for the selected organization
	std::vector<std::string> GetCategories(std::string sOrgName) const;
	
	// Returns alternative stages for the selected organization
	std::vector<std::string> GetStages(std::string sOrgName) const;

	void AddTournament(const Tournament&);

private:
	DatabaseController();

	void InitOrgMap();

	// Returns all categories in a string
	std::vector<std::string> ExtractCategories(std::string sCategoryList)const;

	// Returns all stages in a string
	std::vector<std::string> ExtractStages(std::string sCategoryList)const;

	std::map<std::string, unsigned> m_mapOrg;
};

