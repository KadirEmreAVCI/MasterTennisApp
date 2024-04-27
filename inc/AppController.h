#pragma once
#include <memory>
#include <string>
class IGUIConfigurator;
class AppController{
public:
	static void create();
	static AppController& instance();
	AppController(const AppController&) = delete;
	AppController& operator=(const AppController&) = delete;

	// member functions
	void StartApplication();
	std::string getAppName(); 
private:
	AppController();
	static AppController* ms_pAppController;
	
	// member functions

	// member variables
	std::unique_ptr<IGUIConfigurator> m_upIGUIConfigurator{nullptr};
	std::string m_sAppName{"Master Tennis App"};
};

