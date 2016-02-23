#include "confirm.h"
#include "ui_confirm.h"
#include <QSqlTableModel>
#include <QSqlRecord>

confirm::confirm(QString name, int sum, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirm)
{
    ui->setupUi(this);
    setFixedSize(250,100);
    setWindowTitle("确认界面");
    ui->name->setText(name);
    QString s = QString::number(sum);
    ui->number->setText(s);
}

confirm::~confirm()
{
    delete ui;
}

void confirm::on_cancel_clicked()
{
    close();
}

void confirm::on_confirm_2_clicked()
{
    accept();
}
