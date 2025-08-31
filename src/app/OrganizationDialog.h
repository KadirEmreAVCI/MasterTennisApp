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
	
	void InsertOrg2Table(const Organization& org, unsigned uiRowIdx);
	std::string Serialize(const std::vector<std::string>&)const;
	void UpdateOrganizations(const std::vector<Organization>&);
	void OpenAddDialog();
	void OpenEditDialog(const Organization& org);
	void InsertButtonWithImage2Cell(const std::string& sImageAddr, float fScale, auto func, bool blEnabled, unsigned uiRowIdx, unsigned uiColumnIdx);
	Organization FindSignalingOrganization()const;
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