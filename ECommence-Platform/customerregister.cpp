#include "customerregister.h"
#include "ui_customerregister.h"
#include "user.h"
#include "userdatabase.h"
#include <QMessageBox>

CustomerRegister::CustomerRegister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerRegister)
{
    ui->setupUi(this);
    setWindowTitle("注册用户");
    setFixedSize(280,360);
}

CustomerRegister::~CustomerRegister()
{
    delete ui;
}

void CustomerRegister::on_cancel_clicked()
{
    close();
}

void CustomerRegister::on_confirm_clicked()
{
    QString username = ui->username->text();
    QString name = ui->name->text();
    QString phone = ui->phone->text();
    QString address = ui->address->text();
    QString password1 = ui->password1->text();
    QString password2 = ui->password2->text();
    QString sex = ui->sex->currentText();
    
    int aunother=1,aexist=1;
    for(int i=0;i<username.size();i++)
    {
        if(((username[i]>='0')&&(username[i]<='9'))||((username[i]>='a')&&(username[i]<='z'))||((username[i]>='A')&&(username[i]<='Z'))||username[i]=='_')
        {}
        else
        {
            aunother=0;
            break;
        }

    }
    if(aunother==0)
    {
        QMessageBox::critical(NULL, "警告","用户名包含非法字符！");
    }
    else
    {
        if(searchUser(username))//查询到有一个结果
        {
            QMessageBox::warning(NULL, tr("错误"), tr("用户名已存在！请重新输入！"));
            aexist=0;
        }
    }

    int anum=0,asmall=0,acapital=0,asame=1;

    if(password1.size()<6)
    {
        QMessageBox::critical(NULL, "警告","密码至少六位！");
    }

    for(int i=0;i<password1.size();i++)
    {
        if ((anum==0)&&(password1[i]>='0')&&(password1[i]<='9'))
        {
            anum=1;
        }
        else if((asmall==0)&&(password1[i]>='a')&&(password1[i]<='z'))
        {
            asmall=1;
        }
        else if((acapital==0)&&(password1[i]>='A')&&(password1[i]<='Z'))
        {
            acapital=1;
        }

    }


    if(anum==0)
    {
        QMessageBox::critical(NULL, "警告","密码应包含数字！");
    }

    if(asmall==0)
    {
        QMessageBox::critical(NULL, "警告","密码应包含小写字母！");
    }

    if(acapital==0)
    {
        QMessageBox::critical(NULL, "警告","密码应包含大写字母！");
    }

    if(password1!=password2)
    {
        QMessageBox::critical(NULL, "警告","两次密码输入不一致，请重新输入！");
        asame=0;
    }
    
    if(aexist+aunother+anum+asmall+acapital+asame==6)
    {
        User u(username, sex, password1, name, phone, address);
        if(addUser(u))
        {
            QString s = QString("您的用户名为：%1\n您的密码为：%2").arg(u.getUsername()).arg(u.getPassword());
            QMessageBox::information(NULL, "用户信息",s);
            accept();
        }
        else
        {
            QMessageBox::warning(NULL, "错误","用户创建失败！");
        }
    }
}
