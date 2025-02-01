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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TennisDesktopAppClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Intro2;
    QLabel *label_Intro1;
    QLabel *label_Intro3;
    QLabel *label_WelcomeText;
    QLabel *label_LoginPic;
    QPushButton *continueButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TennisDesktopAppClass)
    {
        if (TennisDesktopAppClass->objectName().isEmpty())
            TennisDesktopAppClass->setObjectName("TennisDesktopAppClass");
        TennisDesktopAppClass->resize(813, 607);
        centralWidget = new QWidget(TennisDesktopAppClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(370, 170, 401, 191));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Intro2 = new QLabel(verticalLayoutWidget);
        label_Intro2->setObjectName("label_Intro2");
        QFont font;
        font.setPointSize(12);
        label_Intro2->setFont(font);

        verticalLayout_2->addWidget(label_Intro2);

        label_Intro1 = new QLabel(verticalLayoutWidget);
        label_Intro1->setObjectName("label_Intro1");
        label_Intro1->setFont(font);

        verticalLayout_2->addWidget(label_Intro1);

        label_Intro3 = new QLabel(verticalLayoutWidget);
        label_Intro3->setObjectName("label_Intro3");
        label_Intro3->setFont(font);

        verticalLayout_2->addWidget(label_Intro3);

        label_WelcomeText = new QLabel(centralWidget);
        label_WelcomeText->setObjectName("label_WelcomeText");
        label_WelcomeText->setGeometry(QRect(130, 30, 541, 51));
        QFont font1;
        font1.setPointSize(25);
        label_WelcomeText->setFont(font1);
        label_WelcomeText->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_LoginPic = new QLabel(centralWidget);
        label_LoginPic->setObjectName("label_LoginPic");
        label_LoginPic->setGeometry(QRect(80, 120, 241, 291));
        QFont font2;
        font2.setItalic(false);
        label_LoginPic->setFont(font2);
        label_LoginPic->setScaledContents(false);
        label_LoginPic->setAlignment(Qt::AlignmentFlag::AlignCenter);
        continueButton = new QPushButton(centralWidget);
        continueButton->setObjectName("continueButton");
        continueButton->setGeometry(QRect(620, 460, 151, 41));
        TennisDesktopAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TennisDesktopAppClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 813, 33));
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
        TennisDesktopAppClass->setWindowTitle(QCoreApplication::translate("TennisDesktopAppClass", "TennisDesktopApp", nullptr));
        label_Intro2->setText(QCoreApplication::translate("TennisDesktopAppClass", "- Display your accomplishment", nullptr));
        label_Intro1->setText(QCoreApplication::translate("TennisDesktopAppClass", "- Record your tournaments", nullptr));
        label_Intro3->setText(QCoreApplication::translate("TennisDesktopAppClass", "- See upcoming matches", nullptr));
        label_WelcomeText->setText(QString());
        label_LoginPic->setText(QCoreApplication::translate("TennisDesktopAppClass", "Login Image", nullptr));
        continueButton->setText(QCoreApplication::translate("TennisDesktopAppClass", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TennisDesktopAppClass: public Ui_TennisDesktopAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TENNISDESKTOPAPP_H
