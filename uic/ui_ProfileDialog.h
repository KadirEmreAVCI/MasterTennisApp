/********************************************************************************
** Form generated from reading UI file 'ProfileDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEDIALOG_H
#define UI_PROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ProfileDialogClass
{
public:

    void setupUi(QDialog *ProfileDialogClass)
    {
        if (ProfileDialogClass->objectName().isEmpty())
            ProfileDialogClass->setObjectName("ProfileDialogClass");
        ProfileDialogClass->resize(1198, 835);

        retranslateUi(ProfileDialogClass);

        QMetaObject::connectSlotsByName(ProfileDialogClass);
    } // setupUi

    void retranslateUi(QDialog *ProfileDialogClass)
    {
        ProfileDialogClass->setWindowTitle(QCoreApplication::translate("ProfileDialogClass", "ProfileDialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileDialogClass: public Ui_ProfileDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEDIALOG_H
