#pragma once
#include <string>
#include <memory>
#include <QDialog>
#include "IQTComponent.h"
#include "ui_ProfileDialog.h"
class QTabWidget;
class QVBoxLayout;
class UpcomingMatch;
class ProfileDialog : public QDialog, public Ui::ProfileDialogClass, public IQTComponent
{
	Q_OBJECT

public:
	ProfileDialog(QWidget *parent = nullptr);
	~ProfileDialog();
	void InitCustomComponents() override final;
	std::unique_ptr<QVBoxLayout> m_MainLayout{};
	std::unique_ptr<QTabWidget> m_upTabWidget{};
private:
	void InitHomePage();
	
	
	
};
