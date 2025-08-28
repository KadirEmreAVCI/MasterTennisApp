#include <iostream>
#include <QWidgetAction>
#include "MasterTennisApp.h"
#include "AppController.h"
#include "ProfileSelectionDialog.h"
#include "OrganizationDialog.h"
MasterTennisApp::MasterTennisApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_upOrganizationDialog = std::make_unique<OrganizationDialog>(this);
    m_upProfileSelectionDialog = std::make_unique<ProfileSelectionDialog>(this);
    InitCustomComponents();
}
MasterTennisApp::~MasterTennisApp()
{}
void MasterTennisApp::InitCustomComponents()
{
    ui.label_WelcomeText->setText(QString::fromStdString("Welcome To The " + AppController::instance().GetAppName() + "!"));
    InitPicture(ui.label_LoginPic, ":/images/welcome2.png", 10.0f);
    setFixedSize(800, 600);
    setWindowTitle(QString::fromStdString(AppController::instance().GetAppName()));
}
void MasterTennisApp::on_StartButton_clicked()
{
    m_upProfileSelectionDialog->setModal(true);
    m_upProfileSelectionDialog->exec();
}
void MasterTennisApp::on_ManageButton_clicked()
{
    std::cout << "MasterTennisApp::on_ManageButton_clicked\n";
    m_upOrganizationDialog->DisplayOrganizations();
    m_upOrganizationDialog->setModal(true);
    m_upOrganizationDialog->exec();
}

