#pragma once
#ifndef DB_ITEM
#define DB_ITEM

#include <string>
#include "SQLiteDB.h"
class DBItem {
public:
	DBItem(const std::string& sDBTable, const std::string& m_sDBColumns);
	virtual ~DBItem();
	virtual bool InsertToDB()const = 0;
	virtual bool EditInDB()const = 0;
	virtual bool DeleteFromDB()const;
	virtual void LoadFromDB(unsigned ID)=0;
	std::string GetDBTable()const;
protected:
	void SetID(unsigned);
	unsigned m_uiID{};
	std::string m_sDBTable;
	std::string m_sDBColumns;
	std::string m_sDBValues;
};

#endif 