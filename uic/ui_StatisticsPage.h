/********************************************************************************
** Form generated from reading UI file 'StatisticsPage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSPAGE_H
#define UI_STATISTICSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsPageClass
{
public:

    void setupUi(QWidget *StatisticsPageClass)
    {
        if (StatisticsPageClass->objectName().isEmpty())
            StatisticsPageClass->setObjectName("StatisticsPageClass");
        StatisticsPageClass->resize(600, 400);

        retranslateUi(StatisticsPageClass);

        QMetaObject::connectSlotsByName(StatisticsPageClass);
    } // setupUi

    void retranslateUi(QWidget *StatisticsPageClass)
    {
        StatisticsPageClass->setWindowTitle(QCoreApplication::translate("StatisticsPageClass", "StatisticsPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsPageClass: public Ui_StatisticsPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSPAGE_H
