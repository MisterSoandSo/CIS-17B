#ifndef CHECKING_H
#define CHECKING_H

#include "account.h"

class checking: public account
{
    private:
        double overdraft_fee = 1.00;
    public:
        checking(string number, double balance);
        virtual ~checking();
        void deposit(double);
        bool withdraw(double);
        bool transfer(double);
        string getNumber();
        void setNumber();
        void getBalance();
        void setBalance();

};

#endif // CHECKING_H
