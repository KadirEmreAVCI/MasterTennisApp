#ifndef FILTERBYSEASON_H
#define FILTERBYSEASON_H
#include "TournamentFilter.h"

class FilterBySeason : public TournamentFilter{
public:
    virtual std::string GetFilteredData(const Tournament& t)const override;
};

#endif