#include "addproduct.h"
#include "ui_addproduct.h"
#include "commodity.h"
#include "commoditydatabase.h"
#include <QMessageBox>

addproduct::addproduct(int i, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addproduct)
{
    ui->setupUi(this);
    setWindowTitle("添加商品");
    setFixedSize(240,380);
    col=i;
    if(i==1)
    {
        ui->label_9->setText("出版社");
        ui->label_10->setText("ISBN");
        ui->label_11->setText("出版日期");
        ui->label_12->setText("页数");
    }
    else if (i==2)
    {
        ui->label_9->setText("品牌");
        ui->label_10->setText("材质");
        ui->label_11->setText("生产日期");
        ui->label_12->setText("型号");
    }
    else if (i==3)
    {
        ui->label_9->setText("品牌");
        ui->label_10->setText("类目");
        ui->label_11->setText("生产日期");
        ui->label_12->setText("重量");
    }
    else if (i==4)
    {
        ui->label_9->setText("品牌");
        ui->label_10->setText("类目");
        ui->label_11->setText("生产日期");
        ui->label_12->setText("重量");
    }
}

addproduct::~addproduct()
{
    delete ui;
}

void addproduct::on_cancel_clicked()
{
    close();
}

void addproduct::on_add_clicked()
{
    int s=0;
    float f=0;
    QString name = ui->name->text();
    QString description = ui->description->text();
    QString yuan = ui->yuan->text();
    QString jiao = ui->jiao->text();
    QString fen = ui->fen->text();
    QString sum = ui->sum->text();
    QString sub1 = ui->label1->text();
    QString sub2 = ui->label2->text();
    QString sub3 = ui->label3->text();
    QString sub4 = ui->label4->text();

    int numflag1=1,a1=1,b1=1;
    for(int i=0;i<yuan.size();i++)
        if ((yuan[i]<'0')||(yuan[i]>'9'))
        {
            numflag1=0;
            break;
        }
    if(yuan=="")
    {
        yuan="0";
        b1=0;
    }
    else if(numflag1==0)
    {
        QMessageBox::critical(NULL, "警告","元输入格式有误！");
        a1=0;
    }

    int numflag2=1,a2=1,b2=1;
    for(int i=0;i<jiao.size();i++)
        if ((jiao[i]<'0')||(jiao[i]>'9'))
        {
            numflag2=0;
            break;
        }
    if(jiao=="")
    {
        jiao="0";
        b2=0;
    }
    else if(numflag2==0)
    {
        QMessageBox::critical(NULL, "警告","角输入格式有误！");
        a2=0;
    }

    int numflag3=1,a3=1,b3=1;
    for(int i=0;i<fen.size();i++)
        if ((fen[i]<'0')||(fen[i]>'9'))
        {
            numflag3=0;
            break;
        }
    if(fen=="")
    {
        fen="0";
        b3=0;
    }
    else if(numflag3==0)
    {
        QMessageBox::critical(NULL, "警告","分输入格式有误！");
        a3=0;
    }


    if(b1+b2+b3==0)
    {
        QMessageBox::critical(NULL, "警告","价格不能为0！");
    }

    if(a1+a2+a3==3)
    {
        f = yuan.toFloat()+jiao.toFloat()/10+fen.toFloat()/100;
    }

    int a4=1;
    if(name == "")
    {
        QMessageBox::critical(NULL, "警告","请输入产品名！");
        a4=0;
    }

    int numflag4=1,a5=1;
    for(int i=0;i<sum.size();i++)
        if ((sum[i]<'0')||(sum[i]>'9'))
        {
            numflag4=0;
            break;
        }

    if(sum=="")
    {
        QMessageBox::critical(NULL, "警告","请输入产品数量！");
        a5=0;
    }
    else if(numflag4==0)
    {
        QMessageBox::critical(NULL, "警告","产品数量格式输入错误！");
        a5=0;
    }
    else
    {
        s = sum.toInt();
    }
    if(a1+a2+a3+a4+a5==5)
    {
        if(col==1)
        {
            Book c(name, description, f, 1, s, sub1, sub2, sub3, sub4);
            if(addBook(c))
            {
                QMessageBox::information(NULL, "添加成功",QObject::tr("商品添加成功！商品编号为：%1").arg(c.getCommoditynumber()));
                accept();
            }
            else
            {
                QMessageBox::warning(NULL, "错误","添加商品失败！");
            }
        }
        else if(col==2)
        {
            Clothes c(name, description, f, 2, s, sub1, sub2, sub3, sub4);
            if(addClothes(c))
            {
                QMessageBox::information(NULL, "添加成功",QObject::tr("商品添加成功！商品编号为：%1").arg(c.getCommoditynumber()));
                accept();
            }
            else
            {
                QMessageBox::warning(NULL, "错误","添加商品失败！");
            }
        }
        else if(col==3)
        {
            Food c(name, description, f, 3, s, sub1, sub2, sub3, sub4);
            if(addFood(c))
            {
                QMessageBox::information(NULL, "添加成功",QObject::tr("商品添加成功！商品编号为：%1").arg(c.getCommoditynumber()));
                accept();
            }
            else
            {
                QMessageBox::warning(NULL, "错误","添加商品失败！");
            }
        }
        if(col==4)
        {
            ElectronicProduct c(name, description, f, 4, s, sub1, sub2, sub3, sub4);
            if(addEProduct(c))
            {
                QMessageBox::information(NULL, "添加成功",QObject::tr("商品添加成功！商品编号为：%1").arg(c.getCommoditynumber()));
                accept();
            }
            else
            {
                QMessageBox::warning(NULL, "错误","添加商品失败！");
            }
        }
    }
}
