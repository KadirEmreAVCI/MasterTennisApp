/********************************************************************************
** Form generated from reading UI file 'UpcomingMatch.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPCOMINGMATCH_H
#define UI_UPCOMINGMATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpcomingMatchClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label_Countdown;
    QVBoxLayout *verticalLayout;
    QLabel *label_TournamentName;
    QLabel *label_TournamentCategory;
    QLabel *label_Opponent;
    QLabel *label_Stage;
    QPushButton *button_DisplayTournament;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *UpcomingMatchClass)
    {
        if (UpcomingMatchClass->objectName().isEmpty())
            UpcomingMatchClass->setObjectName("UpcomingMatchClass");
        UpcomingMatchClass->resize(523, 132);
        gridLayout = new QGridLayout(UpcomingMatchClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        label_Countdown = new QLabel(UpcomingMatchClass);
        label_Countdown->setObjectName("label_Countdown");
        QFont font;
        font.setPointSize(25);
        label_Countdown->setFont(font);
        label_Countdown->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_Countdown, 0, 1, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        label_TournamentName = new QLabel(UpcomingMatchClass);
        label_TournamentName->setObjectName("label_TournamentName");

        verticalLayout->addWidget(label_TournamentName);

        label_TournamentCategory = new QLabel(UpcomingMatchClass);
        label_TournamentCategory->setObjectName("label_TournamentCategory");

        verticalLayout->addWidget(label_TournamentCategory);

        label_Opponent = new QLabel(UpcomingMatchClass);
        label_Opponent->setObjectName("label_Opponent");

        verticalLayout->addWidget(label_Opponent);

        label_Stage = new QLabel(UpcomingMatchClass);
        label_Stage->setObjectName("label_Stage");

        verticalLayout->addWidget(label_Stage);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        button_DisplayTournament = new QPushButton(UpcomingMatchClass);
        button_DisplayTournament->setObjectName("button_DisplayTournament");

        gridLayout->addWidget(button_DisplayTournament, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);


        retranslateUi(UpcomingMatchClass);

        QMetaObject::connectSlotsByName(UpcomingMatchClass);
    } // setupUi

    void retranslateUi(QWidget *UpcomingMatchClass)
    {
        UpcomingMatchClass->setWindowTitle(QCoreApplication::translate("UpcomingMatchClass", "UpcomingMatch", nullptr));
        label_Countdown->setText(QCoreApplication::translate("UpcomingMatchClass", "dd : hh : mm : ss", nullptr));
        label_TournamentName->setText(QCoreApplication::translate("UpcomingMatchClass", "%Tournament Name", nullptr));
        label_TournamentCategory->setText(QCoreApplication::translate("UpcomingMatchClass", "%Tournament Category", nullptr));
        label_Opponent->setText(QCoreApplication::translate("UpcomingMatchClass", "%Opponent Name", nullptr));
        label_Stage->setText(QCoreApplication::translate("UpcomingMatchClass", "%Stage", nullptr));
        button_DisplayTournament->setText(QCoreApplication::translate("UpcomingMatchClass", "Display Tournament", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UpcomingMatchClass: public Ui_UpcomingMatchClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPCOMINGMATCH_H
