#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <QTableView>
#include <QMessageBox>
#include "AddEditTournamentDialog.h"
#include "AppController.h"

AddEditTournamentDialog::AddEditTournamentDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(&AppController::instance(), &AppController::OrganizationAdded, this, &AddEditTournamentDialog::UpdateOrganizations);
	m_sType = "Single";
	InitCustomComponents();
}

AddEditTournamentDialog::~AddEditTournamentDialog()
{}

void AddEditTournamentDialog::InitCustomComponents()
{
	ClearDialog();
	SetOrganizationAlternatives();
}
void AddEditTournamentDialog::ClearDialog()
{
	m_sOrgName = "";
	m_sCategory = "";
	m_sYear = "";
	m_sSeason = "";
	on_radioButton_Single_clicked();
	InitComboBox(ui.comboBox_OrganizationName, "");
	InitComboBox(ui.comboBox_Category, "");
	InitComboBox(ui.comboBox_Year, "");
	InitComboBox(ui.comboBox_Season, "");
	ui.lineEdit_Participant->setText("");
	ui.checkBox_Completion->setChecked(Qt::Unchecked);
	DeactivateOptions();
}
void AddEditTournamentDialog::DeactivateOptions()
{
	ui.radioButton_Single->setEnabled(false);
	ui.radioButton_Double->setEnabled(false);
	ui.lineEdit_Teammate->setEnabled(false);
	ui.comboBox_Category->setEnabled(false);
	ui.comboBox_Year->setEnabled(false);
	ui.comboBox_Season->setEnabled(false);
	ui.lineEdit_Participant->setEnabled(false);
	ui.checkBox_Completion->setEnabled(false);
}
void AddEditTournamentDialog::ActivateOptions()
{
	ui.radioButton_Single->setEnabled(true);
	ui.radioButton_Double->setEnabled(true);
	ui.lineEdit_Teammate->setEnabled(false);
	ui.comboBox_Category->setEnabled(true);
	ui.comboBox_Year->setEnabled(true);
	ui.comboBox_Season->setEnabled(true);
	ui.lineEdit_Participant->setEnabled(true);
	ui.checkBox_Completion->setEnabled(true);
}

void AddEditTournamentDialog::SetOrganizationAlternatives()
{
	ui.comboBox_OrganizationName->clear();
	ui.comboBox_OrganizationName->addItem("");
	const auto& vecOrgName = AppController::instance().GetOrgNames();
	for (const auto& sOrgName : vecOrgName)
	{
		ui.comboBox_OrganizationName->addItem(QString::fromStdString(sOrgName));
	}
}

void AddEditTournamentDialog::SetCategoryAlternatives(std::string sOrgName)
{
	ui.comboBox_Category->clear();
	ui.comboBox_Category->addItem("");
	const auto& vecCategory = AppController::instance().GetCategories(sOrgName);
	for (const auto& sCategory : vecCategory)
	{
		ui.comboBox_Category->addItem(QString::fromStdString(sCategory));
	}
}

bool AddEditTournamentDialog::MandatoryFieldsFilled()const
{
	return m_sOrgName != "" 
		&& m_sType != "" 
		&& (ui.radioButton_Single->isChecked() || (ui.radioButton_Double->isChecked() && ui.lineEdit_Teammate->text() != ""))
		&& m_sCategory != "" 
		&& m_sYear != "" 
		&& m_sSeason != "" 
		&& ui.lineEdit_Participant->text() != "";
}

void AddEditTournamentDialog::InitDialogWithTournament(const Tournament& t)
{
	m_uiTournamentID = t.GetID();
	m_sOrgName = QString::fromStdString(t.GetOrgName());
	InitComboBox(ui.comboBox_OrganizationName, m_sOrgName);
	m_sCategory = QString::fromStdString(t.GetCategory());
	InitComboBox(ui.comboBox_Category, m_sCategory);
	std::string sMixSeason = t.GetSeason();
	size_t pos = sMixSeason.find(' ');
	if (pos != std::string::npos)
	{
		m_sYear = QString::fromStdString(sMixSeason.substr(0, pos));
		InitComboBox(ui.comboBox_Year, m_sYear);
		m_sSeason = QString::fromStdString(sMixSeason.substr(pos + 1));
		InitComboBox(ui.comboBox_Season, m_sSeason);
	}
	ui.checkBox_Completion->setChecked(t.GetCompleted());
	ui.lineEdit_Teammate->setText(QString::fromStdString(t.GetTeammate()));
	ui.lineEdit_Participant->setText(QString::fromStdString(std::to_string(t.GetParticipant())));
	m_sType = QString::fromStdString(t.GetType());
	if (m_sType == "Single")
	{
		on_radioButton_Single_clicked();
	}
	else
	{
		on_radioButton_Double_clicked();
	}
}

