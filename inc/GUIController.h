#pragma once
#include <memory>
#include <string>
#include <QLabel>
class TennisDesktopApp;
class GUIController
{
public:
	static void create(std::string sAppName, std::string sImageFolderLoc);
	static GUIController& instance();
	GUIController(const GUIController&) = delete;
	GUIController& operator=(const GUIController&) = delete;
	static std::string getms_sAppName();
	static void InitializePicture(QLabel* pPicLabel, std::string sPicAddress);
	
private:
	GUIController();
	static GUIController* ms_pGUIController;
	std::unique_ptr<TennisDesktopApp> m_upTennisDesktopApp;
	static std::string ms_sAppName;
	static std::string ms_sImageFolderLoc;
};

