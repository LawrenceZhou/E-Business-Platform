#include "querybalance.h"
#include "ui_querybalance.h"
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QDebug>

querybalance::querybalance(QString ban, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::querybalance)
{
    ui->setupUi(this);
    setWindowTitle("余额");
    setFixedSize(240,120);
    bankaccn=ban;
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccn));
    model.select();
    qDebug()<<model.record(0);
    QString ba = model.record(0).value("balance").toString();
    ui->xianshi->setText(tr("%1元").arg(ba));
}

querybalance::~querybalance()
{
    delete ui;
}

void querybalance::on_pushButton_clicked()
{
    accept();
}
