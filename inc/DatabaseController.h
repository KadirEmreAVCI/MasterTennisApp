#pragma once
#include <vector>
#include <string>
#include <map>
#include <QObject>
#include "Tournament.h"
#include "Organization.h"

class DatabaseController : public QObject{
	Q_OBJECT
public:
	static DatabaseController& instance();
	
	DatabaseController(const DatabaseController&) = delete;
	
	DatabaseController& operator=(const DatabaseController&) = delete;
	
	std::vector<Tournament> GetTournaments(unsigned uiOrgID) const;

	std::vector<Organization> GetOrganizations()const;

	std::vector<Tournament> GetTournaments() const;

	// Returns all possible organization names in table "Organization"
	std::vector<std::string> GetOrgNames()const;

	// Returns all organization IDs in table "Organization"
	std::vector<unsigned> GetOrganizationIDs()const;

	unsigned GetOrgID(std::string sOrgName)const;

	bool AddNewTournament(const Tournament&)const;

	bool AddNewOrganization(const Organization&);

	bool EditTournament(const Tournament&)const;

	bool DeleteTournaments(std::vector<Tournament>)const;

private:
	DatabaseController();

	// Returns name of the selected organization
	std::string GetOrgName(unsigned uiID)const;

	// Returns alternative categories for the selected organization
	std::vector<std::string> GetCategories(unsigned uiID) const;

	void InitOrgMap();

	void UpdateOrgMap();

	std::string Serialize(std::vector<std::string> vecCategories)const;

	// Returns all categories in a string
	std::vector<std::string> ExtractCategories(std::string sCategoryList)const;

	std::map<std::string, unsigned> m_mapOrg;

	const std::string m_sTournamentTable = "Tournament";

	const std::string m_sOrganizationTable = "Organization";
};

