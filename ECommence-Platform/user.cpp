#include "user.h"

User::User(QString uname, QString g, QString pw, QString rname, QString phone, QString ad)
{
    username=uname;
    gender=g;
    password=pw;
    receivername=rname;
    phonenumber=phone;
    address=ad;
    bankbound=0;
    banknumber="";
}

QString User::getUsername()
{
    return username;
}

QString User::getGender()
{
    return gender;
}

QString User::getPassword()
{
    return password;
}

QString User::getReceivername()
{
    return receivername;
}

QString User::getPhonenumber()
{
    return phonenumber;
}

QString User::getAddress()
{
    return address;
}

int User::getBankbound()
{
    return bankbound;
}
QString User::getBanknumber()
{
    return banknumber;
}
