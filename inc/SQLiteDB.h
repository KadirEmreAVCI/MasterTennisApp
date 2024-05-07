#pragma once
#include <QSqlDatabase> 
#include "IDatabase.h"
class QSqlQueryModel;
class QTableView;
class SQLiteDB : public IDatabase{
public:
	
	SQLiteDB(const SQLiteDB&) = delete;
	SQLiteDB& operator=(const SQLiteDB&) = delete;
	static SQLiteDB& instance();
	bool OpenConn() override final;
	void CloseConn() override final;
	bool IsOpen() override final;
	void SetTableContent(QTableView*, std::string sTableName) override final;
	void SetTableContentByColumn(QTableView*, std::string sTableName, std::string sColumnNames) override final;
	QSqlDatabase* GetDatabase()const;
private:
	SQLiteDB();
	static SQLiteDB* m_pDatabase;
	static QSqlDatabase m_SqlDatabase;
};

