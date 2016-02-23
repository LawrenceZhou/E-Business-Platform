#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <QString>
class BankAccount;
class BankAccount
{
private:
    QString bankaccountnumber;
    QString lastname;
    QString firstname;
    QString nationality;
    QString bankname;
    QString gender;
    QString id;
    QString password;
    QString birthdate;
    QString phonenumber;
    QString address;
    float  balance;
    static int netpay;
    static int frozen;
    static int sum;
    static int sumzg;
    static int sumzd;
    static int summgdt;
    static int sumhf;
    static int sumhq;
    void SetBankAccountNumber();
public:
    BankAccount(QString ln, QString fn, QString na, QString bn, QString ge, QString in, QString pw, QString bd, QString pn, QString ad );
    QString getBankAccountNumber() const;
    QString getBankName()const;
    QString getPassword()const;
    QString getLastName()const;
    QString getFirstName()const;
    QString getId()const;
    QString getNationality()const;
    QString getGender()const;
    QString getPhoneNumber()const;
    QString getAddress()const;
    QString getBirthDate()const;
    float getBalance()const;
    int getFrozen()const;
    int getNetpay()const;
    int getSum()const;
    int getHfSum()const;
    int getHqSum()const;
    int getMgdtSum()const;
    int getZdSum()const;
    int getZgSum()const;
};

#endif //BANKACCOUNT_H
