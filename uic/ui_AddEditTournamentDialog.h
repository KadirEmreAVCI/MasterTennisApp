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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddTournamentDialogClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout;
    QLabel *label_OrganizationName;
    QLabel *label_Type;
    QLabel *label_Teammate;
    QLabel *label_Category;
    QLabel *label_Year;
    QLabel *label_Season;
    QLabel *label_Participant;
    QLabel *label_3rdPlaceGameAvailable;
    QLabel *label_SetsBestOf;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_OrganizationName;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_Type;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_Teammate;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox_Category;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spinBox_Year;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_Season;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spinBox_Participant;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox_3rdPlaceGameAvailable;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *comboBox_SetsBestOf;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *_2;
    QPushButton *SaveButton;
    QPushButton *CancelButton;
    QSpacerItem *spacerItem;

    void setupUi(QDialog *AddTournamentDialogClass)
    {
        if (AddTournamentDialogClass->objectName().isEmpty())
            AddTournamentDialogClass->setObjectName("AddTournamentDialogClass");
        AddTournamentDialogClass->resize(502, 276);
        gridLayout = new QGridLayout(AddTournamentDialogClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        label_OrganizationName = new QLabel(AddTournamentDialogClass);
        label_OrganizationName->setObjectName("label_OrganizationName");
        label_OrganizationName->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_OrganizationName);

        label_Type = new QLabel(AddTournamentDialogClass);
        label_Type->setObjectName("label_Type");
        label_Type->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_Type);

        label_Teammate = new QLabel(AddTournamentDialogClass);
        label_Teammate->setObjectName("label_Teammate");
        label_Teammate->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_Teammate);

        label_Category = new QLabel(AddTournamentDialogClass);
        label_Category->setObjectName("label_Category");
        label_Category->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_Category);

        label_Year = new QLabel(AddTournamentDialogClass);
        label_Year->setObjectName("label_Year");
        label_Year->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_Year);

        label_Season = new QLabel(AddTournamentDialogClass);
        label_Season->setObjectName("label_Season");
        label_Season->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_Season);

        label_Participant = new QLabel(AddTournamentDialogClass);
        label_Participant->setObjectName("label_Participant");
        label_Participant->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_Participant);

        label_3rdPlaceGameAvailable = new QLabel(AddTournamentDialogClass);
        label_3rdPlaceGameAvailable->setObjectName("label_3rdPlaceGameAvailable");
        label_3rdPlaceGameAvailable->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_3rdPlaceGameAvailable);

        label_SetsBestOf = new QLabel(AddTournamentDialogClass);
        label_SetsBestOf->setObjectName("label_SetsBestOf");
        label_SetsBestOf->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_SetsBestOf);


        horizontalLayout_10->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        comboBox_OrganizationName = new QComboBox(AddTournamentDialogClass);
        comboBox_OrganizationName->setObjectName("comboBox_OrganizationName");
        comboBox_OrganizationName->setEnabled(true);

        horizontalLayout->addWidget(comboBox_OrganizationName);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        comboBox_Type = new QComboBox(AddTournamentDialogClass);
        comboBox_Type->setObjectName("comboBox_Type");

        horizontalLayout_2->addWidget(comboBox_Type);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        lineEdit_Teammate = new QLineEdit(AddTournamentDialogClass);
        lineEdit_Teammate->setObjectName("lineEdit_Teammate");

        verticalLayout_2->addWidget(lineEdit_Teammate);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        comboBox_Category = new QComboBox(AddTournamentDialogClass);
        comboBox_Category->addItem(QString());
        comboBox_Category->setObjectName("comboBox_Category");

        horizontalLayout_3->addWidget(comboBox_Category);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        spinBox_Year = new QSpinBox(AddTournamentDialogClass);
        spinBox_Year->setObjectName("spinBox_Year");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox_Year->sizePolicy().hasHeightForWidth());
        spinBox_Year->setSizePolicy(sizePolicy);
        spinBox_Year->setBaseSize(QSize(10, 0));
        spinBox_Year->setMinimum(2000);
        spinBox_Year->setMaximum(2100);
        spinBox_Year->setSingleStep(1);
        spinBox_Year->setValue(2000);

        horizontalLayout_4->addWidget(spinBox_Year);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        comboBox_Season = new QComboBox(AddTournamentDialogClass);
        comboBox_Season->addItem(QString());
        comboBox_Season->addItem(QString());
        comboBox_Season->addItem(QString());
        comboBox_Season->addItem(QString());
        comboBox_Season->addItem(QString());
        comboBox_Season->setObjectName("comboBox_Season");

        horizontalLayout_5->addWidget(comboBox_Season);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        spinBox_Participant = new QSpinBox(AddTournamentDialogClass);
        spinBox_Participant->setObjectName("spinBox_Participant");
        spinBox_Participant->setMaximum(256);

        horizontalLayout_6->addWidget(spinBox_Participant);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        checkBox_3rdPlaceGameAvailable = new QCheckBox(AddTournamentDialogClass);
        checkBox_3rdPlaceGameAvailable->setObjectName("checkBox_3rdPlaceGameAvailable");
        checkBox_3rdPlaceGameAvailable->setEnabled(false);

        horizontalLayout_7->addWidget(checkBox_3rdPlaceGameAvailable);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        comboBox_SetsBestOf = new QComboBox(AddTournamentDialogClass);
        comboBox_SetsBestOf->addItem(QString());
        comboBox_SetsBestOf->addItem(QString());
        comboBox_SetsBestOf->addItem(QString());
        comboBox_SetsBestOf->addItem(QString());
        comboBox_SetsBestOf->addItem(QString());
        comboBox_SetsBestOf->setObjectName("comboBox_SetsBestOf");

        horizontalLayout_8->addWidget(comboBox_SetsBestOf);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_10->addLayout(verticalLayout_2);


        horizontalLayout_11->addLayout(horizontalLayout_10);

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


        horizontalLayout_11->addLayout(_2);


        gridLayout->addLayout(horizontalLayout_11, 0, 0, 1, 1);


        retranslateUi(AddTournamentDialogClass);

        QMetaObject::connectSlotsByName(AddTournamentDialogClass);
    } // setupUi

    void retranslateUi(QDialog *AddTournamentDialogClass)
    {
        AddTournamentDialogClass->setWindowTitle(QCoreApplication::translate("AddTournamentDialogClass", "AddTournamentDialog", nullptr));
        label_OrganizationName->setText(QCoreApplication::translate("AddTournamentDialogClass", "Organization:", nullptr));
        label_Type->setText(QCoreApplication::translate("AddTournamentDialogClass", "Type:", nullptr));
        label_Teammate->setText(QCoreApplication::translate("AddTournamentDialogClass", "Teammate:", nullptr));
        label_Category->setText(QCoreApplication::translate("AddTournamentDialogClass", "Category:", nullptr));
        label_Year->setText(QCoreApplication::translate("AddTournamentDialogClass", "Year:", nullptr));
        label_Season->setText(QCoreApplication::translate("AddTournamentDialogClass", "Season:", nullptr));
        label_Participant->setText(QCoreApplication::translate("AddTournamentDialogClass", "Participant:", nullptr));
        label_3rdPlaceGameAvailable->setText(QCoreApplication::translate("AddTournamentDialogClass", "3rd Place Game Available:", nullptr));
        label_SetsBestOf->setText(QCoreApplication::translate("AddTournamentDialogClass", "Best Of (Set):", nullptr));
        comboBox_Category->setItemText(0, QString());

        comboBox_Season->setItemText(0, QString());
        comboBox_Season->setItemText(1, QCoreApplication::translate("AddTournamentDialogClass", "Winter", nullptr));
        comboBox_Season->setItemText(2, QCoreApplication::translate("AddTournamentDialogClass", "Spring", nullptr));
        comboBox_Season->setItemText(3, QCoreApplication::translate("AddTournamentDialogClass", "Summer", nullptr));
        comboBox_Season->setItemText(4, QCoreApplication::translate("AddTournamentDialogClass", "Fall", nullptr));

        checkBox_3rdPlaceGameAvailable->setText(QString());
        comboBox_SetsBestOf->setItemText(0, QString());
        comboBox_SetsBestOf->setItemText(1, QCoreApplication::translate("AddTournamentDialogClass", "Best Of 1", nullptr));
        comboBox_SetsBestOf->setItemText(2, QCoreApplication::translate("AddTournamentDialogClass", "Best Of 3", nullptr));
        comboBox_SetsBestOf->setItemText(3, QCoreApplication::translate("AddTournamentDialogClass", "Best Of 5", nullptr));
        comboBox_SetsBestOf->setItemText(4, QCoreApplication::translate("AddTournamentDialogClass", "Best Of 7", nullptr));

        SaveButton->setText(QCoreApplication::translate("AddTournamentDialogClass", "Save", nullptr));
        CancelButton->setText(QCoreApplication::translate("AddTournamentDialogClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTournamentDialogClass: public Ui_AddTournamentDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITTOURNAMENTDIALOG_H
