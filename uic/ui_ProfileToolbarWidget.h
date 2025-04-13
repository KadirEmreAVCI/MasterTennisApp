/********************************************************************************
** Form generated from reading UI file 'ProfileToolbarWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILETOOLBARWIDGET_H
#define UI_PROFILETOOLBARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileToolbarWidgetClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPP;
    QComboBox *comboBoxProfiles;
    QPushButton *LogOutButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProfileToolbarWidgetClass)
    {
        if (ProfileToolbarWidgetClass->objectName().isEmpty())
            ProfileToolbarWidgetClass->setObjectName("ProfileToolbarWidgetClass");
        ProfileToolbarWidgetClass->resize(248, 110);
        centralWidget = new QWidget(ProfileToolbarWidgetClass);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        labelPP = new QLabel(centralWidget);
        labelPP->setObjectName("labelPP");

        horizontalLayout->addWidget(labelPP);

        comboBoxProfiles = new QComboBox(centralWidget);
        comboBoxProfiles->setObjectName("comboBoxProfiles");

        horizontalLayout->addWidget(comboBoxProfiles);

        LogOutButton = new QPushButton(centralWidget);
        LogOutButton->setObjectName("LogOutButton");

        horizontalLayout->addWidget(LogOutButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        ProfileToolbarWidgetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProfileToolbarWidgetClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 248, 33));
        ProfileToolbarWidgetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProfileToolbarWidgetClass);
        mainToolBar->setObjectName("mainToolBar");
        ProfileToolbarWidgetClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProfileToolbarWidgetClass);
        statusBar->setObjectName("statusBar");
        ProfileToolbarWidgetClass->setStatusBar(statusBar);

        retranslateUi(ProfileToolbarWidgetClass);

        QMetaObject::connectSlotsByName(ProfileToolbarWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProfileToolbarWidgetClass)
    {
        ProfileToolbarWidgetClass->setWindowTitle(QCoreApplication::translate("ProfileToolbarWidgetClass", "ProfileToolbarWidget", nullptr));
        labelPP->setText(QCoreApplication::translate("ProfileToolbarWidgetClass", "PP", nullptr));
        LogOutButton->setText(QCoreApplication::translate("ProfileToolbarWidgetClass", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileToolbarWidgetClass: public Ui_ProfileToolbarWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILETOOLBARWIDGET_H
