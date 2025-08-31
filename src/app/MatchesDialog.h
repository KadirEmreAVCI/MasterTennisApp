#ifndef MATCHESDIALOG_H
#define MATCHESDIALOG_H

#include <QDialog>
#include "ui_MatchesDialog.h"
#include "TableWidgetUser.h"
#include "Profile.h"
class AddEditMatchDialog;
class MatchesDialog : public QDialog, public TableWidgetUser
{
	Q_OBJECT

public:
	MatchesDialog(QWidget *parent = nullptr);
	~MatchesDialog();
	void DisplayMatches(const Tournament& rootTournament);
private:
	virtual void FillTable()override;
	void OpenAddDialog();
	void OpenEditDialog(const Match&);
	void InsertMatch2Table(const Match& m, unsigned uiRowIdx);
	void UpdateActiveProfileData(const Profile& p);
	std::vector<Tournament> ConcatanateTournaments()const;
	virtual void LoadDataToTable()override;
	Match FindSignalingMatch()const;
	Ui::MatchesDialogClass ui;
	std::unique_ptr<AddEditMatchDialog> m_upAddEditMatchDialog{ nullptr };
	std::vector<std::string> m_vecMatchColumnNames{ "", "Statu", "W/L", "Stage", "Score", "Sets", "Teammate", "Opponent 1", "Opponent 2", "Date", "Time" };
	Tournament m_RootTournament;
	std::vector<Match> m_vecMatch;
	std::vector<Organization> m_vecOrganization;
private slots:
	void on_NewMatchButton_clicked();
public slots:
	void EditMatch();
	void DeleteMatch();
};

#endif