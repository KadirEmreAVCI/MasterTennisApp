#pragma once
#include <memory>
#include <QWidget>
#include "ui_HistoryPage.h"
#include "IQTComponent.h"
#include "TableWidgetUser.h"
#include "Profile.h"

class AddEditTournamentDialog;
class MatchesDialog;
class HistoryPage : public QWidget, public TableWidgetUser
{
	Q_OBJECT
public:
	HistoryPage(QWidget *parent = nullptr);
	~HistoryPage();
	void InitCustomComponents() override final;
private:
	virtual void FillTable()override;
	virtual void LoadDataToTable()override;
	void InsertTournament2Table(const Tournament& t, unsigned uiRowIdx);
	void InsertButton2Cell(const std::string& sButtonText, auto func, unsigned uiRowIdx, unsigned uiColumnIdx);
	void InsertButtonWithImage2Cell(const std::string& sImageAddr, float fScale, auto func, bool blEnabled, unsigned uiRowIdx, unsigned uiColumnIdx);
	void InsertTrophyPic(const Tournament& t, unsigned uiRowIdx, unsigned uiColumnIdx);
	void UpdateActiveProfileData(const Profile&);
	void UserLoggedIn(const Profile&);
	std::vector<Tournament> ConcatanateTournaments()const;
	Tournament FindSignalingTournament()const;
	void OpenAddDialog();
	void OpenEditDialog(const Tournament&);
	Ui::HistoryPageClass ui;
	std::unique_ptr<AddEditTournamentDialog> m_upAddEditTournamentDialog{ nullptr };
	std::unique_ptr<MatchesDialog> m_upMatchesDialog;
	std::vector<Tournament> m_vecTournament;
	std::vector<Organization> m_vecOrganization;
	bool m_blFirstLoadOfData = true;
private slots:
	void on_NewTournamentButton_clicked();
public slots:	
	void ShowMatches();
	void LockUnlockTournament();
	void EditTournament();
	void DeleteTournament();
};
