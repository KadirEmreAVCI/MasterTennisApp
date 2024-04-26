#pragma once

#include <QDialog>
#include "ui_ProfileDialog.h"

class ProfileDialog : public QDialog, public Ui::ProfileDialogClass
{
	Q_OBJECT

public:
	ProfileDialog(QWidget *parent = nullptr);
	~ProfileDialog();

private:
	 
};
