#include "bankaccount.h"
#include <QString>
#include <QDebug>
#include "database.h"

BankAccount::BankAccount(QString ln, QString fn, QString na, QString bn, QString ge, QString in, QString pw, QString bd, QString pn, QString ad )
{
    QSqlQuery query;
    query.exec("SELECT * FROM bankaccount");
    query.last();

    frozen=0;
    netpay=0;
    lastname=ln;
    firstname=fn;
    nationality=na;
    bankname=bn;
    gender=ge;
    id=in;
    password=pw;
    birthdate=bd;
    phonenumber=pn;
    address=ad;
    sum=query.value(14).toInt()+1;
    balance=0;

    if(bn=="花旗银行")
    {
        sumhq=query.value(16).toInt()+1;
        int a=1000+sumhq;
        bankaccountnumber=QString::number(a,10);
    }
    else if(bn=="汇丰银行")
    {
        sumhf=query.value(15).toInt()+1;
        int a=2000+sumhf;
        bankaccountnumber=QString::number(a,10);
    }
    else if(bn=="摩根大通银行")
    {
        summgdt=query.value(17).toInt()+1;
        int a=3000+summgdt;
        bankaccountnumber=QString::number(a,10);
    }
    else if(bn=="渣打银行")
    {
        sumzd=query.value(18).toInt()+1;
        int a=4000+sumzd;
        bankaccountnumber=QString::number(a,10);
    }
    else if(bn=="中国银行")
    {
        sumzg=query.value(19).toInt()+1;
        int a=5000+sumzg;
        bankaccountnumber=QString::number(a,10);
    }
}
int BankAccount::getFrozen()const
{
    return frozen;
}
int BankAccount::getNetpay()const
{
    return netpay;
}
float BankAccount::getBalance()const
{
    return balance;
}

QString BankAccount::getBankAccountNumber() const
{
    return bankaccountnumber;
}
QString BankAccount::getLastName() const
{
    return lastname;
}
QString BankAccount::getFirstName() const
{
    return firstname;
}
QString BankAccount::getBankName() const
{
    return bankname;
}
QString BankAccount::getPassword() const
{
    return password;
}
QString BankAccount::getBirthDate()const
{
    return birthdate;
}
QString BankAccount::getAddress() const
{
    return address;
}
QString BankAccount::getId() const
{
    return id;
}
QString BankAccount::getPhoneNumber() const
{
    return phonenumber;
}
QString BankAccount::getGender() const
{
    return gender;
}
QString BankAccount::getNationality() const
{
    return nationality;
}
int BankAccount::getSum() const
{
    return sum;
}
int BankAccount::getHfSum() const
{
    return sumhf;
}
int BankAccount::getHqSum() const
{
    return sumhq;
}
int BankAccount::getMgdtSum() const
{
    return summgdt;
}
int BankAccount::getZdSum() const
{
    return sumzd;
}
int BankAccount::getZgSum() const
{
    return sumzg;
}

int BankAccount::netpay=0;
int BankAccount::frozen=0;
int BankAccount::sum=0;
int BankAccount::sumzg=0;
int BankAccount::sumzd=0;
int BankAccount::summgdt=0;
int BankAccount::sumhf=0;
int BankAccount::sumhq=0;

