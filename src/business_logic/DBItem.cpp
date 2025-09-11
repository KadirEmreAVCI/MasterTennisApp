#include "DBItem.h"
#include <sstream>
#include "Utility.h"

std::shared_ptr<IDatabase> DBItem::m_spIDatabase = nullptr;
DBItem::DBItem(unsigned uiID, const std::string& sDBTable, const std::string& sDBColumns) : m_uiID{uiID}, m_sDBTable { sDBTable }, m_sDBColumns{ sDBColumns }
{
	
}
DBItem::~DBItem()
{
	
}
bool DBItem::DeleteFromDB()const
{
	return m_spIDatabase->DeleteItem(m_sDBTable, "ID", std::to_string(m_uiID));
}
std::string DBItem::GetDBTable()const
{
	return m_sDBTable;
}
void DBItem::SetDatabase(std::shared_ptr<IDatabase> spDatabase)
{
	m_spIDatabase = spDatabase;
}
std::vector<std::string> DBItem::DeserializeDBColumn(const std::string& sColumn)const
{
	std::string sSerialized = m_spIDatabase->RetrieveValue(m_sDBTable, sColumn, "ID", std::to_string(m_uiID));
	std::vector<std::string> vecDeserialized = utility::Deserialize(sSerialized);	
	return vecDeserialized;
}