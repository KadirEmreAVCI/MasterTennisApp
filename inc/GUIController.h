#pragma once
#include <memory>
class TennisDesktopApp;
class GUIController
{
public:
	static GUIController& instance();
	GUIController(const GUIController&) = delete;
	GUIController& operator=(const GUIController&) = delete;
private:
	GUIController();
	std::unique_ptr<TennisDesktopApp> m_uptrTennisDesktopApp{std::make_unique<TennisDesktopApp>()};
};

