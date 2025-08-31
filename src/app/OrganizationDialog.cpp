#include <algorithm>
#include <QMessageBox>
#include "OrganizationDialog.h"
#include "AppController.h"
#include "Config.h"
#include "Utility.h"

OrganizationDialog::OrganizationDialog(QWidget *parent)
	: 
	QDialog(parent),
	TableWidgetUser{{ "", " Organization ", " Categories " , "", ""}}
{
	ui.setupUi(this);
	InitTable(ui.tableWidget);
	m_upAddEditOrganizationDialog = std::make_unique<AddEditOrganizationDialog>(this);
	QObject::connect(&AppController::instance(), &AppController::InitOrganizations, this, &OrganizationDialog::UpdateOrganizations);
	QObject::connect(&AppController::instance(), &AppController::ChangeInOrganizations, this, &OrganizationDialog::UpdateOrganizations);
	setWindowTitle("Tennis Organizations");
	setFixedSize(560, 600);
}

OrganizationDialog::~OrganizationDialog()
{}
void OrganizationDialog::DisplayOrganizations()
{
	LoadDataToTable();
}
void OrganizationDialog::LoadDataToTable()
{
	ClearTable();
	FillTable();
}
void OrganizationDialog::FillTable()
{
	unsigned int uiRowIdx{};
	for (const auto& org : m_vecOrganization)
	{
		ui.tableWidget->insertRow(uiRowIdx);
		PlaceOrg2Table(org, uiRowIdx);
		++uiRowIdx;
	}
	ui.tableWidget->resizeRowsToContents();
	ui.tableWidget->resizeColumnsToContents();
}
void OrganizationDialog::PlaceOrg2Table(const Organization& org, unsigned uiRowIdx)
{
	using namespace utility;
	unsigned uiColumnIdx{};
	if (org.GetOrgPictureAddr() != "")
	{
		PlacePic2TableCell(ui.tableWidget, (Organization::GetOrgImageRootDestDir() + QString::fromStdString(org.GetOrgPictureAddr())).toStdString(), 0.1f, uiRowIdx, uiColumnIdx++);
	}
	else
	{
		PlacePic2TableCell(ui.tableWidget, (Organization::GetOrgImageRootDestDir() + "default_org.png").toStdString(), 0.1f, uiRowIdx, uiColumnIdx++);
	}
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(org.GetName()), uiRowIdx, uiColumnIdx++);
	PlaceValue2TableCell(ui.tableWidget, QString::fromStdString(Serialize(org.GetCategories())), uiRowIdx, uiColumnIdx++);
	QObject::connect(PlaceButton2TableCellWithImage(ui.tableWidget, uiRowIdx, uiColumnIdx++, g_cpDeleteButtonPNG,  0.4f, true), &QPushButton::clicked, this, &OrganizationDialog::DeleteOrganization);
	QObject::connect(PlaceButton2TableCellWithImage(ui.tableWidget, uiRowIdx, uiColumnIdx++, g_cpEditButtonPNG,  0.4f, true), &QPushButton::clicked, this, &OrganizationDialog::EditOrganization);
}

void OrganizationDialog::OpenAddDialog()
{
	m_upAddEditOrganizationDialog->setModal(true);
	m_upAddEditOrganizationDialog->PrepareDialog(DialogMode::eAddDialog);
	m_upAddEditOrganizationDialog->exec();
}
void OrganizationDialog::OpenEditDialog(const Organization& org)
{
	m_upAddEditOrganizationDialog->setModal(true);
	m_upAddEditOrganizationDialog->PrepareDialog(DialogMode::eEditDialog, org);
	m_upAddEditOrganizationDialog->exec();
}
Organization OrganizationDialog::FindSignalingOrganization()const
{
	Organization SignalingOrganization;
	QWidget* w = qobject_cast<QWidget*>(sender()->parent());
	if (w)
	{
		const unsigned int uiSignalingRow = ui.tableWidget->indexAt(w->pos()).row();
		SignalingOrganization = m_vecOrganization[uiSignalingRow];
	}
	return SignalingOrganization;
}
void OrganizationDialog::on_NewOrganizationButton_clicked()
{
	OpenAddDialog();
}
void OrganizationDialog::EditOrganization()
{
	auto SignalingOrganization = FindSignalingOrganization();
	OpenEditDialog(SignalingOrganization);
}
void OrganizationDialog::DeleteOrganization()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want delete this organization permanently? All child tournaments and matches will be deleted.", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
		auto SignalingOrganization = FindSignalingOrganization();
		AppController::instance().DeleteOrganization(SignalingOrganization);
		QMessageBox::information(this, "Information", "The organization deleted successfully");
	}
}
void OrganizationDialog::UpdateOrganizations(const std::vector<Organization>& vecOrganization)
{
	std::cout << "OrganizationDialog::UpdateOrganizations!!!!!!!!!!!!!!!\n";
	m_vecOrganization = vecOrganization;
	DisplayOrganizations();
}
