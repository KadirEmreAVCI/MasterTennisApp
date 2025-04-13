#include <QMessageBox>
#include <QFileDialog>
#include "AddEditProfileDialog.h"
#include "AppController.h"

AddEditProfileDialog::AddEditProfileDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	InitCustomComponents();
}

AddEditProfileDialog::~AddEditProfileDialog()
{}

void AddEditProfileDialog::InitCustomComponents()
{
	InitButtonWithPicture(ui.DefaultPPButton, ":images/images/CrossButton.png", 0.35f);
	InitDialog();
}
void AddEditProfileDialog::PrepareDialog(DialogMode mode, const Profile& p)
{
	SetDialogMode(mode);
	InitDialog();
	switch (m_DialogMode)
	{
	case DialogMode::eAddDialog:
	{
		setWindowTitle("New Profile");
		break;
	}
	case DialogMode::eEditDialog:
	{
		setWindowTitle("Edit Profile");
		m_EditedProfile = p;
		m_sImageFileName = QString::fromStdString(m_EditedProfile.GetPPAddr());
		FillDialog();
		break;
	}
	default:
		std::cout << "AddEditProfileDialog::SetDialogMode Unknown DialogMode!\n";
	}
}
void AddEditProfileDialog::InitDialog()
{
	ui.lineEdit_NameSurname->setText("");
	ui.lineEdit_PPAddr->setText("");
	ui.radioButton_Female->setAutoExclusive(false);
	ui.radioButton_Male->setAutoExclusive(false);
	ui.radioButton_Female->setChecked(false);
	ui.radioButton_Male->setChecked(false);
	ui.radioButton_Female->setAutoExclusive(true);
	ui.radioButton_Male->setAutoExclusive(true);
}
void AddEditProfileDialog::FillDialog()
{
	ui.lineEdit_NameSurname->setText(QString::fromStdString(m_EditedProfile.GetFullName()));
	ui.lineEdit_PPAddr->setText(QString::fromStdString(m_EditedProfile.GetPPAddr()));
	if(m_EditedProfile.GetGender() == Gender::Male)
		ui.radioButton_Male->setChecked(true);
	else
		ui.radioButton_Female->setChecked(true);
}
void AddEditProfileDialog::ClearDialog()
{
	ui.lineEdit_NameSurname->setText("");
	ui.lineEdit_PPAddr->setText("");
	ui.radioButton_Male->setChecked(false);
	ui.radioButton_Female->setChecked(false);
}
bool AddEditProfileDialog::IsMandatoryFieldsFilled()const
{
	return ui.lineEdit_NameSurname->text() != "" 
		&& (ui.radioButton_Male->isChecked() || ui.radioButton_Female->isChecked());
}
bool AddEditProfileDialog::IsThereAnyUnsavedInfo()const
{
	return ui.lineEdit_NameSurname->text() != "" 
		|| (ui.radioButton_Male->isChecked() || ui.radioButton_Female->isChecked()) 
		|| ui.lineEdit_PPAddr->text() != "";
}
void AddEditProfileDialog::on_BrowseButton_clicked()
{
	const QString sFullSourceDir = QFileDialog::getOpenFileName(this, "Select the image.", "Images(.png, .jpg, .jpeg)");
	if (QFileInfo(sFullSourceDir).fileName() != "")
	{
		const QString sRootDestDir = Profile::GetProfileImageRootDestDir();
		OnBrowseButtonClicked(sFullSourceDir, sRootDestDir);
		ui.lineEdit_PPAddr->setText(m_sFullSourceDir);
	}
}
void AddEditProfileDialog::on_DefaultPPButton_clicked()
{
	if (ui.lineEdit_PPAddr->text() != "")
	{
		QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Cancellation", "Are you sure you want to remove the profile picture?", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			ClearImage();
			ui.lineEdit_PPAddr->setText("");
		}
	}
}
void AddEditProfileDialog::on_SaveButton_clicked()
{
	if (IsMandatoryFieldsFilled())
	{
		close();
		Profile p;
		p.SetFullName(ui.lineEdit_NameSurname->text().toStdString());
		p.SetGender(ui.radioButton_Male->isChecked() ? Gender::Male : Gender::Female);
		if (m_sImageFileName != "")
		{
			SaveImage();
			p.SetPPAddr(m_sImageFileName.toStdString());
		}
		switch (m_DialogMode)
		{
			case DialogMode::eAddDialog:
			{
				if (AppController::instance().AddNewProfile(p))
					QMessageBox::information(this, "Information", "New profile is added successfully");
				break;
			}
			case DialogMode::eEditDialog:
			{
				p.SetID(m_EditedProfile.GetID());
				if (p == m_EditedProfile)
				{
					QMessageBox::warning(this, "Warning", "No change detected in the profile.");
				}
				else
				{
					if (AppController::instance().EditProfile(p))
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