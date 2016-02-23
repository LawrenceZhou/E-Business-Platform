#ifndef USER_H
#define USER_H
#include <QString>
#include "commodity.h"
class User
{
private:
    QString username;
    QString gender;
    QString password;
    QString receivername;
    QString phonenumber;
    QString address;
    QString banknumber;
    int bankbound;
public:
    User(QString uname, QString g, QString pw, QString rname, QString phone, QString ad);
    QString getUsername();
    QString getGender();
    QString getPassword();
    QString getReceivername();
    QString getPhonenumber();
    QString getAddress();
    QString getBanknumber();
    int getBankbound();
};
#endif // USER_H
