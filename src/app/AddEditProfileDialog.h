#ifndef ADDEDITPROFILEDIALOG_H
#define ADDEDITPROFILEDIALOG_H

#include <QDialog>
#include "ui_AddEditProfileDialog.h"
#include "IQTComponent.h"
#include "AddEditDialog.h"
#include "Profile.h"

class AddEditProfileDialog : public QDialog, public IQTComponent, public AddEditDialog
{
	Q_OBJECT

public:
	AddEditProfileDialog(QWidget *parent = nullptr);
	~AddEditProfileDialog();
	void PrepareDialog(DialogMode, const Profile& p = Profile{});

private:
	void InitCustomComponents() override final;
	virtual void InitDialog()override;
	virtual void FillDialog()override;
	virtual void ClearDialog()override;
	virtual bool IsMandatoryFieldsFilled()const override;
	virtual bool IsThereAnyUnsavedInfo()const override;
	Ui::AddEditProfileDialogClass ui;
	Profile m_EditedProfile;
private slots:
	void on_BrowseButton_clicked();
	void on_DefaultPPButton_clicked();
	void on_SaveButton_clicked();
	void on_CancelButton_clicked();
};

#endif