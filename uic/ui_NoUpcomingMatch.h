/********************************************************************************
** Form generated from reading UI file 'NoUpcomingMatch.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOUPCOMINGMATCH_H
#define UI_NOUPCOMINGMATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoUpcomingMatchClass
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;

    void setupUi(QWidget *NoUpcomingMatchClass)
    {
        if (NoUpcomingMatchClass->objectName().isEmpty())
            NoUpcomingMatchClass->setObjectName("NoUpcomingMatchClass");
        NoUpcomingMatchClass->resize(571, 124);
        gridLayout_2 = new QGridLayout(NoUpcomingMatchClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        label = new QLabel(NoUpcomingMatchClass);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(13);
        label->setFont(font);

        gridLayout->addWidget(label, 1, 1, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(NoUpcomingMatchClass);

        QMetaObject::connectSlotsByName(NoUpcomingMatchClass);
    } // setupUi

    void retranslateUi(QWidget *NoUpcomingMatchClass)
    {
        NoUpcomingMatchClass->setWindowTitle(QCoreApplication::translate("NoUpcomingMatchClass", "NoUpcomingMatch", nullptr));
        label->setText(QCoreApplication::translate("NoUpcomingMatchClass", "No Upcoming Match", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoUpcomingMatchClass: public Ui_NoUpcomingMatchClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOUPCOMINGMATCH_H
