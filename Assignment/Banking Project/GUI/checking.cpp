#include "checking.h"


checking::checking(double od_fee,string number, double balance):
     overdraft_fee(od_fee), account(number, balance)
{

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
