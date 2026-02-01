#ifndef SQLITEDB_H
#define SQLITEDB_H

#include "IDatabase.h"
#include <QSqlDatabase> 

class SQLiteDB : public IDatabase{
public:
	explicit SQLiteDB(const std::string& sDatabaseAddr);
	// IDatabase interface
	virtual unsigned GetItemCount(const std::string& sTable) const override;
	virtual bool InsertItem(const std::string& sTable, const std::string& sColumnNames, const std::string& sValues)const override;
	virtual bool EditItem(const std::string& sTable, const QMap<QString, QVariant>& columnValues, unsigned uiID)const override;
	virtual bool DeleteItem(const std::string& sTable, const std::string& sColumn, std::string sVal)const override;
	virtual std::string RetrieveValue(const std::string& sTable, const std::string& sColumn, unsigned uiRowIdx)const override;
	virtual std::string RetrieveValue(const std::string& sTable, const std::string& sColumn, const std::string& sCondColumn, const std::string& sCond, unsigned uiRowIdx = 0)const override;
private:
	void SetDatabaseAddr(const QString&);
	bool OpenConn() const;
	void CloseConn() const;
	bool IsOpen();
	std::vector<std::string> GetEntireColumn(const std::string& sTable, const std::string& sColumn)const;
	std::vector<std::string> GetEntireColumn(const std::string& sTable, const std::string& sColumn, const std::string& sCondColumn, const std::string& sCond)const;
	static QSqlDatabase m_SqlDatabase;
};

#endif