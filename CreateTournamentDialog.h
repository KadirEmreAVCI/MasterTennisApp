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
	bool MandatoryFieldsFilled();
	Ui::CreateTournamentDialogClass ui;
	QString m_sOrganizationName, m_sType, m_sCategories, m_Stages;
private slots:
	void on_SaveButton_clicked();
	void on_CancelButton_clicked();
	void on_comboBox_Type_currentTextChanged(const QString& arg);
};
