#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <QString>


class account
{
private:
    QString accountNumber;
    double accountBalance;
public:
    account();
    account(QString number, double balance);
    virtual ~account();
    virtual void deposit(double);
    virtual bool withdraw(double);
    bool transfer(double);

    QString getAccNum();
    double getBalance();
    void setBalance(double);
    account operator=(const account& b);


};

#endif // ACCOUNT_H
