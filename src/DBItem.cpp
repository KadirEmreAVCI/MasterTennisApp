#pragma once
#include "DBItem.h"
DBItem::DBItem(const std::string& sDBTable, const std::string& sDBColumns) : m_sDBTable{ sDBTable }, m_sDBColumns{ sDBColumns }
{
	
}
DBItem::~DBItem()
{
	
}
bool DBItem::DeleteFromDB()const
{
	return SQLiteDB::instance().DeleteItemFromTable(m_sDBTable, "ID", std::to_string(m_uiID));
}
std::string DBItem::GetDBTable()const
{
	return m_sDBTable;
}
void DBItem::SetID(unsigned uiID)
{
	m_uiID = uiID;
}
