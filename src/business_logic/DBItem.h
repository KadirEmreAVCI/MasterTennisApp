#ifndef DBITEM_H
#define DBITEM_H

#include <memory>
#include "IDatabase.h"
class DBItem {
friend class DBItemTest;
public:
	DBItem(unsigned uiID, const std::string& sDBTable, const std::string& m_sDBColumns);
	virtual ~DBItem();
	virtual bool InsertToDB()const = 0;
	virtual bool EditInDB()const = 0;
	virtual bool DeleteFromDB()const;
	virtual void LoadFromDB(unsigned ID)=0;
	std::string GetDBTable()const;
	static void SetDatabase(std::shared_ptr<IDatabase> spDatabase);
protected:
	static std::shared_ptr<IDatabase> m_spIDatabase;
	std::vector<std::string> DeserializeDBColumn(const std::string& sColumn)const;
	unsigned m_uiID{};
	std::string m_sDBTable;
	std::string m_sDBColumns;
	std::string m_sDBValues;
};

#endif 