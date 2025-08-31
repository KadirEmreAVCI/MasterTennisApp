#include "Utility.h"
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QComboBox>
#include <QString>

void utility::InitPicture(QLabel* pPicLabel, std::string sPicAddress, float fScale)
{
    QPixmap pix{ QString::fromStdString(sPicAddress) };
    const float fHeight = pPicLabel->height() * fScale;
    const float fWidth = pPicLabel->width() * fScale;
    pPicLabel->setPixmap(pix.scaled(fHeight, fWidth, Qt::KeepAspectRatio));
    pPicLabel->setAlignment(Qt::AlignCenter);
}
void utility::InitButtonWithPicture(QPushButton* pButton, std::string sPicAddress, float fScale)
{
    QPixmap pix(QString::fromStdString(sPicAddress));
    QIcon ButtonIcon(pix);
    pButton->setIcon(ButtonIcon);
    pButton->setIconSize(pix.rect().size() * fScale);
}
void utility::InitComboBox(QComboBox* pComboBox, const QString& sVal)
{
    const int idx = pComboBox->findText(sVal);
    if (idx != -1) { // Check if the item was found
        pComboBox->setCurrentIndex(idx);
    }
    else
    {
        pComboBox->setCurrentIndex(0);
    }
}
void utility::SetComboBoxAlternatives(QComboBox* pComboBox, const std::vector<std::string>& vecAlternatives, bool blStartWithEmptyAlternative)
{
    pComboBox->clear();
    if (blStartWithEmptyAlternative)
    {
        pComboBox->addItem("");
    }
    for (const auto& sAlternative : vecAlternatives)
    {
        pComboBox->addItem(QString::fromStdString(sAlternative));
    }
}
