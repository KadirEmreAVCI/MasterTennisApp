#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TennisDesktopApp.h"

class TennisDesktopApp : public QMainWindow
{
    Q_OBJECT

public:
    TennisDesktopApp(QWidget *parent = nullptr);
    ~TennisDesktopApp();

private:
    Ui::TennisDesktopAppClass ui;
};
