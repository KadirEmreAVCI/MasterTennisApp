/********************************************************************************
** Form generated from reading UI file 'ProfileBarWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEBARWIDGET_H
#define UI_PROFILEBARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileBarWidgetClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelName;
    QLabel *labelPP;
    QPushButton *pushButton;

    void setupUi(QWidget *ProfileBarWidgetClass)
    {
        if (ProfileBarWidgetClass->objectName().isEmpty())
            ProfileBarWidgetClass->setObjectName("ProfileBarWidgetClass");
        ProfileBarWidgetClass->resize(262, 44);
        gridLayout = new QGridLayout(ProfileBarWidgetClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        labelName = new QLabel(ProfileBarWidgetClass);
        labelName->setObjectName("labelName");

        horizontalLayout->addWidget(labelName);

        labelPP = new QLabel(ProfileBarWidgetClass);
        labelPP->setObjectName("labelPP");

        horizontalLayout->addWidget(labelPP);

        pushButton = new QPushButton(ProfileBarWidgetClass);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(ProfileBarWidgetClass);

        QMetaObject::connectSlotsByName(ProfileBarWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ProfileBarWidgetClass)
    {
        ProfileBarWidgetClass->setWindowTitle(QCoreApplication::translate("ProfileBarWidgetClass", "ProfileBarWidget", nullptr));
        labelName->setText(QCoreApplication::translate("ProfileBarWidgetClass", "Name", nullptr));
        labelPP->setText(QCoreApplication::translate("ProfileBarWidgetClass", "PP", nullptr));
        pushButton->setText(QCoreApplication::translate("ProfileBarWidgetClass", "Sign Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileBarWidgetClass: public Ui_ProfileBarWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEBARWIDGET_H
