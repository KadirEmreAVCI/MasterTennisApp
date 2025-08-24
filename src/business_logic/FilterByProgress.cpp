#include "FilterByProgress.h"

void FilterByProgress::HighlightFilteredColumn(QTableWidget* tableWidget)const
{
    if(nullptr != tableWidget)
    {
        tableWidget->clearSelection();
        tableWidget->selectColumn(7);
    }
}
std::string FilterByProgress::GetFilteredData(const Tournament& t)const
{
    return t.GetLastMatch().has_value() ? t.GetLastMatch().value().GetStage() : "";
}