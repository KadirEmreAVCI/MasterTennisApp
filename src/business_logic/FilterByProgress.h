#ifndef FILTERBYPROGRESS_H
#define FILTERBYPROGRESS_H
#include "TournamentFilter.h"

class FilterByProgress : public TournamentFilter{
public:
    virtual std::string GetFilteredData(const Tournament& t)const override;
};

#endif