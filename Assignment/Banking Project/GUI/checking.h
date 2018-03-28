#ifndef CHECKING_H
#define CHECKING_H

#include "account.h"

class checking: public account
{
private:
    double overdraft_fee;
public:
    checking(QString number, double balance);
    virtual ~checking();
    void deposit(double);
    bool withdraw(double);
    bool transfer(double);

    QString getAccNum();
    double getBalance();
    void setBalance(double);

};

#endif // CHECKING_H
