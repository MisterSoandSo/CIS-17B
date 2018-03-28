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

    /*
    QFile inputFile("accountinfo.txt");
    QString line,login_user, login_pword;
    int num_accounts;
    user D_user[40];
    */
    user TestUser("Manual Tester","password",1234,8108.99,5678,9874.56);
/*
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       num_accounts = in.readLine().toInt();    //first line reads # of accounts

       for (int i = 0; i< num_accounts; i++)
       {
           QString t_username = in.readLine();
           QString t_password = in.readLine();
           int t_account_checking = in.readLine().toInt();
           double t_checking_bal = in.readLine().toDouble();
           int t_account_saving = in.readLine().toInt();
           double t_saving_bal = in.readLine().toDouble();
           user t_user(t_username,t_password,t_account_checking,t_checking_bal,t_account_saving,t_saving_bal);
           D_user[i] = t_user;
       }
       inputFile.close();

       MainWindow window(D_user[0]);
       window.show();
       return app.exec();
   }
    else
    {*/
        //if read fails
        MainWindow window(TestUser);
        window.show();
        return app.exec();
    //}



}
