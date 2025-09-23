#ifndef ADDEDITTOURNAMENTDIALOG_H
#define ADDEDITTOURNAMENTDIALOG_H

#include <string>
#include <QDialog>
#include "ui_AddEditTournamentDialog.h"
#include "AddEditDialog.h"
#include "Profile.h"
class AddEditTournamentDialog : public QDialog, public AddEditDialog<Tournament>
{
	Q_OBJECT

public:
	AddEditTournamentDialog(QWidget *parent = nullptr);
	~AddEditTournamentDialog();
private:
	// AddEditDialog
	virtual void ClearDialog()override;
	virtual void InitDialog()override;
	virtual void FillDialog()override;
	virtual bool IsMandatoryFieldsFilled()const override;
	virtual bool IsThereAnyUnsavedInfo()const override;
	
	void DeactivateOptions();
	void ActivateOptions();
	bool IsMaxParticipantExceeded(unsigned uiParticipant)const;
	void InitSetsBestOfComboBox(unsigned);
	bool IsDoubleTournament()const;
	const unsigned m_uiMaxParticipant{ 128 };
	Ui::AddTournamentDialogClass ui;
	QString m_sOrgName, m_sType, m_sTeammate, m_sCategory, m_sTotalCategory, m_sSeason;
	unsigned m_uiSetsBestOf{}, m_uiOrgID;
	std::vector <Organization> m_vecOrganization;
	Profile m_ActiveProfile;
private slots:
	void on_CancelButton_clicked();
	void on_SaveButton_clicked();
	void on_comboBox_Type_currentTextChanged(const QString& type);
	void on_comboBox_Category_currentTextChanged(const QString& category);
	void on_comboBox_Season_currentTextChanged(const QString& season);
	void on_comboBox_OrganizationName_currentTextChanged(const QString& org);
	void on_comboBox_SetsBestOf_currentTextChanged(const QString& setsbestof);
public slots:
	void UpdateOrganizations(const std::vector<Organization>&);
	void UpdateActiveProfileData(const Profile& p);
};

#endif