#include "trolleydatabase.h"
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

bool createTrolleyConnection()
{
    bool IsExist = QFile::exists("trolley.db");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","trolley.db");

    db.open();
    if (!IsExist)
    {
        QSqlQuery query;
        qDebug() << "Start to create table...";
        bool success=query.exec("create table trolley(number int primary key, name vchar, description vchar, primeprice double, saleprice double, column int, sum int, discount double, publishmentbrand vchar, ISBNmaterialcolumn vchar, date vchar, pagenumbersizeweight vchar)");

        if (success)
        {
            qDebug() << "trolley数据库表创建成功！";
            return true;
        }
        else
        {
            qDebug()<< query.lastError();
            qDebug() << "trolley数据库表创建失败！";
        }
        return false;
    }
    else
    {
        qDebug()<<"数据库已存在！";
    }

    return true;
}

bool addTrolley(int number, QString name, QString description, double primeprice, double saleprice, int column, int sum, double discount,  QString publishmentbrand, QString ISBNmaterialcolumn, QString date, QString pagenumbersizeweight)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE","trolley.db");

    if (!db.isOpen())
    {
        createTrolleyConnection();
    }
    QSqlTableModel model;
    model.setTable("trolley");
    model.setFilter(QObject::tr("number = '%1' ").arg(number)); //根据商品编号进行筛选
    model.select(); //显示结果
    if(model.rowCount()==1)
    {
        model.setData(model.index(0,1),name);
        model.setData(model.index(0,2),description);
        model.setData(model.index(0,3),primeprice);
        model.setData(model.index(0,4),saleprice);
        model.setData(model.index(0,5),column);
        model.setData(model.index(0,6),sum+model.record(0).value("sum").toInt());
        model.setData(model.index(0,7),discount);
        model.setData(model.index(0,8),publishmentbrand);
        model.setData(model.index(0,9),ISBNmaterialcolumn);
        model.setData(model.index(0,10),date);
        model.setData(model.index(0,11),pagenumbersizeweight);
        model.submitAll();
        return true;
    }
    else
    {
        QSqlQuery query;
        qDebug() << "start to insert trolley data";
        query.prepare("insert into trolley(number, name, description, primeprice, saleprice, column, sum, discount, publishmentbrand, ISBNmaterialcolumn, date, pagenumbersizeweight)"" VALUES(?,?,?,?,?,?,?,?,?,?,?,?)");
        query.addBindValue(number);
        query.addBindValue(name);
        query.addBindValue(description);
        query.addBindValue(primeprice);
        query.addBindValue(saleprice);
        query.addBindValue(column);
        query.addBindValue(sum);
        query.addBindValue(discount);
        query.addBindValue(publishmentbrand);
        query.addBindValue(ISBNmaterialcolumn);
        query.addBindValue(date);
        query.addBindValue(pagenumbersizeweight);


        bool success=query.exec();
        if(!success)
        {
            QSqlError lastError = query.lastError();
            qDebug()<<lastError.driverText()<<"TROLLEYcharushibai";
            return false;
        }
        return true;
    }

}

