#pragma once
#include <string>
#include <QDialog>
#include "ui_AddEditTournamentDialog.h"
#include "IQTComponent.h"
#include <Tournament.h>
enum class DialogMode {
	eAddDialog,
	eEditDialog
};
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
	QString m_sOrgName, m_sType, m_sTeammate, m_sCategory, m_sTotalCategory, m_sYear, m_sSeason, m_sParticipant, m_sCompletion;
	unsigned m_uiTournamentID{};
	void ClearDialog();
	void DeactivateOptions();
	void ActivateOptions();
	void SetOrganizationAlternatives();
	void SetCategoryAlternatives(std::string sOrgName);
	bool MandatoryFieldsFilled()const;
	void InitComboBox(QComboBox* pComboBox, const QString& sVal);
	DialogMode m_DialogMode;
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
public slots:
	void UpdateOrganizations();
};
