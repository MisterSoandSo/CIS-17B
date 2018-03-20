#ifndef CHECKING_H
#define CHECKING_H

#include "account.h"

class checking: public account
{
private:
    string accountNumber;
    double accountBalance;
    double overdraft_fee = 0;
public:
    checking(double od_fee,string number, double balance);
    virtual ~checking();
    void deposit(double);
    bool withdraw(double);
    bool transfer(double);
    void getName();
    void setName();
    void getBalance();
    void setBalance();

};

#endif // CHECKING_H
