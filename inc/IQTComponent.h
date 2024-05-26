#pragma once
#include <string>
#include <QLabel>
#include <QPixmap>
class IQTComponent {
public:
	virtual void InitCustomComponents() = 0;
protected:
	void InitPicture(QLabel* pPicLabel, std::string sPicAddress, float fScale = 1)
	{
		QPixmap pix{ QString::fromStdString(sPicAddress) };
		const int iHeight = pPicLabel->height() * fScale;
		const int iWidth = pPicLabel->width() * fScale;
		pPicLabel->setPixmap(pix.scaled(iWidth, iHeight, Qt::KeepAspectRatio));
	}
};