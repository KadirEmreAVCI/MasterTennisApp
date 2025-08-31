#include <QMessageBox>
#include "ProfileWidget.h"
#include "ProfileSelectionDialog.h"
#include "AppController.h"
#include "AddEditProfileDialog.h"
#include "Config.h"
#include "Utility.h"

ProfileWidget::ProfileWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    m_upAddEditProfileDialog = std::make_unique<AddEditProfileDialog>(this);
	utility::InitButtonWithPicture(ui.DeleteButton, g_cpDeleteButtonPNG, 0.4f);
    utility::InitButtonWithPicture(ui.EditButton, g_cpEditButtonPNG, 0.4f);
}

ProfileWidget::~ProfileWidget()
{}
Profile ProfileWidget::GetProfile()const
{
	return m_Profile;
}
void ProfileWidget::SetProfile(const Profile& profile)
{
	m_Profile = profile;
	FillWidget();
}
void ProfileWidget::FillWidget()
{
    FillProfileButton();
}
void ProfileWidget::FillProfileButton()
{
    ui.ProfileButton->setFixedSize(310, 70);

    QWidget* container = new QWidget(ui.ProfileButton);
    QHBoxLayout* layout = new QHBoxLayout(container);
    layout->setContentsMargins(5, 5, 5, 5);

    QLabel* PPLabel = CreatePPLabel();

    QLabel* ProfileNameLabel = new QLabel(QString::fromStdString(m_Profile.GetFullName()));
    QFont font = ProfileNameLabel->font();
    font.setPointSize(11);
    ProfileNameLabel->setFont(font);

    layout->addWidget(PPLabel);
    layout->addWidget(ProfileNameLabel);
    layout->addStretch();
}
QLabel* ProfileWidget::CreatePPLabel()const
{
    QLabel* PPLabel = new QLabel();
    const std::string sPPAddr = (m_Profile.GetPPAddr() != "") ? (Profile::GetProfileImageRootDestDir().toStdString() + m_Profile.GetPPAddr()) : (Profile::GetProfileImageRootDestDir() + "default_profile.png").toStdString();
    QPixmap pixmap(QString::fromStdString(sPPAddr));
    PPLabel->setPixmap(pixmap.scaled(60, 60, Qt::KeepAspectRatio));
    PPLabel->setFixedSize(60, 60);
    return PPLabel;
}
void ProfileWidget::OpenEditDialog(const Profile& selectedProfile)
{
    m_upAddEditProfileDialog->setModal(true);
    m_upAddEditProfileDialog->PrepareDialog(DialogMode::eEditDialog, selectedProfile);
    m_upAddEditProfileDialog->exec();
}
void ProfileWidget::on_ProfileButton_clicked()
{
    AppController::instance().LogInToProfile(m_Profile);
}
void ProfileWidget::on_DeleteButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want delete this profile permanently? All tournaments and matches of the profile will be deleted.", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        AppController::instance().DeleteProfile(m_Profile);
        QMessageBox::information(this, "Information", "The profile deleted successfully");
    }
}
void ProfileWidget::on_EditButton_clicked()
{
    OpenEditDialog(m_Profile);
}
