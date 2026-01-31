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
	// TableWidgetUser
	virtual void LoadDataToTable()override;
	virtual void FillTable()override;
	void PlaceMatch2Table(const Match& m, unsigned uiRowIdx);
	void UpdateActiveProfileData(const Profile& p);
	void ChangeInDB(const std::vector<Profile>&, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&);
	Ui::MatchesDialogClass ui;
	std::unique_ptr<AddEditMatchDialog> m_upAddEditMatchDialog{ nullptr };
	Tournament m_RootTournament;
	std::vector<Match> m_vecMatch;
private slots:
	void on_NewMatchButton_clicked();
public slots:
	void EditMatch();
	void DeleteMatch();
	void NewMatchAdded();
	void MatchEdited();
};

#endif