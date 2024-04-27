#pragma once
#include <string>
class IGUIController {
public:
	virtual void BuildGUIComponents() = 0;
	void setAppName(std::string sAppName)
	{
		m_sAppName = sAppName;
	}
	std::string getAppName() const
	{
		return m_sAppName;
	}
protected:
	std::string m_sAppName{};
};