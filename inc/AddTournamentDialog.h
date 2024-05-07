#pragma once

#include <QDialog>
#include "ui_AddTournamentDialog.h"

class AddTournamentDialog : public QDialog
{
	Q_OBJECT

public:
	AddTournamentDialog(QWidget *parent = nullptr);
	~AddTournamentDialog();

private:
	Ui::AddTournamentDialogClass ui;
private slots:
	void on_CancelButton_clicked();
};
