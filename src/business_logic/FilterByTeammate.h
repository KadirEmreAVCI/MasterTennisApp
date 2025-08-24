#ifndef FILTERBYTEAMMATE_H
#define FILTERBYTEAMMATE_H
#include "TournamentFilter.h"

class FilterByTeammate : public TournamentFilter{
public:
    virtual void HighlightFilteredColumn(QTableWidget* tableWidget)const override;
    virtual std::string GetFilteredData(const Tournament& t)const override;
};

#endif