#pragma once
#include <vector>
#include <string>
#include <map>
#include <QSqlDatabase> 
class QSqlQueryModel;
class QTableView;
class SQLiteDB{
public:
	
	SQLiteDB(const SQLiteDB&) = delete;
	SQLiteDB& operator=(const SQLiteDB&) = delete;
	static SQLiteDB& instance();
	bool OpenConn() const;
	void CloseConn() const;
	bool IsOpen();
	unsigned GetRowSize(const std::string& sTable) const;
	unsigned GetColumnSize(const std::string& sTable) const;
	void SetTableContent(QTableView*, const std::string& sTableName);
	void SetTableContentByColumn(QTableView*, const std::string& sTableName, const std::string& sColumnNames);
	bool InsertRowToTable(const std::string& sTableName, const std::string& sColumnNames, const std::string& sValues);
	std::vector<std::string> GetColumn(const std::string& sTable, const std::string& sColumn);
	std::vector<std::string> GetColumnWithCond(const std::string& sTable, const std::string& sColumn, const std::string& sCondColumn, const std::string& sCond);
	std::string GetValue(const std::string& sTable, const std::string& sColumn, unsigned uiRowIdx);
	std::string GetValueWithCond(const std::string& sTable, const std::string& sColumn, const std::string& sCondColumn, const std::string& sCond, unsigned uiRowIdx);
	QSqlDatabase* GetDatabase()const;
	static std::map<std::string, unsigned int> mapTournamentColumn;
private:
	SQLiteDB();
	static SQLiteDB* m_pDatabase;
	static QSqlDatabase m_SqlDatabase;
};

