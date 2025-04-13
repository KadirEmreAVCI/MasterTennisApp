/********************************************************************************
** Form generated from reading UI file 'AddCategoryDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCATEGORYDIALOG_H
#define UI_ADDCATEGORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddCategoryDialogClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_Master;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_Aplus;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_A;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_B;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_C;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_D;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox_IlkTurnuvam;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ApplyButton;
    QPushButton *ClearButton;
    QPushButton *CancelButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *AddCategoryDialogClass)
    {
        if (AddCategoryDialogClass->objectName().isEmpty())
            AddCategoryDialogClass->setObjectName("AddCategoryDialogClass");
        AddCategoryDialogClass->resize(372, 234);
        gridLayout = new QGridLayout(AddCategoryDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(AddCategoryDialogClass);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox_Master = new QCheckBox(AddCategoryDialogClass);
        checkBox_Master->setObjectName("checkBox_Master");

        horizontalLayout->addWidget(checkBox_Master);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        checkBox_Aplus = new QCheckBox(AddCategoryDialogClass);
        checkBox_Aplus->setObjectName("checkBox_Aplus");

        horizontalLayout_2->addWidget(checkBox_Aplus);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        checkBox_A = new QCheckBox(AddCategoryDialogClass);
        checkBox_A->setObjectName("checkBox_A");

        horizontalLayout_3->addWidget(checkBox_A);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        checkBox_B = new QCheckBox(AddCategoryDialogClass);
        checkBox_B->setObjectName("checkBox_B");

        horizontalLayout_4->addWidget(checkBox_B);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        checkBox_C = new QCheckBox(AddCategoryDialogClass);
        checkBox_C->setObjectName("checkBox_C");

        horizontalLayout_5->addWidget(checkBox_C);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        checkBox_D = new QCheckBox(AddCategoryDialogClass);
        checkBox_D->setObjectName("checkBox_D");

        horizontalLayout_6->addWidget(checkBox_D);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        checkBox_IlkTurnuvam = new QCheckBox(AddCategoryDialogClass);
        checkBox_IlkTurnuvam->setObjectName("checkBox_IlkTurnuvam");

        horizontalLayout_7->addWidget(checkBox_IlkTurnuvam);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_7);


        horizontalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        ApplyButton = new QPushButton(AddCategoryDialogClass);
        ApplyButton->setObjectName("ApplyButton");

        verticalLayout_2->addWidget(ApplyButton);

        ClearButton = new QPushButton(AddCategoryDialogClass);
        ClearButton->setObjectName("ClearButton");

        verticalLayout_2->addWidget(ClearButton);

        CancelButton = new QPushButton(AddCategoryDialogClass);
        CancelButton->setObjectName("CancelButton");

        verticalLayout_2->addWidget(CancelButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_8->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_8, 0, 0, 1, 1);


        retranslateUi(AddCategoryDialogClass);

        QMetaObject::connectSlotsByName(AddCategoryDialogClass);
    } // setupUi

    void retranslateUi(QDialog *AddCategoryDialogClass)
    {
        AddCategoryDialogClass->setWindowTitle(QCoreApplication::translate("AddCategoryDialogClass", "AddCategoryDialog", nullptr));
        label->setText(QCoreApplication::translate("AddCategoryDialogClass", "Select categories you would like to add:", nullptr));
        checkBox_Master->setText(QCoreApplication::translate("AddCategoryDialogClass", "Master", nullptr));
        checkBox_Aplus->setText(QCoreApplication::translate("AddCategoryDialogClass", "A+", nullptr));
        checkBox_A->setText(QCoreApplication::translate("AddCategoryDialogClass", "A", nullptr));
        checkBox_B->setText(QCoreApplication::translate("AddCategoryDialogClass", "B", nullptr));
        checkBox_C->setText(QCoreApplication::translate("AddCategoryDialogClass", "C", nullptr));
        checkBox_D->setText(QCoreApplication::translate("AddCategoryDialogClass", "D", nullptr));
        checkBox_IlkTurnuvam->setText(QCoreApplication::translate("AddCategoryDialogClass", "Ilk Turnuvam", nullptr));
        ApplyButton->setText(QCoreApplication::translate("AddCategoryDialogClass", "Apply", nullptr));
        ClearButton->setText(QCoreApplication::translate("AddCategoryDialogClass", "Clear", nullptr));
        CancelButton->setText(QCoreApplication::translate("AddCategoryDialogClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCategoryDialogClass: public Ui_AddCategoryDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCATEGORYDIALOG_H
