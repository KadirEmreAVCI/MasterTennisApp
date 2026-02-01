#include <QMessageBox>
#include <QFileDialog>
#include "AddEditOrganizationDialog.h"
#include "AppController.h"
#include "Utility.h"
#include "Common.h"

AddEditOrganizationDialog::AddEditOrganizationDialog(QWidget *parent)
	: QDialog(parent), AddEditDialog<Organization>(this)
{
	ui.setupUi(this);
	setFixedSize(470, 250);
	InitCheckboxes();
	InitDialog();
}

AddEditOrganizationDialog::~AddEditOrganizationDialog()
{}
void AddEditOrganizationDialog::InitDialog()
{
	ui.OrgPicWidget->InitWidget();
	ClearDialog();
}
void AddEditOrganizationDialog::FillDialog()
{
	m_vecCategories = m_EditedItem.GetCategories();
	ui.lineEdit_OrganizationName->setText(QString::fromStdString(m_EditedItem.GetName()));
	ui.lineEdit_Categories->setText(QString::fromStdString(utility::Serialize(m_EditedItem.GetCategories())));
	ui.OrgPicWidget->FillWidget(&m_EditedItem);
}
void AddEditOrganizationDialog::ClearDialog()
{
	ui.lineEdit_OrganizationName->setText("");
	ui.lineEdit_Categories->setText("");
	ui.OrgPicWidget->ClearWidget();
}
bool AddEditOrganizationDialog::IsMandatoryFieldsFilled()const
{
	return ui.lineEdit_OrganizationName->text() != "" && ui.lineEdit_Categories->text() != "";
}
bool AddEditOrganizationDialog::IsThereAnyUnsavedInfo()const
{
	return ui.lineEdit_OrganizationName->text() != "" || ui.lineEdit_Categories->text() != "";
}
void AddEditOrganizationDialog::on_SaveButton_clicked()
{
	if (IsMandatoryFieldsFilled())
	{
		const QString sSourcePictureFullPath = ui.OrgPicWidget->GetSourcePictureFullPath(); 
		Organization org{
			m_EditedItem.GetID(),
			ui.lineEdit_OrganizationName->text().toStdString(),
			QFileInfo(sSourcePictureFullPath).fileName().toStdString(),
			m_vecCategories
		};
		if (ui.OrgPicWidget->IsPictureChanged() && sSourcePictureFullPath != "")
		{
			org.SaveImage(sSourcePictureFullPath.toStdString());
		}
		switch (m_DialogMode)
		{
		case DialogMode::eAddDialog:
		{
			if (AppController::instance().AddNewItem(org))
			{
				emit NewOrganizationAdded();
			}
			break;
		}
		case DialogMode::eEditDialog:
		{
			if (AppController::instance().EditItem(org))
			{
				emit OrganizationEdited();
			}
			break;
		}
		default:
			std::cerr << "AddEditOrganizationDialog::on_SaveButton_clicked Unknown DialogMode!\n";
		}
	}
	else
	{
		QMessageBox::critical(this, "Error", "Please fill all the mandatory fields.");
	}
}
void AddEditOrganizationDialog::on_CancelButton_clicked()
{
	if (IsThereAnyUnsavedInfo() && m_DialogMode != DialogMode::eEditDialog)
	{
		QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Cancellation", "Are you sure you want to cancel? All unsaved information will be lost.", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			close();
		}
	}
	else
	{
		close();
	}
}
void AddEditOrganizationDialog::on_ApplyButton_clicked()
{
	m_vecCategories.clear();
	for (const auto& cb : m_vecCategoryCheckboxes)
	{
		if (cb->isChecked())
		{
			m_vecCategories.push_back(cb->text().toStdString());
		}
	}
	ui.lineEdit_Categories->setText(QString::fromStdString(utility::Serialize(m_vecCategories)));
	ClearCategoryCheckboxes();
}
void AddEditOrganizationDialog::on_ClearButton_clicked()
{
	m_vecCategories.clear();
	ClearCategoryCheckboxes();
	ui.lineEdit_Categories->setText(QString::fromStdString(utility::Serialize(m_vecCategories)));
}
void AddEditOrganizationDialog::InitCheckboxes()
{
	using namespace common;
	ui.checkBox_Master->setText(QString::fromStdString(g_vecTournamentCategories[0]));
	ui.checkBox_Aplus->setText(QString::fromStdString(g_vecTournamentCategories[1]));
	ui.checkBox_A->setText(QString::fromStdString(g_vecTournamentCategories[2]));
	ui.checkBox_B->setText(QString::fromStdString(g_vecTournamentCategories[3]));
	ui.checkBox_C->setText(QString::fromStdString(g_vecTournamentCategories[4]));
	ui.checkBox_D->setText(QString::fromStdString(g_vecTournamentCategories[5]));
	ui.checkBox_IlkTurnuvam->setText(QString::fromStdString(g_vecTournamentCategories[6]));
	m_vecCategoryCheckboxes.push_back(ui.checkBox_Master);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_Aplus);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_A);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_B);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_C);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_D);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_IlkTurnuvam);
}
void AddEditOrganizationDialog::ClearCategoryCheckboxes()
{
	std::for_each(m_vecCategoryCheckboxes.begin(), m_vecCategoryCheckboxes.end(), [](QCheckBox* cb) {
		cb->setChecked(false);
		});
}