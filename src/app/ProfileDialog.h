#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H

#include <memory>
#include <QDialog>
#include <QToolBar>
#include "ui_ProfileDialog.h"
#include "Profile.h"

class QTabWidget;
class QVBoxLayout;
class ProfileDialog : public QDialog{
	Q_OBJECT

public:
	ProfileDialog(QWidget* parent = nullptr);
	~ProfileDialog();
private:
	void CreateTabWidget();
	void UserLoggedIn(const Profile&);
	void DBInitialized(const std::vector<Profile>&, const std::vector<Organization>&);
	void ChangeInDB(const std::vector<Profile>&, const std::vector<Organization>&, const std::vector<Tournament>&, const std::vector<Match>&);
	void UpdateProfileAlternatives(const std::vector<Profile>&);
	Ui::ProfileDialogClass ui;
	std::vector<Profile> m_vecProfile;
	Profile m_ActiveProfile;
private slots:
	void on_LogOutButton_clicked();
	void on_comboBoxProfiles_currentTextChanged(const QString& type);
};

#endif