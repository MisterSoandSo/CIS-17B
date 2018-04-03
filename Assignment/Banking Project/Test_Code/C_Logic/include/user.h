#ifndef USER_H
#define USER_H

#include "checking.h"
#include "saving.h"

class user
{
    public:
        user(string, double,string, double, float,string,double));
        virtual ~user();

    protected:

    private:
        string name;
};

#endif // USER_H
