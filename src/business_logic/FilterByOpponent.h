#ifndef FILTERBYOPPONENT_H
#define FILTERBYOPPONENT_H
#include "TournamentFilter.h"

class FilterByOpponent : public TournamentFilter{
public:
    virtual std::string GetFilteredData(const Tournament& t)const override;
};

#endif