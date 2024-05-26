#include <iostream>
#include <QListWidget>
#include <Qlabel>
#include <QVBoxLayout>
#include "ProfileDialog.h"
#include "UpcomingMatch.h"
#include "HomePage.h"
#include "StatisticsPage.h"
#include "AchievementsPage.h"
#include "HistoryPage.h"
ProfileDialog::ProfileDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	InitCustomComponents();
}

ProfileDialog::~ProfileDialog()
{}

void ProfileDialog::InitCustomComponents()
{
	std::cout << "ProfileDialog::InitializeCustomComponents\n";
	m_upTabWidget = std::make_unique<QTabWidget>();
	m_upTabWidget->addTab(new HomePage(), QString("Home"));
	std::cout << "ProfileDialog::InitCustomComponents HomePage constructed succesfully\n";
	m_upTabWidget->addTab(new StatisticsPage(), QString("Statistics"));
	std::cout << "ProfileDialog::InitCustomComponents StatisticsPage constructed succesfully\n";
	m_upTabWidget->addTab(new AchievementsPage(), QString("Achievements"));
	std::cout << "ProfileDialog::InitCustomComponents AchievementsPage constructed succesfully\n";
	m_upTabWidget->addTab(new HistoryPage(), QString("History"));
	std::cout << "ProfileDialog::InitCustomComponents HistoryPage constructed succesfully\n";
	m_MainLayout = std::make_unique<QVBoxLayout>();
	m_MainLayout->addWidget(m_upTabWidget.get());
	setLayout(m_MainLayout.get());
}
void ProfileDialog::InitHomePage()
{
	////auto HomePageTab = ;
	//tabWidget_Profile->mainLa
	//	//addTab(new HomePage(), QString("Home").arg(tabWidget_Profile->count() + 1));
}
