// Project Headers
#include "StatControllerTest.h"

float StatControllerTest::GetWinRatePercentage(size_t szWin, size_t szLose)const
{
    return (szWin + szLose != 0) ? static_cast<float>(szWin) / (szWin + szLose) * 100.0f : 0.0f;
}

TEST_F(StatControllerTest, MatchesStatTest)
{
    const StatReport rExpectedStatReport{6, 6};
    const StatReport rCalculatedStatReport = m_vecStatReport[0];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}
TEST_F(StatControllerTest, MatchTiebreakStatTest)
{
    const StatReport rExpectedStatReport{3, 0};
    const StatReport rCalculatedStatReport = m_vecStatReport[1];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}
TEST_F(StatControllerTest, SetTiebreakStatTest)
{
    const StatReport rExpectedStatReport{0, 2};
    const StatReport rCalculatedStatReport = m_vecStatReport[2];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}