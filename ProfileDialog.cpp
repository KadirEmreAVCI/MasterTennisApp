#include <iostream>
#include "ProfileDialog.h"
#include "UpcomingMatch.h"
#include <QListWidget>
#include <Qlabel>
ProfileDialog::ProfileDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	InitializeCustomComponents();
}

ProfileDialog::~ProfileDialog()
{}

void ProfileDialog::InitializeCustomComponents()
{
	std::cout << "ProfileDialog::InitializeCustomComponents\n";
	// TODO: Dongunun kac kez donecegi upcoming mac sayisina bagli olacak.
	for(int i = 0; i < 2; ++i)
	{
		InsertUpcomingMatch("Tournament " + std::to_string(i), "Category " + std::to_string(i), "Opponent " + std::to_string(i), "Stage " + std::to_string(i));
	}
	listWidget_UpcomingMatches->setFixedSize(listWidget_UpcomingMatches->sizeHintForColumn(0) + listWidget_UpcomingMatches->frameWidth() * 2, listWidget_UpcomingMatches->sizeHintForRow(0) * listWidget_UpcomingMatches->count() + 2 * listWidget_UpcomingMatches->frameWidth());
}

void ProfileDialog::InsertUpcomingMatch(std::string sTournamentName, std::string sTournamentCategory, std::string sOpponentName, std::string sStage)
{
	auto item = new QListWidgetItem(listWidget_UpcomingMatches);
	auto upcomingMatch = new UpcomingMatch(this, sTournamentName, sTournamentCategory, sOpponentName, sStage);
	item->setSizeHint(QSize(upcomingMatch->width(), upcomingMatch->height()));
	listWidget_UpcomingMatches->addItem(item);
	listWidget_UpcomingMatches->setItemWidget(item, upcomingMatch);
}