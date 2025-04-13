/********************************************************************************
** Form generated from reading UI file 'UpcomingMatch.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPCOMINGMATCH_H
#define UI_UPCOMINGMATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpcomingMatchClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *UpcomingMatchButton;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_OrgImage;
    QSpacerItem *verticalSpacer;
    QLabel *label_Countdown;

    void setupUi(QWidget *UpcomingMatchClass)
    {
        if (UpcomingMatchClass->objectName().isEmpty())
            UpcomingMatchClass->setObjectName("UpcomingMatchClass");
        UpcomingMatchClass->resize(437, 122);
        gridLayout = new QGridLayout(UpcomingMatchClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        UpcomingMatchButton = new QPushButton(UpcomingMatchClass);
        UpcomingMatchButton->setObjectName("UpcomingMatchButton");

        horizontalLayout_4->addWidget(UpcomingMatchButton);

        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_OrgImage = new QLabel(UpcomingMatchClass);
        label_OrgImage->setObjectName("label_OrgImage");

        horizontalLayout_3->addWidget(label_OrgImage);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_Countdown = new QLabel(UpcomingMatchClass);
        label_Countdown->setObjectName("label_Countdown");
        QFont font;
        font.setPointSize(15);
        label_Countdown->setFont(font);
        label_Countdown->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_Countdown);


        horizontalLayout_4->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        retranslateUi(UpcomingMatchClass);

        QMetaObject::connectSlotsByName(UpcomingMatchClass);
    } // setupUi

    void retranslateUi(QWidget *UpcomingMatchClass)
    {
        UpcomingMatchClass->setWindowTitle(QCoreApplication::translate("UpcomingMatchClass", "UpcomingMatch", nullptr));
        UpcomingMatchButton->setText(QString());
        label_OrgImage->setText(QCoreApplication::translate("UpcomingMatchClass", "Icon", nullptr));
        label_Countdown->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UpcomingMatchClass: public Ui_UpcomingMatchClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPCOMINGMATCH_H
