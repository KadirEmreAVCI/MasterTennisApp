#pragma once
#include <memory>
#include <QtWidgets/QMainWindow>
#include "ui_TennisDesktopApp.h"
class ProfileDialog;
class TennisDesktopApp : public QMainWindow
{
    Q_OBJECT

public:
    TennisDesktopApp(QWidget *parent = nullptr);
    ~TennisDesktopApp();
    void InitializeCustomComponents();
    void setImageFolderLoc(std::string);
private:
    void InitializePicture(QLabel* pPicLabel, std::string sPicAddress);
    Ui::TennisDesktopAppClass ui;
    std::unique_ptr<ProfileDialog> m_upProfileDialog{nullptr};
    std::string m_sAppName{};
    std::string m_sImageFolderLoc{};

private slots:
    void on_continueButton_clicked();
};
