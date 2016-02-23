#include "renewinfo.h"
#include "ui_renewinfo.h"
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QDebug>
#include <QMessageBox>


renewinfo::renewinfo(QString ban, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::renewinfo)
{
    ui->setupUi(this);
    setWindowTitle("更改信息");
    setFixedSize(260,425);
    bankaccn = ban;
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccn));
    model.select();

    qDebug()<<model.record(0);
    QString ln = model.record(0).value("lastname").toString();
    ui->lastname->setText(tr("%1").arg(ln));
    QString fn = model.record(0).value("firstname").toString();
    ui->firstname->setText(tr("%1").arg(fn));
    QString nn = model.record(0).value("nationality").toString();
    ui->nation->setText(tr("%1").arg(nn));
    QString bd = model.record(0).value("birthdate").toString();
    ui->birthdate->setText(tr("%1").arg(bd));
    QString ge = model.record(0).value("gender").toString();
    ui->gender->setText(tr("%1").arg(ge));
    QString id = model.record(0).value("id").toString();
    ui->id->setText(tr("%1").arg(id));
    ui->bankan->setText(tr("%1").arg(ban));
    QString bn = model.record(0).value("bankname").toString();
    ui->bankname->setText(tr("%1").arg(bn));
    QString op = model.record(0).value("phonennumber").toString();
    ui->oldphone->setText(tr("%1").arg(op));
    QString oa = model.record(0).value("address").toString();
    ui->oldaddress->setText(tr("%1").arg(oa));

}

renewinfo::~renewinfo()
{
    delete ui;
}

void renewinfo::on_cancel_clicked()
{
    close();
}

void renewinfo::on_confirm_clicked()
{
    QString np = ui->newphone->text();
    QString na = ui->newaddress->text();

    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccn));
    model.select();

    if(np=="")
    {}
    else
    {
        model.setData(model.index(0,12),np);
    }

    if(na=="")
    {}
    else
    {
        model.setData(model.index(0,13),na);
    }
    if(model.submitAll())
    {
        QMessageBox::information(NULL, "成功","信息更改成功！");
        accept();
    }

    else
    {
        QMessageBox::warning(NULL, "失败","信息更改失败！");
    }
}
