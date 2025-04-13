#include <iostream>
#include <string>
#include "TennisDesktopApp.h"
#include <QtWidgets/QApplication>
#include "AppController.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppController::instance().StartApplication();
    return a.exec();
}
