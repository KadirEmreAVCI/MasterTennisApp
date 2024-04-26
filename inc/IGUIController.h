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
	void setImageFolderLoc(std::string sImageFolderLoc)
	{
		m_sImageFolderLoc = sImageFolderLoc;
	}
	std::string getImageFolderLoc() const
	{
		return m_sImageFolderLoc;
	}
protected:
	std::string m_sAppName{};
	std::string m_sImageFolderLoc{};
};