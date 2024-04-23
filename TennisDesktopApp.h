#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_TennisDesktopApp.h"

class TennisDesktopApp : public QMainWindow
{
    Q_OBJECT

public:
    TennisDesktopApp(QWidget *parent = nullptr);
    ~TennisDesktopApp();
    void setImageFolderLoc(std::string);
private:
    void InitializePicture(QLabel* pPicLabel, std::string sPicAddress);
    void InitializeCustomComponents();
    Ui::TennisDesktopAppClass ui;
    std::string m_sAppName{};
    std::string m_sImageFolderLoc{};
};
