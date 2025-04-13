#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QScrollBar>
#include <QHeaderView>
#include <QLabel>
#include "TableWidgetUser.h"
TableWidgetUser::TableWidgetUser()
{

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
void TableWidgetUser::InsertValue2Cell(QTableWidget* table, QString sVal, unsigned uiRowIdx, unsigned uiColumnIdx)
{
	QTableWidgetItem* const pVal = new QTableWidgetItem;
	pVal->setText(sVal);
	pVal->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	table->setItem(uiRowIdx, uiColumnIdx++, pVal);
}
void TableWidgetUser::InsertPic2Cell(QTableWidget* table, const std::string& sPicAddr, float fScale, unsigned uiRowIdx, unsigned uiColumnIdx)
{
	QLabel* pLabel = new QLabel;
	InitPicture(pLabel, sPicAddr, fScale);
	table->setCellWidget(uiRowIdx, uiColumnIdx++, pLabel);
}
