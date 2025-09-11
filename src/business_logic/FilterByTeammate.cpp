#include "FilterByTeammate.h"

void FilterByTeammate::HighlightFilteredColumn(QTableWidget* tableWidget)const
{
    if(nullptr != tableWidget)
    {
        tableWidget->clearSelection();
        tableWidget->selectColumn(5);
    }
}
std::string FilterByTeammate::GetFilteredData(const Tournament& t)const
{
    return t.IsDoubleTournament() ? t.GetTeammate() : "";
}