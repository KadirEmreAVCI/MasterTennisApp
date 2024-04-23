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
    ui.label_WelcomeText->setText(QString::fromStdString("Welcome To The " + GUIController::instance().getAppName() + "!"));
    InitializePicture(ui.labelLoginPic, "login_button.png");
}

void TennisDesktopApp::setImageFolderLoc(std::string sImageFolderLoc)
{
    m_sImageFolderLoc = sImageFolderLoc;
}

void TennisDesktopApp::InitializePicture(QLabel* pPicLabel, std::string sPicAddress)
{
    QPixmap pix{ QString::fromStdString(m_sImageFolderLoc + sPicAddress) };
    const int iHeight = pPicLabel->height();
    const int iWidth = pPicLabel->width();
    pPicLabel->setPixmap(pix.scaled(iWidth, iHeight, Qt::KeepAspectRatio));
}

