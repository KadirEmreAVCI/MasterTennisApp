#include "GUIController.h"
#include "TennisDesktopApp.h"
#include <QPixMap>
GUIController* GUIController::ms_pGUIController = nullptr;
std::string GUIController::ms_sAppName{};
std::string GUIController::ms_sImageFolderLoc{};
void GUIController::create(std::string sAppName, std::string sImageFolderLoc)
{
	ms_sAppName = sAppName;
	ms_sImageFolderLoc = sImageFolderLoc;
	static GUIController obj;
	ms_pGUIController = &obj;
}
GUIController& GUIController::instance()
{
	return *ms_pGUIController;
}
GUIController::GUIController()
{
	m_upTennisDesktopApp = std::make_unique<TennisDesktopApp>();
	m_upTennisDesktopApp->show();
}
std::string GUIController::getms_sAppName()
{
	return ms_sAppName;
}

void GUIController::InitializePicture(QLabel* pPicLabel, std::string sPicAddress)
{
	QPixmap pix{ QString::fromStdString(ms_sImageFolderLoc + sPicAddress) };
	const int iHeight = pPicLabel->height();
	const int iWidth = pPicLabel->width();
	pPicLabel->setPixmap(pix.scaled(iWidth, iHeight, Qt::KeepAspectRatio));
}