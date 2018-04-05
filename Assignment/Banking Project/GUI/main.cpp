#include <QApplication>
#include <QMainWindow>

#include "mainwindow.h"
#include "user.h"


//#include "account.h"
//#include "checking.h"
//#include "saving.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //user TestUser("Manual Tester","password",1234,8108.99,5678,9874.56);

    user TestUser("username","password");
    MainWindow window(TestUser);

    window.show();
    return app.exec();




}
