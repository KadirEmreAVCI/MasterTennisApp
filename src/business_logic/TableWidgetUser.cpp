#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QScrollBar>
#include <QHeaderView>
#include <QLabel>
#include "TableWidgetUser.h"
#include "Utility.h"
TableWidgetUser::TableWidgetUser(std::vector<std::string> vecColumnNames) : m_pTableWidget{nullptr}, m_vecColumnNames{vecColumnNames}
{
	
}
void TableWidgetUser::InitTable(QTableWidget* pTableWidget)
{
	if(nullptr != pTableWidget)
	{
		m_pTableWidget = pTableWidget;
		FillColumnNamesOfTable();
		MakeColumnHeaderBold();
	}
}
void TableWidgetUser::MakeColumnHeaderBold()
{
	QFont headerFont = m_pTableWidget->horizontalHeader()->font();
	headerFont.setBold(true);
	m_pTableWidget->horizontalHeader()->setFont(headerFont);
}
void TableWidgetUser::FillColumnNamesOfTable()
{
	m_pTableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
	m_pTableWidget->setColumnCount(0);
	unsigned uiColumnIdx = 0;
	m_pTableWidget->setColumnCount(m_vecColumnNames.size());
	for (const auto& sColumnName : m_vecColumnNames)
	{
		m_pTableWidget->setHorizontalHeaderItem(uiColumnIdx, new QTableWidgetItem(QString::fromStdString(sColumnName)));
		++uiColumnIdx;
	}
	m_pTableWidget->resizeColumnsToContents();
}
void TableWidgetUser::ClearTable()
{
	m_pTableWidget->clearContents();
	m_pTableWidget->setRowCount(0);
}