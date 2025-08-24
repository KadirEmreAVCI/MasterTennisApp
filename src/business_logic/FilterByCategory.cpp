#include "FilterByCategory.h"

std::string FilterByCategory::GetFilteredData(const Tournament& t)const
{
    return t.GetCategory();
}