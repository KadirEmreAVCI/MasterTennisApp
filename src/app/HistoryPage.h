#ifndef HISTORYPAGE_H
#define HISTORYPAGE_H

#include <memory>
#include <QWidget>
#include "ui_HistoryPage.h"
#include "TableWidgetUser.h"
#include "Profile.h"
#include "DataFilter.h"

class AddEditTournamentDialog;
class MatchesDialog;
class HistoryPage : public QWidget, public TableWidgetUser
{
	Q_OBJECT
public:
	HistoryPage(QWidget *parent = nullptr);
	~HistoryPage();
private:
	// TableWidgetUser
	virtual void FillTable()override;
	virtual void LoadDataToTable()override;
	void PlaceTournament2Table(const Tournament& t, unsigned uiRowIdx);
	void ChangeInDB(const std::vector<Profile>&, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&);
	void UpdateActiveProfileData(const Profile&);
	void UserLoggedIn(const Profile&);
	void InitFilterComponents();
	void HighlightFilteredColumn();
	Ui::HistoryPageClass ui;
	std::unique_ptr<AddEditTournamentDialog> m_upAddEditTournamentDialog{ nullptr };
	std::unique_ptr<MatchesDialog> m_upMatchesDialog;
	std::unique_ptr<IDataFilter<Tournament>> m_upActiveFilter{ nullptr };
	std::vector<Tournament> m_vecDisplayedTournament;
	std::vector<Tournament> m_vecTournament;
	bool m_blFirstLoadOfData = true;
	unsigned m_uiProfileID = 0;
	std::string m_sFilter = "";
private slots:
	void on_NewTournamentButton_clicked();
	void on_ClearButton_clicked();
	void on_comboBoxFilter_currentTextChanged(const QString& sFilter);
	void on_lineEditSearchBar_textChanged(const QString& sFilterWord);
public slots:	
	void ShowMatches();
	void LockUnlockTournament();
	void EditTournament();
	void DeleteTournament();
};

#endif