#ifndef FILTERBYTYPE_H
#define FILTERBYTYPE_H
#include "TournamentFilter.h"

class FilterByType : public TournamentFilter{
public:
    virtual void HighlightFilteredColumn(QTableWidget* tableWidget)const override;
    virtual std::string GetFilteredData(const Tournament& t)const override;
};

#endif