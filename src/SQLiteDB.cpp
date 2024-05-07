#include <iostream>
#include "SQLiteDB.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QTableView>
SQLiteDB* SQLiteDB::m_pDatabase{nullptr};
QSqlDatabase SQLiteDB::m_SqlDatabase;
SQLiteDB::SQLiteDB()
{
	
}
SQLiteDB& SQLiteDB::instance()
{
	static SQLiteDB obj;
	return obj;
}
bool SQLiteDB::OpenConn()
{
	m_SqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
	m_SqlDatabase.setDatabaseName("C:/Users/User/Workspaces/VisualStudio2022/TennisDesktopApp/database/tournament_db.db");
	if (m_SqlDatabase.open())
	{
		std::cout << "SQLiteDB::OpenConn database opened successfully\n";
		return true;
	}
	else
	{
		std::cout << "SQLiteDB::OpenConn database could not be opened.\n";
		return false;
	}
}
void SQLiteDB::CloseConn() 
{
	m_SqlDatabase.close();
}
bool SQLiteDB::IsOpen()
{
	return m_SqlDatabase.isOpen();
}
void SQLiteDB::SetTableContent(QTableView* tv, std::string sTableName)
{
	QSqlQuery qry;
	qry.prepare("SELECT * FROM " + QString::fromStdString(sTableName));
	qry.exec();
	QSqlQueryModel* modal = new QSqlQueryModel();
	modal->setQuery(qry);
	tv->setModel(modal);
}
void SQLiteDB::SetTableContentByColumn(QTableView* tv, std::string sTableName, std::string sColumnNames)
{
	QSqlQuery qry;
	qry.prepare("SELECT " + QString::fromStdString(sColumnNames) + " FROM " + QString::fromStdString(sTableName));
	qry.exec();
	QSqlQueryModel* modal = new QSqlQueryModel();
	modal->setQuery(qry);
	tv->setModel(modal);
}
QSqlDatabase* SQLiteDB::GetDatabase()const
{
	return &m_SqlDatabase;
}