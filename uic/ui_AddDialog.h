/********************************************************************************
** Form generated from reading UI file 'AddDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddDialogClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_Organization;
    QRadioButton *radioButton_Tournament;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *OKButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *AddDialogClass)
    {
        if (AddDialogClass->objectName().isEmpty())
            AddDialogClass->setObjectName("AddDialogClass");
        AddDialogClass->resize(245, 126);
        gridLayout = new QGridLayout(AddDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(AddDialogClass);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        radioButton_Organization = new QRadioButton(AddDialogClass);
        radioButton_Organization->setObjectName("radioButton_Organization");

        verticalLayout->addWidget(radioButton_Organization);

        radioButton_Tournament = new QRadioButton(AddDialogClass);
        radioButton_Tournament->setObjectName("radioButton_Tournament");

        verticalLayout->addWidget(radioButton_Tournament);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OKButton = new QPushButton(AddDialogClass);
        OKButton->setObjectName("OKButton");

        horizontalLayout->addWidget(OKButton);

        CancelButton = new QPushButton(AddDialogClass);
        CancelButton->setObjectName("CancelButton");

        horizontalLayout->addWidget(CancelButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(AddDialogClass);

        QMetaObject::connectSlotsByName(AddDialogClass);
    } // setupUi

    void retranslateUi(QDialog *AddDialogClass)
    {
        AddDialogClass->setWindowTitle(QCoreApplication::translate("AddDialogClass", "AddDialog", nullptr));
        label->setText(QCoreApplication::translate("AddDialogClass", "What would you like to add?", nullptr));
        radioButton_Organization->setText(QCoreApplication::translate("AddDialogClass", "Organization", nullptr));
        radioButton_Tournament->setText(QCoreApplication::translate("AddDialogClass", "Tournament", nullptr));
        OKButton->setText(QCoreApplication::translate("AddDialogClass", "OK", nullptr));
        CancelButton->setText(QCoreApplication::translate("AddDialogClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDialogClass: public Ui_AddDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
