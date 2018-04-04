#include <QApplication>
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include "account.h"
#include "checking.h"
#include "saving.h"
#include "user.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //user TestUser("Manual Tester","password",1234,8108.99,5678,9874.56);

    //MainWindow window(TestUser);
    MainWindow window;
    window.show();
    return app.exec();




}
