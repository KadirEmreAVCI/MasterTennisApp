#ifndef TOURNAMENTFILTER_H
#define TOURNAMENTFILTER_H
#include <vector>
#include "Tournament.h"

class TournamentFilter{
public:
    virtual ~TournamentFilter() = default;
    std::vector<Tournament> ApplyFilter(const std::string& sFilteringWord);
    static void SetUnfilteredTournaments(const std::vector<Tournament>&);
private:  
    virtual std::string GetFilteredData(const Tournament& t)const = 0;
protected:
    static std::string ToLowerCase(const std::string&);
    static std::vector<Tournament> ms_vecUnfilteredTournaments;
};

#endif