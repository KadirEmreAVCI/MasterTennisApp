#include "FilterByOrganization.h"

void FilterByOrganization::HighlightFilteredColumn(QTableWidget* tableWidget)const
{
    if(nullptr != tableWidget)
    {
        tableWidget->clearSelection();
        tableWidget->selectColumn(1);
    }
}
std::string FilterByOrganization::GetFilteredData(const Tournament& t)const
{
    return t.GetOrgName();
}