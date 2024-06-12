#pragma once

#include <QDialog>
#include "ui_AddDialog.h"
#include "IQTComponent.h"

class AddDialog : public QDialog, public IQTComponent
{
	Q_OBJECT

public:
	AddDialog(QWidget *parent = nullptr);
	~AddDialog();
	void InitCustomComponents() override final;

private:
	bool IsAnyOptionSelected()const;
	Ui::AddDialogClass ui;
private slots:
	void on_OKButton_clicked();
	void on_CancelButton_clicked();
signals:
	// Signal functions are just declared, not defined by programmers!
	void AddOrganizationRequest();
	void AddTournamentRequest();
	void AddMatchRequest();
};
