#include "database.h"

database::database()    //default
{
    username = "default";
    password = "default";
    account_checking = 9999;
    checking_bal = 0.00;
    account_saving = 9998;
    saving_bal = 0.00;
}
database::database(QString uName,QString pWord,int acc_checking,
                   double check_bal,int acc_saving,double sav_bal)
{
    username = uName;
    password = pWord;
    account_checking = acc_checking;
    checking_bal = check_bal;
    account_saving = acc_saving;
    saving_bal = sav_bal;
}
QString database::getUser()
{
    return username;
}
QString database::getPwd()
{
    return password;
}
int database::getAccCheck()
{
    return account_checking;
}
int database::getAccSave()
{
    return account_saving;
}
double database::getchecking_bal()
{
    return checking_bal;
}
double database::getsaving_bal()
{
    return saving_bal;
}
double database::getOD_FEE()
{
    return OD_FEE;
}
float database::getint_RATE()
{
    return int_RATE;
}
database database::operator=(const database& b)
{
    database data;
    data.username = b.username;
    data.password = b.password;
    data.account_checking = b.account_checking;
    data.checking_bal = b.checking_bal;
    data.account_saving = b.account_saving;
    data.saving_bal = b.saving_bal;
    return data;

}
