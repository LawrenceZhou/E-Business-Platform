#include "event.h"
#include "ui_event.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlRecord>
#include <QDebug>
int man=0;
int jian=0;
event::event(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::event)
{
    ui->setupUi(this);
    setFixedSize(280,220);
    setWindowTitle("折扣");
}

event::~event()
{
    delete ui;
}

void event::on_cancel_clicked()
{
    close();

}

void event::on_confirm_clicked()
{
    QString discount = ui->discount->text();

    int numflag1=1,a=1;
    for(int i=0;i<discount.size();i++)
        if ((discount[i]<'0')||(discount[i]>'9'))
        {
            numflag1=0;
            break;
        }
    if(numflag1==0)
    {
        QMessageBox::critical(NULL, "警告","折扣输入格式有误！");
        a=0;
    }
    float dis = discount.toFloat();

    if(dis<1||dis>100)
    {
        QMessageBox::critical(NULL, "警告","折扣输入格式有误！");
        a=0;
    }
    float d =1-dis/100;
    if(ui->book->isChecked())
    {
        QSqlTableModel model;
        model.setTable("commodity");
        model.setFilter(QObject::tr("column = 1 ")); //根据类别进行筛选
        model.select(); //显示结果
        for (int i = 0; i < model.rowCount(); i++)
        {
            qDebug()<<model.record(i);
            qDebug()<<d;
            model.setData(model.index(i,7),d);
            double p= model.record(i).value("primeprice").toFloat();
            double a = d*p;
            int yy = (int)(a*100+1.0e-6);
            double b = (double)yy/100;
            model.setData(model.index(i,4),b);
            model.submitAll();
            qDebug()<<model.record(i);
        }
        if(a==1)
        {
            QMessageBox::information(NULL, "成功","信息更改成功！");
            accept();
        }
    }
    else if(ui->clothes->isChecked())
    {
        QSqlTableModel model;
        model.setTable("commodity");
        model.setFilter(QObject::tr("column = 2 ")); //根据类别进行筛选
        model.select(); //显示结果
        for (int i = 0; i < model.rowCount(); i++)
        {
            qDebug()<<model.record(i);
            qDebug()<<d;
            model.setData(model.index(i,7),d);
            double p= model.record(i).value("primeprice").toFloat();
            double a = d*p;
            int yy = (int)(a*100+1.0e-6);
            double b = (double)yy/100;
            model.setData(model.index(i,4),b);
            model.submitAll();
            qDebug()<<model.record(i);
        }
        if(a==1)
        {
            QMessageBox::information(NULL, "成功","信息更改成功！");
            accept();
        }
    }
    else if(ui->food->isChecked())
    {
        QSqlTableModel model;
        model.setTable("commodity");
        model.setFilter(QObject::tr("column = 3 ")); //根据类别进行筛选
        model.select(); //显示结果
        qDebug()<<model.rowCount();
        for (int i = 0; i < model.rowCount(); i++)
        {
            qDebug()<<model.record(i);
            qDebug()<<d;
            model.setData(model.index(i,7),d);
            double p= model.record(i).value("primeprice").toFloat();
            double a = d*p;
            int yy = (int)(a*100+1.0e-6);
            double b = (double)yy/100;
            model.setData(model.index(i,4),b);
            model.submitAll();
            qDebug()<<model.record(i);
        }
        if(a==1)
        {
            QMessageBox::information(NULL, "成功","信息更改成功！");
            accept();
        }
    }
    else if(ui->electronic->isChecked())
    {
        QSqlTableModel model;
        model.setTable("commodity");
        model.setFilter(QObject::tr("column = 4 ")); //根据类别进行筛选
        model.select(); //显示结果
        for (int i = 0; i < model.rowCount(); i++)
        {
            qDebug()<<model.record(i);
            qDebug()<<d;
            model.setData(model.index(i,7),d);
            double p= model.record(i).value("primeprice").toFloat();
            double a = d*p;
            int yy = (int)(a*100+1.0e-6);
            double b = (double)yy/100;
            model.setData(model.index(i,4),b);
            model.submitAll();
            qDebug()<<model.record(i);
        }
        if(a==1)
        {
            QMessageBox::information(NULL, "成功","信息更改成功！");
            accept();
        }
    }
    else
    {
        QMessageBox::critical(NULL, "警告","请选择商品！");
    }
}

void event::on_confirm2_clicked()
{
    QString enough = ui->upto->text();
    QString reduce = ui->reduce->text();
    int numflag1=1,a1=1;
    for(int i=0;i<enough.size();i++)
        if ((enough[i]<'0')||(enough[i]>'9'))
        {
            numflag1=0;
            break;
        }
    if(numflag1==0)
    {
        QMessageBox::critical(NULL, "警告","满金额格式有误！");
        a1=0;
    }
    int numflag2=1,a2=1;
    for(int i=0;i<reduce.size();i++)
        if ((reduce[i]<'0')||(reduce[i]>'9'))
        {
            numflag2=0;
            break;
        }
    if(numflag2==0)
    {
        QMessageBox::critical(NULL, "警告","减金额格式有误！");
        a2=0;
    }
    if(a1+a2==2)
    {
    int m=enough.toInt();
    int j=reduce.toInt();
    if(m<j)
    {
         QMessageBox::critical(NULL, "警告","满的金额不能小于减的金额！");
    }
    else
    {
        man=m;
        jian=j;
        QMessageBox::information(NULL, "成功","满减活动提交成功！");
        accept();
    }
    }
}
