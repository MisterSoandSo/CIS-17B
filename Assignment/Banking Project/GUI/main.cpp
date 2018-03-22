#include <QApplication>

#include "mainwindow.h"
#include "account.h"
#include "checking.h"
#include "saving.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    return app.exec();
}
