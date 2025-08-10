#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDialog>
#include "ui_Calendar.h"

class Calendar : public QDialog
{
	Q_OBJECT

public:
	Calendar(QWidget *parent = nullptr);
	~Calendar();

private:
	void ReturnToday();
	Ui::CalendarClass ui;
	QDate m_Date;
private slots:
	void on_CancelButton_clicked();
	void on_OKButton_clicked();
	void on_TodayButton_clicked();
	void on_calendarWidget_clicked(const QDate& date);
public:
signals:
	void MatchDateSet(const QDate& date);
};

#endif