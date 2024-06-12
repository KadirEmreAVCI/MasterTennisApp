#include <QMessageBox>
#include "CreateTournamentDialog.h"
#include "AppController.h"
#include "Organization.h"

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

}

bool CreateTournamentDialog::MandatoryFieldsFilled()const
{
	return ui.lineEdit_OrganizationName->text() != "" && ui.lineEdit_Categories->text() != "";
}

std::vector<std::string> CreateTournamentDialog::Deserialize(std::string str)const
{
	std::vector<std::string> vec;
	std::istringstream iss(str);
	std::string sItem;
	while (std::getline(iss, sItem, ',')) {
		vec.push_back(std::move(sItem));
	}
	return vec;
}

void CreateTournamentDialog::on_SaveButton_clicked()
{
	if (MandatoryFieldsFilled())
	{
		Organization org;
		org.SetName(ui.lineEdit_OrganizationName->text().toStdString());
		org.SetCategories(Deserialize(ui.lineEdit_Categories->text().toStdString()));
		AppController::instance().AddNewOrganization(org);
		QMessageBox::information(this, "Information", "New organization is added successfully");
		close();
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

