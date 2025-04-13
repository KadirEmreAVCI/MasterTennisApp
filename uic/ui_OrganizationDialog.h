/********************************************************************************
** Form generated from reading UI file 'OrganizationDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORGANIZATIONDIALOG_H
#define UI_ORGANIZATIONDIALOG_H

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

class Ui_OrganizationDialogClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *NewOrganizationButton;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *OrganizationDialogClass)
    {
        if (OrganizationDialogClass->objectName().isEmpty())
            OrganizationDialogClass->setObjectName("OrganizationDialogClass");
        OrganizationDialogClass->setEnabled(true);
        OrganizationDialogClass->resize(511, 401);
        gridLayout = new QGridLayout(OrganizationDialogClass);
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

        NewOrganizationButton = new QPushButton(OrganizationDialogClass);
        NewOrganizationButton->setObjectName("NewOrganizationButton");

        horizontalLayout_2->addWidget(NewOrganizationButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        tableWidget = new QTableWidget(OrganizationDialogClass);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEnabled(true);
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        horizontalLayout->addWidget(tableWidget);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(OrganizationDialogClass);

        QMetaObject::connectSlotsByName(OrganizationDialogClass);
    } // setupUi

    void retranslateUi(QDialog *OrganizationDialogClass)
    {
        OrganizationDialogClass->setWindowTitle(QCoreApplication::translate("OrganizationDialogClass", "OrganizationDialog", nullptr));
        NewOrganizationButton->setText(QCoreApplication::translate("OrganizationDialogClass", " New Organization ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrganizationDialogClass: public Ui_OrganizationDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORGANIZATIONDIALOG_H
