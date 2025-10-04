// Project Headers
#include "StatControllerTest.h"

float StatControllerTest::GetWinRatePercentage(size_t szWin, size_t szLose)const
{
    return (szWin + szLose != 0) ? static_cast<float>(szWin) / (szWin + szLose) * 100.0f : 0.0f;
}

TEST_F(StatControllerTest, MatchesStatTest)
{
    const unsigned uiWin = 6, uiLose = 6;
    const StatReport rExpectedStatReport{uiWin, uiLose, GetWinRatePercentage(uiWin, uiLose)};
    const StatReport rCalculatedStatReport = m_vecStatReport[0];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}
TEST_F(StatControllerTest, MatchTiebreakStatTest)
{
    const unsigned uiWin = 3, uiLose = 0;
    const StatReport rExpectedStatReport{uiWin, uiLose, GetWinRatePercentage(uiWin, uiLose)};
    const StatReport rCalculatedStatReport = m_vecStatReport[1];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}
TEST_F(StatControllerTest, SetTiebreakStatTest)
{
    const unsigned uiWin = 0, uiLose = 2;
    const StatReport rExpectedStatReport{uiWin, uiLose, GetWinRatePercentage(uiWin, uiLose)};
    const StatReport rCalculatedStatReport = m_vecStatReport[2];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}