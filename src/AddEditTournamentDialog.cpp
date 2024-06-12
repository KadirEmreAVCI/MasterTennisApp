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
	QObject::connect(&AppController::instance(), &AppController::OrganizationAdded, this, &AddEditTournamentDialog::UpdateOrganizationOptions);
	m_sType = "Single";
	InitCustomComponents();
}

AddEditTournamentDialog::~AddEditTournamentDialog()
{}

void AddEditTournamentDialog::InitCustomComponents()
{
	ClearDialog();
	SetComboBoxAlternatives(ui.comboBox_OrganizationName, AppController::instance().GetOrgNames());
}
void AddEditTournamentDialog::ClearDialog()
{
	m_sOrgName = "";
	m_sCategory = "";
	m_sYear = "";
	m_sSeason = "";
	m_uiSetsBestOf = 0;
	on_radioButton_Single_clicked();
	InitComboBox(ui.comboBox_OrganizationName, "");
	InitComboBox(ui.comboBox_Category, "");
	InitComboBox(ui.comboBox_Year, "");
	InitComboBox(ui.comboBox_Season, "");
	ui.spinBox_Participant->setValue(0);
	ui.checkBox_Completion->setChecked(Qt::Unchecked);
	ui.checkBox_3rdPlaceGameAvailable->setChecked(Qt::Unchecked);
	ui.spinBox_GamesToWin->setValue(0);
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
	ui.comboBox_SetsBestOf->setEnabled(false);
	ui.spinBox_Participant->setEnabled(false);
	ui.checkBox_Completion->setEnabled(false);
	ui.checkBox_3rdPlaceGameAvailable->setEnabled(false);
	ui.spinBox_GamesToWin->setEnabled(false);
}
void AddEditTournamentDialog::ActivateOptions()
{
	ui.radioButton_Single->setEnabled(true);
	ui.radioButton_Double->setEnabled(true);
	ui.lineEdit_Teammate->setEnabled(false);
	ui.comboBox_Category->setEnabled(true);
	ui.comboBox_Year->setEnabled(true);
	ui.comboBox_Season->setEnabled(true);
	ui.comboBox_SetsBestOf->setEnabled(true);
	ui.spinBox_Participant->setEnabled(true);
	ui.checkBox_Completion->setEnabled(true);
	ui.checkBox_3rdPlaceGameAvailable->setEnabled(true);
	ui.spinBox_GamesToWin->setEnabled(true);
}

bool AddEditTournamentDialog::MandatoryFieldsFilled()const
{
	return m_sOrgName != "" 
		&& m_sType != "" 
		&& (ui.radioButton_Single->isChecked() || (ui.radioButton_Double->isChecked() && ui.lineEdit_Teammate->text() != ""))
		&& m_sCategory != "" 
		&& m_sYear != "" 
		&& m_sSeason != "" 
		&& m_uiSetsBestOf != 0
		&& ui.spinBox_Participant->value() != 0
		&& ui.spinBox_GamesToWin->value() != 0;
}

bool AddEditTournamentDialog::MaxParticipantExceeded(unsigned uiParticipant)const
{
	return (uiParticipant > m_uiMaxParticipant);
}

void AddEditTournamentDialog::InitDialogWithTournament(const Tournament& t)
{
	m_uiTournamentID = t.GetID();
	m_sOrgName = QString::fromStdString(t.GetOrgName());
	InitComboBox(ui.comboBox_OrganizationName, m_sOrgName);
	m_sCategory = QString::fromStdString(t.GetCategory());
	InitComboBox(ui.comboBox_Category, m_sCategory);
	m_uiSetsBestOf = t.GetSetsBestOf();
	InitSetsBestOfComboBox(m_uiSetsBestOf);
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
	ui.checkBox_3rdPlaceGameAvailable->setChecked(t.Get3rdPlaceGameAvailable());
	ui.lineEdit_Teammate->setText(QString::fromStdString(t.GetTeammate()));
	ui.spinBox_Participant->setValue(t.GetParticipant());
	ui.spinBox_GamesToWin->setValue(t.GetGamesToWin());
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

void AddEditTournamentDialog::InitSetsBestOfComboBox(unsigned uiSetsBestOf)
{
	QString sSetsBestOf{ "" };
	if (uiSetsBestOf == 1)
		sSetsBestOf = "Best Of 1";
	else if (uiSetsBestOf == 3)
		sSetsBestOf = "Best Of 3";
	else if (uiSetsBestOf == 5)
		sSetsBestOf = "Best Of 5";
	else if (uiSetsBestOf == 7)
		sSetsBestOf = "Best Of 7";
	else
		std::cout << "AddEditTournamentDialog::InitSetsBestOfComboBox Unknown SetsBestOf!\n";
	
	InitComboBox(ui.comboBox_SetsBestOf, sSetsBestOf);
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
		if (!MaxParticipantExceeded(ui.spinBox_Participant->value()))
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
			t.SetParticipant(ui.spinBox_Participant->value());
			t.SetCompleted(ui.checkBox_Completion->isChecked());
			t.Set3rdPlaceGameAvailable(ui.checkBox_3rdPlaceGameAvailable->isChecked());
			t.SetSetsBestOf(m_uiSetsBestOf);
			t.SetGamesToWin(ui.spinBox_GamesToWin->value());
			if (m_DialogMode == DialogMode::eAddDialog)
			{
				if(AppController::instance().AddNewTournament(t))
					QMessageBox::information(this, "Information", "New tournament is added successfully");
			}
			else if (m_DialogMode == DialogMode::eEditDialog)
			{
				if(AppController::instance().EditTournament(t))
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
			std::string sMessage = "Cannot exceed max number of participant(" + std::to_string(m_uiMaxParticipant) + ")";
			QMessageBox::critical(this, "Error", QString::fromStdString(sMessage));
		}
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
		SetComboBoxAlternatives(ui.comboBox_Category, AppController::instance().GetCategories(org.toStdString()));
	}
}
void AddEditTournamentDialog::on_comboBox_SetsBestOf_currentTextChanged(const QString& setsbestof)
{
	if (setsbestof == "Best Of 1")
		m_uiSetsBestOf = 1;
	else if (setsbestof == "Best Of 3")
		m_uiSetsBestOf = 3;
	else if (setsbestof == "Best Of 5")
		m_uiSetsBestOf = 5;
	else if (setsbestof == "Best Of 7")
		m_uiSetsBestOf = 7;
	else
		std::cout << "AddEditTournamentDialog::on_comboBox_SetsBestOf_currentTextChanged Unknown SetsBestOf\n";
}
void AddEditTournamentDialog::UpdateOrganizationOptions()
{
	InitCustomComponents();
}