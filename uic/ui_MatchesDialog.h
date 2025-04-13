/********************************************************************************
** Form generated from reading UI file 'MatchesDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCHESDIALOG_H
#define UI_MATCHESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MatchesDialogClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *NewMatchButton;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *MatchesDialogClass)
    {
        if (MatchesDialogClass->objectName().isEmpty())
            MatchesDialogClass->setObjectName("MatchesDialogClass");
        MatchesDialogClass->resize(1036, 681);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MatchesDialogClass->sizePolicy().hasHeightForWidth());
        MatchesDialogClass->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(MatchesDialogClass);
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

        NewMatchButton = new QPushButton(MatchesDialogClass);
        NewMatchButton->setObjectName("NewMatchButton");

        horizontalLayout_2->addWidget(NewMatchButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        tableWidget = new QTableWidget(MatchesDialogClass);
        tableWidget->setObjectName("tableWidget");
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        tableWidget->setFont(font);
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setAlternatingRowColors(false);

        horizontalLayout->addWidget(tableWidget);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(MatchesDialogClass);

        QMetaObject::connectSlotsByName(MatchesDialogClass);
    } // setupUi

    void retranslateUi(QDialog *MatchesDialogClass)
    {
        MatchesDialogClass->setWindowTitle(QCoreApplication::translate("MatchesDialogClass", "MatchesDialog", nullptr));
        NewMatchButton->setText(QCoreApplication::translate("MatchesDialogClass", " New Match ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MatchesDialogClass: public Ui_MatchesDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHESDIALOG_H
