// Project Headers
#include "StatControllerTest.h"

// TEST_F(StatControllerTest, AllCategoriesMatchesStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile);
//     const StatReport rExpectedStatReport{11, 8};
//     const StatReport rCalculatedStatReport = m_vecStatReport[0];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, AllCategoriesMatchTiebreakStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile);
//     const StatReport rExpectedStatReport{4, 1};
//     const StatReport rCalculatedStatReport = m_vecStatReport[1];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, AllCategoriesSetTiebreakStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile);
//     const StatReport rExpectedStatReport{2, 3};
//     const StatReport rCalculatedStatReport = m_vecStatReport[2];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, AllCategoriesQuarterFinalStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile);
//     const StatReport rExpectedStatReport{2, 2};
//     const StatReport rCalculatedStatReport = m_vecStatReport[3];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, AllCategoriesSemiFinalStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile);
//     const StatReport rExpectedStatReport{3, 2};
//     const StatReport rCalculatedStatReport = m_vecStatReport[4];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, AllCategories3rdPlaceGameStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile);
//     const StatReport rExpectedStatReport{1, 1};
//     const StatReport rCalculatedStatReport = m_vecStatReport[5];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, AllCategoriesFinalStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile);
//     const StatReport rExpectedStatReport{1, 1};
//     const StatReport rCalculatedStatReport = m_vecStatReport[6];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }

// TEST_F(StatControllerTest, IlkTurnuvamMatchesStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "Ilk Turnuvam");
//     const StatReport rExpectedStatReport{4, 1};
//     const StatReport rCalculatedStatReport = m_vecStatReport[0];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, IlkTurnuvamMatchTiebreakStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "Ilk Turnuvam");
//     const StatReport rExpectedStatReport{1, 0};
//     const StatReport rCalculatedStatReport = m_vecStatReport[1];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, IlkTurnuvamSetTiebreakStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "Ilk Turnuvam");
//     const StatReport rExpectedStatReport{0, 1};
//     const StatReport rCalculatedStatReport = m_vecStatReport[2];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, IlkTurnuvamQuarterFinalStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "Ilk Turnuvam");
//     const StatReport rExpectedStatReport{0, 0};
//     const StatReport rCalculatedStatReport = m_vecStatReport[3];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, IlkTurnuvamSemiFinalStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "Ilk Turnuvam");
//     const StatReport rExpectedStatReport{0, 1};
//     const StatReport rCalculatedStatReport = m_vecStatReport[4];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, IlkTurnuvam3rdPlaceGameStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "Ilk Turnuvam");
//     const StatReport rExpectedStatReport{0, 0};
//     const StatReport rCalculatedStatReport = m_vecStatReport[5];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, IlkTurnuvamFinalStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "Ilk Turnuvam");
//     const StatReport rExpectedStatReport{0, 0};
//     const StatReport rCalculatedStatReport = m_vecStatReport[6];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }

// TEST_F(StatControllerTest, CategoryDMatchesStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "D");
//     const StatReport rExpectedStatReport{5, 3};
//     const StatReport rCalculatedStatReport = m_vecStatReport[0];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, CategoryDMatchTiebreakStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "D");
//     const StatReport rExpectedStatReport{2, 0};
//     const StatReport rCalculatedStatReport = m_vecStatReport[1];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, CategoryDSetTiebreakStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "D");
//     const StatReport rExpectedStatReport{2, 2};
//     const StatReport rCalculatedStatReport = m_vecStatReport[2];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, CategoryDQuarterFinalStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "D");
//     const StatReport rExpectedStatReport{2, 1};
//     const StatReport rCalculatedStatReport = m_vecStatReport[3];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, CategoryDSemiFinalStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "D");
//     const StatReport rExpectedStatReport{2, 0};
//     const StatReport rCalculatedStatReport = m_vecStatReport[4];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, CategoryD3rdPlaceGameStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "D");
//     const StatReport rExpectedStatReport{0, 0};
//     const StatReport rCalculatedStatReport = m_vecStatReport[5];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, CategoryDFinalStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "D");
//     const StatReport rExpectedStatReport{1, 1};
//     const StatReport rCalculatedStatReport = m_vecStatReport[6];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }

// TEST_F(StatControllerTest, CategoryCMatchesStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "C");
//     const StatReport rExpectedStatReport{2, 4};
//     const StatReport rCalculatedStatReport = m_vecStatReport[0];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, CategoryCMatchTiebreakStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "C");
//     const StatReport rExpectedStatReport{1, 1};
//     const StatReport rCalculatedStatReport = m_vecStatReport[1];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, CategoryCSetTiebreakStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "C");
//     const StatReport rExpectedStatReport{0, 0};
//     const StatReport rCalculatedStatReport = m_vecStatReport[2];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, CategoryCQuarterFinalStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "C");
//     const StatReport rExpectedStatReport{0, 1};
//     const StatReport rCalculatedStatReport = m_vecStatReport[3];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, CategoryCSemiFinalStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "C");
//     const StatReport rExpectedStatReport{1, 1};
//     const StatReport rCalculatedStatReport = m_vecStatReport[4];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, CategoryC3rdPlaceGameStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "C");
//     const StatReport rExpectedStatReport{1, 1};
//     const StatReport rCalculatedStatReport = m_vecStatReport[5];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }
// TEST_F(StatControllerTest, CategoryCFinalStatTest)
// {
//     m_vecStatReport = m_upStatController->UpdateCareerStatsByCategory(m_rActiveProfile, "C");
//     const StatReport rExpectedStatReport{0, 0};
//     const StatReport rCalculatedStatReport = m_vecStatReport[6];
//     EXPECT_EQ(rCalculatedStatReport, rExpectedStatReport);
// }