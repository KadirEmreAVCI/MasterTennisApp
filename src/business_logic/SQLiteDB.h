#ifndef SQLITEDB_H
#define SQLITEDB_H

#include <vector>
#include <string>
#include <QSqlDatabase> 
class QSqlQueryModel;
class SQLiteDB{
public:
	
	SQLiteDB(const SQLiteDB&) = delete;
	SQLiteDB& operator=(const SQLiteDB&) = delete;
	static SQLiteDB& instance();
	void SetDatabaseAddr(const QString&);
	bool OpenConn() const;
	void CloseConn() const;
	bool IsOpen();
	unsigned GetRowSize(const std::string& sTable) const;
	bool InsertItem2Table(const std::string& sTable, const std::string& sColumnNames, const std::string& sValues)const;
	bool EditItemInTable(const std::string& sTable, const QMap<QString, QVariant>& columnValues, unsigned uiID)const;
	bool DeleteItemFromTable(const std::string& sTable, std::string Column, std::string sVal)const;
	std::vector<std::string> GetColumn(const std::string& sTable, const std::string& sColumn)const;
	std::vector<std::string> GetColumnWithCond(const std::string& sTable, const std::string& sColumn, const std::string& sCondColumn, const std::string& sCond)const;
	std::string GetValue(const std::string& sTable, const std::string& sColumn, unsigned uiRowIdx)const;
	std::string GetValueWithCond(const std::string& sTable, const std::string& sColumn, const std::string& sCondColumn, const std::string& sCond, unsigned uiRowIdx = 0)const;
private:
	SQLiteDB();
	static QSqlDatabase m_SqlDatabase;
};

#endif