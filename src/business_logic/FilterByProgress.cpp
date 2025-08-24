#include "FilterByProgress.h"

std::string FilterByProgress::GetFilteredData(const Tournament& t)const
{
    return t.GetLastMatch().has_value() ? t.GetLastMatch().value().GetStage() : "";
}