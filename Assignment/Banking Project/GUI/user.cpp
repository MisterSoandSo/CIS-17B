#include "user.h"

user::user(string u_name,string c_num, double c_bal,string s_num,double s_bal)
{
    name = u_name;
    checking(c_num,c_bal);
    saving(s_num,s_bal);
}

user::~user()
{
    //dtor
}
