#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

class account
{
private:
    string accountNumber;
    double accountBalance;
public:
    account();
    account(string number, double balance);
    virtual ~account();
    virtual void deposit(double);
    virtual bool withdraw(double);
    bool transfer(double);
    void getName();
    void setName();
    double getBalance();
    void setBalance();


};

#endif // ACCOUNT_H
