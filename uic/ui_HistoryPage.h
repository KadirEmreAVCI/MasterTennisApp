/********************************************************************************
** Form generated from reading UI file 'HistoryPage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYPAGE_H
#define UI_HISTORYPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryPageClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *NewTournamentButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *HistoryPageClass)
    {
        if (HistoryPageClass->objectName().isEmpty())
            HistoryPageClass->setObjectName("HistoryPageClass");
        HistoryPageClass->resize(349, 250);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HistoryPageClass->sizePolicy().hasHeightForWidth());
        HistoryPageClass->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(HistoryPageClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        NewTournamentButton = new QPushButton(HistoryPageClass);
        NewTournamentButton->setObjectName("NewTournamentButton");
        NewTournamentButton->setToolTipDuration(-1);

        horizontalLayout_2->addWidget(NewTournamentButton);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget = new QTableWidget(HistoryPageClass);
        tableWidget->setObjectName("tableWidget");
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        tableWidget->setFont(font);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSortingEnabled(false);

        verticalLayout->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(HistoryPageClass);

        QMetaObject::connectSlotsByName(HistoryPageClass);
    } // setupUi

    void retranslateUi(QWidget *HistoryPageClass)
    {
        HistoryPageClass->setWindowTitle(QCoreApplication::translate("HistoryPageClass", "Tournament History", nullptr));
#if QT_CONFIG(tooltip)
        NewTournamentButton->setToolTip(QCoreApplication::translate("HistoryPageClass", "Add new tournament", nullptr));
#endif // QT_CONFIG(tooltip)
        NewTournamentButton->setText(QCoreApplication::translate("HistoryPageClass", " New Tournament ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryPageClass: public Ui_HistoryPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYPAGE_H
