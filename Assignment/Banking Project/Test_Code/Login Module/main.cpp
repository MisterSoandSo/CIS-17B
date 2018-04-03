#include <QApplication>

#include "login.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Login client;
    client.show();
    return app.exec();
}
