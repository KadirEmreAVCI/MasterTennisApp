/********************************************************************************
** Form generated from reading UI file 'OnboardingDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONBOARDINGDIALOG_H
#define UI_ONBOARDINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_OnboardingDialogClass
{
public:

    void setupUi(QDialog *OnboardingDialogClass)
    {
        if (OnboardingDialogClass->objectName().isEmpty())
            OnboardingDialogClass->setObjectName("OnboardingDialogClass");
        OnboardingDialogClass->resize(600, 400);

        retranslateUi(OnboardingDialogClass);

        QMetaObject::connectSlotsByName(OnboardingDialogClass);
    } // setupUi

    void retranslateUi(QDialog *OnboardingDialogClass)
    {
        OnboardingDialogClass->setWindowTitle(QCoreApplication::translate("OnboardingDialogClass", "OnboardingDialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OnboardingDialogClass: public Ui_OnboardingDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONBOARDINGDIALOG_H
