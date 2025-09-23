#ifndef ORGANIZATIONDIALOG_H
#define ORGANIZATIONDIALOG_H

#include <memory>
#include <QDialog>
#include "ui_OrganizationDialog.h"
#include "TableWidgetUser.h"
#include "Organization.h"
#include "AddEditOrganizationDialog.h"

class OrganizationDialog : public QDialog, public TableWidgetUser
{
	Q_OBJECT

public:
	OrganizationDialog(QWidget *parent = nullptr);
	~OrganizationDialog();
	void DisplayOrganizations();
private:
	// TableWidgetUser
	virtual void LoadDataToTable()override;
	virtual void FillTable()override;
	void PlaceOrg2Table(const Organization& org, unsigned uiRowIdx);
	void UpdateOrganizations(const std::vector<Organization>&);
	Ui::OrganizationDialogClass ui;
	std::unique_ptr<AddEditOrganizationDialog> m_upAddEditOrganizationDialog;
	std::vector<Organization> m_vecOrganization;
private slots:
	void on_NewOrganizationButton_clicked();
public slots:
	void EditOrganization();
	void DeleteOrganization();
};

#endif