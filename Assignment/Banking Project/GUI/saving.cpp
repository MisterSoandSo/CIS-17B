#include "saving.h"


saving::saving(float int_rate,string number, double balance):
    interest_rate(int_rate),account(number,balance)
{

}
saving::~saving()
{

}
void saving::deposit(double)
{

}
bool saving::withdraw(double)
{
    return false;
}
