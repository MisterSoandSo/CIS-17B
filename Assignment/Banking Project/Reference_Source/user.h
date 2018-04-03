#ifndef USER_H
#define USER_H

#include <QtWidgets>
#include "checking.h"
#include "saving.h"

class user
{
private:

    QString username;
    QString password;
    QString account_checking;
    double checking_bal;
    QString account_saving;
    double saving_bal;
public:

    user();
    user(QString uName,QString pWord,int acc_checking,
                double check_bal,int acc_saving,double sav_bal);
    ~user();

    QString getUser();
    QString getPwd();

    QString getAccNumC();
    QString getBalanceC();
    QString getAccNumS();
    QString getBalanceS();

};

#endif // USER_H
