#pragma once

#include <QDialog>
#include "ui_CreateTournamentDialog.h"
#include "IQTComponent.h"
class CreateTournamentDialog : public QDialog, public IQTComponent
{
	Q_OBJECT

public:
	CreateTournamentDialog(QWidget *parent = nullptr);
	~CreateTournamentDialog();

private:
	void InitCustomComponents() override final;
	bool MandatoryFieldsFilled()const;
	std::vector<std::string> Deserialize(std::string str)const;
	Ui::CreateTournamentDialogClass ui;
private slots:
	void on_SaveButton_clicked();
	void on_CancelButton_clicked();
};
