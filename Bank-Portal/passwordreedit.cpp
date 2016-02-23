#include "passwordreedit.h"
#include "ui_passwordreedit.h"
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QDebug>

passwordreedit::passwordreedit(QString ban, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passwordreedit)
{
    ui->setupUi(this);
    setWindowTitle("更改密码");
    setFixedSize(240,150);
    bankaccn = ban;

}

passwordreedit::~passwordreedit()
{
    delete ui;
}



void passwordreedit::on_confirm_clicked()
{
    QString opw = ui->oldpw->text();
    QString npw = ui->npw->text();
    QString npw2 = ui->npw2->text();

    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccn));
    model.select();
    QString pw = model.record(0).value("password").toString();
    if(opw!=pw)
    {
        QMessageBox::critical(NULL, "错误","原密码输入错误！");
    }
    else
    {
        int numflag=1, a=0, b=0;
        for(int i=0;i<pw.size();i++)
            if ((npw[i]<'0')||(npw[i]>'9'))
            {
                numflag=0;
                break;
            }

        if(npw.size()!=6||numflag==0)
        {
            QMessageBox::critical(NULL, "警告","密码仅能是六位数字！");
            a=0;
        }else
        {
            a=1;
        }
        if(npw!=npw2)
        {
            QMessageBox::critical(NULL, "警告","两次密码输入不一致，请重新输入！");
            b=0;
        }
        else if((npw!="")&&(npw2!=""))
        {
            b=1;
        }

        if(a+b==2)
        {
            model.setData(model.index(0,1),npw);
            qDebug()<<model.record(0);
            if(model.submitAll())
            {
                QMessageBox::information(NULL, "成功","密码更改成功！");
                accept();
            }

            else
            {
                QMessageBox::warning(NULL, "失败","密码更改失败！");
            }
        }
    }
}

void passwordreedit::on_cancel_clicked()
{
    close();
}

