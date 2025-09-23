#include <QMessageBox>
#include "ProfileSelectionDialog.h"
#include "ProfileWidget.h"
#include "AppController.h"
#include "Utility.h"
ProfileSelectionDialog::ProfileSelectionDialog(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(&AppController::instance(), &AppController::InitProfiles, this, &ProfileSelectionDialog::UpdateProfiles);
	QObject::connect(&AppController::instance(), &AppController::ChangeInProfiles, this, &ProfileSelectionDialog::UpdateProfiles);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &ProfileSelectionDialog::close);
	m_upAddEditProfileDialog = std::make_unique<AddEditProfileDialog>(this);
	setFixedSize(400, 500);
	setWindowTitle("");
}
ProfileSelectionDialog::~ProfileSelectionDialog()
{
	utility::ClearListWidget(ui.listWidget);
}
void ProfileSelectionDialog::OpenEditDialog(const Profile& selectedProfile)
{
	m_upAddEditProfileDialog->OpenEditDialog(selectedProfile);
}
bool ProfileSelectionDialog::IsProfileDeleted(const std::vector<Profile>& vecProfile)const
{
	return ui.listWidget->count() > vecProfile.size();
}
void ProfileSelectionDialog::UpdateProfiles(const std::vector<Profile>& vecProfile)
{
	if(IsProfileDeleted(vecProfile))
	{
		QMessageBox::information(this, "Information", "The profile deleted successfully");
	}
	utility::ClearListWidget(ui.listWidget);
	for (const auto& p : vecProfile)
	{
		auto pw = new ProfileWidget(this, p);
		QObject::connect(pw, &ProfileWidget::EditProfileButtonClicked, this, &ProfileSelectionDialog::OpenEditDialog);
		utility::InsertItem2ListWidget(ui.listWidget, pw);
	}
}
void ProfileSelectionDialog::on_NewProfileButton_clicked()
{
	m_upAddEditProfileDialog->OpenAddDialog();
}
