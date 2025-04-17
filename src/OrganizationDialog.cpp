#include <algorithm>
#include <QMessageBox>
#include "OrganizationDialog.h"
#include "AppController.h"
#include "Config.h"

OrganizationDialog::OrganizationDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	m_upAddEditOrganizationDialog = std::make_unique<AddEditOrganizationDialog>(this);
	QObject::connect(&AppController::instance(), &AppController::InitOrganizations, this, &OrganizationDialog::UpdateOrganizations);
	QObject::connect(&AppController::instance(), &AppController::ChangeInOrganizations, this, &OrganizationDialog::UpdateOrganizations);
	InitCustomComponents();
}

OrganizationDialog::~OrganizationDialog()
{}
void OrganizationDialog::InitCustomComponents()
{
	setWindowTitle("Tennis Organizations");
	m_vecColumnNames = { "", " Organization ", " Categories " , "", ""};
	FillColumnNamesOfTable(ui.tableWidget);
	MakeColumnHeaderBold(ui.tableWidget);
	setFixedSize(560, 600);
}
void OrganizationDialog::DisplayOrganizations()
{
	LoadDataToTable();
}
void OrganizationDialog::LoadDataToTable()
{
	ClearTable(ui.tableWidget);
	FillTable();
}
void OrganizationDialog::FillTable()
{
	unsigned int uiRowIdx{};
	for (const auto& org : m_vecOrganization)
	{
		ui.tableWidget->insertRow(uiRowIdx);
		InsertOrg2Table(org, uiRowIdx);
		++uiRowIdx;
	}
	ui.tableWidget->resizeRowsToContents();
	ui.tableWidget->resizeColumnsToContents();
}
void OrganizationDialog::InsertOrg2Table(const Organization& org, unsigned uiRowIdx)
{
	unsigned uiColumnIdx{};
	if (org.GetOrgPictureAddr() != "")
	{
		InsertPic2Cell(ui.tableWidget, (Organization::GetOrgImageRootDestDir() + QString::fromStdString(org.GetOrgPictureAddr())).toStdString(), 0.1f, uiRowIdx, uiColumnIdx++);
	}
	else
	{
		InsertPic2Cell(ui.tableWidget, (Organization::GetOrgImageRootDestDir() + "default_org.png").toStdString(), 0.1f, uiRowIdx, uiColumnIdx++);
	}
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(org.GetName()), uiRowIdx, uiColumnIdx++);
	InsertValue2Cell(ui.tableWidget, QString::fromStdString(Serialize(org.GetCategories())), uiRowIdx, uiColumnIdx++);
	InsertButtonWithImage2Cell(g_cpDeleteButtonPNG, 0.4f, &OrganizationDialog::DeleteOrganization, true, uiRowIdx, uiColumnIdx++);
	InsertButtonWithImage2Cell(g_cpEditButtonPNG, 0.4f, &OrganizationDialog::EditOrganization, true, uiRowIdx, uiColumnIdx++);
}
std::string OrganizationDialog::Serialize(const std::vector<std::string>& vecDeserialized)const
{
	std::string sSerialized{};
	for (const auto& str : vecDeserialized)
	{
		if (sSerialized != "")
		{
			sSerialized.append(", ");
		}
		sSerialized.append(str);
	}
	return sSerialized;
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
void OrganizationDialog::InsertButtonWithImage2Cell(const std::string& sImageAddr, float fScale, auto func, bool blEnabled, unsigned uiRowIdx, unsigned uiColumnIdx)
{
	QWidget* pWidget = new QWidget();
	QPushButton* pBtn = new QPushButton;
	InitButtonWithPicture(pBtn, sImageAddr, fScale);
	connect(pBtn, &QPushButton::clicked, this, func);
	pBtn->setEnabled(blEnabled);
	QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
	pLayout->addWidget(pBtn);
	pLayout->setAlignment(Qt::AlignCenter);
	pLayout->setContentsMargins(0, 0, 0, 0);
	pWidget->setLayout(pLayout);
	ui.tableWidget->setCellWidget(uiRowIdx, uiColumnIdx, pWidget);
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
