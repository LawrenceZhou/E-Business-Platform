#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "register.h"
#include "bankaccount.h"
#include "database.h"
#include <QSqlTableModel>
#include <QObject>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setFixedSize(250,150);
    setWindowTitle("银行账户登录");
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{

    RegisterFunction();
}


void login::on_pushButton_2_clicked()
{
    QString num = ui->name->text();
    QString pw = ui->password->text();
    QSqlTableModel model;
    model.setTable("bankaccount");
    model.setFilter(tr("bankaccountnumber = '%1' and password = '%2'").arg(num).arg(pw));
    model.select();
    if(model.rowCount()==1)//查询到有一个结果
    {
        Name = num;
        Pwd = pw;
        accept();//隐含窗口，并返回结果QDialg::Accepted
    }else
    {
        QMessageBox::warning(NULL, tr("错误"), tr("用户名或者密码不正确！"));
    }

}
void login::RegisterFunction()
{
    Register RegisterInterface;
    RegisterInterface.exec();

}

QString login::getName()
{
    return Name;
}
//返回密码
QString login::getPwd()
{
    return Pwd;
}
