#include <string>
#include "TennisDesktopApp.h"
#include <QtWidgets/QApplication>
#include "GUIController.h"
std::string g_AppName{"Master Tennis Application"};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIController::instance();
    return a.exec();
}
