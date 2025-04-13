/********************************************************************************
** Form generated from reading UI file 'ProfileWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEWIDGET_H
#define UI_PROFILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileWidgetClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *ProfileButton;
    QVBoxLayout *verticalLayout;
    QPushButton *DeleteButton;
    QPushButton *EditButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ProfileWidgetClass)
    {
        if (ProfileWidgetClass->objectName().isEmpty())
            ProfileWidgetClass->setObjectName("ProfileWidgetClass");
        ProfileWidgetClass->resize(308, 88);
        gridLayout = new QGridLayout(ProfileWidgetClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        ProfileButton = new QPushButton(ProfileWidgetClass);
        ProfileButton->setObjectName("ProfileButton");

        horizontalLayout->addWidget(ProfileButton);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        DeleteButton = new QPushButton(ProfileWidgetClass);
        DeleteButton->setObjectName("DeleteButton");

        verticalLayout->addWidget(DeleteButton);

        EditButton = new QPushButton(ProfileWidgetClass);
        EditButton->setObjectName("EditButton");

        verticalLayout->addWidget(EditButton);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(ProfileWidgetClass);

        QMetaObject::connectSlotsByName(ProfileWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ProfileWidgetClass)
    {
        ProfileWidgetClass->setWindowTitle(QCoreApplication::translate("ProfileWidgetClass", "ProfileWidget", nullptr));
        ProfileButton->setText(QString());
        DeleteButton->setText(QString());
        EditButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProfileWidgetClass: public Ui_ProfileWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEWIDGET_H
