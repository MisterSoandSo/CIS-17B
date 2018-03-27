#ifndef USER_H
#define USER_H
#include "checking.h"
#include "saving.h"
#include <iostream>
using namespace std;

class user
{
private:
    string name;
public:
        user(string u_name,string c_num, double c_bal,string s_num,double s_bal);
        ~user();
};

#endif // USER_H
