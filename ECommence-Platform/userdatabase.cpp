#include "userdatabase.h"
#include "user.h"
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
#include <QObject>

bool createUserConnection()
{
    bool IsExist = QFile::exists("user.db");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    db.open();
    if (!IsExist)
    {
        QSqlQuery query;
        qDebug() << "Start to create table...";
        bool success=query.exec("create table user(username varchar primary key, gender vchar, password vchar, receivername vchar, phonenumber vchar, address vchar, bankbound int, banknumber vchar)");

        if (success)
        {
            qDebug() << "user数据库表创建成功！";
            return true;
        }
        else
        {
            qDebug()<< query.lastError();
            qDebug() << "user数据库表创建失败！";
        }
        return false;
    }
    else
    {
        qDebug()<<"数据库已存在！";
    }

    return true;
}

bool addUser( User U )
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if (!db.isOpen())
    {
        createUserConnection();
    }
    QSqlQuery query;
    qDebug() << "start to insert user data";
    query.prepare("insert into user(username, gender, password, receivername, phonenumber, address, bankbound, banknumber)"" VALUES(?,?,?,?,?,?,?,?)");

    query.addBindValue(U.getUsername());
    query.addBindValue(U.getGender());
    query.addBindValue(U.getPassword());
    query.addBindValue(U.getReceivername());
    query.addBindValue(U.getPhonenumber());
    query.addBindValue(U.getAddress());
    query.addBindValue(U.getBankbound());
    query.addBindValue(U.getBanknumber());

    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug()<<lastError.driverText()<<"USERcharushibai";
        return false;
    }
    return true;
}

bool searchUser(QString username)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if (!db.isOpen())
    {
        createUserConnection();
    }
    QSqlTableModel model;
    model.setTable("user");
    model.setFilter(QObject::tr("username='%1'").arg(username));
    model.select();
    if(model.rowCount()==1)//查询到有一个结果
    {
        return true;
    }else
    {
        return false;
    }
}

bool confirmation(QString username, QString password)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if (!db.isOpen())
    {
        createUserConnection();
    }
    QSqlTableModel model;
    model.setTable("user");
    model.setFilter(QObject::tr("username='%1' and password='%2'").arg(username).arg(password));
    model.select();
    if(model.rowCount()==1)//查询到有一个结果
    {
        return true;
    }else
    {
        return false;
    }
}

QString returnsex(QString username)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if (!db.isOpen())
    {
        createUserConnection();
    }
    QSqlTableModel model;
    model.setTable("user");
    model.setFilter(QObject::tr("username='%1'").arg(username));
    model.select();
    QString sex = model.record(0).value("gender").toString();
    return sex;
}

QString returnname(QString username)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if (!db.isOpen())
    {
        createUserConnection();
    }
    QSqlTableModel model;
    model.setTable("user");
    model.setFilter(QObject::tr("username='%1'").arg(username));
    model.select();
    QString name = model.record(0).value("receivername").toString();
    return name;
}

QString returnphone(QString username)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if (!db.isOpen())
    {
        createUserConnection();
    }
    QSqlTableModel model;
    model.setTable("user");
    model.setFilter(QObject::tr("username='%1'").arg(username));
    model.select();
    QString phone = model.record(0).value("phonenumber").toString();
    return phone;
}

QString returnaddress(QString username)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if (!db.isOpen())
    {
        createUserConnection();
    }
    QSqlTableModel model;
    model.setTable("user");
    model.setFilter(QObject::tr("username='%1'").arg(username));
    model.select();
    QString address = model.record(0).value("address").toString();
    return address;
}
int returnbankbound(QString username)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if (!db.isOpen())
    {
        createUserConnection();
    }
    QSqlTableModel model;
    model.setTable("user");
    model.setFilter(QObject::tr("username='%1'").arg(username));
    model.select();
    int bankbound = model.record(0).value("bankbound").toInt();
    return bankbound;
}

bool renew(QString username, QString newname, QString newphone, QString newaddress)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if (!db.isOpen())
    {
        createUserConnection();
    }
    QSqlTableModel model;
    model.setTable("user");
    model.setFilter(QObject::tr("username='%1'").arg(username));
    model.select();

    if(newname=="")
    {}
    else
    {
        model.setData(model.index(0,3),newname);
    }
    if(newphone=="")
    {}
    else
    {
        model.setData(model.index(0,4),newphone);
    }

    if(newaddress=="")
    {}
    else
    {
        model.setData(model.index(0,5),newaddress);
    }
    if(model.submitAll())
    {
        QMessageBox::information(NULL, "成功","信息更改成功！");
        return true;
    }

    else
    {
        QMessageBox::warning(NULL, "失败","信息更改失败！");
        return false;
    }
}
bool openbankbound(QString username)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if (!db.isOpen())
    {
        createUserConnection();
    }
    QSqlTableModel model;
    model.setTable("user");
    model.setFilter(QObject::tr("username='%1'").arg(username));
    model.select();
    int bankbound = model.record(0).value("bankbound").toInt();
    if(bankbound==0)
    {
        model.setData(model.index(0,6),1);

        if(model.submitAll())
        {
            QMessageBox::information(NULL, "成功","成功开通银行支付！");
            return true;

        }
        else
        {
            return false;
        }
    }
    else
    {
        QMessageBox::warning(NULL, "注意","您的用户已经开通，请勿重复开通！");
        return false;

    }
}

bool closebankbound(QString username)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if (!db.isOpen())
    {
        createUserConnection();
    }
    QSqlTableModel model;
    model.setTable("user");
    model.setFilter(QObject::tr("username='%1'").arg(username));
    model.select();
    int bankbound = model.record(0).value("bankbound").toInt();
    if(bankbound==1)
    {
        model.setData(model.index(0,6),0);

        if(model.submitAll())
        {
            QMessageBox::information(NULL, "成功","成功关闭银行支付！");
            return true;

        }
        else
        {
            return false;
        }
    }
    else
    {
        QMessageBox::warning(NULL, "注意","您的用户尚未开通，请勿重复关闭！");
        return false;

    }
}


QString returnbanknumber(QString username)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if (!db.isOpen())
    {
        createUserConnection();
    }
    QSqlTableModel model;
    model.setTable("user");
    model.setFilter(QObject::tr("username='%1'").arg(username));
    model.select();
    //qDebug()<<model.record(0);
    QString banknumber = model.record(0).value("banknumber").toString();
    return banknumber;
}
