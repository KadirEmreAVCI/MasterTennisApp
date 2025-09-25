#include <QMessageBox>
#include <QFileDialog>
#include "AddEditOrganizationDialog.h"
#include "AppController.h"
#include "Utility.h"

AddEditOrganizationDialog::AddEditOrganizationDialog(QWidget *parent)
	: QDialog(parent), AddEditDialog<Organization>(this)
{
	ui.setupUi(this);
	setFixedSize(470, 250);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_Master);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_Aplus);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_A);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_B);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_C);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_D);
	m_vecCategoryCheckboxes.push_back(ui.checkBox_IlkTurnuvam);
	InitDialog();
}

AddEditOrganizationDialog::~AddEditOrganizationDialog()
{}
void AddEditOrganizationDialog::InitDialog()
{
	ui.ProfilePicWidget->InitWidget(Organization::GetPictureRootDestDir());
	ClearDialog();
}
void AddEditOrganizationDialog::FillDialog()
{
	m_vecCategories = m_EditedItem.GetCategories();
	ui.lineEdit_OrganizationName->setText(QString::fromStdString(m_EditedItem.GetName()));
	ui.lineEdit_Categories->setText(QString::fromStdString(utility::Serialize(m_EditedItem.GetCategories())));
	ui.ProfilePicWidget->FillWidget(QString::fromStdString(m_EditedItem.GetPictureAddr()));
}
void AddEditOrganizationDialog::ClearDialog()
{
	ui.lineEdit_OrganizationName->setText("");
	ui.lineEdit_Categories->setText("");
	ui.ProfilePicWidget->ClearWidget();
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
		Organization org{
			m_EditedItem.GetID(),
			ui.lineEdit_OrganizationName->text().toStdString(),
			ui.ProfilePicWidget->GetImageFileName().toStdString(),
			m_vecCategories
		};
		if (org.GetPictureAddr() != "")
		{
			ui.ProfilePicWidget->SaveImage();
		}
		switch (m_DialogMode)
		{
		case DialogMode::eAddDialog:
		{
			if (AppController::instance().AddNewItem(org))
			{
				close();
				QMessageBox::information(this, "Information", "New organization is added successfully");
			}
			break;
		}
		case DialogMode::eEditDialog:
		{
			if (AppController::instance().EditItem(org))
			{
				close();
				QMessageBox::information(this, "Information", "The organization is edited successfully");
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
void AddEditOrganizationDialog::ClearCategoryCheckboxes()
{
	std::for_each(m_vecCategoryCheckboxes.begin(), m_vecCategoryCheckboxes.end(), [](QCheckBox* cb) {
		cb->setChecked(false);
		});
}