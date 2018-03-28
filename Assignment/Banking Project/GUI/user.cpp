#include "user.h"
/*
#include "checking.h"
#include "saving.h"

user::user():    //default
    AC(QString::fromStdString("9999"),0.00),
    AS(QString::fromStdString("9998"),0.00),username("default"),
    password("default")
{

}
user::user(QString uName,QString pWord,int acc_checking,double check_bal,int acc_saving,double sav_bal):
    checking::AC(QString::number(acc_checking),check_bal),
saving::AS(QString::number(acc_saving),sav_bal),username(uName),
password(pWord)
{

}*/
user::user()
{
    username="default";
    password="default";
    account_checking="9999";
    checking_bal=0.00;
    account_saving="9998";
    saving_bal=0.00;
}
user::user(QString uName,QString pWord,int acc_checking,
     double check_bal,int acc_saving,double sav_bal)
{
    username=uName;
    password=pWord;
    account_checking=QString::number(acc_checking);
    checking_bal=check_bal;
    account_saving=QString::number(acc_saving);
    saving_bal=sav_bal;
}
user::~user()
{

}

QString user::getUser()
{
    return username;
}
QString user::getPwd()
{
    return password;
}

QString user::getAccNumC()
{
    return account_checking;
}
QString user::getBalanceC()
{
    return QString::number(checking_bal);
}
QString user::getAccNumS()
{
    return account_saving;
}
QString user::getBalanceS()
{
    return QString::number(saving_bal);
}


/*
user user::operator=(const user& b)
{
    user data;
    data.username = b.username;
    data.password = b.password;
    data.account_checking = b.account_checking;
    data.checking_bal = b.checking_bal;
    data.account_saving = b.account_saving;
    data.saving_bal = b.saving_bal;
    return data;

}*/
