#pragma once
#include <string>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QComboBox>

enum class DialogMode {
	eAddDialog,
	eEditDialog
};
class IQTComponent {
public:
	virtual void InitCustomComponents() = 0;
protected:
	void InitPicture(QLabel* pPicLabel, std::string sPicAddress, float fScale = 1.0f)
	{
		QPixmap pix{ QString::fromStdString(sPicAddress) };
		const float fHeight = pPicLabel->height() * fScale;
		const float fWidth = pPicLabel->width() * fScale;
		pPicLabel->setPixmap(pix.scaled(fHeight, fWidth, Qt::KeepAspectRatio));
	}
	void InitButtonWithPicture(QPushButton* pButton, std::string sPicAddress, float fScale = 1.0f)
	{
		QPixmap pix(QString::fromStdString(sPicAddress));
		QIcon ButtonIcon(pix);
		pButton->setIcon(ButtonIcon);
		pButton->setIconSize(pix.rect().size() * fScale);
	}
	void InitComboBox(QComboBox* pComboBox, const QString& sVal = "")
	{
		const size_t idx = pComboBox->findText(sVal);
		if (idx != -1) { // Check if the item was found
			pComboBox->setCurrentIndex(idx);
		}
		else
		{
			pComboBox->setCurrentIndex(0);
		}
	}
	void SetComboBoxAlternatives(QComboBox* pComboBox, const std::vector<std::string>& vecAlternatives)
	{
		pComboBox->clear();
		pComboBox->addItem("");
		for (const auto& sAlternative : vecAlternatives)
		{
			pComboBox->addItem(QString::fromStdString(sAlternative));
		}
	}
};