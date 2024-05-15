#include <iostream>
#include "SQLiteDB.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QTableView>
SQLiteDB* SQLiteDB::m_pDatabase{nullptr};
QSqlDatabase SQLiteDB::m_SqlDatabase;
std::map<std::string, unsigned int> SQLiteDB::mapTournamentColumn;
SQLiteDB::SQLiteDB()
{
	m_SqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
	m_SqlDatabase.setDatabaseName("C:/Users/User/Workspaces/VisualStudio2022/TennisDesktopApp/database/tournament_db.db");
	mapTournamentColumn["OrganizationID"] = 1;
	mapTournamentColumn["Type"] = 2;
	mapTournamentColumn["Teammate"] = 3;
	mapTournamentColumn["Category"] = 4;
	mapTournamentColumn["Season"] = 5;
	mapTournamentColumn["Participant"] = 6;
	mapTournamentColumn["Completion"] = 7;
	mapTournamentColumn["Progress"] = 8;
}
SQLiteDB& SQLiteDB::instance()
{
	static SQLiteDB obj;
	return obj;
}
bool SQLiteDB::OpenConn() const
{
	if (m_SqlDatabase.open())
	{
		return true;
	}
	else
	{
		std::cout << "SQLiteDB::OpenConn database could not be opened.\n";
		return false;
	}
}
void SQLiteDB::CloseConn() const
{
	m_SqlDatabase.close();
}
bool SQLiteDB::IsOpen()
{
	return m_SqlDatabase.isOpen();
}

unsigned SQLiteDB::GetRowSize(const std::string& sTable) const
{
	unsigned uiRowCount{};
	if (OpenConn())
	{
		QSqlQuery qry;
		qry.exec("SELECT COUNT(*) FROM " + QString::fromStdString(sTable));
		if (qry.next()) {
			uiRowCount = qry.value(0).toInt();
		}
		else
		{
			std::cout << "SQLiteDB::GetRowSize row count could not be read! uiRowCount = " << uiRowCount << "\n";
		}
	}
	CloseConn();
	return uiRowCount;
}

unsigned SQLiteDB::GetColumnSize(const std::string& sTable) const
{
	return 0;
}

void SQLiteDB::SetTableContent(QTableView* tv, const std::string& sTable)
{
	QSqlQuery qry;
	qry.exec("SELECT * FROM " + QString::fromStdString(sTable));
	QSqlQueryModel* modal = new QSqlQueryModel();
	modal->setQuery(qry);
	tv->setModel(modal);
}
void SQLiteDB::SetTableContentByColumn(QTableView* tv, const std::string& sTable, const std::string& sColumnNames)
{
	if (OpenConn())
	{
		QSqlQuery qry;
		qry.exec("SELECT " + QString::fromStdString(sColumnNames) + " FROM " + QString::fromStdString(sTable));
		QSqlQueryModel* modal = new QSqlQueryModel();
		modal->setQuery(qry);
		tv->setModel(modal);
	}	
	CloseConn();
}
bool SQLiteDB::InsertRowToTable(const std::string& sTable, const std::string& sColumnNames, const std::string& sValues)
{
	bool blRowInsertion{ false };
	if (OpenConn())
	{
		QSqlQuery qry;
		if (qry.exec("INSERT INTO " + QString::fromStdString(sTable) + " (" + QString::fromStdString(sColumnNames) + ") VALUES (" + QString::fromStdString(sValues) + ")"))
		{
			//std::cout << "Data inserted successfully to the table: " << sTableName << "\n";
			blRowInsertion = true;
		}
		else
		{
			std::cout << "Data insertion failed to the table: " << sTable << " query: " << qry.lastQuery().toStdString() << "\n";
		}
	}
	CloseConn();
	return blRowInsertion;
}
std::vector<std::string> SQLiteDB::GetColumn(const std::string& sTable, const std::string& sColumn)
{
	std::vector<std::string> vecColumn;
	if (OpenConn())
	{
		QSqlQuery qry;
		//std::cout << "SQLiteDB::GetColumn query: " << sQry.toStdString() << "\n";
		if (qry.exec("SELECT " + QString::fromStdString(sColumn) + " FROM " + QString::fromStdString(sTable)))
		{
			//std::cout << "SQLiteDB::GetColumn Column gotten successfully from table: " << sTable << "\n";
			while (qry.next())
			{
				std::string str = qry.value(QString::fromStdString(sColumn)).toString().toStdString();
				
				//std::cout << "SQLiteDB::GetColumn str = " << str << "\n";
				vecColumn.push_back(std::move(str));
			}
		}
		else
		{
			std::cout << "SQLiteDB::GetColumn Column could not be get from table: " << sTable << " query: " << qry.lastQuery().toStdString() << "\n";
		}
	}
	else
	{
		std::cout << "SQLiteDB::GetColumn Database could not be opened!\n";
	}
	CloseConn();
	return vecColumn;
}
std::vector<std::string> SQLiteDB::GetColumnWithCond(const std::string& sTable, const std::string& sColumn, const std::string& sCondColumn, const std::string& sCond)
{
	std::vector<std::string> vecColumn;
	if (OpenConn())
	{
		QSqlQuery qry;
		if (qry.exec("SELECT " + QString::fromStdString(sColumn) + " FROM " + QString::fromStdString(sTable) + " WHERE " + QString::fromStdString(sCondColumn) + " = '" + QString::fromStdString(sCond) + "'"))
		{
			//std::cout << "SQLiteDB::GetColumnWithCond Column gotten successfully from table: " << sTable << "\n";
			while (qry.next())
			{
				std::string str = qry.value(QString::fromStdString(sColumn)).toString().toStdString();
				//std::cout << "SQLiteDB::GetColumnWithCond str = " << str << "\n";
				vecColumn.push_back(std::move(str));
			}
		}
		else
		{
			std::cout << "SQLiteDB::GetColumnWithCond Column could not be get from table: " << sTable << " query: " << qry.lastQuery().toStdString() << "\n";
		}
	}
	else
	{
		std::cout << "SQLiteDB::GetColumnWithCond Database could not be opened!\n";
	}
	CloseConn();
	return vecColumn;
}

std::string SQLiteDB::GetValue(const std::string& sTable, const std::string& sColumn, unsigned uiRowIdx)
{
	std::vector<std::string> vecColumn;
	if (OpenConn())
	{
		vecColumn = GetColumn(sTable, sColumn);
	}
	CloseConn();
	return vecColumn[uiRowIdx];
}

std::string SQLiteDB::GetValueWithCond(const std::string& sTable, const std::string& sColumn, const std::string& sCondColumn, const std::string& sCond, unsigned uiRowIdx)
{
	std::vector<std::string> vecColumn;
	if (OpenConn())
	{
		vecColumn = GetColumnWithCond(sTable, sColumn, sCondColumn, sCond);
	}
	CloseConn();
	return vecColumn[uiRowIdx];
}

QSqlDatabase* SQLiteDB::GetDatabase()const
{
	return &m_SqlDatabase;
}