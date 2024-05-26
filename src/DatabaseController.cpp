#include <iostream>
#include <algorithm>
#include <QMap>
#include <QVariant>
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

std::vector<Tournament> DatabaseController::GetTournaments(unsigned uiOrgID) const
{
	std::vector<Tournament> vecAllTournaments = GetTournaments();
	std::vector<Tournament> vecTournaments;
	std::copy_if(vecAllTournaments.cbegin(), vecAllTournaments.cend(), std::back_inserter(vecTournaments), [uiOrgID](const auto& t) {
		return t.GetOrgID() == uiOrgID;
		});
	return vecTournaments;
}

std::vector<Tournament> DatabaseController::GetTournaments() const
{
	SQLiteDB& db = SQLiteDB::instance();
	std::vector<Tournament> vecTournament;
	const unsigned uiTournamentSize = db.GetRowSize(m_sTournamentTable);
	std::cout << "DatabaseController::GetTournaments() uiTournamentSize = " << uiTournamentSize << "\n";
	if (uiTournamentSize != 0)
	{
		vecTournament.resize(uiTournamentSize);
		unsigned uiRowIdx{};
		std::for_each(vecTournament.begin(), vecTournament.end(), [&](auto& t) {
			t.SetID(stoi(db.GetValue(m_sTournamentTable, "ID", uiRowIdx++)));
			t.SetOrgID(stoi(db.GetValueWithCond(m_sTournamentTable, "OrganizationID", "ID", std::to_string(t.GetID()))));
			t.SetOrgName(GetOrgName(t.GetOrgID()));
			t.SetSeason(db.GetValueWithCond(m_sTournamentTable, "Season", "ID", std::to_string(t.GetID())));
			t.SetCategory(db.GetValueWithCond(m_sTournamentTable, "Category", "ID", std::to_string(t.GetID())));
			t.SetType(db.GetValueWithCond(m_sTournamentTable, "Type", "ID", std::to_string(t.GetID())));
			t.SetTeammate(db.GetValueWithCond(m_sTournamentTable, "Teammate", "ID", std::to_string(t.GetID())));
			t.SetParticipant(stoi(db.GetValueWithCond(m_sTournamentTable, "Participant", "ID", std::to_string(t.GetID()))));
			t.SetCompleted(stoi(db.GetValueWithCond(m_sTournamentTable, "Completion", "ID", std::to_string(t.GetID()))));
			std::cout << t << '\n';
			});
	}
	std::cout << "\n";
	return vecTournament;
}

std::vector<Organization> DatabaseController::GetOrganizations()const
{
	std::cout << "\nDatabaseController::GetOrganizations()\n";
	SQLiteDB& db = SQLiteDB::instance();
	std::vector<Organization> vecOrg;
	const unsigned uiOrgSize = db.GetRowSize(m_sOrganizationTable);
	if (uiOrgSize != 0)
	{
		vecOrg.resize(uiOrgSize);
		unsigned uiRowIdx{};
		std::for_each(vecOrg.begin(), vecOrg.end(), [&](auto& org) {
			org.SetID(stoi(db.GetValue(m_sOrganizationTable, "ID", uiRowIdx)));
			org.SetName(db.GetValueWithCond(m_sOrganizationTable, "Name", "ID", std::to_string(org.GetID())));
			org.SetType(db.GetValueWithCond(m_sOrganizationTable, "Type", "ID", std::to_string(org.GetID())));
			org.SetCategories(GetCategories(org.GetID()));
			std::cout << org << "\n";
			++uiRowIdx;
			});
	}
	return vecOrg;
}

