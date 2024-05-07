#include "AddTournamentDialog.h"

AddTournamentDialog::AddTournamentDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

AddTournamentDialog::~AddTournamentDialog()
{}

void AddTournamentDialog::on_CancelButton_clicked()
{
	close();
}
