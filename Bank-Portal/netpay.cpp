#include "netpay.h"
#include "ui_netpay.h"
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QDebug>
#include <QMessageBox>
#include "confirminterface.h"
netpay::netpay(QString ban, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::netpay)
{
    ui->setupUi(this);
    setWindowTitle("网络支付信息");
    setFixedSize(240,170);
    bankaccn=ban;
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccn));
    model.select();
    qDebug()<<model.record(0);
    n = model.record(0).value("netpay").toInt();
    if(n==0)
    {
        ui->label->setText(tr("您尚未开通网络支付功能。"));
    }
    else
    {
        ui->label->setText(tr("您的账户已开通网络支付功能。"));
    }
}

netpay::~netpay()
{
    delete ui;
}

void netpay::on_n_clicked()
{
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccn));
    model.select();
    if(n==0)
    {
        model.setData(model.index(0,9),1);
        if(model.submitAll())
        {
            QMessageBox::information(NULL, "成功","您的账户已开通网络支付功能！");
            accept();
        }
        else
        {
            QMessageBox::warning(NULL, "失败","账户开通网络支付功能失败！");
        }
    }
    else
    {
        QMessageBox::warning(NULL, "注意","您的账户已开通网络支付功能，请勿重复开通！");
    }
}

void netpay::on_dn_clicked()
{
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccn));
    model.select();
    if(n==1)
    {
        model.setData(model.index(0,9),0);
        if(model.submitAll())
        {
            QMessageBox::information(NULL, "成功","您的账户已关闭网络支付功能！");
            accept();
        }
        else
        {
            QMessageBox::warning(NULL, "失败","账户关闭网络支付功能失败！");
        }
    }
    else
    {
        QMessageBox::warning(NULL, "注意","您的账户未开通网络支付功能，请勿重复关闭！");
    }
}

void netpay::on_cancel_clicked()
{
    close();
}

void netpay::on_confirm_clicked()
{
    if(n==0)
    {
        QMessageBox::warning(NULL, "注意","您的账户尚未通网络支付功能！");
    }
    else
    {
        confirminterface c(bankaccn);
        c.exec();
    }
}
