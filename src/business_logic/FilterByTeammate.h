#ifndef FILTERBYTEAMMATE_H
#define FILTERBYTEAMMATE_H
#include "TournamentFilter.h"

class FilterByTeammate : public TournamentFilter{
public:
    virtual std::string GetFilteredData(const Tournament& t)const override;
};

#endif