#include "DatabaseController.h"
#include "SQLiteDB.h"

DatabaseController::DatabaseController()
{
	InitOrgMap();
}

DatabaseController& DatabaseController::instance()
{
	static DatabaseController obj;
	return obj;
}

std::vector<Tournament> DatabaseController::GetTournaments() const
{
	SQLiteDB& db = SQLiteDB::instance();
	const std::string sTable = "Tournament";
	const unsigned uiTournamentSize = db.GetRowSize(sTable);
	std::vector<Tournament> vecTournament(uiTournamentSize);
	unsigned uiRowIdx{};
	std::for_each(vecTournament.begin(), vecTournament.end(), [&](auto& t) {
		t.SetOrganizationName(db.GetValueWithCond("Organization", "Name", "ID", db.GetValue(sTable, "OrganizationID", uiRowIdx), 0));
		t.SetType(db.GetValue(sTable, "Type", uiRowIdx));
		t.SetTeammate(db.GetValue(sTable, "Teammate", uiRowIdx));
		t.SetCategory(db.GetValue(sTable, "Category", uiRowIdx));
		t.SetSeason(db.GetValue(sTable, "Season", uiRowIdx));
		t.SetParticipant(stoi(db.GetValue(sTable, "Participant", uiRowIdx)));
		t.SetCompleted(stoi(db.GetValue(sTable, "Completion", uiRowIdx)));
		t.SetProgress(db.GetValue(sTable, "Progress", uiRowIdx));
		std::cout << "DatabaseController::GetTournaments " << t << "\n";
		++uiRowIdx;
	});
	return vecTournament;
}

std::vector<std::string> DatabaseController::GetOrganizations()const
{
	std::vector<std::string> vecOrgName = SQLiteDB::instance().GetColumn("Organization", "Name");
	return vecOrgName;
}

unsigned DatabaseController::GetOrgID(std::string sOrgName)const
{
	const auto& iterOrg = m_mapOrg.find(sOrgName);
	return (iterOrg != m_mapOrg.end()) ? iterOrg->second : 0;
}

std::vector<unsigned> DatabaseController::GetOrganizationIDs()const
{
	std::vector<unsigned> vecOrgID;
	std::vector<std::string> vecStrOrgID = SQLiteDB::instance().GetColumn("Organization", "ID");
	std::transform(vecStrOrgID.cbegin(), vecStrOrgID.cend(), std::back_inserter(vecOrgID), [](const auto& sOrgID) {
		return stoi(sOrgID);
	});
	return vecOrgID;
}

std::vector<std::string> DatabaseController::GetCategories(std::string sOrgName) const
{
	std::vector<std::string> vecCategory;
	std::vector<std::string> vecCategoryList = SQLiteDB::instance().GetColumnWithCond("Organization", "Categories", "Name", sOrgName);
	if (!vecCategoryList.empty())
	{
		const auto& sCategoryList = vecCategoryList.front();	// There is only one category list for each tournament, if any
		vecCategory = ExtractCategories(sCategoryList);
	}
	return vecCategory;
}

std::vector<std::string> DatabaseController::ExtractCategories(std::string sCategoryList)const
{
	std::vector<std::string> vecCategory;
	std::istringstream iss(sCategoryList);
	std::string sCategory;
	while (std::getline(iss, sCategory, ',')) {
		vecCategory.push_back(std::move(sCategory));
	}
	return vecCategory;
} 

std::vector<std::string> DatabaseController::GetStages(std::string sOrgName) const
{
	std::vector<std::string> vecStage;
	std::vector<std::string> vecStageList = SQLiteDB::instance().GetColumnWithCond("Organization", "Stages", "Name", sOrgName);
	if (!vecStageList.empty())
	{
		const auto& sStageList = vecStageList.front();	// There is only one category list for each tournament, if any
		vecStage = ExtractStages(sStageList);
	}
	return vecStage;
}

std::vector<std::string> DatabaseController::ExtractStages(std::string sStageList)const
{
	std::vector<std::string> vecStages;
	std::istringstream iss(sStageList);
	std::string sStage;
	while (std::getline(iss, sStage, ',')) {
		vecStages.push_back(std::move(sStage));
	}
	return vecStages;
}

void DatabaseController::AddTournament(const Tournament& t)
{
	std::string sColumns{ "OrganizationID,Type,Teammate,Category,Season,Participant,Completion,Progress" };
	std::string sValues{	"'" + std::to_string(GetOrgID(t.GetOrganizationName())) +
							"','" + t.GetType() + 
							"','" + t.GetTeammate() + 
							"','" + t.GetCategory() + 
							"','" + t.GetSeason() + 
							"','" + std::to_string(t.GetParticipant()) + 
							"','" + std::to_string(t.GetCompleted()) + 
							"','" + t.GetProgress() + "'"};
	std::cout << "DatabaseController::AddTournament t = " << t << "\n";
	SQLiteDB::instance().InsertRowToTable("Tournament", sColumns, sValues);
}

void DatabaseController::InitOrgMap()
{
	std::vector<std::string> vecOrgName = GetOrganizations();
	std::vector<unsigned> vecOrgID = GetOrganizationIDs();
	if (vecOrgName.size() == vecOrgID.size())
	{
		for (unsigned int uiIdx{}; uiIdx < vecOrgName.size(); ++uiIdx)
		{
			m_mapOrg.insert(std::make_pair(vecOrgName.at(uiIdx), vecOrgID.at(uiIdx)));
		}
	}
	else
	{
		std::cout << "DatabaseController::InitOrgMap Error! Unmatched org name and ID size!\n";
	}
}
