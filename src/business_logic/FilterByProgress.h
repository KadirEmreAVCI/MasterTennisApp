#ifndef FILTERBYPROGRESS_H
#define FILTERBYPROGRESS_H
#include "TournamentFilter.h"

class FilterByProgress : public TournamentFilter{
public:
    virtual void HighlightFilteredColumn(QTableWidget* tableWidget)const override;
    virtual std::string GetFilteredData(const Tournament& t)const override;
};

#endif