#pragma once
#include <string>
class QTableView;
class IDatabase {
public:
	virtual bool OpenConn() = 0;
	virtual void CloseConn() = 0;
	virtual bool IsOpen() = 0;
	virtual void SetTableContent(QTableView*, std::string sTableName) = 0;
	virtual void SetTableContentByColumn(QTableView*, std::string sTableName, std::string sColumnNames) = 0;
private:
};