#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <vector>
#include <string>
#include <map>
#include <QObject>
#include "Profile.h"
class IDatabase;
class DatabaseController : public QObject{
	Q_OBJECT
public:
	friend class DatabaseControllerTest;

	static DatabaseController& instance();
	DatabaseController(const DatabaseController&) = delete;
	DatabaseController& operator=(const DatabaseController&) = delete;
	void InitDatabase(std::shared_ptr<IDatabase> spDatabase);
	Profile GetActiveProfile(unsigned int uiActiveProfileID);
	std::vector<Profile> GetProfiles();
	std::vector<Organization> GetOrganizations();
	std::vector<Match> FindMatchesOfTournament(unsigned uiTournamentID)const;
	std::vector<Tournament> FindTournamentsOfOrganization(unsigned uiOrgID)const;
	std::vector<Tournament> FindTournamentsOfProfile(unsigned uiProfileID)const;
	template<typename T>
	bool DeleteDBItem(const T& item)
	{
		std::vector<T> vecItem = LoadDBItems<T>();
		auto iterItem = std::find(vecItem.cbegin(), vecItem.cend(), item);
		if (iterItem == vecItem.cend())
		{
			std::cerr << "DatabaseController::DeleteDBItem item to be deleted could not be found in DB!\n";
			return false;
		}
		return iterItem->DeleteFromDB();
	}
	template<typename T>
	bool AddNewDBItem(const T& item)const
	{
		return item.InsertToDB();
	}
	template<typename T>
	bool EditDBItem(const T& item)const
	{
		return item.EditInDB();
	}
private:
	DatabaseController() = default;
	void LoadDataFromDB();
	template<typename T>
	std::vector<T> LoadDBItems()const
	{
		std::vector<T> vecItem;
		if (const unsigned uiSize = m_spIDatabase->GetItemCount(T{}.GetDBTable()); uiSize != 0)
		{
			vecItem.resize(uiSize);
			unsigned uiRowIdx{};
			std::for_each(vecItem.begin(), vecItem.end(), [&](auto& item) {
				item.LoadFromDB(uiRowIdx++);
				});
		}
		return vecItem;
	}
	std::vector<Profile> m_vecProfile;
	std::vector<Organization> m_vecOrganization;
	std::vector<Tournament> m_vecTournament;
	std::vector<Match> m_vecMatch;
	std::shared_ptr<IDatabase> m_spIDatabase{ nullptr };
};

#endif