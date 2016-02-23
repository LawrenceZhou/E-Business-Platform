#include "administrator_login.h"
#include "ui_administrator_login.h"
#include <QMessageBox>
#include "administrator.h"

administrator_login::administrator_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrator_login)
{
    ui->setupUi(this);
    setFixedSize(240,130);
    setWindowTitle("管理员登录");
}

administrator_login::~administrator_login()
{
    delete ui;
}

void administrator_login::on_cancel_clicked()
{
    close();
}

void administrator_login::on_confirm_clicked()
{
    QString password = ui->password->text();
    if(password=="111111")
    {
        accept();
        administrator a;
        a.exec();
    }
    else
    {
        QMessageBox::warning(NULL, tr("错误"), tr("密码不正确！"));
    }
}
