#include <iostream>
#include "HomePage.h"
#include "UpcomingMatch.h"
HomePage::HomePage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	InitCustomComponents();
}

HomePage::~HomePage()
{}
void HomePage::InitCustomComponents()
{
	std::cout << "ProfileDialog::InitializeCustomComponents\n";
	InitUpcomingMatches();
	InitStats();
}
void HomePage::InitUpcomingMatches()
{
	// TODO: Dongunun kac kez donecegi upcoming mac sayisina bagli olacak.
	for (int i = 0; i < 3; ++i)
	{
		InsertUpcomingMatch("Tournament " + std::to_string(i), "Category " + std::to_string(i), "Opponent " + std::to_string(i), "Stage " + std::to_string(i));
	}
	ui.listWidget_UpcomingMatches->setFixedSize(ui.listWidget_UpcomingMatches->sizeHintForColumn(0) + ui.listWidget_UpcomingMatches->frameWidth() * 2, ui.listWidget_UpcomingMatches->sizeHintForRow(0) * ui.listWidget_UpcomingMatches->count() + 2 * ui.listWidget_UpcomingMatches->frameWidth());
	ui.groupBox_UpcomingMatches->setFixedSize(ui.listWidget_UpcomingMatches->width(), ui.listWidget_UpcomingMatches->height() + 20);
}
void HomePage::InsertUpcomingMatch(std::string sTournamentName, std::string sTournamentCategory, std::string sOpponentName, std::string sStage)
{
	auto item = new QListWidgetItem(ui.listWidget_UpcomingMatches);
	auto upcomingMatch = new UpcomingMatch(this, sTournamentName, sTournamentCategory, sOpponentName, sStage);
	item->setSizeHint(QSize(upcomingMatch->width(), upcomingMatch->height()));
	ui.listWidget_UpcomingMatches->addItem(item);
	ui.listWidget_UpcomingMatches->setItemWidget(item, upcomingMatch);
}
void HomePage::InitStats()
{
	InitStatIcons();
	// TODO: Databaseden statler ile ilgili bilgiler okunacak ve buna gore deðerler ilklendirilecek.
}
void HomePage::InitStatIcons()
{
	const float fScale{ 1.5f };
	InitPicture(ui.label_IconWin, ":images/images/win.png", fScale);
	InitPicture(ui.label_IconLose, ":images/images/lose.png", fScale);
	InitPicture(ui.label_IconGame, ":images/images/games.png", fScale);
	InitPicture(ui.label_IconClutchness, ":images/images/clutchness.png", fScale);
	InitPicture(ui.label_IconTrophies, ":images/images/trophy.png", fScale);
	InitPicture(ui.label_IconGA, ":images/images/GA.png", fScale);
}