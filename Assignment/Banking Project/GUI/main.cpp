#include <QApplication>
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include "account.h"
#include "checking.h"
#include "saving.h"

struct DataBase
{
    QString username;
    QString password;
    int account_checking;
    int account_saving;
    double checking_bal;
    double saving_bal;
    double OD_FEE = 1.00;
    float  int_RATE = 0.001;
};

int main(int argc, char *argv[])
{
    QFile inputFile("accountinfo.txt");
    QString line,login_user, login_pword;
    int num_accounts;
    DataBase D_user[40];
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       num_accounts = in.readLine().toInt();    //first line reads # of accounts

       for (int i = 0; i< num_accounts; i++)
       {
           D_user[i].username = in.readLine();
           D_user[i].password = in.readLine();
           D_user[i].account_checking = in.readLine().toInt();
           D_user[i].checking_bal = in.readLine().toDouble();
           D_user[i].account_saving = in.readLine().toInt();
           D_user[i].saving_bal = in.readLine().toDouble();
       }
       inputFile.close();
    }


    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    return app.exec();
}