std::vector<std::string> DatabaseController::GetOrgNames()const
{
	std::vector<std::string> vecOrgName = SQLiteDB::instance().GetColumn(m_sOrganizationTable, "Name");
	std::cout << "DatabaseController::GetOrgNames\n";
	std::copy(vecOrgName.begin(), vecOrgName.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	return vecOrgName;
}

std::string DatabaseController::GetOrgName(unsigned uiID)const
{
	auto iterOrgName = std::find_if(m_mapOrg.begin(), m_mapOrg.end(), [uiID](const auto& pair) {
		return pair.second == uiID;
		});
	return iterOrgName != m_mapOrg.end() ? iterOrgName->first : "";
}

unsigned DatabaseController::GetOrgID(std::string sOrgName)const
{
	std::cout << "DatabaseController::GetOrgID sOrgName: " << sOrgName << "\n";
	const auto& iterOrg = m_mapOrg.find(sOrgName);
	return (iterOrg != m_mapOrg.end()) ? iterOrg->second : 0;
}

std::vector<unsigned> DatabaseController::GetOrganizationIDs()const
{
	std::vector<unsigned> vecOrgID;
	std::vector<std::string> vecStrOrgID = SQLiteDB::instance().GetColumn(m_sOrganizationTable, "ID");
	std::transform(vecStrOrgID.cbegin(), vecStrOrgID.cend(), std::back_inserter(vecOrgID), [](const auto& sOrgID) {
		return stoi(sOrgID);
	});
	return vecOrgID;
}

std::vector<std::string> DatabaseController::GetCategories(unsigned uiID) const
{
	std::vector<std::string> vecCategory;
	std::vector<std::string> vecCategoryList = SQLiteDB::instance().GetColumnWithCond(m_sOrganizationTable, "Categories", "ID", std::to_string(uiID));
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

bool DatabaseController::AddNewTournament(const Tournament& t)const
{
	std::string sColumns{ "OrganizationID,Season,Category,Type,Teammate,Participant,Completion" };
	std::string sValues{	"'" + std::to_string(GetOrgID(t.GetOrgName())) +
							"','" + t.GetSeason() +
							"','" + t.GetCategory() +
							"','" + t.GetType() + 
							"','" + t.GetTeammate() + 
							"','" + std::to_string(t.GetParticipant()) + 
							"','" + std::to_string(t.GetCompleted()) + "'"};
	std::cout << "DatabaseController::AddNewTournament t = " << t << "\n";
	const bool blTournamentAddition = SQLiteDB::instance().InsertItem2Table(m_sTournamentTable, sColumns, sValues);
	return blTournamentAddition;
}

bool DatabaseController::AddNewOrganization(const Organization& org)
{
	std::string sColumns{ "Name,Type,Categories" };
	std::string sValues{ "'" + org.GetName() + 
						"','" + org.GetType() + 
						"','" + Serialize(org.GetCategories()) + "'"};
	std::cout << "DatabaseController::AddNewOrganization org = " << org << "\n";
	const bool blOrgAddition = SQLiteDB::instance().InsertItem2Table("Organization", sColumns, sValues);
	UpdateOrgMap();
	return blOrgAddition;
}

bool DatabaseController::EditTournament(const Tournament& t)const
{
	std::cout << "DatabaseController::EditTournament t = " << t << '\n';
	QMap<QString, QVariant> columnValues;
	columnValues["OrganizationID"] = QString::fromStdString(std::to_string(GetOrgID(t.GetOrgName())));
	columnValues["Season"] = QString::fromStdString(t.GetSeason());
	columnValues["Category"] = QString::fromStdString(t.GetCategory());
	columnValues["Type"] = QString::fromStdString(t.GetType());
	columnValues["Teammate"] = QString::fromStdString(t.GetTeammate());
	columnValues["Participant"] = QString::fromStdString(std::to_string(t.GetParticipant()));
	columnValues["Completion"] = QString::fromStdString(std::to_string(t.GetCompleted()));
	const bool blTournamentEdition = SQLiteDB::instance().EditItemInTable(m_sTournamentTable, columnValues, t.GetID());
	return blTournamentEdition;
}

bool DatabaseController::DeleteTournaments(std::vector<Tournament> vecTournament)const
{
	bool blDeletion = true;
	std::for_each(vecTournament.cbegin(), vecTournament.cend(), [&](const auto& t) {
		blDeletion = SQLiteDB::instance().DeleteItemFromTable(m_sTournamentTable, "ID", std::to_string(t.GetID())) && blDeletion;
	});
	return blDeletion;
}

void DatabaseController::InitOrgMap()
{
	std::vector<unsigned> vecOrgID = GetOrganizationIDs();
	
	std::vector<std::string> vecOrgName;
	std::for_each(vecOrgID.cbegin(), vecOrgID.cend(), [&](unsigned uiID) {
		auto vec = SQLiteDB::instance().GetColumnWithCond(m_sOrganizationTable, "Name", "ID", std::to_string(uiID));
		vecOrgName.push_back(std::move(vec.front()));
		});
	for (unsigned int uiIdx{}; uiIdx < vecOrgName.size(); ++uiIdx)
	{
		std::cout << "DatabaseController::InitOrgMap org name: " << vecOrgName.at(uiIdx) << ", org ID: "<< vecOrgID.at(uiIdx)<< "\n";
		m_mapOrg.insert(std::make_pair(vecOrgName.at(uiIdx), vecOrgID.at(uiIdx)));
	}
}

void DatabaseController::UpdateOrgMap()
{
	m_mapOrg.clear();
	InitOrgMap();
}

std::string DatabaseController::Serialize(std::vector<std::string> vec)const
{
	std::ostringstream oss{};
	std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<std::string>(oss, ","));
	std::string sSerialized{ oss.str() };
	sSerialized.pop_back();
	return sSerialized;
}
