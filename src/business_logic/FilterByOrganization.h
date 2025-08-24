#ifndef FILTERBYORGANIZATION_H
#define FILTERBYORGANIZATION_H
#include "TournamentFilter.h"

class FilterByOrganization : public TournamentFilter{
public:
    virtual std::string GetFilteredData(const Tournament& t)const override;
};

#endif