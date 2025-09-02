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
void ProfileSelectionDialog::OpenAddDialog()
{
	m_upAddEditProfileDialog->setModal(true);
	m_upAddEditProfileDialog->PrepareDialog(DialogMode::eAddDialog);
	m_upAddEditProfileDialog->exec();
}
void ProfileSelectionDialog::UpdateProfiles(const std::vector<Profile>& vecProfile)
{
	std::cout << "ProfileSelectionDialog::UpdateProfiles!!!!!!!!!!!!!!!\n";
	utility::ClearListWidget(ui.listWidget);
	for (const auto& profile : vecProfile)
	{
		utility::InsertItem2ListWidget(ui.listWidget, new ProfileWidget(this, profile));
	}
}
void ProfileSelectionDialog::on_NewProfileButton_clicked()
{
	OpenAddDialog();
}
