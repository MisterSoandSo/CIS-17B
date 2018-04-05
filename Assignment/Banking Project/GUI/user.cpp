#include "user.h"

user::user()
{
    username="default";
    password="default";
}
user::user(QString uName,QString pWord)
{
    username=uName;
    password=pWord;
}
user::~user()
{

}
void user::setUser(QString x)
{
    username = x;
}
void user::setPwd(QString x)
{
    password = x;
}

QString user::getUser()
{
    return username;
}
QString user::getPwd()
{
    return password;
}
