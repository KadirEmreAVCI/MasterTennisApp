#ifndef FILTERBYORGANIZATION_H
#define FILTERBYORGANIZATION_H
#include "TournamentFilter.h"

class FilterByOrganization : public TournamentFilter{
public:
    virtual std::vector<Tournament> ApplyFilter(const std::string& sFilteredWord) override;
};

#endif