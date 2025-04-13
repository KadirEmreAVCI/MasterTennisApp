/********************************************************************************
** Form generated from reading UI file 'HomePage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePageClass
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_IconHomePage;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_UpcomingMatches;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget_UpcomingMatches;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *HomePageClass)
    {
        if (HomePageClass->objectName().isEmpty())
            HomePageClass->setObjectName("HomePageClass");
        HomePageClass->resize(625, 391);
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        HomePageClass->setFont(font);
        HomePageClass->setAutoFillBackground(true);
        gridLayout_4 = new QGridLayout(HomePageClass);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_IconHomePage = new QLabel(HomePageClass);
        label_IconHomePage->setObjectName("label_IconHomePage");

        horizontalLayout->addWidget(label_IconHomePage);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        groupBox_UpcomingMatches = new QGroupBox(HomePageClass);
        groupBox_UpcomingMatches->setObjectName("groupBox_UpcomingMatches");
        groupBox_UpcomingMatches->setMaximumSize(QSize(16777215, 300));
        groupBox_UpcomingMatches->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox_UpcomingMatches);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        listWidget_UpcomingMatches = new QListWidget(groupBox_UpcomingMatches);
        listWidget_UpcomingMatches->setObjectName("listWidget_UpcomingMatches");
        listWidget_UpcomingMatches->setMaximumSize(QSize(16777215, 200));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setStrikeOut(false);
        font1.setKerning(false);
        listWidget_UpcomingMatches->setFont(font1);
        listWidget_UpcomingMatches->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        listWidget_UpcomingMatches->setAutoFillBackground(false);
        listWidget_UpcomingMatches->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        listWidget_UpcomingMatches->setAlternatingRowColors(true);

        gridLayout_2->addWidget(listWidget_UpcomingMatches, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_UpcomingMatches);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(HomePageClass);

        QMetaObject::connectSlotsByName(HomePageClass);
    } // setupUi

    void retranslateUi(QWidget *HomePageClass)
    {
        HomePageClass->setWindowTitle(QCoreApplication::translate("HomePageClass", "HomePage", nullptr));
        label_IconHomePage->setText(QCoreApplication::translate("HomePageClass", "HOME PAGE ICON", nullptr));
        groupBox_UpcomingMatches->setTitle(QCoreApplication::translate("HomePageClass", "Upcoming Matches", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomePageClass: public Ui_HomePageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
