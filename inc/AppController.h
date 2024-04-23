#pragma once
#include <string>
class IGUIConfigurator;
class AppController{
public:
	static void create();
	static AppController& instance();
	AppController(const AppController&) = delete;
	AppController& operator=(const AppController&) = delete;

	// member functions
	std::string getAppName(); 
	std::string getImageFolderLoc();
private:
	AppController();
	static AppController* ms_pAppController;
	
	// member functions

	// member variables
	IGUIConfigurator* m_pIGUIConfigurator{nullptr};
	std::string m_sAppName{"Master Tennis App"};
	std::string m_sImageFolderLoc{"images/"};
};

