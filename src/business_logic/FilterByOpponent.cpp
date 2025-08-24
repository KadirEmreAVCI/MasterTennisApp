#include "FilterByOpponent.h"

void FilterByOpponent::HighlightFilteredColumn(QTableWidget* tableWidget)const
{
    if(nullptr != tableWidget)
    {
        tableWidget->clearSelection();
        tableWidget->selectColumn(9);
    }
}
std::string FilterByOpponent::GetFilteredData(const Tournament& t)const
{
    std::string sConcatanatedOpponents;
    for(const Match& m : t.GetMatches())
    {
        sConcatanatedOpponents += m.GetOpponent1() + " ";
        if(t.IsDoubleTournament())
        {
            sConcatanatedOpponents += m.GetOpponent2() + " ";
        }
    }
    return sConcatanatedOpponents;
}