#ifndef ADDEDITPROFILEDIALOG_H
#define ADDEDITPROFILEDIALOG_H

#include <QDialog>
#include "ui_AddEditProfileDialog.h"
#include "AddEditDialog.h"
#include "Profile.h"

class AddEditProfileDialog : public QDialog, public AddEditDialog<Profile>
{
	Q_OBJECT

public:
	AddEditProfileDialog(QWidget *parent = nullptr);
	~AddEditProfileDialog();
private:
	virtual void InitDialog()override;
	virtual void FillDialog()override;
	virtual void ClearDialog()override;
	virtual bool IsMandatoryFieldsFilled()const override;
	virtual bool IsThereAnyUnsavedInfo()const override;
	Ui::AddEditProfileDialogClass ui;
private slots:
	void on_SaveButton_clicked();
	void on_CancelButton_clicked();
};

#endif