#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <QTableView>
#include <QMessageBox>
#include "AddEditTournamentDialog.h"
#include "AppController.h"
#include "Utility.h"

AddEditTournamentDialog::AddEditTournamentDialog(QWidget *parent)
	: QDialog(parent), AddEditDialog<Tournament>(this)
{
	ui.setupUi(this);
	QObject::connect(&AppController::instance(), &AppController::DBInitialized, this, &AddEditTournamentDialog::DBInitialized);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &AddEditTournamentDialog::UpdateActiveProfileData);
	QObject::connect(&AppController::instance(), &AppController::ChangeInDB, this, &AddEditTournamentDialog::ChangeInDB);
	ClearDialog();
	setFixedHeight(250);
	const unsigned int uiFixedWidth = 120;
	ui.comboBox_Type->setFixedWidth(uiFixedWidth);
	ui.comboBox_Category->setFixedWidth(uiFixedWidth);
	ui.spinBox_Year->setFixedWidth(uiFixedWidth);
	ui.comboBox_Season->setFixedWidth(uiFixedWidth);
	ui.spinBox_Participant->setFixedWidth(uiFixedWidth);
	ui.comboBox_SetsBestOf->setFixedWidth(uiFixedWidth);
}
AddEditTournamentDialog::~AddEditTournamentDialog()
{}
void AddEditTournamentDialog::ClearDialog()
{
	using namespace utility;
	m_sOrgName = "";
	m_sCategory = "";
	m_sSeason = "";
	m_sType = "";
	m_uiSetsBestOf = 0;
	InitComboBox(ui.comboBox_OrganizationName, "");
	InitComboBox(ui.comboBox_Category, "");
	ui.spinBox_Year->setValue(QDate::currentDate().year());
	InitComboBox(ui.comboBox_Season, "");
	InitComboBox(ui.comboBox_Type, "");
	ui.spinBox_Participant->setValue(0);
	ui.checkBox_3rdPlaceGameAvailable->setChecked(Qt::Unchecked);
	InitComboBox(ui.comboBox_SetsBestOf);
	DeactivateOptions();
}
void AddEditTournamentDialog::InitDialog()
{
	ClearDialog();
}
void AddEditTournamentDialog::DeactivateOptions()
{
	ui.comboBox_Type->setEnabled(false);
	ui.lineEdit_Teammate->setEnabled(false);
	ui.comboBox_Category->setEnabled(false);
	ui.spinBox_Year->setEnabled(false);
	ui.comboBox_Season->setEnabled(false);
	ui.comboBox_SetsBestOf->setEnabled(false);
	ui.spinBox_Participant->setEnabled(false);
	ui.checkBox_3rdPlaceGameAvailable->setEnabled(false);
}
void AddEditTournamentDialog::ActivateOptions()
{
	ui.comboBox_Type->setEnabled(true);
	ui.lineEdit_Teammate->setEnabled(false);
	ui.comboBox_Category->setEnabled(true);
	ui.spinBox_Year->setEnabled(true);
	ui.comboBox_Season->setEnabled(true);
	ui.comboBox_SetsBestOf->setEnabled(true);
	ui.spinBox_Participant->setEnabled(true);
	ui.checkBox_3rdPlaceGameAvailable->setEnabled(true);
}
bool AddEditTournamentDialog::IsMandatoryFieldsFilled()const
{
	return m_sOrgName != ""
		&& m_sType != ""
		&& (!IsDoubleTournament() || (IsDoubleTournament() && ui.lineEdit_Teammate->text() != ""))
		&& m_sCategory != ""
		&& ui.spinBox_Year->value() != 0
		&& m_sSeason != ""
		&& m_uiSetsBestOf != 0
		&& ui.spinBox_Participant->value() != 0;
}
bool AddEditTournamentDialog::IsThereAnyUnsavedInfo()const
{
	return m_sOrgName != ""
		|| m_sType != ""
		|| (IsDoubleTournament() && ui.lineEdit_Teammate->text() != "")
		|| m_sCategory != ""
		|| ui.spinBox_Year->value() != QDate::currentDate().year()
		|| m_sSeason != ""
		|| m_uiSetsBestOf != 0
		|| ui.spinBox_Participant->value() != 0;
}
bool AddEditTournamentDialog::IsMaxParticipantExceeded(unsigned uiParticipant)const
{
	return (uiParticipant > m_uiMaxParticipant);
}
void AddEditTournamentDialog::FillDialog()
{
	using namespace utility;
	m_uiOrgID = m_EditedItem.GetOrgID();
	m_sOrgName = QString::fromStdString(DatabaseController::instance().FindRootOrganization(m_EditedItem).GetName());
	InitComboBox(ui.comboBox_OrganizationName, m_sOrgName);
	m_sCategory = QString::fromStdString(m_EditedItem.GetCategory());
	InitComboBox(ui.comboBox_Category, m_sCategory);
	m_sType = QString::fromStdString(m_EditedItem.GetType());
	if (IsDoubleTournament())
	{
		ui.lineEdit_Teammate->setEnabled(true);
	}
	else
	{
		ui.lineEdit_Teammate->setEnabled(false);
	}
	InitComboBox(ui.comboBox_Type, m_sType);
	m_uiSetsBestOf = m_EditedItem.GetSetsBestOf();
	InitSetsBestOfComboBox(m_uiSetsBestOf);
	std::string sMixSeason = m_EditedItem.GetSeason();
	if (size_t pos = sMixSeason.find(' '); pos != std::string::npos)
	{
		const std::string& sYear = sMixSeason.substr(0, pos);
		ui.spinBox_Year->setValue(std::stoi(sYear));
		m_sSeason = QString::fromStdString(sMixSeason.substr(pos + 1));
		InitComboBox(ui.comboBox_Season, m_sSeason);
	}
	ui.checkBox_3rdPlaceGameAvailable->setChecked(m_EditedItem.Get3rdPlaceGameAvailable());
	m_sTeammate = QString::fromStdString(m_EditedItem.GetTeammate());
	ui.lineEdit_Teammate->setText(QString::fromStdString(m_EditedItem.GetTeammate()));
	ui.spinBox_Participant->setValue(m_EditedItem.GetParticipant());
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
	
	utility::InitComboBox(ui.comboBox_SetsBestOf, sSetsBestOf);
}
bool AddEditTournamentDialog::IsDoubleTournament()const
{
	return m_sType.toStdString().find("Double") != std::string::npos;
}
void AddEditTournamentDialog::DBInitialized(const std::vector<Profile>&, const std::vector<Organization>& vecOrganization)
{
	UpdateOrganizations(vecOrganization);
}
void AddEditTournamentDialog::ChangeInDB(const std::vector<Profile>&, const std::vector<Organization>& vecOrganization, const std::vector<Tournament>&, const std::vector<Match>&)
{
	UpdateOrganizations(vecOrganization);
}
void AddEditTournamentDialog::on_CancelButton_clicked()
{
	if (IsThereAnyUnsavedInfo() && m_DialogMode != DialogMode::eEditDialog)
	{
		QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Cancellation", "Are you sure you want to cancel? All unsaved information will be lost.", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			close();
		}
	}
	else
	{
		close();
	}
}
void AddEditTournamentDialog::on_SaveButton_clicked()
{
	if (IsMandatoryFieldsFilled())
	{
		close();
		Tournament t{
			m_EditedItem.GetID(),
			m_ActiveProfile.GetID(),
			m_uiOrgID,
			m_sOrgName.toStdString(),
			(QString::number(ui.spinBox_Year->value()) + " " + m_sSeason).toStdString(),
			m_sCategory.toStdString(),
			m_sType.toStdString(),
			(IsDoubleTournament() ? std::optional<std::string>(ui.lineEdit_Teammate->text().toStdString()) : std::nullopt),
			static_cast<unsigned>(ui.spinBox_Participant->value()),
			m_EditedItem.IsLocked(),
			ui.checkBox_3rdPlaceGameAvailable->isChecked(),
			m_uiSetsBestOf
		};
		if (t.IsValid())
		{
			if (m_DialogMode == DialogMode::eAddDialog)
			{
				if (AppController::instance().AddNewItem(t))
					QMessageBox::information(this, "Information", "New tournament is added successfully");
			}
			else if (m_DialogMode == DialogMode::eEditDialog)
			{
				if (AppController::instance().EditItem(t))
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
			QMessageBox::critical(this, "Error", "Invalid tournament.");
		}
	}
	else
	{
		QMessageBox::critical(this, "Error", "Please fill all the mandatory fields.");
	}
}
void AddEditTournamentDialog::on_comboBox_Type_currentTextChanged(const QString& type)
{
	m_sType = type;
	if (IsDoubleTournament())
	{
		ui.lineEdit_Teammate->setEnabled(true);
	}
	else
	{
		m_sTeammate = "";
		ui.lineEdit_Teammate->setText(m_sTeammate);
		ui.lineEdit_Teammate->setEnabled(false);
	}
}
void AddEditTournamentDialog::on_comboBox_Category_currentTextChanged(const QString& category)
{
	m_sCategory = category;
}
void AddEditTournamentDialog::on_comboBox_Season_currentTextChanged(const QString& season)
{
	m_sSeason = season;
}
void AddEditTournamentDialog::on_comboBox_OrganizationName_currentTextChanged(const QString& orgName)
{
	m_sOrgName = orgName;
	if (orgName == "")
	{
		DeactivateOptions();
	}
	else
	{
		ActivateOptions();
		const auto& iterOrg = std::find_if(m_vecOrganization.cbegin(), m_vecOrganization.cend(), [orgName](const auto& org) {
			return org.GetName() == orgName.toStdString();
			});
		if (iterOrg != m_vecOrganization.end())
		{
			m_uiOrgID = iterOrg->GetID();
			utility::SetComboBoxAlternatives(ui.comboBox_Category, iterOrg->GetCategories());
		}
		else
		{
			std::cerr << "AddEditTournamentDialog::on_comboBox_OrganizationName_currentTextChanged org name could not be found.\n";
		}
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
void AddEditTournamentDialog::UpdateOrganizations(const std::vector<Organization>& vecOrganization)
{
	m_vecOrganization = vecOrganization;
	std::vector<std::string> vecOrgOptions;
	for (const auto& org : m_vecOrganization)
	{
		vecOrgOptions.insert(vecOrgOptions.cend(), org.GetName());
	}
	utility::SetComboBoxAlternatives(ui.comboBox_OrganizationName, vecOrgOptions);
}
void AddEditTournamentDialog::UpdateActiveProfileData(const Profile& p)
{
	m_ActiveProfile = p;
	utility::SetComboBoxAlternatives(ui.comboBox_Type, (m_ActiveProfile.GetGender() == Gender::Male) ? std::vector<std::string>{"Single Men", "Double Men", "Double Mixed"} : std::vector<std::string>{ "Single Women", "Double Women", "Double Mixed" });
}