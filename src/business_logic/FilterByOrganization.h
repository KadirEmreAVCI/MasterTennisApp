#ifndef FILTERBYORGANIZATION_H
#define FILTERBYORGANIZATION_H
#include "TournamentFilter.h"

class FilterByOrganization : public TournamentFilter{
public:
    virtual void HighlightFilteredColumn(QTableWidget* tableWidget)const override;
    virtual std::string GetFilteredData(const Tournament& t)const override;
};

#endif