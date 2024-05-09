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
	if (OpenConn())
	{
		QSqlQuery qry;
		qry.prepare("SELECT " + QString::fromStdString(sColumnNames) + " FROM " + QString::fromStdString(sTableName));
		qry.exec();
		QSqlQueryModel* modal = new QSqlQueryModel();
		modal->setQuery(qry);
		tv->setModel(modal);
		CloseConn();
	}	
}
bool SQLiteDB::InsertRowToTable(std::string sTableName, std::string sColumnNames, std::string sValues)
{
	if (OpenConn())
	{
		QSqlQuery qry;
		QString sQry = "INSERT INTO " + QString::fromStdString(sTableName) + " (" + QString::fromStdString(sColumnNames) + ") VALUES (" + QString::fromStdString(sValues) + ")";
		std::cout << "query: " << sQry.toStdString() << "\n";
		qry.prepare(sQry);
		if (qry.exec())
		{
			std::cout << "Data inserted successfully to the table: " << sTableName << "\n";
			return true;
		}
		else
		{
			std::cout << "Data insertion to the table: " << sTableName << " failed!\n";
			std::cout << "query: " << qry.lastQuery().toStdString() << "\n";
			return false;
		}
		CloseConn();
	}
	else
	{
		return false;
	}
}
QSqlDatabase* SQLiteDB::GetDatabase()const
{
	return &m_SqlDatabase;
}