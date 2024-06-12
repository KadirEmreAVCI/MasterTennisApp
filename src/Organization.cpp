#include <algorithm>
#include "Organization.h"
Organization::Organization()
{
	
}
unsigned Organization::GetID()const
{
	return m_uiID;
}
void Organization::SetID(unsigned uiID)
{
	m_uiID = uiID;
}
std::string Organization::GetName()const
{
	return m_sName;
}
void Organization::SetName(const std::string& sName)
{
	m_sName = sName;
}
std::vector<std::string> Organization::GetCategories()const
{
	return m_vecCategories;
}
void Organization::SetCategories(const std::vector<std::string>& vecCategories)
{
	m_vecCategories = vecCategories;
}
void Organization::AddCategory(const std::string& sCategory)
{
	m_vecCategories.push_back(sCategory);
}