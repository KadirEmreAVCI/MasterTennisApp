/********************************************************************************
** Form generated from reading UI file 'ProfileSelectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILESELECTIONDIALOG_H
#define UI_PROFILESELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProfileSelectionDialogClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *NewProfileButton;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;

    void setupUi(QDialog *ProfileSelectionDialogClass)
    {
        if (ProfileSelectionDialogClass->objectName().isEmpty())
            ProfileSelectionDialogClass->setObjectName("ProfileSelectionDialogClass");
        ProfileSelectionDialogClass->resize(462, 282);
        gridLayout = new QGridLayout(ProfileSelectionDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        NewProfileButton = new QPushButton(ProfileSelectionDialogClass);
        NewProfileButton->setObjectName("NewProfileButton");

        horizontalLayout->addWidget(NewProfileButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        listWidget = new QListWidget(ProfileSelectionDialogClass);
        listWidget->setObjectName("listWidget");

        horizontalLayout_2->addWidget(listWidget);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ProfileSelectionDialogClass);

        QMetaObject::connectSlotsByName(ProfileSelectionDialogClass);
    } // setupUi

    void retranslateUi(QDialog *ProfileSelectionDialogClass)
    {
        ProfileSelectionDialogClass->setWindowTitle(QCoreApplication::translate("ProfileSelectionDialogClass", "ProfileSelectionDialog", nullptr));
        NewProfileButton->setText(QCoreApplication::translate("ProfileSelectionDialogClass", "New Profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileSelectionDialogClass: public Ui_ProfileSelectionDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILESELECTIONDIALOG_H
