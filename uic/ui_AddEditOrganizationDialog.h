/********************************************************************************
** Form generated from reading UI file 'AddEditOrganizationDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITORGANIZATIONDIALOG_H
#define UI_ADDEDITORGANIZATIONDIALOG_H

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

class Ui_AddEditOrganizationDialogClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_OrganizationName;
    QLineEdit *lineEdit_OrganizationName;
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
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_ImagePath;
    QPushButton *DefaultPPButton;
    QPushButton *BrowseButton;
    QVBoxLayout *verticalLayout_4;
    QPushButton *SaveButton;
    QPushButton *CancelButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *AddEditOrganizationDialogClass)
    {
        if (AddEditOrganizationDialogClass->objectName().isEmpty())
            AddEditOrganizationDialogClass->setObjectName("AddEditOrganizationDialogClass");
        AddEditOrganizationDialogClass->resize(481, 234);
        gridLayout = new QGridLayout(AddEditOrganizationDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        label_OrganizationName = new QLabel(AddEditOrganizationDialogClass);
        label_OrganizationName->setObjectName("label_OrganizationName");

        verticalLayout->addWidget(label_OrganizationName);

        lineEdit_OrganizationName = new QLineEdit(AddEditOrganizationDialogClass);
        lineEdit_OrganizationName->setObjectName("lineEdit_OrganizationName");

        verticalLayout->addWidget(lineEdit_OrganizationName);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(AddEditOrganizationDialogClass);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox_Master = new QCheckBox(AddEditOrganizationDialogClass);
        checkBox_Master->setObjectName("checkBox_Master");

        horizontalLayout->addWidget(checkBox_Master);

        checkBox_Aplus = new QCheckBox(AddEditOrganizationDialogClass);
        checkBox_Aplus->setObjectName("checkBox_Aplus");

        horizontalLayout->addWidget(checkBox_Aplus);

        checkBox_A = new QCheckBox(AddEditOrganizationDialogClass);
        checkBox_A->setObjectName("checkBox_A");

        horizontalLayout->addWidget(checkBox_A);

        checkBox_B = new QCheckBox(AddEditOrganizationDialogClass);
        checkBox_B->setObjectName("checkBox_B");

        horizontalLayout->addWidget(checkBox_B);

        checkBox_C = new QCheckBox(AddEditOrganizationDialogClass);
        checkBox_C->setObjectName("checkBox_C");

        horizontalLayout->addWidget(checkBox_C);

        checkBox_D = new QCheckBox(AddEditOrganizationDialogClass);
        checkBox_D->setObjectName("checkBox_D");

        horizontalLayout->addWidget(checkBox_D);

        checkBox_IlkTurnuvam = new QCheckBox(AddEditOrganizationDialogClass);
        checkBox_IlkTurnuvam->setObjectName("checkBox_IlkTurnuvam");

        horizontalLayout->addWidget(checkBox_IlkTurnuvam);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ApplyButton = new QPushButton(AddEditOrganizationDialogClass);
        ApplyButton->setObjectName("ApplyButton");

        horizontalLayout_2->addWidget(ApplyButton);

        ClearButton = new QPushButton(AddEditOrganizationDialogClass);
        ClearButton->setObjectName("ClearButton");

        horizontalLayout_2->addWidget(ClearButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        lineEdit_Categories = new QLineEdit(AddEditOrganizationDialogClass);
        lineEdit_Categories->setObjectName("lineEdit_Categories");
        lineEdit_Categories->setEnabled(false);

        verticalLayout_2->addWidget(lineEdit_Categories);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(AddEditOrganizationDialogClass);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lineEdit_ImagePath = new QLineEdit(AddEditOrganizationDialogClass);
        lineEdit_ImagePath->setObjectName("lineEdit_ImagePath");
        lineEdit_ImagePath->setEnabled(false);

        horizontalLayout_3->addWidget(lineEdit_ImagePath);

        DefaultPPButton = new QPushButton(AddEditOrganizationDialogClass);
        DefaultPPButton->setObjectName("DefaultPPButton");

        horizontalLayout_3->addWidget(DefaultPPButton);

        BrowseButton = new QPushButton(AddEditOrganizationDialogClass);
        BrowseButton->setObjectName("BrowseButton");

        horizontalLayout_3->addWidget(BrowseButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        SaveButton = new QPushButton(AddEditOrganizationDialogClass);
        SaveButton->setObjectName("SaveButton");

        verticalLayout_4->addWidget(SaveButton);

        CancelButton = new QPushButton(AddEditOrganizationDialogClass);
        CancelButton->setObjectName("CancelButton");

        verticalLayout_4->addWidget(CancelButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        retranslateUi(AddEditOrganizationDialogClass);

        QMetaObject::connectSlotsByName(AddEditOrganizationDialogClass);
    } // setupUi

    void retranslateUi(QDialog *AddEditOrganizationDialogClass)
    {
        AddEditOrganizationDialogClass->setWindowTitle(QCoreApplication::translate("AddEditOrganizationDialogClass", "AddEditOrganizationDialog", nullptr));
        label_OrganizationName->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "1- Enter organization name:", nullptr));
        label->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "2- Select the categories you would like to add:", nullptr));
        checkBox_Master->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "Master", nullptr));
        checkBox_Aplus->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "A+", nullptr));
        checkBox_A->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "A", nullptr));
        checkBox_B->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "B", nullptr));
        checkBox_C->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "C", nullptr));
        checkBox_D->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "D", nullptr));
        checkBox_IlkTurnuvam->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "Ilk Turnuvam", nullptr));
        ApplyButton->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "Apply", nullptr));
        ClearButton->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "Clear", nullptr));
        label_2->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "3- Select organization logo:", nullptr));
        DefaultPPButton->setText(QString());
        BrowseButton->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "Browse", nullptr));
        SaveButton->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "Save", nullptr));
        CancelButton->setText(QCoreApplication::translate("AddEditOrganizationDialogClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEditOrganizationDialogClass: public Ui_AddEditOrganizationDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITORGANIZATIONDIALOG_H
