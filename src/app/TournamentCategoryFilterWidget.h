#ifndef TOURNAMENTCATEGORYFILTERWIDGET_H
#define TOURNAMENTCATEGORYFILTERWIDGET_H

#include <QWidget>
#include "ui_TournamentCategoryFilterWidget.h"
class TournamentCategoryFilterWidget : public QWidget, public Ui::TournamentCategoryFilterWidget
{
	Q_OBJECT

public:
	TournamentCategoryFilterWidget(QWidget *parent = nullptr);
	~TournamentCategoryFilterWidget();
private:
    void InitFilterComponents();
    std::vector<std::string> m_vecTournamentCategories{"Master", "A+", "A", "B", "C", "D", "Ilk Turnuvam"};
	QWidget* m_pParentWidget;
private slots:
	void on_comboBoxTournamentCategory_currentTextChanged(const QString& sCategory);
	void on_ClearButton_clicked();
};

#endif	// TOURNAMENTCATEGORYFILTERWIDGET_H