/********************************************************************************
** Form generated from reading UI file 'AddEditProfileDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITPROFILEDIALOG_H
#define UI_ADDEDITPROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddEditProfileDialogClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_NameSurname;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Male;
    QRadioButton *radioButton_Female;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_PPAddr;
    QPushButton *DefaultPPButton;
    QPushButton *BrowseButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *CancelButton;
    QPushButton *SaveButton;

    void setupUi(QDialog *AddEditProfileDialogClass)
    {
        if (AddEditProfileDialogClass->objectName().isEmpty())
            AddEditProfileDialogClass->setObjectName("AddEditProfileDialogClass");
        AddEditProfileDialogClass->resize(451, 261);
        gridLayout = new QGridLayout(AddEditProfileDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(AddEditProfileDialogClass);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit_NameSurname = new QLineEdit(AddEditProfileDialogClass);
        lineEdit_NameSurname->setObjectName("lineEdit_NameSurname");

        verticalLayout->addWidget(lineEdit_NameSurname);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(AddEditProfileDialogClass);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        radioButton_Male = new QRadioButton(AddEditProfileDialogClass);
        radioButton_Male->setObjectName("radioButton_Male");

        horizontalLayout->addWidget(radioButton_Male);

        radioButton_Female = new QRadioButton(AddEditProfileDialogClass);
        radioButton_Female->setObjectName("radioButton_Female");

        horizontalLayout->addWidget(radioButton_Female);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(AddEditProfileDialogClass);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_PPAddr = new QLineEdit(AddEditProfileDialogClass);
        lineEdit_PPAddr->setObjectName("lineEdit_PPAddr");
        lineEdit_PPAddr->setEnabled(false);

        horizontalLayout_2->addWidget(lineEdit_PPAddr);

        DefaultPPButton = new QPushButton(AddEditProfileDialogClass);
        DefaultPPButton->setObjectName("DefaultPPButton");

        horizontalLayout_2->addWidget(DefaultPPButton);

        BrowseButton = new QPushButton(AddEditProfileDialogClass);
        BrowseButton->setObjectName("BrowseButton");

        horizontalLayout_2->addWidget(BrowseButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        CancelButton = new QPushButton(AddEditProfileDialogClass);
        CancelButton->setObjectName("CancelButton");

        horizontalLayout_3->addWidget(CancelButton);

        SaveButton = new QPushButton(AddEditProfileDialogClass);
        SaveButton->setObjectName("SaveButton");

        horizontalLayout_3->addWidget(SaveButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(AddEditProfileDialogClass);

        QMetaObject::connectSlotsByName(AddEditProfileDialogClass);
    } // setupUi

    void retranslateUi(QDialog *AddEditProfileDialogClass)
    {
        AddEditProfileDialogClass->setWindowTitle(QCoreApplication::translate("AddEditProfileDialogClass", "AddEditProfileDialog", nullptr));
        label->setText(QCoreApplication::translate("AddEditProfileDialogClass", "1- Enter your name and surname", nullptr));
        label_2->setText(QCoreApplication::translate("AddEditProfileDialogClass", "2- Select your gender", nullptr));
        radioButton_Male->setText(QCoreApplication::translate("AddEditProfileDialogClass", "Male", nullptr));
        radioButton_Female->setText(QCoreApplication::translate("AddEditProfileDialogClass", "Female", nullptr));
        label_3->setText(QCoreApplication::translate("AddEditProfileDialogClass", "3- Upload your profile picture (Optional)", nullptr));
        DefaultPPButton->setText(QString());
        BrowseButton->setText(QCoreApplication::translate("AddEditProfileDialogClass", "Browse", nullptr));
        CancelButton->setText(QCoreApplication::translate("AddEditProfileDialogClass", "Cancel", nullptr));
        SaveButton->setText(QCoreApplication::translate("AddEditProfileDialogClass", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEditProfileDialogClass: public Ui_AddEditProfileDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITPROFILEDIALOG_H
