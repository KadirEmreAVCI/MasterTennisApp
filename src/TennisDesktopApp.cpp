#include <iostream>
#include <QWidgetAction>
#include "TennisDesktopApp.h"
#include "AppController.h"
#include "ProfileSelectionDialog.h"
#include "OrganizationDialog.h"
TennisDesktopApp::TennisDesktopApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_upOrganizationDialog = std::make_unique<OrganizationDialog>(this);
    m_upProfileSelectionDialog = std::make_unique<ProfileSelectionDialog>(this);
    InitCustomComponents();
}
TennisDesktopApp::~TennisDesktopApp()
{}
void TennisDesktopApp::InitCustomComponents()
{
    ui.label_WelcomeText->setText(QString::fromStdString("Welcome To The " + AppController::instance().GetAppName() + "!"));
    InitPicture(ui.label_LoginPic, ":/images/images/welcome2.png", 10.0f);
    setFixedSize(800, 600);
    setWindowTitle(QString::fromStdString(AppController::instance().GetAppName()));
}
void TennisDesktopApp::on_StartButton_clicked()
{
    m_upProfileSelectionDialog->setModal(true);
    m_upProfileSelectionDialog->exec();
}
void TennisDesktopApp::on_OrganizationsButton_clicked()
{
    std::cout << "TennisDesktopApp::on_OrganizationsButton_clicked\n";
    m_upOrganizationDialog->DisplayOrganizations();
    m_upOrganizationDialog->setModal(true);
    m_upOrganizationDialog->exec();
}

