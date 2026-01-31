#ifndef COMMON_H
#define COMMON_H

// Standard Headers
#include <vector>
#include <string> 

namespace common{

// Upcoming Match Parameters
constexpr unsigned int g_uiUpcomingMatchCardWidth = 500;
constexpr unsigned int g_uiUpcomingMatchCardHeight = 120;
constexpr unsigned int g_uiMaxUpcomingMatchCards = 2;

// PNG Files
constexpr const char* g_cpDeleteButtonPNG = ":images/DeleteButton.png";
constexpr const char* g_cpEditButtonPNG = ":images/EditButton.png";

// All possible tournament categories
inline std::vector<std::string> g_vecTournamentCategories{"Master", "A+", "A", "B", "C", "D", "Ilk Turnuvam"};

enum class Outcome {
    HomeWin = 0,
    AwayWin = 1,
    Tied = 2
};

};



#endif  // COMMON_H