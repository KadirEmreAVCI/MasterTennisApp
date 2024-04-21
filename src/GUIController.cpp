#include "GUIController.h"
#include "TennisDesktopApp.h"
GUIController& GUIController::instance()
{
	static GUIController obj;
	return obj;
}
GUIController::GUIController()
{
	m_uptrTennisDesktopApp->show();
}