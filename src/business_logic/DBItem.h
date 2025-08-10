#ifndef DBITEM_H
#define DBITEM_H

#include <string>
#include "SQLiteDB.h"
class DBItem {
public:
	DBItem(unsigned uiID, const std::string& sDBTable, const std::string& m_sDBColumns);
	virtual ~DBItem();
	virtual bool InsertToDB()const = 0;
	virtual bool EditInDB()const = 0;
	virtual bool DeleteFromDB()const;
	virtual void LoadFromDB(unsigned ID)=0;
	std::string GetDBTable()const;
protected:
	static std::string Serialize(std::vector<std::string> vec);
	static std::vector<std::string> Deserialize(std::string sSerialized);
	std::vector<std::string> DeserializeDBColumn(const std::string& sColumn)const;
	unsigned m_uiID{};
	std::string m_sDBTable;
	std::string m_sDBColumns;
	std::string m_sDBValues;
};

#endif 