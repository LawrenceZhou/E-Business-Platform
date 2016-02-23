#include "customer_login.h"
#include "ui_customer_login.h"
#include "customerregister.h"
#include "userdatabase.h"
#include <QMessageBox>
#include "widget.h"

customer_login::customer_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customer_login)
{
    ui->setupUi(this);
    setFixedSize(240,130);
    setWindowTitle("客户登录");
}

customer_login::~customer_login()
{
    delete ui;
}


void customer_login::on_register_2_clicked()
{
    CustomerRegister RegisterInterface;
    RegisterInterface.exec();
}

void customer_login::on_log_clicked()
{
    QString username = ui->name->text();
    QString password = ui->password->text();

    if(confirmation(username,password))//查询到有一个结果
    {
        Name = username;
        Pwd = password;
        accept();//隐含窗口，并返回结果QDialg::Accepted
        Widget w(username);
        w.exec();
    }else
    {
        QMessageBox::warning(NULL, tr("错误"), tr("用户名或者密码不正确！"));
    }
}
