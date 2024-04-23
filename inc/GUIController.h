#pragma once
#include <memory>
#include <string>
#include <QLabel>
#include "IGUIController.h"
class TennisDesktopApp;
class GUIController : public IGUIController{
public:
	static void create();
	static GUIController& instance();
	GUIController(const GUIController&) = delete;
	GUIController& operator=(const GUIController&) = delete;
	
	// Member functions
	void BuildGUIComponents() override final;

private:
	GUIController() = default;
	static GUIController* ms_pGUIController;	
	
	// Member variables
	std::unique_ptr<TennisDesktopApp> m_upTennisDesktopApp;
	
	// Member functions
	void InitializePicture(QLabel* pPicLabel, std::string sPicAddress);
};

