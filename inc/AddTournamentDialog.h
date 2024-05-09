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
	void InitializeCustomComponents() override final;
private:
	Ui::AddTournamentDialogClass ui;
	QString m_sTournamentName, m_sType, m_sTeammate, m_sCategory, m_sTotalCategory, m_sYear, m_sSeason, m_sParticipant, m_sCompletion, m_sProgress;
private slots:
	void on_CancelButton_clicked();
	void on_AddButton_clicked();
	void on_radioButton_Single_clicked();
	void on_radioButton_Double_clicked();
	void on_comboBox_Season_currentTextChanged(const QString& sSeason);
	void on_checkBox_Completion_stateChanged(int);
};
