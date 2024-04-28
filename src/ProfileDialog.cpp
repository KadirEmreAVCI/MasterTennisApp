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
	InitUpcomingMatches();
	InitStats();
}
void ProfileDialog::InitUpcomingMatches()
{
	// TODO: Dongunun kac kez donecegi upcoming mac sayisina bagli olacak.
	for (int i = 0; i < 3; ++i)
	{
		InsertUpcomingMatch("Tournament " + std::to_string(i), "Category " + std::to_string(i), "Opponent " + std::to_string(i), "Stage " + std::to_string(i));
	}
	listWidget_UpcomingMatches->setFixedSize(listWidget_UpcomingMatches->sizeHintForColumn(0) + listWidget_UpcomingMatches->frameWidth() * 2, listWidget_UpcomingMatches->sizeHintForRow(0) * listWidget_UpcomingMatches->count() + 2 * listWidget_UpcomingMatches->frameWidth());
	groupBox_UpcomingMatches->setFixedSize(listWidget_UpcomingMatches->width(), listWidget_UpcomingMatches->height() + 20);
}
void ProfileDialog::InsertUpcomingMatch(std::string sTournamentName, std::string sTournamentCategory, std::string sOpponentName, std::string sStage)
{
	auto item = new QListWidgetItem(listWidget_UpcomingMatches);
	auto upcomingMatch = new UpcomingMatch(this, sTournamentName, sTournamentCategory, sOpponentName, sStage);
	item->setSizeHint(QSize(upcomingMatch->width(), upcomingMatch->height()));
	listWidget_UpcomingMatches->addItem(item);
	listWidget_UpcomingMatches->setItemWidget(item, upcomingMatch);
}
void ProfileDialog::InitStats()
{
	InitStatIcons();
	// TODO: Databaseden statler ile ilgili bilgiler okunacak ve buna gore deðerler ilklendirilecek.
}
void ProfileDialog::InitStatIcons()
{
	InitializePicture(label_IconWin, ":images/images/win.png");
	InitializePicture(label_IconLose, ":images/images/lose.png");
	InitializePicture(label_IconGame, ":images/images/games.png");
	InitializePicture(label_IconClutchness, ":images/images/clutchness.png");
	InitializePicture(label_IconTrophies, ":images/images/trophy.png");
	InitializePicture(label_IconGA, ":images/images/GA.png");
}
void ProfileDialog::InitializePicture(QLabel* pPicLabel, std::string sPicAddress)
{
	QPixmap pix{ QString::fromStdString(sPicAddress) };
	const int iHeight = pPicLabel->height() * 1.5;
	const int iWidth = pPicLabel->width() * 1.5;
	pPicLabel->setPixmap(pix.scaled(iWidth, iHeight, Qt::KeepAspectRatio));
}