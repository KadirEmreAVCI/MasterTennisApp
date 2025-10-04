// Project Headers
#include "StatControllerTest.h"

TEST_F(StatControllerTest, MatchesStatTest)
{
    const StatReport rExpectedStatReport{11, 8};
    const StatReport rCalculatedStatReport = m_vecStatReport[0];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}
TEST_F(StatControllerTest, MatchTiebreakStatTest)
{
    const StatReport rExpectedStatReport{4, 1};
    const StatReport rCalculatedStatReport = m_vecStatReport[1];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}
TEST_F(StatControllerTest, SetTiebreakStatTest)
{
    const StatReport rExpectedStatReport{2, 3};
    const StatReport rCalculatedStatReport = m_vecStatReport[2];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}
TEST_F(StatControllerTest, QuarterFinalStatTest)
{
    const StatReport rExpectedStatReport{2, 2};
    const StatReport rCalculatedStatReport = m_vecStatReport[3];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}
TEST_F(StatControllerTest, SemiFinalStatTest)
{
    const StatReport rExpectedStatReport{3, 2};
    const StatReport rCalculatedStatReport = m_vecStatReport[4];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}
TEST_F(StatControllerTest, 3rdPlaceGameStatTest)
{
    const StatReport rExpectedStatReport{1, 1};
    const StatReport rCalculatedStatReport = m_vecStatReport[5];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}
TEST_F(StatControllerTest, FinalStatTest)
{
    const StatReport rExpectedStatReport{1, 1};
    const StatReport rCalculatedStatReport = m_vecStatReport[5];
    EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
}