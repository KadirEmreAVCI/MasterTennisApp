#include "FilterByType.h"

std::string FilterByType::GetFilteredData(const Tournament& t)const
{
    return t.GetType();
}