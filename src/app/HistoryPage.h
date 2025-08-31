#ifndef HISTORYPAGE_H
#define HISTORYPAGE_H

#include <memory>
#include <QWidget>
#include "ui_HistoryPage.h"
#include "TableWidgetUser.h"
#include "Profile.h"

class AddEditTournamentDialog;
class MatchesDialog;
class TournamentFilter;
class HistoryPage : public QWidget, public TableWidgetUser
{
	Q_OBJECT
public:
	HistoryPage(QWidget *parent = nullptr);
	~HistoryPage();
private:
	virtual void FillTable()override;
	virtual void LoadDataToTable()override;
	void PlaceTournament2Table(const Tournament& t, unsigned uiRowIdx);
	void UpdateActiveProfileData(const Profile&);
	void UserLoggedIn(const Profile&);
	std::vector<Tournament> ConcatanateTournaments()const;
	Tournament FindSignalingTournament()const;
	void OpenAddDialog();
	void OpenEditDialog(const Tournament&);
	void InitFilterComponents();
	Ui::HistoryPageClass ui;
	std::unique_ptr<AddEditTournamentDialog> m_upAddEditTournamentDialog{ nullptr };
	std::unique_ptr<MatchesDialog> m_upMatchesDialog;
	std::unique_ptr<TournamentFilter> m_upActiveFilter{ nullptr };
	std::vector<Tournament> m_vecDisplayedTournament;
	std::vector<Tournament> m_vecTournament;
	std::vector<Organization> m_vecOrganization;
	bool m_blFirstLoadOfData = true;
private slots:
	void on_NewTournamentButton_clicked();
	void on_RemoveFilterButton_clicked();
	void on_comboBoxFilter_currentTextChanged(const QString& sFilter);
	void on_lineEditSearchBar_textChanged(const QString& sFilterWord);
public slots:	
	void ShowMatches();
	void LockUnlockTournament();
	void EditTournament();
	void DeleteTournament();
};

#endif