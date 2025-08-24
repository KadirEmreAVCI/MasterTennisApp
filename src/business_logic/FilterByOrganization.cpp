#include "FilterByOrganization.h"

std::string FilterByOrganization::GetFilteredData(const Tournament& t)const
{
    return t.GetOrgName();
}