/********************************************************************************
** Form generated from reading UI file 'AddEditTournamentDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITTOURNAMENTDIALOG_H
#define UI_ADDEDITTOURNAMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddTournamentDialogClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_OrganizationName;
    QComboBox *comboBox_OrganizationName;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *_2;
    QPushButton *SaveButton;
    QPushButton *CancelButton;
    QSpacerItem *spacerItem;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Type;
    QRadioButton *radioButton_Single;
    QRadioButton *radioButton_Double;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_Teammate;
    QLineEdit *lineEdit_Teammate;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Category;
    QComboBox *comboBox_Category;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_Year;
    QComboBox *comboBox_Year;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Season;
    QComboBox *comboBox_Season;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_Participant;
    QSpinBox *spinBox_Participant;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3rdPlaceGameAvailable;
    QCheckBox *checkBox_3rdPlaceGameAvailable;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_Completion;
    QCheckBox *checkBox_Completion;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_SetsBestOf;
    QComboBox *comboBox_SetsBestOf;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_GamesToWin;
    QSpinBox *spinBox_GamesToWin;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *AddTournamentDialogClass)
    {
        if (AddTournamentDialogClass->objectName().isEmpty())
            AddTournamentDialogClass->setObjectName("AddTournamentDialogClass");
        AddTournamentDialogClass->resize(406, 301);
        gridLayout = new QGridLayout(AddTournamentDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        label_OrganizationName = new QLabel(AddTournamentDialogClass);
        label_OrganizationName->setObjectName("label_OrganizationName");

        horizontalLayout->addWidget(label_OrganizationName);

        comboBox_OrganizationName = new QComboBox(AddTournamentDialogClass);
        comboBox_OrganizationName->setObjectName("comboBox_OrganizationName");
        comboBox_OrganizationName->setEnabled(true);

        horizontalLayout->addWidget(comboBox_OrganizationName);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        _2 = new QVBoxLayout();
        _2->setSpacing(6);
        _2->setContentsMargins(0, 0, 0, 0);
        _2->setObjectName("_2");
        SaveButton = new QPushButton(AddTournamentDialogClass);
        SaveButton->setObjectName("SaveButton");

        _2->addWidget(SaveButton);

        CancelButton = new QPushButton(AddTournamentDialogClass);
        CancelButton->setObjectName("CancelButton");

        _2->addWidget(CancelButton);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        _2->addItem(spacerItem);


        gridLayout->addLayout(_2, 0, 1, 3, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_Type = new QLabel(AddTournamentDialogClass);
        label_Type->setObjectName("label_Type");

        horizontalLayout_2->addWidget(label_Type);

        radioButton_Single = new QRadioButton(AddTournamentDialogClass);
        radioButton_Single->setObjectName("radioButton_Single");
        radioButton_Single->setEnabled(false);
        radioButton_Single->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_Single);

        radioButton_Double = new QRadioButton(AddTournamentDialogClass);
        radioButton_Double->setObjectName("radioButton_Double");
        radioButton_Double->setEnabled(false);

        horizontalLayout_2->addWidget(radioButton_Double);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_Teammate = new QLabel(AddTournamentDialogClass);
        label_Teammate->setObjectName("label_Teammate");

        horizontalLayout_10->addWidget(label_Teammate);

        lineEdit_Teammate = new QLineEdit(AddTournamentDialogClass);
        lineEdit_Teammate->setObjectName("lineEdit_Teammate");

        horizontalLayout_10->addWidget(lineEdit_Teammate);


        gridLayout->addLayout(horizontalLayout_10, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_Category = new QLabel(AddTournamentDialogClass);
        label_Category->setObjectName("label_Category");

        horizontalLayout_3->addWidget(label_Category);

        comboBox_Category = new QComboBox(AddTournamentDialogClass);
        comboBox_Category->addItem(QString());
        comboBox_Category->setObjectName("comboBox_Category");

        horizontalLayout_3->addWidget(comboBox_Category);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_Year = new QLabel(AddTournamentDialogClass);
        label_Year->setObjectName("label_Year");

        horizontalLayout_9->addWidget(label_Year);

        comboBox_Year = new QComboBox(AddTournamentDialogClass);
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->addItem(QString());
        comboBox_Year->setObjectName("comboBox_Year");
        comboBox_Year->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_Year->sizePolicy().hasHeightForWidth());
        comboBox_Year->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(comboBox_Year);


        horizontalLayout_13->addLayout(horizontalLayout_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_Season = new QLabel(AddTournamentDialogClass);
        label_Season->setObjectName("label_Season");

        horizontalLayout_5->addWidget(label_Season);

        comboBox_Season = new QComboBox(AddTournamentDialogClass);
        comboBox_Season->addItem(QString());
        comboBox_Season->addItem(QString());
        comboBox_Season->addItem(QString());
        comboBox_Season->addItem(QString());
        comboBox_Season->addItem(QString());
        comboBox_Season->setObjectName("comboBox_Season");
        comboBox_Season->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_Season->sizePolicy().hasHeightForWidth());
        comboBox_Season->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(comboBox_Season);


        horizontalLayout_13->addLayout(horizontalLayout_5);


        gridLayout->addLayout(horizontalLayout_13, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_Participant = new QLabel(AddTournamentDialogClass);
        label_Participant->setObjectName("label_Participant");

        horizontalLayout_6->addWidget(label_Participant);

        spinBox_Participant = new QSpinBox(AddTournamentDialogClass);
        spinBox_Participant->setObjectName("spinBox_Participant");

        horizontalLayout_6->addWidget(spinBox_Participant);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_6, 5, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_3rdPlaceGameAvailable = new QLabel(AddTournamentDialogClass);
        label_3rdPlaceGameAvailable->setObjectName("label_3rdPlaceGameAvailable");

        horizontalLayout_8->addWidget(label_3rdPlaceGameAvailable);

        checkBox_3rdPlaceGameAvailable = new QCheckBox(AddTournamentDialogClass);
        checkBox_3rdPlaceGameAvailable->setObjectName("checkBox_3rdPlaceGameAvailable");
        checkBox_3rdPlaceGameAvailable->setEnabled(false);

        horizontalLayout_8->addWidget(checkBox_3rdPlaceGameAvailable);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_8, 6, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_Completion = new QLabel(AddTournamentDialogClass);
        label_Completion->setObjectName("label_Completion");

        horizontalLayout_7->addWidget(label_Completion);

        checkBox_Completion = new QCheckBox(AddTournamentDialogClass);
        checkBox_Completion->setObjectName("checkBox_Completion");
        checkBox_Completion->setEnabled(false);

        horizontalLayout_7->addWidget(checkBox_Completion);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_7, 7, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_SetsBestOf = new QLabel(AddTournamentDialogClass);
        label_SetsBestOf->setObjectName("label_SetsBestOf");

        horizontalLayout_4->addWidget(label_SetsBestOf);

        comboBox_SetsBestOf = new QComboBox(AddTournamentDialogClass);
        comboBox_SetsBestOf->addItem(QString());
        comboBox_SetsBestOf->addItem(QString());
        comboBox_SetsBestOf->addItem(QString());
        comboBox_SetsBestOf->addItem(QString());
        comboBox_SetsBestOf->addItem(QString());
        comboBox_SetsBestOf->setObjectName("comboBox_SetsBestOf");

        horizontalLayout_4->addWidget(comboBox_SetsBestOf);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        gridLayout->addLayout(horizontalLayout_4, 8, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_GamesToWin = new QLabel(AddTournamentDialogClass);
        label_GamesToWin->setObjectName("label_GamesToWin");

        horizontalLayout_11->addWidget(label_GamesToWin);

        spinBox_GamesToWin = new QSpinBox(AddTournamentDialogClass);
        spinBox_GamesToWin->setObjectName("spinBox_GamesToWin");

        horizontalLayout_11->addWidget(spinBox_GamesToWin);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_11, 9, 0, 1, 1);


        retranslateUi(AddTournamentDialogClass);

        QMetaObject::connectSlotsByName(AddTournamentDialogClass);
    } // setupUi

    void retranslateUi(QDialog *AddTournamentDialogClass)
    {
        AddTournamentDialogClass->setWindowTitle(QCoreApplication::translate("AddTournamentDialogClass", "AddTournamentDialog", nullptr));
        label_OrganizationName->setText(QCoreApplication::translate("AddTournamentDialogClass", "Select Organization:", nullptr));
        SaveButton->setText(QCoreApplication::translate("AddTournamentDialogClass", "Save", nullptr));
        CancelButton->setText(QCoreApplication::translate("AddTournamentDialogClass", "Cancel", nullptr));
        label_Type->setText(QCoreApplication::translate("AddTournamentDialogClass", "Type:", nullptr));
        radioButton_Single->setText(QCoreApplication::translate("AddTournamentDialogClass", "Single", nullptr));
        radioButton_Double->setText(QCoreApplication::translate("AddTournamentDialogClass", "Double", nullptr));
        label_Teammate->setText(QCoreApplication::translate("AddTournamentDialogClass", "Teammate:", nullptr));
        label_Category->setText(QCoreApplication::translate("AddTournamentDialogClass", "Category:", nullptr));
        comboBox_Category->setItemText(0, QString());

        label_Year->setText(QCoreApplication::translate("AddTournamentDialogClass", "Year:", nullptr));
        comboBox_Year->setItemText(0, QString());
        comboBox_Year->setItemText(1, QCoreApplication::translate("AddTournamentDialogClass", "2024", nullptr));
        comboBox_Year->setItemText(2, QCoreApplication::translate("AddTournamentDialogClass", "2023", nullptr));
        comboBox_Year->setItemText(3, QCoreApplication::translate("AddTournamentDialogClass", "2022", nullptr));
        comboBox_Year->setItemText(4, QCoreApplication::translate("AddTournamentDialogClass", "2021", nullptr));
        comboBox_Year->setItemText(5, QCoreApplication::translate("AddTournamentDialogClass", "2020", nullptr));
        comboBox_Year->setItemText(6, QCoreApplication::translate("AddTournamentDialogClass", "2019", nullptr));
        comboBox_Year->setItemText(7, QCoreApplication::translate("AddTournamentDialogClass", "2018", nullptr));
        comboBox_Year->setItemText(8, QCoreApplication::translate("AddTournamentDialogClass", "2017", nullptr));
        comboBox_Year->setItemText(9, QCoreApplication::translate("AddTournamentDialogClass", "2016", nullptr));
        comboBox_Year->setItemText(10, QCoreApplication::translate("AddTournamentDialogClass", "2015", nullptr));
        comboBox_Year->setItemText(11, QCoreApplication::translate("AddTournamentDialogClass", "2014", nullptr));
        comboBox_Year->setItemText(12, QCoreApplication::translate("AddTournamentDialogClass", "2013", nullptr));
        comboBox_Year->setItemText(13, QCoreApplication::translate("AddTournamentDialogClass", "2012", nullptr));
        comboBox_Year->setItemText(14, QCoreApplication::translate("AddTournamentDialogClass", "2011", nullptr));
        comboBox_Year->setItemText(15, QCoreApplication::translate("AddTournamentDialogClass", "2010", nullptr));
        comboBox_Year->setItemText(16, QCoreApplication::translate("AddTournamentDialogClass", "2009", nullptr));
        comboBox_Year->setItemText(17, QCoreApplication::translate("AddTournamentDialogClass", "2008", nullptr));
        comboBox_Year->setItemText(18, QCoreApplication::translate("AddTournamentDialogClass", "2007", nullptr));
        comboBox_Year->setItemText(19, QCoreApplication::translate("AddTournamentDialogClass", "2006", nullptr));
        comboBox_Year->setItemText(20, QCoreApplication::translate("AddTournamentDialogClass", "2005", nullptr));
        comboBox_Year->setItemText(21, QCoreApplication::translate("AddTournamentDialogClass", "2004", nullptr));
        comboBox_Year->setItemText(22, QCoreApplication::translate("AddTournamentDialogClass", "2003", nullptr));
        comboBox_Year->setItemText(23, QCoreApplication::translate("AddTournamentDialogClass", "2002", nullptr));
        comboBox_Year->setItemText(24, QCoreApplication::translate("AddTournamentDialogClass", "2001", nullptr));
        comboBox_Year->setItemText(25, QCoreApplication::translate("AddTournamentDialogClass", "2000", nullptr));
        comboBox_Year->setItemText(26, QCoreApplication::translate("AddTournamentDialogClass", "1999", nullptr));
        comboBox_Year->setItemText(27, QCoreApplication::translate("AddTournamentDialogClass", "1998", nullptr));
        comboBox_Year->setItemText(28, QCoreApplication::translate("AddTournamentDialogClass", "1997", nullptr));
        comboBox_Year->setItemText(29, QCoreApplication::translate("AddTournamentDialogClass", "1996", nullptr));
        comboBox_Year->setItemText(30, QCoreApplication::translate("AddTournamentDialogClass", "1995", nullptr));
        comboBox_Year->setItemText(31, QCoreApplication::translate("AddTournamentDialogClass", "1994", nullptr));
        comboBox_Year->setItemText(32, QCoreApplication::translate("AddTournamentDialogClass", "1993", nullptr));
        comboBox_Year->setItemText(33, QCoreApplication::translate("AddTournamentDialogClass", "1992", nullptr));
        comboBox_Year->setItemText(34, QCoreApplication::translate("AddTournamentDialogClass", "1991", nullptr));
        comboBox_Year->setItemText(35, QCoreApplication::translate("AddTournamentDialogClass", "1990", nullptr));

        label_Season->setText(QCoreApplication::translate("AddTournamentDialogClass", "Season:", nullptr));
        comboBox_Season->setItemText(0, QString());
        comboBox_Season->setItemText(1, QCoreApplication::translate("AddTournamentDialogClass", "Winter", nullptr));
        comboBox_Season->setItemText(2, QCoreApplication::translate("AddTournamentDialogClass", "Spring", nullptr));
        comboBox_Season->setItemText(3, QCoreApplication::translate("AddTournamentDialogClass", "Summer", nullptr));
        comboBox_Season->setItemText(4, QCoreApplication::translate("AddTournamentDialogClass", "Fall", nullptr));

        label_Participant->setText(QCoreApplication::translate("AddTournamentDialogClass", "Participant:", nullptr));
        label_3rdPlaceGameAvailable->setText(QCoreApplication::translate("AddTournamentDialogClass", "3rd Place Game Available:", nullptr));
        checkBox_3rdPlaceGameAvailable->setText(QString());
        label_Completion->setText(QCoreApplication::translate("AddTournamentDialogClass", "Tournament Completed:", nullptr));
        checkBox_Completion->setText(QString());
        label_SetsBestOf->setText(QCoreApplication::translate("AddTournamentDialogClass", "Best Of (Set):", nullptr));
        comboBox_SetsBestOf->setItemText(0, QString());
        comboBox_SetsBestOf->setItemText(1, QCoreApplication::translate("AddTournamentDialogClass", "Best Of 1", nullptr));
        comboBox_SetsBestOf->setItemText(2, QCoreApplication::translate("AddTournamentDialogClass", "Best Of 3", nullptr));
        comboBox_SetsBestOf->setItemText(3, QCoreApplication::translate("AddTournamentDialogClass", "Best Of 5", nullptr));
        comboBox_SetsBestOf->setItemText(4, QCoreApplication::translate("AddTournamentDialogClass", "Best Of 7", nullptr));

        label_GamesToWin->setText(QCoreApplication::translate("AddTournamentDialogClass", "Games Needed To Win:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTournamentDialogClass: public Ui_AddTournamentDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITTOURNAMENTDIALOG_H
