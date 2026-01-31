#include <QMessageBox>
#include "ProfileSelectionDialog.h"
#include "ProfileWidget.h"
#include "AppController.h"
#include "Utility.h"
ProfileSelectionDialog::ProfileSelectionDialog(QWidget* parent)
	: QDialog(parent), m_upAddEditProfileDialog(std::make_unique<AddEditProfileDialog>(this))
{
	ui.setupUi(this);
	QObject::connect(&AppController::instance(), &AppController::DBInitialized, this, &ProfileSelectionDialog::DBInitialized);
	QObject::connect(&AppController::instance(), &AppController::ChangeInDB, this, &ProfileSelectionDialog::ChangeInDB);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &ProfileSelectionDialog::close);
	QObject::connect(m_upAddEditProfileDialog.get(), &AddEditProfileDialog::NewProfileAdded, this, &ProfileSelectionDialog::NewProfileAdded);
	QObject::connect(m_upAddEditProfileDialog.get(), &AddEditProfileDialog::ProfileEdited, this, &ProfileSelectionDialog::ProfileEdited);
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
void ProfileSelectionDialog::DBInitialized(const std::vector<Profile>& vecProfiles, const std::vector<Organization>&)
{
	UpdateProfiles(vecProfiles);
}
void ProfileSelectionDialog::ChangeInDB(const std::vector<Profile>& vecProfile, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&)
{
	if(vecProfile != m_vecProfile)
	{
		UpdateProfiles(vecProfile);
	}
}
void ProfileSelectionDialog::UpdateProfiles(const std::vector<Profile>& vecProfile)
{
	m_vecProfile = vecProfile;
	if(IsProfileDeleted(m_vecProfile))
	{
		QMessageBox::information(this, "Information", "The profile deleted successfully");
	}
	utility::ClearListWidget(ui.listWidget);
	for (const auto& p : m_vecProfile)
	{
		auto pw = new ProfileWidget(this, p);
		QObject::connect(pw, &ProfileWidget::EditProfileButtonClicked, this, &ProfileSelectionDialog::OpenEditDialog);
		utility::InsertItem2ListWidget(ui.listWidget, pw);
	}
}
void ProfileSelectionDialog::on_NewButton_clicked()
{
	m_upAddEditProfileDialog->OpenAddDialog();
}
void ProfileSelectionDialog::NewProfileAdded()
{
	m_upAddEditProfileDialog->close();
	QMessageBox::information(this, "Information", "New profile is added successfully");
}
void ProfileSelectionDialog::ProfileEdited()
{
	m_upAddEditProfileDialog->close();
	QMessageBox::information(this, "Information", "The profile is edited successfully");
}