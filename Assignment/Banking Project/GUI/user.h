#ifndef USER_H
#define USER_H

#include <QtWidgets>


class user
{
private:

    QString username;
    QString password;
    //QString account_checking;
    //double checking_bal;
    //QString account_saving;
    //double saving_bal;
public:

    user();
    user(QString uName,QString pWord);
    ~user();

    QString getUser();
    QString getPwd();
    void setUser(QString);
    void setPwd(QString);
    user operator=(const user& b);


};

#endif // USER_H
