#include "TournamentFilter.h"

std::vector<Tournament> TournamentFilter::ms_vecUnfilteredTournaments; 

std::vector<Tournament> TournamentFilter::ApplyFilter(const std::string& sFilteringWord)
{
    std::vector<Tournament> vecFilteredTournaments;
    if(sFilteringWord != "")
    {
        const auto sFilteredWordLower = ToLowerCase(sFilteringWord);
        std::copy_if(ms_vecUnfilteredTournaments.cbegin(), ms_vecUnfilteredTournaments.cend(), std::back_inserter(vecFilteredTournaments), [this, &sFilteredWordLower](const Tournament& t){
            const auto sFilteredDataLower = ToLowerCase(GetFilteredData(t));
            return (sFilteredDataLower.find(sFilteredWordLower) != std::string::npos);
        });
    }
    else
    {
        vecFilteredTournaments = ms_vecUnfilteredTournaments;
    }
    return vecFilteredTournaments;
}
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
