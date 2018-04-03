#include "checking.h"


checking::checking(string number, double balance):
     account(number, balance)
{

}
checking::~checking()
{

}
void checking::deposit(double money)
{
    accountBalance += money;
}
bool checking::withdraw(double money)
{
    return false;
}
