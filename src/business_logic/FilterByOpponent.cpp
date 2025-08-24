#include "FilterByOpponent.h"

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