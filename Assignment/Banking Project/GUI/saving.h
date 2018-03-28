#ifndef SAVING_H
#define SAVING_H
#include "account.h"

class saving: public account
{
private:
    float interest_rate;
public:
    saving(QString number, double balance);
    virtual ~saving();
    void deposit(double);
    bool withdraw(double);
    bool transfer(double);

    QString getAccNum();
    double getBalance();
    void setBalance(double);
};

#endif // SAVING_H
