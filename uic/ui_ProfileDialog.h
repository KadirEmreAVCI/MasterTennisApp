/********************************************************************************
** Form generated from reading UI file 'ProfileDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEDIALOG_H
#define UI_PROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileDialogClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *labelPP;
    QComboBox *comboBoxProfiles;
    QPushButton *LogOutButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QDialog *ProfileDialogClass)
    {
        if (ProfileDialogClass->objectName().isEmpty())
            ProfileDialogClass->setObjectName("ProfileDialogClass");
        ProfileDialogClass->resize(600, 400);
        gridLayout = new QGridLayout(ProfileDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelPP = new QLabel(ProfileDialogClass);
        labelPP->setObjectName("labelPP");

        horizontalLayout->addWidget(labelPP);

        comboBoxProfiles = new QComboBox(ProfileDialogClass);
        comboBoxProfiles->setObjectName("comboBoxProfiles");

        horizontalLayout->addWidget(comboBoxProfiles);

        LogOutButton = new QPushButton(ProfileDialogClass);
        LogOutButton->setObjectName("LogOutButton");

        horizontalLayout->addWidget(LogOutButton);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(ProfileDialogClass);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ProfileDialogClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ProfileDialogClass);
    } // setupUi

    void retranslateUi(QDialog *ProfileDialogClass)
    {
        ProfileDialogClass->setWindowTitle(QCoreApplication::translate("ProfileDialogClass", "ProfileDialog", nullptr));
        labelPP->setText(QCoreApplication::translate("ProfileDialogClass", "PP", nullptr));
        LogOutButton->setText(QCoreApplication::translate("ProfileDialogClass", "Log Out", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("ProfileDialogClass", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("ProfileDialogClass", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileDialogClass: public Ui_ProfileDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEDIALOG_H
