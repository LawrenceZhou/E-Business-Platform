#include "database.h"
#include <QtCore>
#include <QtDebug>
#include <QTextCodec>
#include <QMessageBox>
#include <QTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QSqlTableModel>
#include "bankaccount.h"
#include <QObject>



bool createConnection()
{
    bool IsExist = QFile::exists("bankaccount.db");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bankaccount.db");
    db.open();
    if (!IsExist)
    {
        QSqlQuery query;
        qDebug() << "Start to create table...";
        bool success=query.exec("create table bankaccount(bankaccountnumber varchar primary key, password varchar, bankname varchar, lastname varchar, firstname varchar,  id varchar,  gender varchar, nationality varchar, balance float , netpay int, frozen int, birthdate varchar, phonennumber varchar, address varchar, sum int, hfsum int, hqsum int, mgdtsum int, zdsum int, zgsum int  )");

        if (success)
        {
            qDebug() << "数据库表创建成功！";
            return true;
        }
        else
        {
            qDebug()<< query.lastError();
            qDebug() << "数据库表创建失败！";
        }
        return false;
    }
    else
    {
        qDebug()<<"数据库已存在！";
    }

    return true;
}

bool addAccount( BankAccount BA )
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bankaccount.db");
    if (!db.isOpen())
    {
        createConnection();
    }
    QSqlQuery query;
    qDebug() << "start to insert data";
    query.prepare("insert into bankaccount(bankaccountnumber, password, bankname, lastname, firstname,  id,  gender, nationality, balance, netpay, frozen, birthdate, phonennumber, address, sum , hfsum, hqsum, mgdtsum, zdsum, zgsum)"" VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");

    query.addBindValue(BA.getBankAccountNumber());
    query.addBindValue(BA.getPassword());
    query.addBindValue(BA.getBankName());
    query.addBindValue(BA.getLastName());
    query.addBindValue(BA.getFirstName());
    query.addBindValue(BA.getId());
    query.addBindValue(BA.getGender());
    query.addBindValue(BA.getNationality());
    query.addBindValue(BA.getBalance());
    query.addBindValue(BA.getNetpay());
    query.addBindValue(BA.getFrozen());
    query.addBindValue(BA.getBirthDate());
    query.addBindValue(BA.getPhoneNumber());
    query.addBindValue(BA.getAddress());
    query.addBindValue(BA.getSum());
    query.addBindValue(BA.getHfSum());
    query.addBindValue(BA.getHqSum());
    query.addBindValue(BA.getMgdtSum());
    query.addBindValue(BA.getZdSum());
    query.addBindValue(BA.getZgSum());
    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug()<<lastError.driverText()<<"charushibai";
        return false;
    }
    return true;
}

