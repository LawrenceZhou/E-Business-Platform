#include "register.h"
#include "ui_register.h"
#include "bankaccount.h"
#include "database.h"

Register::Register(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    setWindowTitle("注册账户");
    setFixedSize(400,480);
}

Register::~Register()
{
    delete ui;
}


void Register::on_cancel_clicked()
{
    close();
}

void Register::on_confirm_clicked()
{
    int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0;
    QString in = ui->idnumber->text();
    int numflag1=1;
    for(int i=0;i<in.size();i++)
        if ((in[i]<'0')||(in[i]>'9'))
        {
            numflag1=0;
            break;
        }
    if(in=="")
    {
        QMessageBox::critical(NULL, "警告","请输入您的二代身份证号！");
        a1=0;
    }
    else if(in.size()!=18||numflag1==0)
    {
        QMessageBox::critical(NULL, "警告","二代身份证号格式不正确！");
        a1=0;
    }
    else
    {
        a1=1;
    }
    QString ln = ui->lastname->text();
    if (ln=="")
    {
        QMessageBox::critical(NULL, "警告","请输入您的姓！");
        a2=0;
    }
    else
    {
        a2=1;
    }
    QString fn = ui->firstname->text();
    if (fn=="")
    {
        QMessageBox::critical(NULL, "警告","请输入您的名！");
        a3=0;
    }
    else
    {
        a3=1;
    }

    QString ge = ui->gender->currentText();

    QString na = ui->nation->text();
    if (na=="")
    {
        QMessageBox::critical(NULL, "警告","请输入您的民族！");
        a4=0;
    }
    else
    {
        a4=1;
    }
    QString pn = ui->cellphonenumber->text();
    if (pn=="")
    {
        QMessageBox::critical(NULL, "警告","请输入您的手机号码！");
        a5=0;
    }
    else
    {
        a5=1;
    }
    QString ad = ui->address->text();

    QString bd = ui->birth->text() ;
    QString bn;
    if(ui->huaqi->isChecked())
    {
        bn = "花旗银行";
        a6=1;
    }
    else if(ui->huifeng->isChecked())
    {
        bn = "汇丰银行";
        a6=1;
    }
    else if(ui->zhongguo->isChecked())
    {
        bn = "中国银行";
        a6=1;
    }
    else if(ui->zhada->isChecked())
    {
        bn = "渣打银行";
        a6=1;
    }
    else if(ui->mogendatong->isChecked())
    {
        bn = "摩根大通银行";
        a6=1;
    }
    else
    {
        QMessageBox::critical(NULL, "警告","请选择银行！");
        a6=0;
    }
    QString pw = ui->password->text();
    QString pw2 = ui->password2->text();
    int numflag2=1;
    for(int i=0;i<pw.size();i++)
        if ((pw[i]<'0')||(pw[i]>'9'))
        {
            numflag2=0;
            break;
        }

    if(pw.size()!=6||numflag2==0)
    {
        QMessageBox::critical(NULL, "警告","密码仅能是六位数字！");
        a7=0;
    }else
    {
        a7=1;
    }
    if(pw!=pw2)
    {
        QMessageBox::critical(NULL, "警告","两次密码输入不一致，请重新输入！");
        a8=0;
    }
    else if((pw!="")&&(pw2!=""))
    {
        a8=1;
    }
    if(a1+a2+a3+a4+a5+a6+a7+a8==8)
    {
        BankAccount BA(ln, fn, na, bn, ge, in, pw, bd, pn, ad);
        if(addAccount(BA))
        {
            QString s = QString("您的开户银行为：%1\n您的银行卡号为：%2\n密码是：%3").arg(BA.getBankName()).arg(BA.getBankAccountNumber()).arg(BA.getPassword());
            QMessageBox::information(NULL, "账户信息",s);
            accept();
        }
        else
        {
            QMessageBox::warning(NULL, "错误","用户创建失败！");
        }

    }
}

