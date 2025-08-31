#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QScrollBar>
#include <QHeaderView>
#include <QLabel>
#include "TableWidgetUser.h"
#include "Utility.h"
TableWidgetUser::TableWidgetUser()
{

}
void TableWidgetUser::InitTable(QTableWidget* table, const std::vector<std::string>& vecColumnNames)
{
	m_vecColumnNames = vecColumnNames;
	FillColumnNamesOfTable(table);
	MakeColumnHeaderBold(table);
}
void TableWidgetUser::MakeColumnHeaderBold(QTableWidget* table)
{
	QFont headerFont = table->horizontalHeader()->font();
	headerFont.setBold(true);
	table->horizontalHeader()->setFont(headerFont);
}
void TableWidgetUser::FillColumnNamesOfTable(QTableWidget* table)
{
	table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
	table->setColumnCount(0);
	unsigned uiColumnIdx = 0;
	table->setColumnCount(m_vecColumnNames.size());
	for (const auto& sColumnName : m_vecColumnNames)
	{
		table->setHorizontalHeaderItem(uiColumnIdx, new QTableWidgetItem(QString::fromStdString(sColumnName)));
		++uiColumnIdx;
	}
	table->resizeColumnsToContents();
}
void TableWidgetUser::ClearTable(QTableWidget* table)
{
	table->clearContents();
	table->setRowCount(0);
}