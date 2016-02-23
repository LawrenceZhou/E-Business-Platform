#include "withdraw.h"
#include "ui_withdraw.h"
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QDebug>

withdraw::withdraw(QString ban, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::withdraw)
{
    ui->setupUi(this);
    setWindowTitle("取款");
    setFixedSize(240,160);
    bankaccn=ban;
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccn));
    model.select();
    QString ba = model.record(0).value("balance").toString();
    ui->zhushi->setText(tr("*取款金额不能超过余额：\n%1元\n本次取款上限为9999999.99元").arg(ba));
}

withdraw::~withdraw()
{
    delete ui;
}

void withdraw::on_cancel_clicked()
{
    close();
}

void withdraw::on_withdraw_2_clicked()
{
    int a1=1, a2=1, a3=1;
    QString y = ui->yuan->text();
    int numflag1=1;
    for(int i=0;i<y.size();i++)
        if ((y[i]<'0')||(y[i]>'9'))
        {
            numflag1=0;
            break;
        }
    if(y=="")
    {
        y="0";
    }
    else if(numflag1==0)
    {
        QMessageBox::critical(NULL, "警告","输入元格式有误！");
        a1=0;
    }

    QString j = ui->jiao->text();

    int numflag2=1;
    for(int i=0;i<j.size();i++)
        if ((j[i]<'0')||(j[i]>'9'))
        {
            numflag2=0;
            break;
        }
    if(j=="")
    {
        j="0";
    }
    else if(numflag2==0)
    {
        QMessageBox::critical(NULL, "警告","输入角格式有误！");
        a2=0;
    }

    QString f =ui->fen->text();

    int numflag3=1;
    for(int i=0;i<f.size();i++)
        if ((f[i]<'0')||(f[i]>'9'))
        {
            numflag3=0;
            break;
        }
    if(f=="")
    {
        f="0";
    }
    else if(numflag3==0)
    {
        QMessageBox::critical(NULL, "警告","输入分格式有误！");
        a3=0;
    }

    if(a1+a2+a3==3)
    {
        float s = y.toFloat()+j.toFloat()/10+f.toFloat()/100;
        QSqlTableModel model;
        model.setTable("bankaccount");
        model.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccn));
        model.select();
        float n = model.record(0).value("balance").toFloat();
        qDebug()<<model.record(0);
        if(s>n)
        {
            QMessageBox::warning(NULL, "错误","取款金额超出余额！");
        }
        else
        {
            n = model.record(0).value("balance").toFloat()-s;
            qDebug()<<n;
            model.setData(model.index(0,8),n);
            qDebug()<<model.record(0);
            if(model.submitAll())
            {
                QMessageBox::information(NULL, "成功","取款成功！");
                qDebug()<<model.record(0).value("balance");
                accept();
            }

            else
            {
                QMessageBox::warning(NULL, "失败","取款失败！");
            }
        }

    }
}
