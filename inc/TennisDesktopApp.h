#pragma once
#include <memory>
#include <QtWidgets/QMainWindow>
#include "ui_TennisDesktopApp.h"
#include "IQTComponent.h"
class ProfileDialog;
class TennisDesktopApp : public QMainWindow, public IQTComponent
{
    Q_OBJECT

public:
    TennisDesktopApp(QWidget *parent = nullptr);
    ~TennisDesktopApp();
    void InitCustomComponents() override final;
private:
    void InitializePicture(QLabel* pPicLabel, std::string sPicAddress);
    Ui::TennisDesktopAppClass ui;
    std::unique_ptr<ProfileDialog> m_upProfileDialog{nullptr};
    std::string m_sAppName{};

private slots:
    void on_continueButton_clicked();
};
