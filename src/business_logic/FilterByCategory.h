#ifndef FILTERBYCATEGORY_H
#define FILTERBYCATEGORY_H
#include "TournamentFilter.h"

class FilterByCategory : public TournamentFilter{
public:
    virtual std::string GetFilteredData(const Tournament& t)const override;
};

#endif