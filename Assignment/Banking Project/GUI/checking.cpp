#include "checking.h"


checking::checking(string number, double balance):
     account(number, balance)
{
    overdraft_fee=1.5;
}
checking::~checking()
{

}
void checking::deposit(double)
{

}
bool checking::withdraw(double)
{
    return false;
}
