#ifndef ADDEDITORGANIZATIONDIALOG_H
#define ADDEDITORGANIZATIONDIALOG_H

#include <QDialog>
#include "ui_AddEditOrganizationDialog.h"
#include "AddEditDialog.h"
#include "Organization.h"

class AddEditOrganizationDialog : public QDialog, public AddEditDialog<Organization>
{
	Q_OBJECT

public:
	AddEditOrganizationDialog(QWidget *parent = nullptr);
	~AddEditOrganizationDialog();
private:
	virtual void InitDialog()override;
	virtual void FillDialog()override;
	virtual void ClearDialog()override;
	virtual bool IsMandatoryFieldsFilled()const override;
	virtual bool IsThereAnyUnsavedInfo()const override;
	void ClearCategoryCheckboxes();
	Ui::AddEditOrganizationDialogClass ui;
	std::vector<QCheckBox*> m_vecCategoryCheckboxes;
	std::vector<std::string> m_vecCategories;
	
private slots:
	void on_SaveButton_clicked();
	void on_CancelButton_clicked();
	void on_ApplyButton_clicked();
	void on_ClearButton_clicked();
};

#endif