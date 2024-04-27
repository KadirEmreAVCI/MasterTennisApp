#pragma once
#include <string>
#include <QDialog>
#include "IQTComponent.h"
#include "ui_ProfileDialog.h"
class UpcomingMatch;
class ProfileDialog : public QDialog, public Ui::ProfileDialogClass, public IQTComponent
{
	Q_OBJECT

public:
	ProfileDialog(QWidget *parent = nullptr);
	~ProfileDialog();
	void InitializeCustomComponents() override final;
private:
	void InitUpcomingMatches();
	void InsertUpcomingMatch(std::string sTournamentName, std::string sTournamentCategory, std::string sOpponentName, std::string sStage);
	void InitStats();
	void InitStatIcons();
	void InitializePicture(QLabel* pPicLabel, std::string sPicAddress);
};
