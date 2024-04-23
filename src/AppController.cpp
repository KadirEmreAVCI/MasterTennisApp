#include <iostream>
#include "AppController.h"
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
	std::cout << "AppController::AppController\n";
	m_pIGUIConfigurator = new GUIConfigurator;
	if (m_pIGUIConfigurator != nullptr)
	{
		m_pIGUIConfigurator->ConfigureGUI();
	}
	else
	{
		std::cerr << "Error! GUIConfigurator could not be created!";
	}
}
std::string AppController::getAppName()
{
	return m_sAppName;
}
std::string AppController::getImageFolderLoc()
{
	return m_sImageFolderLoc;
}