#include "TournamentFilter.h"

std::vector<Tournament> TournamentFilter::ms_vecUnfilteredTournaments; 

void TournamentFilter::SetUnfilteredTournaments(const std::vector<Tournament>& vecUnfilteredTournaments)
{
    ms_vecUnfilteredTournaments = vecUnfilteredTournaments;
}
std::string TournamentFilter::ToLowerCase(const std::string& sWord)
{
    std::string sResult = sWord;
    std::transform(sResult.begin(), sResult.end(), sResult.begin(), [](unsigned char c){
        return std::tolower(c);
    });
    return sResult;
}
