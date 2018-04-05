#include <QtWidgets>

#include "login.h"
#include "user.h"

Login::Login(user &user_data)
{
    setUserPass(user_data);
}

void Login::setUserPass(user &user_data)
{
    userInput = user_data.getUser();
    passInput = user_data.getPwd();
}
bool Login::getLogStat()
{
    return login_status;
}
void Login::setLogStat(bool b_check)
{
    login_status = b_check;
}
void Login::requestLogincheck(QString inUser, QString inPass)
{
    bool valid_user((inUser==userInput) && (inPass == passInput));
    if(valid_user)
    {
        setLogStat(true);
    }
    else
    {
        setLogStat(false);
    }
}

