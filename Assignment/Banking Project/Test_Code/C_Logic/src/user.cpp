#include "user.h"

user::user(string u_name,string c_num, double c_bal, float int_rate,string s_num,double s_bal)
{
    name = u_name;
    checking(c_num,c_bal);
    saving(int_rate,s_num,s_bal);
}

user::~user()
{
    //dtor
}
