#pragma once
#include <memory>
#include <QtWidgets/QMainWindow>
#include "ui_TennisDesktopApp.h"
#include "IQTComponent.h"
class OnboardingDialog;
class ProfileSelectionDialog;
class OrganizationDialog;
class TennisDesktopApp : public QMainWindow, public IQTComponent
{
    Q_OBJECT

public:
    TennisDesktopApp(QWidget *parent = nullptr);
    ~TennisDesktopApp();
    void InitCustomComponents() override final;
private:
    Ui::TennisDesktopAppClass ui;
    std::unique_ptr<ProfileSelectionDialog> m_upProfileSelectionDialog{nullptr};
    std::unique_ptr<OrganizationDialog> m_upOrganizationDialog{ nullptr };
    std::string m_sAppName{};
private slots:
    void on_StartButton_clicked();
    void on_OrganizationsButton_clicked();
};
