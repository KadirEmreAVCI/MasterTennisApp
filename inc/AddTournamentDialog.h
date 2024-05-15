#pragma once
#include <QDialog>
#include "ui_AddTournamentDialog.h"
#include "IQTComponent.h"
class AddTournamentDialog : public QDialog, public IQTComponent
{
	Q_OBJECT

public:
	AddTournamentDialog(QWidget *parent = nullptr);
	~AddTournamentDialog();
	void InitCustomComponents() override final;
private:
	Ui::AddTournamentDialogClass ui;
	QString m_sOrgName, m_sType, m_sTeammate, m_sCategory, m_sTotalCategory, m_sYear, m_sSeason, m_sParticipant, m_sCompletion, m_sProgress;
	void DeactivateOptions();
	void ActivateOptions();
	void SetOrganizationAlternatives();
	void SetCategoryAlternatives(std::string sOrgName);
	void SetStageAlternatives(std::string sOrgName);
private slots:
	void on_CancelButton_clicked();
	void on_SaveButton_clicked();
	void on_radioButton_Single_clicked();
	void on_radioButton_Double_clicked();
	void on_comboBox_Category_currentTextChanged(const QString& category);
	void on_comboBox_Year_currentTextChanged(const QString& year);
	void on_comboBox_Season_currentTextChanged(const QString& season);
	void on_checkBox_Completion_stateChanged(int);
	void on_comboBox_OrganizationName_currentTextChanged(const QString& org);
};
