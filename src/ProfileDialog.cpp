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
	InitializeCustomComponents();
}

ProfileDialog::~ProfileDialog()
{}

void ProfileDialog::InitializeCustomComponents()
{
	std::cout << "ProfileDialog::InitializeCustomComponents\n";
	m_upTabWidget = std::make_unique<QTabWidget>();
	m_upTabWidget->addTab(new HomePage(), QString("Home"));
	m_upTabWidget->addTab(new StatisticsPage(), QString("Statistics"));
	m_upTabWidget->addTab(new AchievementsPage(), QString("Achievements"));
	m_upTabWidget->addTab(new HistoryPage(), QString("History"));
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
