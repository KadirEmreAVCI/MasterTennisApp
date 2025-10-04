// Project Headers
#include "StatWidget.h"
#include "Utility.h"

StatWidget::StatWidget(QWidget *parent): QWidget(parent)
{
	setupUi(this);
}
void StatWidget::InitWidget(const std::string& sStatName, const std::string& sPicturePath, float fPictureScale)
{
    lblStatName->setText(QString::fromStdString(sStatName));
    utility::InitLabelWithPicture(lblIcon, sPicturePath, fPictureScale);
}
void StatWidget::FillWidget(const StatReport& rStatReport)
{
    lblWin->setText(QString::fromStdString(std::to_string(rStatReport.m_uiWin)));
    lblLose->setText(QString::fromStdString(std::to_string(rStatReport.m_uiLose)));
    lblWinRate->setText(QString::fromStdString(std::format("{:.1f}", rStatReport.GetWinRate())) + "%");
}
QLabel* StatWidget::GetLabelIcon()const
{
    return lblIcon;
}
QLabel* StatWidget::GetLabelStatName()const
{
    return lblStatName;
}
QLabel* StatWidget::GetLabelWinText()const
{
    return lblWinText;
}
QLabel* StatWidget::GetLabelWin()const
{
    return lblWin;
}
QLabel* StatWidget::GetLabelLoseText()const
{
    return lblLoseText;
}
QLabel* StatWidget::GetLabelLose()const
{
    return lblLose;
}
QLabel* StatWidget::GetLabelWinRate()const
{
    return lblWinRate;
}
QLabel* StatWidget::GetLabelWinRateText()const
{
    return lblWinRateText;
}