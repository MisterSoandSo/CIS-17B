#include "saving.h"

saving::saving(float int_rate,string number, double balance):
    account(number, balance),interest_rate(int_rate)
{

}
saving::~saving()
{

}
void saving::deposit(double money)
{
    accountBalance += money;
}
bool saving::withdraw(double)
{
    return false;
}
