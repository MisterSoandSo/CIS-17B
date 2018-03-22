#include <iostream>
#include <fstream>
#include "login.h"

using namespace std;

struct DataBase
{
    string username;
    string password;
    int account_checking;
    int account_saving;
    double checking_bal;
    double saving_bal;
};


double OD_FEE = 1.00;
float int_RATE = 0.001;
bool login_status = false;

int main()
{
    int num_accounts;
    string login_user, login_pword;


    ofstream io_account;
    io_account.open("accountinfo.txt", ios::out | ios::in );
    io_account >> num_accounts;

    DataBase D_user[num_accounts];

    for (int i = 0; i< num_accounts; i++)
    {
        io_account >> D_user[i].username;
        io_account >> D_user[i].password;
        io_account >> D_user[i].account_checking;
        io_account >> D_user[i].checking_bal;
        io_account >> D_user[i].account_saving;
        io_account >> D_user[i].saving_bal;
    }

    //login

    while(!login_status)
    {
       cout<<"Username: ";
       cin>>login_user;
       cout<<"\nPassword: "
       cin>> login_pword;
       for (int i = 0;i< num_accounts; i++)
       {
           if(login_check(D_user[i].username,D_user[i].password, login_user, login_pword))
            login_status = true;
            //create user with  accounts
            user current(login_user,D_user[i].account_checking, D_user[i].checking_bal,
                 0.0001,D_user[i].account_saving,D_user[i].saving_bal);
                 break;
       }
    }



    account.close();
    return 0;
}
