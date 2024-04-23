#include "TennisDesktopApp.h"
#include "GUIController.h"
TennisDesktopApp::TennisDesktopApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    InitializeCustomComponents();
}

TennisDesktopApp::~TennisDesktopApp()
{}

void TennisDesktopApp::InitializeCustomComponents()
{
    ui.label_WelcomeText->setText(QString::fromStdString("Welcome To The " + GUIController::getms_sAppName() + "!"));
    GUIController::InitializePicture(ui.labelLoginPic, "login_button.png");
}

