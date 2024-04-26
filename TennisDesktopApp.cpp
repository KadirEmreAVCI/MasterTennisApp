#include <iostream>
#include "TennisDesktopApp.h"
#include "GUIController.h"
#include "ProfileDialog.h"
TennisDesktopApp::TennisDesktopApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

TennisDesktopApp::~TennisDesktopApp()
{}

void TennisDesktopApp::InitializeCustomComponents()
{
    ui.label_WelcomeText->setText(QString::fromStdString("Welcome To The " + GUIController::instance().getAppName() + "!"));
    InitializePicture(ui.label_LoginPic, "welcome_img.png");
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
void TennisDesktopApp::on_continueButton_clicked()
{
    std::cout << "Continue button clicked\n";
    m_upProfileDialog = std::make_unique<ProfileDialog>(this);
    m_upProfileDialog->setModal(true);
    hide();
    m_upProfileDialog->exec();
}

