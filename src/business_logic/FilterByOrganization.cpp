#include "FilterByOrganization.h"

std::vector<Tournament> FilterByOrganization::ApplyFilter(const std::string& sFilteredWord)
{
    std::vector<Tournament> vecFilteredTournaments;
    if(sFilteredWord != "")
    {
        const auto sFilteredWordLower = ToLowerCase(sFilteredWord);
        std::copy_if(ms_vecUnfilteredTournaments.cbegin(), ms_vecUnfilteredTournaments.cend(), std::back_inserter(vecFilteredTournaments), [&sFilteredWordLower](const Tournament& t){
            const auto sOrgNameLower = ToLowerCase(t.GetOrgName());
            return (sOrgNameLower.find(sFilteredWordLower) != std::string::npos);
        });
    }
    else
    {
        vecFilteredTournaments = ms_vecUnfilteredTournaments;
    }
    return vecFilteredTournaments;
}