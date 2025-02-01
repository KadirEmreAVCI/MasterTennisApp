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
    QGroupBox *groupBox_UpcomingMatches;
    QListWidget *listWidget_UpcomingMatches;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_IconGame;
    QLabel *label_FeatureGame;
    QSpacerItem *horizontalSpacer;
    QLabel *label_StatGame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_IconWin;
    QLabel *label_FeatureWin;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_StatWin;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_IconLose;
    QLabel *label_FeatureLose;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_StatLose;
    QHBoxLayout *horizontalLayout;
    QLabel *label_IconClutchness;
    QLabel *label_FeatureClutchness;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_GameClutchness;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_IconTrophies;
    QLabel *label_FeatureTrophies;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_StatTrophies;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_IconGA;
    QLabel *label_FeatureGA;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_StatGA;

    void setupUi(QWidget *HomePageClass)
    {
        if (HomePageClass->objectName().isEmpty())
            HomePageClass->setObjectName("HomePageClass");
        HomePageClass->resize(1168, 761);
        groupBox_UpcomingMatches = new QGroupBox(HomePageClass);
        groupBox_UpcomingMatches->setObjectName("groupBox_UpcomingMatches");
        groupBox_UpcomingMatches->setGeometry(QRect(610, 30, 541, 411));
        listWidget_UpcomingMatches = new QListWidget(groupBox_UpcomingMatches);
        listWidget_UpcomingMatches->setObjectName("listWidget_UpcomingMatches");
        listWidget_UpcomingMatches->setGeometry(QRect(0, 20, 541, 391));
        layoutWidget = new QWidget(HomePageClass);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 280, 531, 461));
        QFont font;
        font.setPointSize(20);
        layoutWidget->setFont(font);
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_IconGame = new QLabel(layoutWidget);
        label_IconGame->setObjectName("label_IconGame");
        label_IconGame->setFont(font);

        horizontalLayout_2->addWidget(label_IconGame);

        label_FeatureGame = new QLabel(layoutWidget);
        label_FeatureGame->setObjectName("label_FeatureGame");
        label_FeatureGame->setFont(font);

        horizontalLayout_2->addWidget(label_FeatureGame);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_StatGame = new QLabel(layoutWidget);
        label_StatGame->setObjectName("label_StatGame");
        label_StatGame->setFont(font);

        horizontalLayout_2->addWidget(label_StatGame);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_IconWin = new QLabel(layoutWidget);
        label_IconWin->setObjectName("label_IconWin");
        label_IconWin->setFont(font);

        horizontalLayout_3->addWidget(label_IconWin);

        label_FeatureWin = new QLabel(layoutWidget);
        label_FeatureWin->setObjectName("label_FeatureWin");
        label_FeatureWin->setFont(font);

        horizontalLayout_3->addWidget(label_FeatureWin);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_StatWin = new QLabel(layoutWidget);
        label_StatWin->setObjectName("label_StatWin");
        label_StatWin->setFont(font);

        horizontalLayout_3->addWidget(label_StatWin);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_IconLose = new QLabel(layoutWidget);
        label_IconLose->setObjectName("label_IconLose");
        label_IconLose->setFont(font);

        horizontalLayout_4->addWidget(label_IconLose);

        label_FeatureLose = new QLabel(layoutWidget);
        label_FeatureLose->setObjectName("label_FeatureLose");
        label_FeatureLose->setFont(font);

        horizontalLayout_4->addWidget(label_FeatureLose);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_StatLose = new QLabel(layoutWidget);
        label_StatLose->setObjectName("label_StatLose");
        label_StatLose->setFont(font);

        horizontalLayout_4->addWidget(label_StatLose);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        label_IconClutchness = new QLabel(layoutWidget);
        label_IconClutchness->setObjectName("label_IconClutchness");
        label_IconClutchness->setFont(font);

        horizontalLayout->addWidget(label_IconClutchness);

        label_FeatureClutchness = new QLabel(layoutWidget);
        label_FeatureClutchness->setObjectName("label_FeatureClutchness");
        label_FeatureClutchness->setFont(font);

        horizontalLayout->addWidget(label_FeatureClutchness);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_GameClutchness = new QLabel(layoutWidget);
        label_GameClutchness->setObjectName("label_GameClutchness");
        label_GameClutchness->setFont(font);

        horizontalLayout->addWidget(label_GameClutchness);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_IconTrophies = new QLabel(layoutWidget);
        label_IconTrophies->setObjectName("label_IconTrophies");
        label_IconTrophies->setFont(font);

        horizontalLayout_5->addWidget(label_IconTrophies);

        label_FeatureTrophies = new QLabel(layoutWidget);
        label_FeatureTrophies->setObjectName("label_FeatureTrophies");
        label_FeatureTrophies->setFont(font);

        horizontalLayout_5->addWidget(label_FeatureTrophies);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        label_StatTrophies = new QLabel(layoutWidget);
        label_StatTrophies->setObjectName("label_StatTrophies");
        label_StatTrophies->setFont(font);

        horizontalLayout_5->addWidget(label_StatTrophies);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_IconGA = new QLabel(layoutWidget);
        label_IconGA->setObjectName("label_IconGA");
        label_IconGA->setFont(font);

        horizontalLayout_6->addWidget(label_IconGA);

        label_FeatureGA = new QLabel(layoutWidget);
        label_FeatureGA->setObjectName("label_FeatureGA");
        label_FeatureGA->setFont(font);

        horizontalLayout_6->addWidget(label_FeatureGA);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        label_StatGA = new QLabel(layoutWidget);
        label_StatGA->setObjectName("label_StatGA");
        label_StatGA->setFont(font);

        horizontalLayout_6->addWidget(label_StatGA);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(HomePageClass);

        QMetaObject::connectSlotsByName(HomePageClass);
    } // setupUi

    void retranslateUi(QWidget *HomePageClass)
    {
        HomePageClass->setWindowTitle(QCoreApplication::translate("HomePageClass", "HomePage", nullptr));
        groupBox_UpcomingMatches->setTitle(QCoreApplication::translate("HomePageClass", "Upcoming Matches", nullptr));
        label_IconGame->setText(QCoreApplication::translate("HomePageClass", "ICON", nullptr));
        label_FeatureGame->setText(QCoreApplication::translate("HomePageClass", "    Total Game: ", nullptr));
        label_StatGame->setText(QCoreApplication::translate("HomePageClass", "#Num", nullptr));
        label_IconWin->setText(QCoreApplication::translate("HomePageClass", "ICON", nullptr));
        label_FeatureWin->setText(QCoreApplication::translate("HomePageClass", "    Wins: ", nullptr));
        label_StatWin->setText(QCoreApplication::translate("HomePageClass", "#Num", nullptr));
        label_IconLose->setText(QCoreApplication::translate("HomePageClass", "ICON", nullptr));
        label_FeatureLose->setText(QCoreApplication::translate("HomePageClass", "    Loses", nullptr));
        label_StatLose->setText(QCoreApplication::translate("HomePageClass", "#Num", nullptr));
        label_IconClutchness->setText(QCoreApplication::translate("HomePageClass", "ICON", nullptr));
        label_FeatureClutchness->setText(QCoreApplication::translate("HomePageClass", "    Clutchness: ", nullptr));
        label_GameClutchness->setText(QCoreApplication::translate("HomePageClass", "#Num", nullptr));
        label_IconTrophies->setText(QCoreApplication::translate("HomePageClass", "ICON", nullptr));
        label_FeatureTrophies->setText(QCoreApplication::translate("HomePageClass", "    Trophies: ", nullptr));
        label_StatTrophies->setText(QCoreApplication::translate("HomePageClass", "#Num", nullptr));
        label_IconGA->setText(QCoreApplication::translate("HomePageClass", "ICON", nullptr));
        label_FeatureGA->setText(QCoreApplication::translate("HomePageClass", "    Greatest Achievement: ", nullptr));
        label_StatGA->setText(QCoreApplication::translate("HomePageClass", "#Num", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomePageClass: public Ui_HomePageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
