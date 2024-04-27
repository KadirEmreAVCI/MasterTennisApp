#include <iostream>
#include "AppController.h"
#include "GUIController.h"
#include "GUIConfigurator.h"
AppController* AppController::ms_pAppController = nullptr;
void AppController::create()
{
	std::cout << "AppController::create\n";
	static AppController obj;
	ms_pAppController = &obj;
}
AppController& AppController::instance()
{
	if (ms_pAppController == nullptr)
		create();
	return *ms_pAppController;
}
AppController::AppController() 
{
	m_upIGUIConfigurator = std::make_unique<GUIConfigurator>();
}
void AppController::StartApplication()
{
	GUIController::create();
	m_upIGUIConfigurator->ConfigureGUI();
}
std::string AppController::getAppName()
{
	return m_sAppName;
}
std::string AppController::getImageFolderLoc()
{
	return m_sImageFolderLoc;
}