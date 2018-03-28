#ifndef DATABASE_H
#define DATABASE_H

#include <QtWidgets>

class database
{
private:

    QString username;
    QString password;
    int account_checking;
    int account_saving;
    double checking_bal;
    double saving_bal;
    double OD_FEE = 1.00;
    float  int_RATE = 0.001;
public:
    database();
    database(QString uName,QString pWord,int acc_checking,
                double check_bal,int acc_saving,double sav_bal);
    QString getUser();
    QString getPwd();
    int getAccCheck();
    int getAccSave();
    double getchecking_bal();
    double getsaving_bal();
    double getOD_FEE();
    float getint_RATE();
    database operator=(const database& b);
};

#endif // DATABASE_H
