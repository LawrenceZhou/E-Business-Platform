#include "widget.h"
#include "ui_widget.h"
#include "bankaccount.h"
#include <QSql>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlTableModel>
#include <QObject>
#include "deposit.h"
#include "withdraw.h"
#include "querybalance.h"
#include "passwordreedit.h"
#include "renewinfo.h"
#include "frozen.h"
#include "netpay.h"
#include <QMessageBox>

Widget::Widget(QString n, QString p, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(470,230);
    setWindowTitle("您的银行账户");
    name = n;
    pwd = p;
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(name));
    model.select();
    QString bn = model.record(0).value("bankname").toString();
    QString ln = model.record(0).value("lastname").toString();
    QString fn = model.record(0).value("firstname").toString();
    QString ban = model.record(0).value("bankaccountnumber").toString();
    ui->bankname->setText(tr("%1").arg(bn));
    ui->name->setText(tr("%1%2").arg(ln).arg(fn));
    ui->bankan->setText(tr("%1").arg(ban));


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_frozen_clicked()
{
    frozen frozeninterface(name);
    frozeninterface.exec();
}

void Widget::on_deposit_clicked()
{
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(name));
    model.select();
    int f = model.record(0).value("frozen").toInt();
    if(f==0)
    {
        deposit depositinterface(name);
        depositinterface.exec();
    }
    else
    {
        QMessageBox::warning(NULL, "注意","您的账户已冻结！该操作已被禁止。");
    }

}

void Widget::on_withdraw_clicked()
{
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(name));
    model.select();
    int f = model.record(0).value("frozen").toInt();
    if(f==0)
    {
        withdraw withdrawinterface(name);
        withdrawinterface.exec();
    }
    else
    {
        QMessageBox::warning(NULL, "注意","您的账户已冻结！该操作已被禁止。");
    }

}

void Widget::on_exit_clicked()
{
    close();
}

void Widget::on_balance_clicked()
{
    querybalance querybalanceinterface(name);
    querybalanceinterface.exec();
}

void Widget::on_pwr_clicked()
{
    passwordreedit passwordreeditinterface(name);
    passwordreeditinterface.exec();
}

void Widget::on_phoneadd_clicked()
{
    renewinfo renewinfointerface(name);
    renewinfointerface.exec();
}

void Widget::on_netp_clicked()
{
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(name));
    model.select();
    int f = model.record(0).value("frozen").toInt();
    if(f==0)
    {
        netpay netpayinterface(name);
        netpayinterface.exec();
    }
    else
    {
        QMessageBox::warning(NULL, "注意","您的账户已冻结！该操作已被禁止。");
    }

}


