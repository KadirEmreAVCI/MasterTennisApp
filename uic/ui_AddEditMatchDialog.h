/********************************************************************************
** Form generated from reading UI file 'AddEditMatchDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITMATCHDIALOG_H
#define UI_ADDEDITMATCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddEditMatchDialogClass
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Statu;
    QLabel *label_Stage;
    QLabel *label_Opponent1;
    QLabel *label_Opponent2;
    QLabel *label_Date;
    QLabel *label_Time;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_Statu;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Win;
    QRadioButton *radioButton_Lose;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_Stage;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit__Opponent1;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit__Opponent2;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_Date;
    QPushButton *DateButton;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_9;
    QTimeEdit *timeEdit;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddSetButton;
    QPushButton *RemoveSetButton;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *SaveButton;
    QPushButton *ClearButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *AddEditMatchDialogClass)
    {
        if (AddEditMatchDialogClass->objectName().isEmpty())
            AddEditMatchDialogClass->setObjectName("AddEditMatchDialogClass");
        AddEditMatchDialogClass->resize(649, 558);
        gridLayout_3 = new QGridLayout(AddEditMatchDialogClass);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_Statu = new QLabel(AddEditMatchDialogClass);
        label_Statu->setObjectName("label_Statu");
        label_Statu->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(label_Statu);

        label_Stage = new QLabel(AddEditMatchDialogClass);
        label_Stage->setObjectName("label_Stage");
        label_Stage->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(label_Stage);

        label_Opponent1 = new QLabel(AddEditMatchDialogClass);
        label_Opponent1->setObjectName("label_Opponent1");
        label_Opponent1->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(label_Opponent1);

        label_Opponent2 = new QLabel(AddEditMatchDialogClass);
        label_Opponent2->setObjectName("label_Opponent2");
        label_Opponent2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(label_Opponent2);

        label_Date = new QLabel(AddEditMatchDialogClass);
        label_Date->setObjectName("label_Date");
        label_Date->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(label_Date);

        label_Time = new QLabel(AddEditMatchDialogClass);
        label_Time->setObjectName("label_Time");
        label_Time->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(label_Time);


        horizontalLayout_10->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        comboBox_Statu = new QComboBox(AddEditMatchDialogClass);
        comboBox_Statu->setObjectName("comboBox_Statu");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_Statu->sizePolicy().hasHeightForWidth());
        comboBox_Statu->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(comboBox_Statu);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        radioButton_Win = new QRadioButton(AddEditMatchDialogClass);
        radioButton_Win->setObjectName("radioButton_Win");

        horizontalLayout->addWidget(radioButton_Win);

        radioButton_Lose = new QRadioButton(AddEditMatchDialogClass);
        radioButton_Lose->setObjectName("radioButton_Lose");

        horizontalLayout->addWidget(radioButton_Lose);


        horizontalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        comboBox_Stage = new QComboBox(AddEditMatchDialogClass);
        comboBox_Stage->setObjectName("comboBox_Stage");
        sizePolicy.setHeightForWidth(comboBox_Stage->sizePolicy().hasHeightForWidth());
        comboBox_Stage->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(comboBox_Stage);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lineEdit__Opponent1 = new QLineEdit(AddEditMatchDialogClass);
        lineEdit__Opponent1->setObjectName("lineEdit__Opponent1");
        lineEdit__Opponent1->setEnabled(false);

        horizontalLayout_6->addWidget(lineEdit__Opponent1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        lineEdit__Opponent2 = new QLineEdit(AddEditMatchDialogClass);
        lineEdit__Opponent2->setObjectName("lineEdit__Opponent2");
        lineEdit__Opponent2->setEnabled(false);

        horizontalLayout_7->addWidget(lineEdit__Opponent2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lineEdit_Date = new QLineEdit(AddEditMatchDialogClass);
        lineEdit_Date->setObjectName("lineEdit_Date");
        lineEdit_Date->setEnabled(false);

        horizontalLayout_3->addWidget(lineEdit_Date);

        DateButton = new QPushButton(AddEditMatchDialogClass);
        DateButton->setObjectName("DateButton");

        horizontalLayout_3->addWidget(DateButton);


        horizontalLayout_8->addLayout(horizontalLayout_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        timeEdit = new QTimeEdit(AddEditMatchDialogClass);
        timeEdit->setObjectName("timeEdit");
        sizePolicy.setHeightForWidth(timeEdit->sizePolicy().hasHeightForWidth());
        timeEdit->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(timeEdit);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_9);


        horizontalLayout_10->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_10);

        groupBox_3 = new QGroupBox(AddEditMatchDialogClass);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        AddSetButton = new QPushButton(groupBox_3);
        AddSetButton->setObjectName("AddSetButton");

        gridLayout->addWidget(AddSetButton, 1, 2, 1, 1);

        RemoveSetButton = new QPushButton(groupBox_3);
        RemoveSetButton->setObjectName("RemoveSetButton");

        gridLayout->addWidget(RemoveSetButton, 1, 3, 1, 1);

        listWidget = new QListWidget(groupBox_3);
        listWidget->setObjectName("listWidget");
        listWidget->setAlternatingRowColors(true);

        gridLayout->addWidget(listWidget, 0, 0, 1, 4);


        verticalLayout_4->addWidget(groupBox_3);


        gridLayout_2->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        SaveButton = new QPushButton(AddEditMatchDialogClass);
        SaveButton->setObjectName("SaveButton");

        verticalLayout->addWidget(SaveButton);

        ClearButton = new QPushButton(AddEditMatchDialogClass);
        ClearButton->setObjectName("ClearButton");

        verticalLayout->addWidget(ClearButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(AddEditMatchDialogClass);

        QMetaObject::connectSlotsByName(AddEditMatchDialogClass);
    } // setupUi

    void retranslateUi(QDialog *AddEditMatchDialogClass)
    {
        AddEditMatchDialogClass->setWindowTitle(QCoreApplication::translate("AddEditMatchDialogClass", "AddEditMatchDialog", nullptr));
        label_Statu->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Statu:", nullptr));
        label_Stage->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Stage:", nullptr));
        label_Opponent1->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Opponent 1:", nullptr));
        label_Opponent2->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Opponent 2:", nullptr));
        label_Date->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Date:", nullptr));
        label_Time->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Time:", nullptr));
        radioButton_Win->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Win", nullptr));
        radioButton_Lose->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Lose", nullptr));
        DateButton->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("AddEditMatchDialogClass", "Set Scores", nullptr));
        AddSetButton->setText(QString());
        RemoveSetButton->setText(QString());
        SaveButton->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Save", nullptr));
        ClearButton->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEditMatchDialogClass: public Ui_AddEditMatchDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITMATCHDIALOG_H
