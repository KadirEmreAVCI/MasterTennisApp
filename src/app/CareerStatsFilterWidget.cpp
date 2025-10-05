// Project Headers
#include "CareerStatsFilterWidget.h"
#include "AchievementsPage.h"
#include "DatabaseController.h"
#include "Utility.h"
#include "Common.h"

// Standard QT Headers
#include <QStandardItemModel>

CareerStatsFilterWidget::CareerStatsFilterWidget(QWidget *parent) : m_pParentWidget{parent}
{
    setupUi(this);
    utility::SetComboBoxAlternatives(comboBoxFilterType, m_vecCareerStatFilters);
	utility::DisableFirstItemOfComboBox(comboBoxFilterType);
    comboBoxFilteringItem->setFixedWidth(150);
    InitFilterComponents();
}
CareerStatsFilterWidget::~CareerStatsFilterWidget()
{

}
void CareerStatsFilterWidget::ClearWidget()
{
    InitFilterComponents();
}
void CareerStatsFilterWidget::InitFilterComponents()
{
    m_sFilterType = "";
    comboBoxFilterType->setCurrentIndex(0);
    comboBoxFilteringItem->setVisible(false);
	ClearButton->setVisible(false);
    comboBoxFilteringItem->clear();
}
void CareerStatsFilterWidget::on_comboBoxFilterType_currentTextChanged(const QString& sFilterType)
{
    m_sFilterType = sFilterType.toStdString();
    ClearButton->setVisible(true);
    comboBoxFilteringItem->setVisible(true);
    std::vector<std::string> vecFilteringItems;
    if(m_sFilterType == "Organization")
    {
        const auto vecOrganizations = DatabaseController::instance().GetOrganizations();
        std::transform(vecOrganizations.cbegin(), vecOrganizations.cend(), std::back_inserter(vecFilteringItems), [](const Organization& org){
            return org.GetName();
        });
    }
    else if(m_sFilterType == "Type")
    {   
        vecFilteringItems = {"Single", "Double"};
    }
    else if(m_sFilterType == "Category")
    {
        vecFilteringItems = common::g_vecTournamentCategories;
    }
    utility::SetComboBoxAlternatives(comboBoxFilteringItem, vecFilteringItems);
	utility::DisableFirstItemOfComboBox(comboBoxFilteringItem);
}
void CareerStatsFilterWidget::on_comboBoxFilteringItem_currentTextChanged(const QString& sFilteringItem)
{
    reinterpret_cast<AchievementsPage*>(m_pParentWidget)->CareerStatsFilterChanged(m_sFilterType, sFilteringItem.toStdString());
}
void CareerStatsFilterWidget::on_ClearButton_clicked()
{
    InitFilterComponents();
    reinterpret_cast<AchievementsPage*>(m_pParentWidget)->CareerStatsFilterCleared();
}