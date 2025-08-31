#ifndef TABLEWIDGETUSER_H
#define TABLEWIDGETUSER_H

#include <string>
#include <vector>
#include <QTableWidget>
class TableWidgetUser{
protected:
	explicit TableWidgetUser(std::vector<std::string> vecColumnNames);
	void InitTable(QTableWidget* pTableWidget);
	void ClearTable();
	virtual void LoadDataToTable()=0;
	virtual void FillTable() = 0;
	std::vector<std::string> m_vecColumnNames;
	QTableWidget* m_pTableWidget;
private:
	void MakeColumnHeaderBold();
	void FillColumnNamesOfTable();	
};

#endif