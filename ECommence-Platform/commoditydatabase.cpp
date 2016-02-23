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
#include "commodity.h"

bool createCommodityConnection()
{
    bool IsExist = QFile::exists("commodity.db");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","commodity.db");

    db.open();
    if (!IsExist)
    {
        QSqlQuery query;
        qDebug() << "Start to create table...";
        bool success=query.exec("create table commodity(number int primary key, name vchar, description vchar, primeprice double, saleprice double, column int, sum int, discount double, publishmentbrand vchar, ISBNmaterialcolumn vchar, date vchar, pagenumbersizeweight vchar)");

        if (success)
        {
            qDebug() << "commodity数据库表创建成功！";
            return true;
        }
        else
        {
            qDebug()<< query.lastError();
            qDebug() << "commodity数据库表创建失败！";
        }
        return false;
    }
    else
    {
        qDebug()<<"数据库已存在！";
    }

    return true;
}

bool addBook( Book B )
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE","commodity.db");

    if (!db.isOpen())
    {
        createCommodityConnection();
    }
    QSqlQuery query;
    qDebug() << "start to insert commodity data";
    query.prepare("insert into commodity(number, name, description, primeprice, saleprice, column, sum, discount, publishmentbrand, ISBNmaterialcolumn, date, pagenumbersizeweight)"" VALUES(?,?,?,?,?,?,?,?,?,?,?,?)");
    query.addBindValue(B.getCommoditynumber());
    query.addBindValue(B.getCommodityname());
    query.addBindValue(B.getCommoditydescription());
    query.addBindValue(B.getCommodityprimeprice());
    query.addBindValue(B.getCommoditysaleprice());
    query.addBindValue(B.getCommoditycolumn());
    query.addBindValue(B.getCommoditysum());
    query.addBindValue(B.getCommoditydiscount());
    query.addBindValue(B.getBookpublishment());
    query.addBindValue(B.getBookISBN());
    query.addBindValue(B.getBookdate());
    query.addBindValue(B.getBookpagenumber());


    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug()<<lastError.driverText()<<"COMMODITYcharushibai";
        return false;
    }
    return true;
}

bool addClothes( Clothes B )
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE","commodity.db");

    if (!db.isOpen())
    {
        createCommodityConnection();
    }
    QSqlQuery query;
    qDebug() << "start to insert commodity data";
    query.prepare("insert into commodity(number, name, description, primeprice, saleprice, column, sum, discount, publishmentbrand, ISBNmaterialcolumn, date, pagenumbersizeweight)"" VALUES(?,?,?,?,?,?,?,?,?,?,?,?)");
    query.addBindValue(B.getCommoditynumber());
    query.addBindValue(B.getCommodityname());
    query.addBindValue(B.getCommoditydescription());
    query.addBindValue(B.getCommodityprimeprice());
    query.addBindValue(B.getCommoditysaleprice());
    query.addBindValue(B.getCommoditycolumn());
    query.addBindValue(B.getCommoditysum());
    query.addBindValue(B.getCommoditydiscount());
    query.addBindValue(B.getClothesbrand());
    query.addBindValue(B.getClothesmaterial());
    query.addBindValue(B.getClothesdate());
    query.addBindValue(B.getClothessize());


    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug()<<lastError.driverText()<<"COMMODITYcharushibai";
        return false;
    }
    return true;
}

bool addFood( Food B )
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE","commodity.db");

    if (!db.isOpen())
    {
        createCommodityConnection();
    }
    QSqlQuery query;
    qDebug() << "start to insert commodity data";
    query.prepare("insert into commodity(number, name, description, primeprice, saleprice, column, sum, discount, publishmentbrand, ISBNmaterialcolumn, date, pagenumbersizeweight)"" VALUES(?,?,?,?,?,?,?,?,?,?,?,?)");
    query.addBindValue(B.getCommoditynumber());
    query.addBindValue(B.getCommodityname());
    query.addBindValue(B.getCommoditydescription());
    query.addBindValue(B.getCommodityprimeprice());
    query.addBindValue(B.getCommoditysaleprice());
    query.addBindValue(B.getCommoditycolumn());
    query.addBindValue(B.getCommoditysum());
    query.addBindValue(B.getCommoditydiscount());
    query.addBindValue(B.getFoodbrand());
    query.addBindValue(B.getFoodcolumn());
    query.addBindValue(B.getFooddate());
    query.addBindValue(B.getFoodweight());


    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug()<<lastError.driverText()<<"COMMODITYcharushibai";
        return false;
    }
    return true;
}

bool addEProduct( ElectronicProduct B )
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE","commodity.db");

    if (!db.isOpen())
    {
        createCommodityConnection();
    }
    QSqlQuery query;
    qDebug() << "start to insert commodity data";
    query.prepare("insert into commodity(number, name, description, primeprice, saleprice, column, sum, discount, publishmentbrand, ISBNmaterialcolumn, date, pagenumbersizeweight)"" VALUES(?,?,?,?,?,?,?,?,?,?,?,?)");
    query.addBindValue(B.getCommoditynumber());
    query.addBindValue(B.getCommodityname());
    query.addBindValue(B.getCommoditydescription());
    query.addBindValue(B.getCommodityprimeprice());
    query.addBindValue(B.getCommoditysaleprice());
    query.addBindValue(B.getCommoditycolumn());
    query.addBindValue(B.getCommoditysum());
    query.addBindValue(B.getCommoditydiscount());
    query.addBindValue(B.getEproductbrand());
    query.addBindValue(B.getEproductcolumn());
    query.addBindValue(B.getEproductdate());
    query.addBindValue(B.getEproductweight());


    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug()<<lastError.driverText()<<"COMMODITYcharushibai";
        return false;
    }
    return true;
}
int returnnumber()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE","commodity.db");

    if (!db.isOpen())
    {
        createCommodityConnection();
    }
    QSqlQuery query;
    query.exec("SELECT * FROM commodity");
    query.last();
    return query.value(0).toInt()+1;
}
