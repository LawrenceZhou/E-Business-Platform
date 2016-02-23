#include "renewinfo.h"
#include "ui_renewinfo.h"
#include "userdatabase.h"

renewinfo::renewinfo(QString un, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::renewinfo)
{
    username=un;
    ui->setupUi(this);
    setWindowTitle("更改信息");
    setFixedSize(240,350);
    ui->username->setText(un);
    QString s = returnsex(un);
    ui->sex->setText(s);
    QString rn = returnname(un);
    ui->name->setText(rn);
    QString p = returnphone(un);
    ui->phone->setText(p);
    QString a = returnaddress(un);
    ui->address->setText(a);
}

renewinfo::~renewinfo()
{
    delete ui;
}

void renewinfo::on_pushButton_clicked()
{
    close();
}

void renewinfo::on_pushButton_2_clicked()
{
    QString nr = ui->newname->text();
    QString np = ui->newphone->text();
    QString na = ui->newaddress->text();

    if(renew(username, nr, np, na))
    {
        accept();
    }
    else
    {}
}
