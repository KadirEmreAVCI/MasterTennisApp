#ifndef TABLEWIDGETUSER_H
#define TABLEWIDGETUSER_H

#include <string>
#include <vector>
#include <QTableWidget>
class TableWidgetUser{
protected:
	TableWidgetUser();
	void InitTable(QTableWidget* table, const std::vector<std::string>& vecColumnNames);
	void ClearTable(QTableWidget* table);
	virtual void LoadDataToTable()=0;
	virtual void FillTable() = 0;
private:
	void MakeColumnHeaderBold(QTableWidget* table);
	void FillColumnNamesOfTable(QTableWidget* table);	
	std::vector<std::string> m_vecColumnNames;
};

#endif