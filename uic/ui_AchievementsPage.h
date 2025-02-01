/********************************************************************************
** Form generated from reading UI file 'AchievementsPage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACHIEVEMENTSPAGE_H
#define UI_ACHIEVEMENTSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AchievementsPageClass
{
public:

    void setupUi(QWidget *AchievementsPageClass)
    {
        if (AchievementsPageClass->objectName().isEmpty())
            AchievementsPageClass->setObjectName("AchievementsPageClass");
        AchievementsPageClass->resize(600, 400);

        retranslateUi(AchievementsPageClass);

        QMetaObject::connectSlotsByName(AchievementsPageClass);
    } // setupUi

    void retranslateUi(QWidget *AchievementsPageClass)
    {
        AchievementsPageClass->setWindowTitle(QCoreApplication::translate("AchievementsPageClass", "AchievementsPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AchievementsPageClass: public Ui_AchievementsPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACHIEVEMENTSPAGE_H
