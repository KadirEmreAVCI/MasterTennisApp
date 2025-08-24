#include "FilterByTeammate.h"

std::string FilterByTeammate::GetFilteredData(const Tournament& t)const
{
    return t.IsDoubleTournament() ? t.GetTeammate() : "";
}