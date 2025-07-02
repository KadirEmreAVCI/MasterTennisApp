//#define RUN_TESTS
#ifdef RUN_TESTS
#include <gtest/gtest.h>
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#else
#include "TennisDesktopApp.h"
#include <QtWidgets/QApplication>
#include "AppController.h"
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    AppController::instance().StartApplication();
    return a.exec();
}
#endif