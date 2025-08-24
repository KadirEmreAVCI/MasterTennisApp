#include "FilterBySeason.h"

void FilterBySeason::HighlightFilteredColumn(QTableWidget* tableWidget)const
{
    if(nullptr != tableWidget)
    {
        tableWidget->clearSelection();
        tableWidget->selectColumn(2);
    }
}
std::string FilterBySeason::GetFilteredData(const Tournament& t)const
{
    return t.GetSeason();
}