#include "login.h"

login::login()
{
    //ctor
}

login::~login()
{
    //dtor
}

bool login::login_check(string d_user,string d_pword, string i_user, string i_pword)
{
    if(d_user == i_user)
    {
        if(d_pword == i_pword) return true;
    }
    return false;
}
