#ifndef CAREERSTATSFILTERWIDGET_H
#define CAREERSTATSFILTERWIDGET_H

#include <QWidget>
#include "ui_CareerStatsFilterWidget.h"
class CareerStatsFilterWidget : public QWidget, public Ui::CareerStatsFilterWidget
{
	Q_OBJECT

public:
	CareerStatsFilterWidget(QWidget *parent = nullptr);
	~CareerStatsFilterWidget();
    void ClearWidget();
private:
    void InitFilterComponents();
	QWidget* m_pParentWidget;
	std::vector<std::string> m_vecCareerStatFilters{"Organization", "Type", "Category"};
	std::string m_sFilterType = "";
private slots:
	void on_comboBoxFilterType_currentTextChanged(const QString& sFilterType);
	void on_comboBoxFilteringItem_currentTextChanged(const QString& sFilteringItem);
	void on_ClearButton_clicked();
};

#endif	// CAREERSTATSFILTERWIDGET_H