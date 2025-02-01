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
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_Date;
    QLineEdit *lineEdit_Date;
    QPushButton *DateButton;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_Time;
    QTimeEdit *timeEdit;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QPushButton *SaveButton;
    QPushButton *DeleteButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Opponent1;
    QLineEdit *lineEdit__Opponent1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Statu;
    QComboBox *comboBox_Statu;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Win;
    QRadioButton *radioButton_Lose;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Stage;
    QComboBox *comboBox_Stage;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Opponent2;
    QLineEdit *lineEdit__Opponent2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddSetButton;
    QPushButton *RemoveSetButton;
    QListWidget *listWidget;

    void setupUi(QDialog *AddEditMatchDialogClass)
    {
        if (AddEditMatchDialogClass->objectName().isEmpty())
            AddEditMatchDialogClass->setObjectName("AddEditMatchDialogClass");
        AddEditMatchDialogClass->resize(691, 682);
        gridLayout_2 = new QGridLayout(AddEditMatchDialogClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox = new QGroupBox(AddEditMatchDialogClass);
        groupBox->setObjectName("groupBox");
        QFont font;
        font.setWeight(QFont::Light);
        groupBox->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_Date = new QLabel(groupBox);
        label_Date->setObjectName("label_Date");

        horizontalLayout_7->addWidget(label_Date);

        lineEdit_Date = new QLineEdit(groupBox);
        lineEdit_Date->setObjectName("lineEdit_Date");
        lineEdit_Date->setEnabled(false);

        horizontalLayout_7->addWidget(lineEdit_Date);

        DateButton = new QPushButton(groupBox);
        DateButton->setObjectName("DateButton");

        horizontalLayout_7->addWidget(DateButton);

        horizontalSpacer_4 = new QSpacerItem(380, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_Time = new QLabel(groupBox);
        label_Time->setObjectName("label_Time");

        horizontalLayout_8->addWidget(label_Time);

        timeEdit = new QTimeEdit(groupBox);
        timeEdit->setObjectName("timeEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(timeEdit->sizePolicy().hasHeightForWidth());
        timeEdit->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(timeEdit);

        horizontalSpacer_5 = new QSpacerItem(410, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_8);


        gridLayout_2->addWidget(groupBox, 4, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        SaveButton = new QPushButton(AddEditMatchDialogClass);
        SaveButton->setObjectName("SaveButton");

        verticalLayout->addWidget(SaveButton);

        DeleteButton = new QPushButton(AddEditMatchDialogClass);
        DeleteButton->setObjectName("DeleteButton");

        verticalLayout->addWidget(DeleteButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 3, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_Opponent1 = new QLabel(AddEditMatchDialogClass);
        label_Opponent1->setObjectName("label_Opponent1");

        horizontalLayout_4->addWidget(label_Opponent1);

        lineEdit__Opponent1 = new QLineEdit(AddEditMatchDialogClass);
        lineEdit__Opponent1->setObjectName("lineEdit__Opponent1");
        lineEdit__Opponent1->setEnabled(false);

        horizontalLayout_4->addWidget(lineEdit__Opponent1);


        horizontalLayout_6->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_Statu = new QLabel(AddEditMatchDialogClass);
        label_Statu->setObjectName("label_Statu");

        horizontalLayout_2->addWidget(label_Statu);

        comboBox_Statu = new QComboBox(AddEditMatchDialogClass);
        comboBox_Statu->addItem(QString());
        comboBox_Statu->addItem(QString());
        comboBox_Statu->addItem(QString());
        comboBox_Statu->addItem(QString());
        comboBox_Statu->setObjectName("comboBox_Statu");
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

        horizontalSpacer_2 = new QSpacerItem(350, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_Stage = new QLabel(AddEditMatchDialogClass);
        label_Stage->setObjectName("label_Stage");

        horizontalLayout_3->addWidget(label_Stage);

        comboBox_Stage = new QComboBox(AddEditMatchDialogClass);
        comboBox_Stage->setObjectName("comboBox_Stage");
        sizePolicy.setHeightForWidth(comboBox_Stage->sizePolicy().hasHeightForWidth());
        comboBox_Stage->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(comboBox_Stage);

        horizontalSpacer_3 = new QSpacerItem(430, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_Opponent2 = new QLabel(AddEditMatchDialogClass);
        label_Opponent2->setObjectName("label_Opponent2");

        horizontalLayout_5->addWidget(label_Opponent2);

        lineEdit__Opponent2 = new QLineEdit(AddEditMatchDialogClass);
        lineEdit__Opponent2->setObjectName("lineEdit__Opponent2");
        lineEdit__Opponent2->setEnabled(false);

        horizontalLayout_5->addWidget(lineEdit__Opponent2);


        gridLayout_2->addLayout(horizontalLayout_5, 3, 0, 1, 1);

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


        gridLayout_2->addWidget(groupBox_3, 5, 0, 1, 1);


        retranslateUi(AddEditMatchDialogClass);

        QMetaObject::connectSlotsByName(AddEditMatchDialogClass);
    } // setupUi

    void retranslateUi(QDialog *AddEditMatchDialogClass)
    {
        AddEditMatchDialogClass->setWindowTitle(QCoreApplication::translate("AddEditMatchDialogClass", "AddEditMatchDialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AddEditMatchDialogClass", "Date && Time", nullptr));
        label_Date->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Date:", nullptr));
        DateButton->setText(QString());
        label_Time->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Time:", nullptr));
        SaveButton->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Save", nullptr));
        DeleteButton->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Delete", nullptr));
        label_Opponent1->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Opponent 1:", nullptr));
        label_Statu->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Statu:", nullptr));
        comboBox_Statu->setItemText(0, QString());
        comboBox_Statu->setItemText(1, QCoreApplication::translate("AddEditMatchDialogClass", "Regular", nullptr));
        comboBox_Statu->setItemText(2, QCoreApplication::translate("AddEditMatchDialogClass", "WO", nullptr));
        comboBox_Statu->setItemText(3, QCoreApplication::translate("AddEditMatchDialogClass", "BYE", nullptr));

        radioButton_Win->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Win", nullptr));
        radioButton_Lose->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Lose", nullptr));
        label_Stage->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Stage:", nullptr));
        label_Opponent2->setText(QCoreApplication::translate("AddEditMatchDialogClass", "Opponent 2:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("AddEditMatchDialogClass", "Set Scores", nullptr));
        AddSetButton->setText(QString());
        RemoveSetButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddEditMatchDialogClass: public Ui_AddEditMatchDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITMATCHDIALOG_H
