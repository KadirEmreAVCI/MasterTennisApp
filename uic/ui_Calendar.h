/********************************************************************************
** Form generated from reading UI file 'Calendar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CalendarClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QPushButton *TodayButton;
    QVBoxLayout *verticalLayout_2;
    QPushButton *OKButton;
    QPushButton *CancelButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *CalendarClass)
    {
        if (CalendarClass->objectName().isEmpty())
            CalendarClass->setObjectName("CalendarClass");
        CalendarClass->resize(476, 313);
        gridLayout = new QGridLayout(CalendarClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        calendarWidget = new QCalendarWidget(CalendarClass);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);

        verticalLayout->addWidget(calendarWidget);

        TodayButton = new QPushButton(CalendarClass);
        TodayButton->setObjectName("TodayButton");

        verticalLayout->addWidget(TodayButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        OKButton = new QPushButton(CalendarClass);
        OKButton->setObjectName("OKButton");

        verticalLayout_2->addWidget(OKButton);

        CancelButton = new QPushButton(CalendarClass);
        CancelButton->setObjectName("CancelButton");

        verticalLayout_2->addWidget(CancelButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);


        retranslateUi(CalendarClass);

        QMetaObject::connectSlotsByName(CalendarClass);
    } // setupUi

    void retranslateUi(QDialog *CalendarClass)
    {
        CalendarClass->setWindowTitle(QCoreApplication::translate("CalendarClass", "Calendar", nullptr));
        TodayButton->setText(QCoreApplication::translate("CalendarClass", "Today", nullptr));
        OKButton->setText(QCoreApplication::translate("CalendarClass", "OK", nullptr));
        CancelButton->setText(QCoreApplication::translate("CalendarClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalendarClass: public Ui_CalendarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
