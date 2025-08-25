#ifndef ADDEDITORGANIZATIONDIALOG_H
#define ADDEDITORGANIZATIONDIALOG_H

#include <QDialog>
#include "ui_AddEditOrganizationDialog.h"
#include "IQTComponent.h"
#include "AddEditDialog.h"
#include "Organization.h"

class AddEditOrganizationDialog : public QDialog, public IQTComponent, public AddEditDialog
{
	Q_OBJECT

public:
	AddEditOrganizationDialog(QWidget *parent = nullptr);
	~AddEditOrganizationDialog();
	void PrepareDialog(DialogMode mode, const Organization& org = Organization{});
private:
	void InitCustomComponents() override final;
	virtual void InitDialog()override;
	virtual void FillDialog()override;
	virtual void ClearDialog()override;
	virtual bool IsMandatoryFieldsFilled()const override;
	virtual bool IsThereAnyUnsavedInfo()const override;
	std::string Serialize(const std::vector<std::string>& vecDeserialized)const;
	void ClearCategoryCheckboxes();
	Ui::AddEditOrganizationDialogClass ui;
	Organization m_EditedOrganization;
	std::vector<QCheckBox*> m_vecCategoryCheckboxes;
	std::vector<std::string> m_vecCategories;
	
private slots:
	void on_SaveButton_clicked();
	void on_CancelButton_clicked();
	void on_ApplyButton_clicked();
	void on_ClearButton_clicked();
	void on_BrowseButton_clicked();
	void on_DefaultPPButton_clicked();
};

#endif