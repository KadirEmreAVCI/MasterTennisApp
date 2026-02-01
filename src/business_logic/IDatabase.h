#ifndef IDATABASE_H
#define IDATABASE_H

#include <vector>
#include <string>
#include <QMap>
#include <QVariant>
class IDatabase{
public:
	virtual unsigned GetItemCount(const std::string& sTable) const = 0;
	virtual bool InsertItem(const std::string& sTable, const std::string& sColumnNames, const std::string& sValues)const = 0;
	virtual bool EditItem(const std::string& sTable, const QMap<QString, QVariant>& columnValues, unsigned uiID)const = 0;
	virtual bool DeleteItem(const std::string& sTable, const std::string& sColumn, std::string sVal)const = 0;
	virtual std::string RetrieveValue(const std::string& sTable, const std::string& sColumn, unsigned uiRowIdx)const = 0;
	virtual std::string RetrieveValue(const std::string& sTable, const std::string& sColumn, const std::string& sCondColumn, const std::string& sCond, unsigned uiRowIdx = 0)const = 0;
};

#endif