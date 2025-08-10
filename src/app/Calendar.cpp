#include <iostream>
#include "Calendar.h"

Calendar::Calendar(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Calendar::~Calendar()
{}

void Calendar::ReturnToday()
{
	m_Date = QDate::currentDate();
	ui.calendarWidget->setSelectedDate(m_Date);
}
void Calendar::on_CancelButton_clicked()
{
	ReturnToday();
	close();
}
void Calendar::on_OKButton_clicked()
{
	emit MatchDateSet(m_Date);
	ReturnToday();
	close();
}
void Calendar::on_TodayButton_clicked()
{
	ReturnToday();
}
void Calendar::on_calendarWidget_clicked(const QDate& date)
{
	m_Date = date;
}