void AddEditTournamentDialog::SetDialogMode(DialogMode mode, const Tournament& t)
{
	using enum DialogMode;
	m_DialogMode = mode;
	switch (m_DialogMode)
	{
	case eAddDialog:
	{
		setWindowTitle("Add Tournament");
		ClearDialog();
		break;
	}
	case eEditDialog:
	{
		setWindowTitle("Edit Tournament");
		InitDialogWithTournament(t);
		break;
	}
	default:
		std::cout << "AddTournamentDialog::SetDialogMode unknown DialogMode!\n";
	}
}

void AddEditTournamentDialog::InitComboBox(QComboBox* pComboBox, const QString& sVal)
{
	const size_t idx = pComboBox->findText(sVal);
	if (idx != -1) { // Check if the item was found
		pComboBox->setCurrentIndex(idx);
	}
	else
	{
		pComboBox->setCurrentIndex(0);
	}
}

void AddEditTournamentDialog::on_CancelButton_clicked()
{
	close();
	ClearDialog();
}
void AddEditTournamentDialog::on_SaveButton_clicked()
{
	if (MandatoryFieldsFilled())
	{
		close();
		Tournament t;
		t.SetID(m_uiTournamentID);
		t.SetOrgName(m_sOrgName.toStdString());
		t.SetSeason((m_sYear + " " + m_sSeason).toStdString());
		t.SetCategory(m_sCategory.toStdString());
		t.SetType(m_sType.toStdString());
		m_sTeammate = ui.radioButton_Double->isChecked() ? ui.lineEdit_Teammate->text() : "";
		t.SetTeammate(m_sTeammate.toStdString());
		m_sParticipant = ui.lineEdit_Participant->text();
		t.SetParticipant(stoi(m_sParticipant.toStdString()));
		t.SetCompleted(ui.checkBox_Completion->isChecked());
		if (m_DialogMode == DialogMode::eAddDialog)
		{
			AppController::instance().AddNewTournament(t);
			QMessageBox::information(this, "Information", "New tournament is added successfully");
		}
		else if (m_DialogMode == DialogMode::eEditDialog)
		{
			AppController::instance().EditTournament(t);
			QMessageBox::information(this, "Information", "Tournament edited successfully");
		}
		else
		{
			std::cout << "AddTournamentDialog::on_SaveButton_clicked unknown DialogMode!\n";
		}
		ClearDialog();
	}
	else
	{
		QMessageBox::critical(this, "Error", "Please fill all the mandatory fields.");
	}
}
void AddEditTournamentDialog::on_radioButton_Single_clicked()
{
	m_sTeammate = "";
	ui.lineEdit_Teammate->setText(m_sTeammate);
	ui.lineEdit_Teammate->setEnabled(false);
	ui.radioButton_Single->setChecked(true);
	ui.radioButton_Double->setChecked(false);
	m_sType = "Single";
}
void AddEditTournamentDialog::on_radioButton_Double_clicked()
{
	ui.lineEdit_Teammate->setEnabled(true);
	ui.radioButton_Single->setChecked(false);
	ui.radioButton_Double->setChecked(true);
	m_sType = "Double";
}

void AddEditTournamentDialog::on_comboBox_Category_currentTextChanged(const QString& category)
{
	m_sCategory = category;
}

void AddEditTournamentDialog::on_comboBox_Year_currentTextChanged(const QString& year)
{
	m_sYear = year;
}

void AddEditTournamentDialog::on_comboBox_Season_currentTextChanged(const QString& season)
{
	m_sSeason = season;
}
void AddEditTournamentDialog::on_checkBox_Completion_stateChanged(int arg)
{
	if (arg == 0)
	{
		m_sCompletion = "0";
	}
	else
	{
		m_sCompletion = "1";
	}
}
void AddEditTournamentDialog::on_comboBox_OrganizationName_currentTextChanged(const QString& org)
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
	}
}
void AddEditTournamentDialog::UpdateOrganizations()
{
	InitCustomComponents();
}