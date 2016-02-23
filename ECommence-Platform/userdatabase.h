#ifndef USERDATABASE_H
#define USERDATABASE_H
#include"user.h"
#include <QObject>


bool createUserConnection();
bool addUser( User U );
bool searchUser(QString username);
bool confirmation(QString username, QString password);
QString returnsex(QString username);
QString returnname(QString username);
QString returnphone(QString username);
QString returnaddress(QString username);
int returnbankbound(QString username);
bool renew(QString username, QString newname, QString newphone, QString newaddress);
bool openbankbound(QString username);
bool closebankbound(QString username);
QString returnbanknumber(QString username);


#endif // USERDATABASE_H
