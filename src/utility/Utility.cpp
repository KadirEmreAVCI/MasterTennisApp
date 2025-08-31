#include "Utility.h"
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QComboBox>
#include <QString>
#include <QHBoxLayout>
#include <QTableWidget> 

void utility::InitPicture(QLabel* pPicLabel, std::string sPicAddress, float fScale)
{
    QPixmap pix{ QString::fromStdString(sPicAddress) };
    const float fHeight = pPicLabel->height() * fScale;
    const float fWidth = pPicLabel->width() * fScale;
    pPicLabel->setPixmap(pix.scaled(fHeight, fWidth, Qt::KeepAspectRatio));
    pPicLabel->setAlignment(Qt::AlignCenter);
}
QPushButton* utility::CreateButtonWithPicture(const std::string& sPicAddress, float fScale)
{
    QPushButton* pButton = new QPushButton;
    InitButtonWithPicture(pButton, sPicAddress, fScale);
    return pButton;
}
void utility::InitButtonWithPicture(QPushButton* pButton, const std::string& sPicAddress, float fScale)
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
void utility::PlaceValue2TableCell(QTableWidget* table, QString sVal, unsigned uiRowIdx, unsigned uiColumnIdx)
{
	QTableWidgetItem* const pVal = new QTableWidgetItem;
	pVal->setText(sVal);
	pVal->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	table->setItem(uiRowIdx, uiColumnIdx++, pVal);
}
QLabel* utility::PlacePic2TableCell(QTableWidget* pTableWidget, const std::string& sPicAddr, float fScale, unsigned uiRowIdx, unsigned uiColumnIdx)
{
	QLabel* pLabel = new QLabel;
	InitPicture(pLabel, sPicAddr, fScale);
	pTableWidget->setCellWidget(uiRowIdx, uiColumnIdx++, pLabel);
    return pLabel;
}
QPushButton* utility::PlaceButton2TableCell(QTableWidget* pTableWidget, unsigned uiRowIdx, unsigned uiColumnIdx, const std::string& sButtonText)
{
	QWidget* pWidget = new QWidget();
	QPushButton* pBtn = new QPushButton();
	pBtn->setText(QString::fromStdString(sButtonText));
	QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
	pLayout->addWidget(pBtn);
	pLayout->setAlignment(Qt::AlignCenter);
	pLayout->setContentsMargins(0, 0, 0, 0);
	pWidget->setLayout(pLayout);
	pTableWidget->setCellWidget(uiRowIdx, uiColumnIdx, pWidget);
	return pBtn;
}
QPushButton* utility::PlaceButton2TableCellWithImage(QTableWidget* pTableWidget, unsigned uiRowIdx, unsigned uiColumnIdx, const std::string& sImageAddr, float fScale, bool blEnabled)
{
	QPushButton* pBtn = CreateButtonWithPicture(sImageAddr, fScale);
	pBtn->setEnabled(blEnabled);
    QWidget* pWidget = new QWidget();
	QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
	pLayout->addWidget(pBtn);
	pLayout->setAlignment(Qt::AlignCenter);
	pLayout->setContentsMargins(0, 0, 0, 0);
	pWidget->setLayout(pLayout);
	pTableWidget->setCellWidget(uiRowIdx, uiColumnIdx, pWidget);
    return pBtn;
}
std::string utility::Serialize(const std::vector<std::string>& vecDeserialized)
{
	std::string sSerialized{};
	for (const auto& str : vecDeserialized)
	{
		if (sSerialized != "")
		{
			sSerialized.append(", ");
		}
		sSerialized.append(str);
	}
	return sSerialized;
}
