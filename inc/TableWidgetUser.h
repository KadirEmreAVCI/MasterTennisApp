#pragma once
#include <string>
#include <vector>
#include <QTableWidget>
#include "IQTComponent.h"
class TableWidgetUser : public IQTComponent {
protected:
	TableWidgetUser();
	void MakeColumnHeaderBold(QTableWidget* table);
	void FillColumnNamesOfTable(QTableWidget* table);
	void ClearTable(QTableWidget* table);
	void InsertValue2Cell(QTableWidget* table, QString sVal, unsigned uiRowIdx, unsigned uiColumnIdx);
	void InsertPic2Cell(QTableWidget* table, const std::string& sPicAddr, float fScale, unsigned uiRowIdx, unsigned uiColumnIdx);
	virtual void LoadDataToTable()=0;
	virtual void FillTable() = 0;
	std::vector<std::string> m_vecColumnNames;
};