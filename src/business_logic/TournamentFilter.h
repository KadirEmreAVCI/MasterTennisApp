#ifndef TOURNAMENTFILTER_H
#define TOURNAMENTFILTER_H
#include <vector>
#include "Tournament.h"

class TournamentFilter{
public:
    virtual ~TournamentFilter() = default;
    virtual std::vector<Tournament> ApplyFilter(const std::string& sFilteredWord) = 0;
    static void SetUnfilteredTournaments(const std::vector<Tournament>&);
private:    
protected:
    static std::string ToLowerCase(const std::string&);
    static std::vector<Tournament> ms_vecUnfilteredTournaments;
};

#endif