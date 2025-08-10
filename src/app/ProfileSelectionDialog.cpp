#include <QMessageBox>
#include "ProfileSelectionDialog.h"
#include "ProfileWidget.h"
#include "AppController.h"
ProfileSelectionDialog::ProfileSelectionDialog(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(&AppController::instance(), &AppController::InitProfiles, this, &ProfileSelectionDialog::UpdateProfiles);
	QObject::connect(&AppController::instance(), &AppController::ChangeInProfiles, this, &ProfileSelectionDialog::UpdateProfiles);
	QObject::connect(&AppController::instance(), &AppController::UserLoggedIn, this, &ProfileSelectionDialog::close);
	m_upAddEditProfileDialog = std::make_unique<AddEditProfileDialog>(this);
	setFixedSize(400, 500);
	setWindowTitle("Select Your Profile");
}

ProfileSelectionDialog::~ProfileSelectionDialog()
{}

void ProfileSelectionDialog::InsertProfile(const Profile& profile)
{
	auto item = new QListWidgetItem(ui.listWidget);
	auto profileWidget = new ProfileWidget(this);
	profileWidget->SetProfile(profile);
	item->setSizeHint(QSize(profileWidget->width(), profileWidget->height()));
	ui.listWidget->addItem(item);
	ui.listWidget->setItemWidget(item, profileWidget);
}
void ProfileSelectionDialog::OpenAddDialog()
{
	m_upAddEditProfileDialog->setModal(true);
	m_upAddEditProfileDialog->PrepareDialog(DialogMode::eAddDialog);
	m_upAddEditProfileDialog->exec();
}
void ProfileSelectionDialog::UpdateProfiles(const std::vector<Profile>& vecProfile)
{
	std::cout << "ProfileSelectionDialog::UpdateProfiles!!!!!!!!!!!!!!!\n";
	ui.listWidget->clear();
	for (const auto& profile : vecProfile)
	{
		InsertProfile(profile);
	}
}
void ProfileSelectionDialog::on_NewProfileButton_clicked()
{
	OpenAddDialog();
}
