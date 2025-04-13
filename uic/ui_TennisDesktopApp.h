/********************************************************************************
** Form generated from reading UI file 'TennisDesktopApp.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TENNISDESKTOPAPP_H
#define UI_TENNISDESKTOPAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TennisDesktopAppClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_WelcomeText;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_LoginPic;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Intro2;
    QLabel *label_Intro1;
    QLabel *label_Intro3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QPushButton *StartButton;
    QPushButton *OrganizationsButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TennisDesktopAppClass)
    {
        if (TennisDesktopAppClass->objectName().isEmpty())
            TennisDesktopAppClass->setObjectName("TennisDesktopAppClass");
        TennisDesktopAppClass->resize(688, 523);
        centralWidget = new QWidget(TennisDesktopAppClass);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_WelcomeText = new QLabel(centralWidget);
        label_WelcomeText->setObjectName("label_WelcomeText");
        QFont font;
        font.setPointSize(25);
        label_WelcomeText->setFont(font);
        label_WelcomeText->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_WelcomeText);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_LoginPic = new QLabel(centralWidget);
        label_LoginPic->setObjectName("label_LoginPic");
        QFont font1;
        font1.setPointSize(15);
        font1.setItalic(false);
        label_LoginPic->setFont(font1);
        label_LoginPic->setScaledContents(false);
        label_LoginPic->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_LoginPic);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(30, -1, -1, -1);
        label_Intro2 = new QLabel(centralWidget);
        label_Intro2->setObjectName("label_Intro2");
        QFont font2;
        font2.setPointSize(12);
        label_Intro2->setFont(font2);

        verticalLayout_2->addWidget(label_Intro2);

        label_Intro1 = new QLabel(centralWidget);
        label_Intro1->setObjectName("label_Intro1");
        label_Intro1->setFont(font2);

        verticalLayout_2->addWidget(label_Intro1);

        label_Intro3 = new QLabel(centralWidget);
        label_Intro3->setObjectName("label_Intro3");
        label_Intro3->setFont(font2);

        verticalLayout_2->addWidget(label_Intro3);


        verticalLayout->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        StartButton = new QPushButton(centralWidget);
        StartButton->setObjectName("StartButton");
        StartButton->setFont(font2);

        verticalLayout_4->addWidget(StartButton);

        OrganizationsButton = new QPushButton(centralWidget);
        OrganizationsButton->setObjectName("OrganizationsButton");
        OrganizationsButton->setFont(font2);
        OrganizationsButton->setIconSize(QSize(32, 32));

        verticalLayout_4->addWidget(OrganizationsButton);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);

        TennisDesktopAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TennisDesktopAppClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 688, 33));
        TennisDesktopAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TennisDesktopAppClass);
        mainToolBar->setObjectName("mainToolBar");
        TennisDesktopAppClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TennisDesktopAppClass);
        statusBar->setObjectName("statusBar");
        TennisDesktopAppClass->setStatusBar(statusBar);

        retranslateUi(TennisDesktopAppClass);

        QMetaObject::connectSlotsByName(TennisDesktopAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *TennisDesktopAppClass)
    {
        TennisDesktopAppClass->setWindowTitle(QString());
        label_WelcomeText->setText(QCoreApplication::translate("TennisDesktopAppClass", "App Name", nullptr));
        label_LoginPic->setText(QCoreApplication::translate("TennisDesktopAppClass", "WELCOME IMAGE", nullptr));
        label_Intro2->setText(QCoreApplication::translate("TennisDesktopAppClass", "- Display your career statistics", nullptr));
        label_Intro1->setText(QCoreApplication::translate("TennisDesktopAppClass", "- Record your tournament history", nullptr));
        label_Intro3->setText(QCoreApplication::translate("TennisDesktopAppClass", "- See upcoming matches", nullptr));
        StartButton->setText(QCoreApplication::translate("TennisDesktopAppClass", "Start", nullptr));
        OrganizationsButton->setText(QCoreApplication::translate("TennisDesktopAppClass", " Organizations ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TennisDesktopAppClass: public Ui_TennisDesktopAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TENNISDESKTOPAPP_H
