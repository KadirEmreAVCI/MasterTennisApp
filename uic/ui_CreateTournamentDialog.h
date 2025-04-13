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
#include <QtWidgets/QCheckBox>
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
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_OrganizationName;
    QLineEdit *lineEdit_OrganizationName;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_Master;
    QCheckBox *checkBox_Aplus;
    QCheckBox *checkBox_A;
    QCheckBox *checkBox_B;
    QCheckBox *checkBox_C;
    QCheckBox *checkBox_D;
    QCheckBox *checkBox_IlkTurnuvam;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *ApplyButton;
    QPushButton *ClearButton;
    QLineEdit *lineEdit_Categories;
    QVBoxLayout *verticalLayout_4;
    QPushButton *SaveButton;
    QPushButton *CancelButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *CreateTournamentDialogClass)
    {
        if (CreateTournamentDialogClass->objectName().isEmpty())
            CreateTournamentDialogClass->setObjectName("CreateTournamentDialogClass");
        CreateTournamentDialogClass->resize(481, 194);
        gridLayout = new QGridLayout(CreateTournamentDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        label_OrganizationName = new QLabel(CreateTournamentDialogClass);
        label_OrganizationName->setObjectName("label_OrganizationName");

        verticalLayout->addWidget(label_OrganizationName);

        lineEdit_OrganizationName = new QLineEdit(CreateTournamentDialogClass);
        lineEdit_OrganizationName->setObjectName("lineEdit_OrganizationName");

        verticalLayout->addWidget(lineEdit_OrganizationName);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(CreateTournamentDialogClass);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox_Master = new QCheckBox(CreateTournamentDialogClass);
        checkBox_Master->setObjectName("checkBox_Master");

        horizontalLayout->addWidget(checkBox_Master);

        checkBox_Aplus = new QCheckBox(CreateTournamentDialogClass);
        checkBox_Aplus->setObjectName("checkBox_Aplus");

        horizontalLayout->addWidget(checkBox_Aplus);

        checkBox_A = new QCheckBox(CreateTournamentDialogClass);
        checkBox_A->setObjectName("checkBox_A");

        horizontalLayout->addWidget(checkBox_A);

        checkBox_B = new QCheckBox(CreateTournamentDialogClass);
        checkBox_B->setObjectName("checkBox_B");

        horizontalLayout->addWidget(checkBox_B);

        checkBox_C = new QCheckBox(CreateTournamentDialogClass);
        checkBox_C->setObjectName("checkBox_C");

        horizontalLayout->addWidget(checkBox_C);

        checkBox_D = new QCheckBox(CreateTournamentDialogClass);
        checkBox_D->setObjectName("checkBox_D");

        horizontalLayout->addWidget(checkBox_D);

        checkBox_IlkTurnuvam = new QCheckBox(CreateTournamentDialogClass);
        checkBox_IlkTurnuvam->setObjectName("checkBox_IlkTurnuvam");

        horizontalLayout->addWidget(checkBox_IlkTurnuvam);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ApplyButton = new QPushButton(CreateTournamentDialogClass);
        ApplyButton->setObjectName("ApplyButton");

        horizontalLayout_2->addWidget(ApplyButton);

        ClearButton = new QPushButton(CreateTournamentDialogClass);
        ClearButton->setObjectName("ClearButton");

        horizontalLayout_2->addWidget(ClearButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        lineEdit_Categories = new QLineEdit(CreateTournamentDialogClass);
        lineEdit_Categories->setObjectName("lineEdit_Categories");
        lineEdit_Categories->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit_Categories);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        SaveButton = new QPushButton(CreateTournamentDialogClass);
        SaveButton->setObjectName("SaveButton");

        verticalLayout_4->addWidget(SaveButton);

        CancelButton = new QPushButton(CreateTournamentDialogClass);
        CancelButton->setObjectName("CancelButton");

        verticalLayout_4->addWidget(CancelButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        retranslateUi(CreateTournamentDialogClass);

        QMetaObject::connectSlotsByName(CreateTournamentDialogClass);
    } // setupUi

    void retranslateUi(QDialog *CreateTournamentDialogClass)
    {
        CreateTournamentDialogClass->setWindowTitle(QCoreApplication::translate("CreateTournamentDialogClass", "CreateTournamentDialog", nullptr));
        label_OrganizationName->setText(QCoreApplication::translate("CreateTournamentDialogClass", "1- Enter organization name:", nullptr));
        label->setText(QCoreApplication::translate("CreateTournamentDialogClass", "2- Select the categories you would like to add:", nullptr));
        checkBox_Master->setText(QCoreApplication::translate("CreateTournamentDialogClass", "Master", nullptr));
        checkBox_Aplus->setText(QCoreApplication::translate("CreateTournamentDialogClass", "A+", nullptr));
        checkBox_A->setText(QCoreApplication::translate("CreateTournamentDialogClass", "A", nullptr));
        checkBox_B->setText(QCoreApplication::translate("CreateTournamentDialogClass", "B", nullptr));
        checkBox_C->setText(QCoreApplication::translate("CreateTournamentDialogClass", "C", nullptr));
        checkBox_D->setText(QCoreApplication::translate("CreateTournamentDialogClass", "D", nullptr));
        checkBox_IlkTurnuvam->setText(QCoreApplication::translate("CreateTournamentDialogClass", "Ilk Turnuvam", nullptr));
        ApplyButton->setText(QCoreApplication::translate("CreateTournamentDialogClass", "Apply", nullptr));
        ClearButton->setText(QCoreApplication::translate("CreateTournamentDialogClass", "Clear", nullptr));
        SaveButton->setText(QCoreApplication::translate("CreateTournamentDialogClass", "Save", nullptr));
        CancelButton->setText(QCoreApplication::translate("CreateTournamentDialogClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateTournamentDialogClass: public Ui_CreateTournamentDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETOURNAMENTDIALOG_H
