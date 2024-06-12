#include <iostream>
#include <QMessageBox>
#include "AddDialog.h"


AddDialog::AddDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	InitCustomComponents();
}

AddDialog::~AddDialog()
{}

void AddDialog::InitCustomComponents()
{
	ui.radioButton_Organization->setChecked(false);
	ui.radioButton_Tournament->setChecked(false);
	ui.radioButton_Match->setChecked(false);
}

bool AddDialog::IsAnyOptionSelected()const
{
	return ui.radioButton_Organization->isChecked() || ui.radioButton_Tournament->isChecked() || ui.radioButton_Match->isChecked();
}

void AddDialog::on_OKButton_clicked()
{
	if (IsAnyOptionSelected())
	{
		close();
		if (ui.radioButton_Organization->isChecked())
		{
			emit AddOrganizationRequest();
		}
		else if (ui.radioButton_Tournament->isChecked())
		{
			emit AddTournamentRequest();
		}
		else if (ui.radioButton_Match->isChecked())
		{
			emit AddMatchRequest();
		}
		else
		{
			std::cerr << "Error! Undefined item to add!\n";
		}
	}
	else
	{
		QMessageBox::critical(this, "Error", "Please select an item to add!");
	}
}

void AddDialog::on_CancelButton_clicked()
{
	close();
}