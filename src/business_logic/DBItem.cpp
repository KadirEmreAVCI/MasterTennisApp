#include "DBItem.h"
#include <sstream>
DBItem::DBItem(unsigned uiID, const std::string& sDBTable, const std::string& sDBColumns) : m_uiID{uiID}, m_sDBTable { sDBTable }, m_sDBColumns{ sDBColumns }
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
std::string DBItem::Serialize(std::vector<std::string> vec)
{
	std::ostringstream oss{};
	std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<std::string>(oss, ","));
	std::string sSerialized{ oss.str() };
	sSerialized.pop_back();
	return sSerialized;
}
std::vector<std::string> DBItem::Deserialize(std::string sSerialized)
{
	std::vector<std::string> vecDeserialized;
	std::istringstream iss(sSerialized);
	std::string sItem;
	while (std::getline(iss, sItem, ',')) {
		vecDeserialized.push_back(std::move(sItem));
	}
	return vecDeserialized;
}
std::vector<std::string> DBItem::DeserializeDBColumn(const std::string& sColumn)const
{
	std::vector<std::string> vecDeserialized;
	std::vector<std::string> vecSerialized = SQLiteDB::instance().GetColumnWithCond(m_sDBTable, sColumn, "ID", std::to_string(m_uiID));
	if (!vecSerialized.empty())
	{
		const auto& sSerialized = vecSerialized.front();
		vecDeserialized = Deserialize(sSerialized);
	}
	return vecDeserialized;
}