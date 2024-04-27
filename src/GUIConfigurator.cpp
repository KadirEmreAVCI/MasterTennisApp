#include "GUIConfigurator.h"
#include "GUIController.h"
#include "AppController.h"
#include <iostream>
void GUIConfigurator::ConfigureGUI()
{
	std::cout << "GUIConfigurator::ConfigureGUI\n";
	GUIController::instance().setAppName(AppController::instance().getAppName());
	GUIController::instance().BuildGUIComponents();
}