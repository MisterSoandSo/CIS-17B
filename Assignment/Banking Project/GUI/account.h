#ifndef ACCOUNT_H
#define ACCOUNT_H


class account
{
private:
    string accountNumber;
    double accountBalance;
public:
    account();
    account(string number, double balance);
    void deposit();
    void withdraw();
    void transfer();
    void getName();
    void setName();
    void getBalance();
    void setBalance();
    void updateBalance();

};

#endif // ACCOUNT_H
