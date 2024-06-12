#pragma once
#include <memory>
#include <string>
#include <vector>
#include <QObject>
#include "Organization.h"
#include "Tournament.h"
#include "Match.h"

class GUIConfigurator;
class AppController : public QObject {
	Q_OBJECT
public:
	static void create();
	static AppController& instance();
	AppController(const AppController&) = delete;
	AppController& operator=(const AppController&) = delete;
	~AppController();
	// member functions
	void StartApplication();
	std::string getAppName(); 
	std::vector<Organization> GetOrganizations()const;
	std::vector<Tournament> GetTournaments()const;
	std::vector<std::string> GetOrgNames()const;
	std::vector<std::string> GetCategories(const std::string& sOrg) const;
	void AddNewOrganization(const Organization& org);
	bool AddNewTournament(Tournament t);
	void DeleteTournaments(std::vector<Tournament> vecTournament);
	bool EditTournament(Tournament t);
	bool AddNewMatch(const Match& m);
private:
	AppController();
	static AppController* ms_pAppController;
	const Organization& GetOrg(const std::string& sOrg)const;
	// member functions
	void LoadOrganizations();
	void LoadTournaments();
	// member variables
	GUIConfigurator* m_pGUIConfigurator{nullptr};
	std::string m_sAppName{"Master Tennis App"};
	std::vector<Organization> m_vecOrganizations;
	std::vector<Tournament> m_vecTournament;
signals:
	// Signal functions are just declared, not defined by programmers!
	void OrganizationAdded();
	void TournamentAdded();
	void TournamentsDeleted();
	void TournamentEdited();
};

