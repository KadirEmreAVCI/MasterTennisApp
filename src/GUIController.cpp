#include <iostream>
#include "GUIController.h"
#include "TennisDesktopApp.h"
#include <QPixMap>
GUIController* GUIController::ms_pGUIController = nullptr;
void GUIController::create()
{
	std::cout << "GUIController::create\n";
	static GUIController obj;
	ms_pGUIController = &obj;
}
GUIController& GUIController::instance()
{
	if (ms_pGUIController == nullptr)
		create();
	return *ms_pGUIController;
}
void GUIController::BuildGUIComponents()
{
	std::cout << "GUIController::BuildGUIComponents\n";
	m_upTennisDesktopApp = std::make_unique<TennisDesktopApp>();
	m_upTennisDesktopApp->setImageFolderLoc(m_sImageFolderLoc);
	m_upTennisDesktopApp->InitializeCustomComponents();
	m_upTennisDesktopApp->show();
}

