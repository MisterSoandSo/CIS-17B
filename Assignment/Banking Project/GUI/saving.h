#ifndef SAVING_H
#define SAVING_H
#include "account.h"

class saving: public account
{
private:
    string accountNumber;
    double accountBalance;
    float interest_rate;
public:
    saving(string number, double balance);
    virtual ~saving();
    void deposit(double);
    bool withdraw(double);
    bool transfer(double);
    void getName();
    void setName();
    void getBalance();
    void setBalance();
};

#endif // SAVING_H
