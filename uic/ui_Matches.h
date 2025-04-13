/********************************************************************************
** Form generated from reading UI file 'Matches.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCHES_H
#define UI_MATCHES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *vboxLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *spacerItem;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(736, 381);
        widget = new QWidget(Dialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-5, 0, 741, 381));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(widget);
        tableWidget->setObjectName("tableWidget");

        horizontalLayout->addWidget(tableWidget);

        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName("vboxLayout");
        okButton = new QPushButton(widget);
        okButton->setObjectName("okButton");

        vboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName("cancelButton");

        vboxLayout->addWidget(cancelButton);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout->addItem(spacerItem);


        horizontalLayout->addLayout(vboxLayout);


        retranslateUi(Dialog);
        QObject::connect(okButton, &QPushButton::clicked, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelButton, &QPushButton::clicked, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        okButton->setText(QCoreApplication::translate("Dialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("Dialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHES_H
