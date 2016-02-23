#include "deposit.h"
#include "ui_deposit.h"
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QDebug>

deposit::deposit(QString ban, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::deposit)
{
    ui->setupUi(this);
    setWindowTitle("存款");
    setFixedSize(240,120);
    bankaccn=ban;
}

deposit::~deposit()
{
    delete ui;
}

void deposit::on_cancel_clicked()
{
    close();
}


void deposit::on_deposit_2_clicked()
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
        qDebug()<<model.record(0);
        float n = model.record(0).value("balance").toFloat()+s;
        qDebug()<<n;
        model.setData(model.index(0,8),n);
        qDebug()<<model.record(0);
        if(model.submitAll())
        {
            QMessageBox::information(NULL, "成功","存款成功！");
            qDebug()<<model.record(0).value("balance");
            accept();
        }

        else
        {
            QMessageBox::warning(NULL, "失败","存款失败！");
        }

    }
}
