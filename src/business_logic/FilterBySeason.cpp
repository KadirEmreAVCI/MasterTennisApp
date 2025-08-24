#include "FilterBySeason.h"

std::string FilterBySeason::GetFilteredData(const Tournament& t)const
{
    return t.GetSeason();
}