#include "login.h"
#include "ui_login.h"
#include "customer_login.h"
#include "administrator_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setFixedSize(240,130);
    setWindowTitle("登录");
}

login::~login()
{
    delete ui;
}

void login::on_exit_clicked()
{
    accept();
}

void login::on_customer_clicked()
{
    customer_login customer_login_interface;
    customer_login_interface.exec();
}

void login::on_administrator_clicked()
{
    administrator_login administrator_login_interface;
    administrator_login_interface.exec();
}
