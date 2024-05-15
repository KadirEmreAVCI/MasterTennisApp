#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <QTableView>
#include "AddTournamentDialog.h"
#include "DatabaseController.h"

AddTournamentDialog::AddTournamentDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	InitCustomComponents();
}

AddTournamentDialog::~AddTournamentDialog()
{}

void AddTournamentDialog::InitCustomComponents()
{
	DeactivateOptions();
	SetOrganizationAlternatives();
}
void AddTournamentDialog::DeactivateOptions()
{
	ui.radioButton_Single->setEnabled(false);
	ui.radioButton_Double->setEnabled(false);
	ui.lineEdit_Teammate->setEnabled(false);
	ui.comboBox_Category->setEnabled(false);
	ui.comboBox_Year->setEnabled(false);
	ui.comboBox_Season->setEnabled(false);
	ui.lineEdit_Participant->setEnabled(false);
	ui.checkBox_Completion->setEnabled(false);
	ui.comboBox_Progress->setEnabled(false);
}
void AddTournamentDialog::ActivateOptions()
{
	ui.radioButton_Single->setEnabled(true);
	ui.radioButton_Double->setEnabled(true);
	ui.lineEdit_Teammate->setEnabled(false);
	ui.comboBox_Category->setEnabled(true);
	ui.comboBox_Year->setEnabled(true);
	ui.comboBox_Season->setEnabled(true);
	ui.lineEdit_Participant->setEnabled(true);
	ui.checkBox_Completion->setEnabled(true);
	ui.comboBox_Progress->setEnabled(false);
}

void AddTournamentDialog::SetOrganizationAlternatives()
{
	const auto& vecOrgName = DatabaseController::instance().GetOrganizations();
	for (const auto& sOrgName : vecOrgName)
	{
		ui.comboBox_OrganizationName->addItem(QString::fromStdString(sOrgName));
	}
}

void AddTournamentDialog::SetCategoryAlternatives(std::string sOrgName)
{
	ui.comboBox_Category->clear();
	const auto& vecCategory = DatabaseController::instance().GetCategories(sOrgName);
	for (const auto& sCategory : vecCategory)
	{
		ui.comboBox_Category->addItem(QString::fromStdString(sCategory));
	}
}

void AddTournamentDialog::SetStageAlternatives(std::string sOrgName)
{
	ui.comboBox_Progress->clear();
	const auto& vecStage = DatabaseController::instance().GetStages(sOrgName);
	for (const auto& sStage : vecStage)
	{
		ui.comboBox_Progress->addItem(QString::fromStdString(sStage));
	}
}

void AddTournamentDialog::on_CancelButton_clicked()
{
	close();
}
void AddTournamentDialog::on_SaveButton_clicked()
{
	Tournament t;
	t.SetOrganizationName(m_sOrgName.toStdString());
	t.SetType(m_sType.toStdString());
	m_sTeammate = ui.radioButton_Double->isChecked() ? ui.lineEdit_Teammate->text() : "";
	t.SetTeammate(m_sTeammate.toStdString());
	t.SetCategory(m_sCategory.toStdString());
	t.SetSeason((m_sYear + " " + m_sSeason).toStdString());
	m_sParticipant = ui.lineEdit_Participant->text();
	t.SetParticipant(stoi(m_sParticipant.toStdString()));
	t.SetCompleted(ui.checkBox_Completion->isChecked());
	m_sProgress = (ui.checkBox_Completion->isChecked()) ? ui.comboBox_Progress->currentText() : "";
	t.SetProgress(m_sProgress.toStdString());
	DatabaseController::instance().AddTournament(t);
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

void AddTournamentDialog::on_comboBox_Category_currentTextChanged(const QString& category)
{
	m_sCategory = category;
}

void AddTournamentDialog::on_comboBox_Year_currentTextChanged(const QString& year)
{
	m_sYear = year;
}

void AddTournamentDialog::on_comboBox_Season_currentTextChanged(const QString& season)
{
	m_sSeason = season;
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
void AddTournamentDialog::on_comboBox_OrganizationName_currentTextChanged(const QString& org)
{
	m_sOrgName = org;
	if (org == "")
	{
		DeactivateOptions();
	}
	else
	{
		ActivateOptions();
		SetCategoryAlternatives(org.toStdString());
		SetStageAlternatives(org.toStdString());
	}
}
