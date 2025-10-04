#ifndef CONFIG_H
#define CONFIG_H

// Standard Headers
#include <vector>
#include <string> 

// Upcoming Match Parameters
static const unsigned int g_uiUpcomingMatchWidth = 500;
static const unsigned int g_uiUpcomingMatchHeight = 120;
static const unsigned int g_uiMaxUpcomingMatch = 2;

// PNG Files
static const char* g_cpDeleteButtonPNG = ":images/DeleteButton.png";
static const char* g_cpEditButtonPNG = ":images/EditButton.png";

static const std::vector<std::string> g_vecTournamentCategories{"Master", "A+", "A", "B", "C", "D", "Ilk Turnuvam"};

#endif