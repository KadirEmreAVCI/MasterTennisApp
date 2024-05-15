#include <QMessageBox>
#include "CreateTournamentDialog.h"
#include "SQLiteDB.h"

CreateTournamentDialog::CreateTournamentDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	InitCustomComponents();
}

CreateTournamentDialog::~CreateTournamentDialog()
{}

void CreateTournamentDialog::InitCustomComponents()
{
	m_sType = "Tournament";
}

bool CreateTournamentDialog::MandatoryFieldsFilled()
{
	return m_sOrganizationName != "" && m_sCategories != "" && m_Stages != "";
}

void CreateTournamentDialog::on_SaveButton_clicked()
{
	m_sOrganizationName = ui.lineEdit_OrganizationName->text();
	m_sCategories = ui.lineEdit_Categories->text();
	m_Stages = ui.lineEdit_Stages->text();
	if (MandatoryFieldsFilled())
	{
		QString sColumns{ "Name,Type,Categories,Stages" };
		QString sValues{ "'" + m_sOrganizationName + "','" + m_sType + "','" + m_sCategories + "','" + m_Stages + "'" };
		SQLiteDB::instance().InsertRowToTable("Organization", sColumns.toStdString(), sValues.toStdString());
	}
	else
	{
		QMessageBox::critical(this, "Error", "Please fill all the mandatory fields.");
	}
}

void CreateTournamentDialog::on_CancelButton_clicked()
{
	close();
}

void CreateTournamentDialog::on_comboBox_Type_currentTextChanged(const QString& arg)
{
	m_sType = arg;
}
