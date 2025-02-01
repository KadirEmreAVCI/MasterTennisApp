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
#include <QtWidgets/QComboBox>
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
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *AddButton;
    QPushButton *EditButton;
    QPushButton *DeleteButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_DisplayedTable;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *HistoryPageClass)
    {
        if (HistoryPageClass->objectName().isEmpty())
            HistoryPageClass->setObjectName("HistoryPageClass");
        HistoryPageClass->resize(1012, 514);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HistoryPageClass->sizePolicy().hasHeightForWidth());
        HistoryPageClass->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(HistoryPageClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        tableWidget = new QTableWidget(HistoryPageClass);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setSortingEnabled(true);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        AddButton = new QPushButton(HistoryPageClass);
        AddButton->setObjectName("AddButton");

        verticalLayout->addWidget(AddButton);

        EditButton = new QPushButton(HistoryPageClass);
        EditButton->setObjectName("EditButton");

        verticalLayout->addWidget(EditButton);

        DeleteButton = new QPushButton(HistoryPageClass);
        DeleteButton->setObjectName("DeleteButton");

        verticalLayout->addWidget(DeleteButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        comboBox_DisplayedTable = new QComboBox(HistoryPageClass);
        comboBox_DisplayedTable->addItem(QString());
        comboBox_DisplayedTable->addItem(QString());
        comboBox_DisplayedTable->setObjectName("comboBox_DisplayedTable");

        horizontalLayout->addWidget(comboBox_DisplayedTable);

        horizontalSpacer = new QSpacerItem(780, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(HistoryPageClass);

        QMetaObject::connectSlotsByName(HistoryPageClass);
    } // setupUi

    void retranslateUi(QWidget *HistoryPageClass)
    {
        HistoryPageClass->setWindowTitle(QCoreApplication::translate("HistoryPageClass", "History", nullptr));
        AddButton->setText(QCoreApplication::translate("HistoryPageClass", "Add", nullptr));
        EditButton->setText(QCoreApplication::translate("HistoryPageClass", "Edit", nullptr));
        DeleteButton->setText(QCoreApplication::translate("HistoryPageClass", "Delete", nullptr));
        comboBox_DisplayedTable->setItemText(0, QCoreApplication::translate("HistoryPageClass", "Tournament", nullptr));
        comboBox_DisplayedTable->setItemText(1, QCoreApplication::translate("HistoryPageClass", "Match", nullptr));

    } // retranslateUi

};

namespace Ui {
    class HistoryPageClass: public Ui_HistoryPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYPAGE_H
