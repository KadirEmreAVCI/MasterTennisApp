#include "FilterByType.h"

void FilterByType::HighlightFilteredColumn(QTableWidget* tableWidget)const
{
    if(nullptr != tableWidget)
    {
        tableWidget->clearSelection();
        tableWidget->selectColumn(3);
    }
}
std::string FilterByType::GetFilteredData(const Tournament& t)const
{
    return t.GetType();
}