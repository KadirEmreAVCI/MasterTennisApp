#include <QMessageBox>
#include <QFileDialog>
#include "AddEditProfileDialog.h"
#include "AppController.h"
#include "Utility.h"

AddEditProfileDialog::AddEditProfileDialog(QWidget *parent)
	: QDialog(parent), AddEditDialog<Profile>(this)
{
	ui.setupUi(this);
	InitDialog();
}

AddEditProfileDialog::~AddEditProfileDialog()
{}
void AddEditProfileDialog::InitDialog()
{
	ui.ProfilePicWidget->InitWidget();
	ui.lineEdit_NameSurname->setText("");
	ui.radioButton_Female->setAutoExclusive(false);
	ui.radioButton_Male->setAutoExclusive(false);
	ui.radioButton_Female->setChecked(false);
	ui.radioButton_Male->setChecked(false);
	ui.radioButton_Female->setAutoExclusive(true);
	ui.radioButton_Male->setAutoExclusive(true);
}
void AddEditProfileDialog::FillDialog()
{
	ui.lineEdit_NameSurname->setText(QString::fromStdString(m_EditedItem.GetFullName()));
	ui.ProfilePicWidget->FillWidget(&m_EditedItem);
	if(m_EditedItem.GetGender() == Gender::Male)
		ui.radioButton_Male->setChecked(true);
	else
		ui.radioButton_Female->setChecked(true);
}
void AddEditProfileDialog::ClearDialog()
{
	ui.lineEdit_NameSurname->setText("");
	ui.radioButton_Male->setChecked(false);
	ui.radioButton_Female->setChecked(false);
	ui.ProfilePicWidget->ClearWidget();
}
bool AddEditProfileDialog::IsMandatoryFieldsFilled()const
{
	return ui.lineEdit_NameSurname->text() != "" && (ui.radioButton_Male->isChecked() || ui.radioButton_Female->isChecked());
}
bool AddEditProfileDialog::IsThereAnyUnsavedInfo()const
{
	return ui.lineEdit_NameSurname->text() != "" || (ui.radioButton_Male->isChecked() || ui.radioButton_Female->isChecked());
}
void AddEditProfileDialog::on_SaveButton_clicked()
{
	if (IsMandatoryFieldsFilled())
	{
		close();
		const QString sSourcePictureFullPath = ui.ProfilePicWidget->GetSourcePictureFullPath(); 
		Profile p{
			m_EditedItem.GetID(),
			ui.lineEdit_NameSurname->text().toStdString(),
			QFileInfo(sSourcePictureFullPath).fileName().toStdString(),
			ui.radioButton_Male->isChecked() ? Gender::Male : Gender::Female
		};
		if (sSourcePictureFullPath != "")
		{
			p.SaveImage(sSourcePictureFullPath.toStdString());
		}
		switch (m_DialogMode)
		{
			case DialogMode::eAddDialog:
			{
				if (AppController::instance().AddNewItem(p))
					QMessageBox::information(this, "Information", "New profile is added successfully");
				break;
			}
			case DialogMode::eEditDialog:
			{
				if (p == m_EditedItem)
				{
					QMessageBox::warning(this, "Warning", "No change detected in the profile.");
				}
				else
				{
					if (AppController::instance().EditItem(p))
						QMessageBox::information(this, "Information", "The profile is edited successfully");
				}
				break;
			}
			default:
				std::cerr << "AddEditProfileDialog::on_SaveButton_clicked Unknown DialogMode!\n";
		}
	}
	else
	{
		QMessageBox::critical(this, "Error", "Please fill all the mandatory fields.");
	}
}
void AddEditProfileDialog::on_CancelButton_clicked()
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