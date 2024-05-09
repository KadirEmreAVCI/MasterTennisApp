#include <iostream>
#include "AddTournamentDialog.h"
#include "SQLiteDB.h"
AddTournamentDialog::AddTournamentDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

AddTournamentDialog::~AddTournamentDialog()
{}

void AddTournamentDialog::InitializeCustomComponents()
{
	ui.radioButton_Single->setChecked(true);
	m_sType = "Single";
	ui.checkBox_Completion->setEnabled(false);
}

void AddTournamentDialog::on_CancelButton_clicked()
{
	close();
}
void AddTournamentDialog::on_AddButton_clicked()	
{
	m_sTournamentName = ui.lineEdit_TournamentName->text();
	m_sTeammate = ui.radioButton_Single->isChecked() ? ui.lineEdit_Teammate->text() : "";
	m_sCategory = ui.lineEdit_Category->text();
	m_sTotalCategory = ui.lineEdit_TotalCategory->text();
	m_sParticipant = ui.lineEdit_Participant->text();
	m_sProgress = (ui.checkBox_Completion->isEnabled()) ? ui.comboBox_Progress->currentText() : "";
	QString sColumns{"Name,Type,Teammate,Category,TotalCategory,Season,Participant,Completion,Progress"};
	QString sValues{"'"+ m_sTournamentName + "','" + m_sType + "','" + m_sTeammate + "','" + m_sCategory + "','" + m_sTotalCategory + "','" + m_sYear + m_sSeason + "','" + m_sParticipant + "','" + m_sCompletion + "','" + m_sProgress + "'"};
	SQLiteDB::instance().InsertRowToTable("Tournament", sColumns.toStdString(), sValues.toStdString());
}
void AddTournamentDialog::on_radioButton_Single_clicked()
{
	ui.lineEdit_Teammate->setEnabled(false);
	m_sType = "Single";
}
void AddTournamentDialog::on_radioButton_Double_clicked()
{
	ui.lineEdit_Teammate->setEnabled(true);
	m_sType = "Double";
}
void AddTournamentDialog::on_comboBox_Season_currentTextChanged(const QString& arg)
{
	m_sSeason = arg;
}
void AddTournamentDialog::on_checkBox_Completion_stateChanged(int arg)
{
	if (arg == 0)
	{
		m_sCompletion = "0";
		ui.comboBox_Progress->setEnabled(false);
	}
	else
	{
		m_sCompletion = "1";
		ui.comboBox_Progress->setEnabled(true);
	}
}
