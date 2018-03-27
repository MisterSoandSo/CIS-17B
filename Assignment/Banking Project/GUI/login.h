#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
using namespace std;
class login
{
    public:
        login();
        virtual ~login();
        bool login_check(string,string, string, string);

};

#endif // LOGIN_H
