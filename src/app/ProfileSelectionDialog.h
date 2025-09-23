#ifndef PROFILESELECTIONDIALOG_H
#define PROFILESELECTIONDIALOG_H

#include <QDialog>
#include "ui_ProfileSelectionDialog.h"
#include "AddEditProfileDialog.h"
#include "Profile.h"

class ProfileSelectionDialog : public QDialog
{
	Q_OBJECT

public:
	ProfileSelectionDialog(QWidget* parent = nullptr);
	~ProfileSelectionDialog();
	void OpenEditDialog(const Profile& selectedProfile);
private:
	bool IsProfileDeleted(const std::vector<Profile>&)const;
	Ui::ProfileSelectionDialogClass ui;
	std::unique_ptr<AddEditProfileDialog> m_upAddEditProfileDialog{ nullptr };
public slots:
	void UpdateProfiles(const std::vector<Profile>& vecProfile);
private slots:
	void on_NewProfileButton_clicked();
};

#endif