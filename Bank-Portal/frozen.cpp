#include "frozen.h"
#include "ui_frozen.h"
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QDebug>
#include <QMessageBox>


frozen::frozen(QString ban, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frozen)
{
    ui->setupUi(this);
    setWindowTitle("冻结信息");
    setFixedSize(240,140);
    bankaccn=ban;
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccn));
    model.select();
    qDebug()<<model.record(0);
    int n = model.record(0).value("frozen").toInt();
    if(n==0)
    {
        ui->label->setText(tr("您尚未冻结账户。"));
    }
    else
    {
        ui->label->setText(tr("您的账户已冻结。"));
    }

}
frozen::~frozen()
{
    delete ui;
}

void frozen::on_cancel_clicked()
{
    close();
}

void frozen::on_f_clicked()
{
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccn));
    model.select();
    int n = model.record(0).value("frozen").toInt();
    if(n==0)
    {
        model.setData(model.index(0,10),1);
        if(model.submitAll())
        {
            QMessageBox::information(NULL, "成功","您的账户已冻结！");
            accept();
        }
        else
        {
            QMessageBox::warning(NULL, "失败","账户冻结失败！");
        }
    }
    else
    {
        QMessageBox::warning(NULL, "注意","您的账户已应冻结，请勿重复冻结！");
    }

}

void frozen::on_df_clicked()
{
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccn));
    model.select();
    int n = model.record(0).value("frozen").toInt();
    if(n==1)
    {
        model.setData(model.index(0,10),0);
        if(model.submitAll())
        {
            QMessageBox::information(NULL, "成功","您的账户已解冻！");
            accept();
        }
        else
        {
            QMessageBox::warning(NULL, "失败","账户解冻失败！");
        }
    }
    else
    {
        QMessageBox::warning(NULL, "注意","您的账户已未冻结，请勿解冻！");
    }
}
