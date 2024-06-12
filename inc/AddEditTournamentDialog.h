#pragma once
#include <string>
#include <QDialog>
#include "ui_AddEditTournamentDialog.h"
#include "IQTComponent.h"
#include <Tournament.h>
class AddEditTournamentDialog : public QDialog, public IQTComponent
{
	Q_OBJECT

public:
	AddEditTournamentDialog(QWidget *parent = nullptr);
	~AddEditTournamentDialog();
	void InitCustomComponents() override final;
	void InitDialogWithTournament(const Tournament& t);
	void SetDialogMode(DialogMode mode, const Tournament& t = {});
private:
	Ui::AddTournamentDialogClass ui;
	QString m_sOrgName, m_sType, m_sTeammate, m_sCategory, m_sTotalCategory, m_sYear, m_sSeason;
	unsigned m_uiTournamentID{}, m_uiSetsBestOf{};
	void ClearDialog();
	void DeactivateOptions();
	void ActivateOptions();
	bool MandatoryFieldsFilled()const;
	bool MaxParticipantExceeded(unsigned uiParticipant)const;
	void InitSetsBestOfComboBox(unsigned);
	DialogMode m_DialogMode;
	const unsigned m_uiMaxParticipant{ 128 };
private slots:
	void on_CancelButton_clicked();
	void on_SaveButton_clicked();
	void on_radioButton_Single_clicked();
	void on_radioButton_Double_clicked();
	void on_comboBox_Category_currentTextChanged(const QString& category);
	void on_comboBox_Year_currentTextChanged(const QString& year);
	void on_comboBox_Season_currentTextChanged(const QString& season);
	void on_comboBox_OrganizationName_currentTextChanged(const QString& org);
	void on_comboBox_SetsBestOf_currentTextChanged(const QString& setsbestof);
public slots:
	void UpdateOrganizationOptions();
};
