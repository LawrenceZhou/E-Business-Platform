#include "administrator.h"
#include "ui_administrator.h"
#include <QMessageBox>
#include "addproduct.h"
#include "viewcommodity.h"
#include "viewuser.h"
#include "deletecommodity.h"
#include "modifycommodity.h"
#include "event.h"
administrator::administrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrator)
{
    ui->setupUi(this);
    setWindowTitle("管理员");
    setFixedSize(240,360);
}

administrator::~administrator()
{
    delete ui;
}

void administrator::on_exit_clicked()
{
    close();
}

void administrator::on_add_clicked()
{
    if(ui->book->isChecked())
    {
        addproduct a(1);
        a.exec();
    }
    else if(ui->clothes->isChecked())
    {
        addproduct a(2);
        a.exec();
    }
    else if(ui->food->isChecked())
    {
        addproduct a(3);
        a.exec();
    }
    else if(ui->eproduct->isChecked())
    {
        addproduct a(4);
        a.exec();
    }
    else
    {
        QMessageBox::critical(NULL, "警告","请选择商品！");
    }
}

void administrator::on_comminfo_clicked()
{
    viewcommodity v;
    v.exec();
}

void administrator::on_userinfo_clicked()
{
    viewuser v;
    v.exec();
}

void administrator::on_delete_2_clicked()
{
    deletecommodity d;
    d.exec();
}

void administrator::on_modify_clicked()
{
    modifycommodity m;
    m.exec();
}

void administrator::on_event_clicked()
{
    event::event e;
    e.exec();
}
