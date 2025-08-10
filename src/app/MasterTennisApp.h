#ifndef MASTERTENNISAPP_H
#define MASTERTENNISAPP_H

#include <memory>
#include <QtWidgets/QMainWindow>
#include "ui_MasterTennisApp.h"
#include "IQTComponent.h"
class OnboardingDialog;
class ProfileSelectionDialog;
class OrganizationDialog;
class MasterTennisApp : public QMainWindow, public IQTComponent
{
    Q_OBJECT

public:
    MasterTennisApp(QWidget *parent = nullptr);
    ~MasterTennisApp();
    void InitCustomComponents() override final;
private:
    Ui::MasterTennisAppClass ui;
    std::unique_ptr<ProfileSelectionDialog> m_upProfileSelectionDialog{nullptr};
    std::unique_ptr<OrganizationDialog> m_upOrganizationDialog{ nullptr };
    std::string m_sAppName{};
private slots:
    void on_StartButton_clicked();
    void on_OrganizationsButton_clicked();
};

#endif