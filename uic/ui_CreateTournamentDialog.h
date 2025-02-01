/********************************************************************************
** Form generated from reading UI file 'CreateTournamentDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETOURNAMENTDIALOG_H
#define UI_CREATETOURNAMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateTournamentDialogClass
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *SaveButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_OrganizationName;
    QLineEdit *lineEdit_OrganizationName;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Categories;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_Categories;
    QPushButton *CancelButton;

    void setupUi(QDialog *CreateTournamentDialogClass)
    {
        if (CreateTournamentDialogClass->objectName().isEmpty())
            CreateTournamentDialogClass->setObjectName("CreateTournamentDialogClass");
        CreateTournamentDialogClass->resize(498, 133);
        gridLayout_2 = new QGridLayout(CreateTournamentDialogClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        SaveButton = new QPushButton(CreateTournamentDialogClass);
        SaveButton->setObjectName("SaveButton");

        gridLayout->addWidget(SaveButton, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        label_OrganizationName = new QLabel(CreateTournamentDialogClass);
        label_OrganizationName->setObjectName("label_OrganizationName");

        verticalLayout->addWidget(label_OrganizationName);

        lineEdit_OrganizationName = new QLineEdit(CreateTournamentDialogClass);
        lineEdit_OrganizationName->setObjectName("lineEdit_OrganizationName");

        verticalLayout->addWidget(lineEdit_OrganizationName);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 2, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_Categories = new QLabel(CreateTournamentDialogClass);
        label_Categories->setObjectName("label_Categories");

        verticalLayout_2->addWidget(label_Categories);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_Categories = new QLineEdit(CreateTournamentDialogClass);
        lineEdit_Categories->setObjectName("lineEdit_Categories");

        horizontalLayout_2->addWidget(lineEdit_Categories);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 4, 0, 1, 1);

        CancelButton = new QPushButton(CreateTournamentDialogClass);
        CancelButton->setObjectName("CancelButton");

        gridLayout->addWidget(CancelButton, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(CreateTournamentDialogClass);

        QMetaObject::connectSlotsByName(CreateTournamentDialogClass);
    } // setupUi

    void retranslateUi(QDialog *CreateTournamentDialogClass)
    {
        CreateTournamentDialogClass->setWindowTitle(QCoreApplication::translate("CreateTournamentDialogClass", "CreateTournamentDialog", nullptr));
        SaveButton->setText(QCoreApplication::translate("CreateTournamentDialogClass", "Save", nullptr));
        label_OrganizationName->setText(QCoreApplication::translate("CreateTournamentDialogClass", "Enter organization name:", nullptr));
        label_Categories->setText(QCoreApplication::translate("CreateTournamentDialogClass", "Enter all possible categories (From hardest to easiest):", nullptr));
        CancelButton->setText(QCoreApplication::translate("CreateTournamentDialogClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateTournamentDialogClass: public Ui_CreateTournamentDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETOURNAMENTDIALOG_H
