#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H

#include <memory>
#include <QDialog>
#include <QToolBar>
#include "IQTComponent.h"
#include "ui_ProfileDialog.h"
#include "Profile.h"

class QTabWidget;
class QVBoxLayout;
class ProfileDialog : public QDialog, public IQTComponent
{
	Q_OBJECT

public:
	ProfileDialog(QWidget* parent = nullptr);
	~ProfileDialog();
private:
	void InitCustomComponents() override final;
	void CreateTabWidget();
	void UpdateProfileName();
	void UpdatePP();
	void UserLoggedIn(const Profile&);
	void UpdateProfileAlternatives(const std::vector<Profile>&);
	Ui::ProfileDialogClass ui;
	std::vector<Profile> m_vecProfile;
	Profile m_ActiveProfile;
private slots:
	void on_LogOutButton_clicked();
	void on_comboBoxProfiles_currentTextChanged(const QString& type);
};

#endif