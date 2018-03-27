#include "account.h"

account::account()
{
    accountNumber = "0000";
    accountBalance = 0.00;
}
account::account(string number, double balance)
{
    accountNumber = number;
    accountBalance = balance;
}
account::~account()
{

}
void account::deposit(double money)
{
    //deposit money into account
    accountBalance += money;
}

bool account::withdraw(double money)
{
    if(money == 0.00)    //withdraw $0 case
    {
        return true;
    }
    else if(this->accountBalance < money)    //we dont have enough money
    {
        cout <<"You do not have enough cash in account"<<endl;
        //saving - to mininimum of $0
        //return false;
        //checking - apply overdraft fee
    }
    else if(this->accountBalance >= money)    //we have enough money
    {
        accountBalance -= money;
        return true;
    }
    return false;
}
bool account::transfer(double money)
{
    //call withdraw function
    if(this->withdraw(money))
    {
        //if true
        //deposit function
    }
    //else return false not enough money
    return false;
}

double account::getBalance()
{
    return accountBalance;
}
void account::setBalance(double money)
{
    accountBalance = money;
}
