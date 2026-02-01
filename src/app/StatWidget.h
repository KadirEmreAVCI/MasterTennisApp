#ifndef STATWIDGET_H
#define STATWIDGET_H

#include <QWidget>
#include "ui_StatWidget.h"
#include "Stat.h"
class StatWidget : public QWidget, public Ui::StatWidget
{
	Q_OBJECT

public:
	explicit StatWidget(QWidget *parent = nullptr);
	~StatWidget() = default;
    void InitWidget(const std::string& sStatName, const std::string& sPicturePath, float fPictureScale);
    void FillWidget(const StatReport& rStatReport);
	QLabel* GetLabelIcon()const;
	QLabel* GetLabelStatName()const;
	QLabel* GetLabelTotalText()const;
	QLabel* GetLabelTotal()const;
	QLabel* GetLabelWinText()const;
	QLabel* GetLabelWin()const;
	QLabel* GetLabelLoseText()const;
	QLabel* GetLabelLose()const;
	QLabel* GetLabelWinRate()const;
};

#endif  // STATWIDGET_H