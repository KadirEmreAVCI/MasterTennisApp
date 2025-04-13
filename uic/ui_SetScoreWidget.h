/********************************************************************************
** Form generated from reading UI file 'SetScoreWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETSCOREWIDGET_H
#define UI_SETSCOREWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetScoreWidgetClass
{
public:
    QGridLayout *gridLayout;
    QCheckBox *checkBox_Tiebreak;
    QPushButton *ClearButton;
    QLabel *label_Set;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox_HomeTiebreakScore;
    QSpinBox *spinBox_AwayTiebreakScore;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox_HomeScore;
    QSpinBox *spinBox_AwayScore;

    void setupUi(QWidget *SetScoreWidgetClass)
    {
        if (SetScoreWidgetClass->objectName().isEmpty())
            SetScoreWidgetClass->setObjectName("SetScoreWidgetClass");
        SetScoreWidgetClass->resize(517, 75);
        gridLayout = new QGridLayout(SetScoreWidgetClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        checkBox_Tiebreak = new QCheckBox(SetScoreWidgetClass);
        checkBox_Tiebreak->setObjectName("checkBox_Tiebreak");

        gridLayout->addWidget(checkBox_Tiebreak, 0, 3, 1, 1);

        ClearButton = new QPushButton(SetScoreWidgetClass);
        ClearButton->setObjectName("ClearButton");

        gridLayout->addWidget(ClearButton, 1, 3, 1, 1);

        label_Set = new QLabel(SetScoreWidgetClass);
        label_Set->setObjectName("label_Set");

        gridLayout->addWidget(label_Set, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(SetScoreWidgetClass);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(181, 0));
        groupBox_2->setMaximumSize(QSize(16777215, 57));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        spinBox_HomeTiebreakScore = new QSpinBox(groupBox_2);
        spinBox_HomeTiebreakScore->setObjectName("spinBox_HomeTiebreakScore");
        spinBox_HomeTiebreakScore->setMinimumSize(QSize(0, 21));
        QFont font;
        font.setBold(true);
        spinBox_HomeTiebreakScore->setFont(font);

        horizontalLayout_2->addWidget(spinBox_HomeTiebreakScore);

        spinBox_AwayTiebreakScore = new QSpinBox(groupBox_2);
        spinBox_AwayTiebreakScore->setObjectName("spinBox_AwayTiebreakScore");
        spinBox_AwayTiebreakScore->setMinimumSize(QSize(0, 21));
        spinBox_AwayTiebreakScore->setFont(font);

        horizontalLayout_2->addWidget(spinBox_AwayTiebreakScore);


        gridLayout->addWidget(groupBox_2, 0, 2, 2, 1);

        groupBox = new QGroupBox(SetScoreWidgetClass);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(181, 0));
        groupBox->setMaximumSize(QSize(181, 57));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        spinBox_HomeScore = new QSpinBox(groupBox);
        spinBox_HomeScore->setObjectName("spinBox_HomeScore");
        spinBox_HomeScore->setMinimumSize(QSize(0, 21));
        spinBox_HomeScore->setFont(font);

        horizontalLayout->addWidget(spinBox_HomeScore);

        spinBox_AwayScore = new QSpinBox(groupBox);
        spinBox_AwayScore->setObjectName("spinBox_AwayScore");
        spinBox_AwayScore->setMinimumSize(QSize(0, 21));
        spinBox_AwayScore->setFont(font);

        horizontalLayout->addWidget(spinBox_AwayScore);


        gridLayout->addWidget(groupBox, 0, 1, 2, 1);


        retranslateUi(SetScoreWidgetClass);

        QMetaObject::connectSlotsByName(SetScoreWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *SetScoreWidgetClass)
    {
        SetScoreWidgetClass->setWindowTitle(QCoreApplication::translate("SetScoreWidgetClass", "SetScoreWidget", nullptr));
        checkBox_Tiebreak->setText(QCoreApplication::translate("SetScoreWidgetClass", "Tiebreak", nullptr));
        ClearButton->setText(QCoreApplication::translate("SetScoreWidgetClass", "Clear", nullptr));
        label_Set->setText(QCoreApplication::translate("SetScoreWidgetClass", "Set #:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SetScoreWidgetClass", "Tiebreak", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SetScoreWidgetClass", "Major", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetScoreWidgetClass: public Ui_SetScoreWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETSCOREWIDGET_H
