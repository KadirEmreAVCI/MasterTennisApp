// Project Headers
#include "TournamentCategoryFilterWidget.h"
#include "AchievementsPage.h"
#include "Utility.h"
#include "Common.h"

// Standard QT Headers
#include <QStandardItemModel>

TournamentCategoryFilterWidget::TournamentCategoryFilterWidget(QWidget *parent) : m_pParentWidget{parent}
{
    setupUi(this);
    InitFilterComponents();
}
TournamentCategoryFilterWidget::~TournamentCategoryFilterWidget()
{

}
void TournamentCategoryFilterWidget::ClearWidget()
{
    InitFilterComponents();
}
void TournamentCategoryFilterWidget::InitFilterComponents()
{
    utility::SetComboBoxAlternatives(comboBoxTournamentCategory, common::g_vecTournamentCategories);
	if(auto* pModel = qobject_cast<QStandardItemModel*>(comboBoxTournamentCategory->model()); pModel != nullptr)
	{
		if(auto* pItem = pModel->item(0); pItem != nullptr)
		{
			pItem->setFlags(pItem->flags() & ~Qt::ItemIsEnabled);
		}
	}
    comboBoxTournamentCategory->setCurrentIndex(0);
	ClearButton->setVisible(false);
}
void TournamentCategoryFilterWidget::on_comboBoxTournamentCategory_currentTextChanged(const QString& sCategory)
{
    ClearButton->setVisible(true);
    reinterpret_cast<AchievementsPage*>(m_pParentWidget)->TournamentCategoryChanged(sCategory.toStdString());
}
void TournamentCategoryFilterWidget::on_ClearButton_clicked()
{
    InitFilterComponents();
    reinterpret_cast<AchievementsPage*>(m_pParentWidget)->TournamentCategoryCleared();
}