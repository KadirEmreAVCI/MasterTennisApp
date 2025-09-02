#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include "ui_ProfileWidget.h"
#include "Profile.h"
#include "ProfileDialog.h"
class AddEditProfileDialog;
class ProfileWidget : public QWidget{
	Q_OBJECT

public:
	ProfileWidget(QWidget *parent = nullptr, const Profile& p = Profile{});
	~ProfileWidget();
private:
	void FillProfileButton();
	void OpenEditDialog(const Profile& selectedProfile);
	Ui::ProfileWidgetClass ui;
	std::unique_ptr<AddEditProfileDialog> m_upAddEditProfileDialog{ nullptr };
	Profile m_Profile;
private slots:
	void on_ProfileButton_clicked();
	void on_DeleteButton_clicked();
	void on_EditButton_clicked();
};

#endif