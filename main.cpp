#include <string>
#include "TennisDesktopApp.h"
#include <QtWidgets/QApplication>
#include "GUIController.h"
std::string g_AppName{"Master Tennis App"};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIController::create(g_AppName, std::string{"images/"});
    return a.exec();
}
