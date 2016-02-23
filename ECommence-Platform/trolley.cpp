#include "trolley.h"
#include "ui_trolley.h"
#include "estore.h"
#include "trolleydatabase.h"
#include "commoditydatabase.h"
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include "pay.h"
#include "userdatabase.h"
extern int man;
extern int jian;
trolley::trolley( QString un, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trolley)
{


    ui->setupUi(this);
    setWindowTitle("购物车");
    setFixedSize(700,280);
    username=un;
    QSqlQueryModel *mode  = new QSqlQueryModel(ui->tableView);   //建立一个Model
    mode->setQuery("select * from trolley") ;
    mode->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));
    mode->setHeaderData(1,Qt::Horizontal,QObject::tr("名称"));
    mode->setHeaderData(2,Qt::Horizontal,QObject::tr("描述"));
    mode->setHeaderData(3,Qt::Horizontal,QObject::tr("原价"));
    mode->setHeaderData(4,Qt::Horizontal,QObject::tr("售价"));
    mode->setHeaderData(5,Qt::Horizontal,QObject::tr("种类"));
    mode->setHeaderData(6,Qt::Horizontal,QObject::tr("数量"));
    mode->setHeaderData(7,Qt::Horizontal,QObject::tr("折扣"));
    mode->setHeaderData(8,Qt::Horizontal,QObject::tr("出版社/品牌"));
    mode->setHeaderData(9,Qt::Horizontal,QObject::tr("ISBN/材料/类别"));
    mode->setHeaderData(10,Qt::Horizontal,QObject::tr("日期"));
    mode->setHeaderData(11,Qt::Horizontal,QObject::tr("页数/型号/重量"));
    ui->tableView->setModel(mode);

    QSqlTableModel model;
    model.setTable("trolley");

    model.select(); //显示结果
    qDebug()<<model.rowCount();
    s =0;
    itemnum=model.rowCount();
    for (int i = 0; i < model.rowCount(); i++)
    {
        s+=model.record(i).value("saleprice").toFloat()*model.record(i).value("sum").toInt();
    }
    if(s>=man)
    {
        s-=jian;
        ui->label_6->setText(tr("（参加满%1减%2活动）").arg(man).arg(jian));
    }
    ui->zongji->setText(QString::number(s));

}

trolley::~trolley()
{
    delete ui;
}

void trolley::on_cancel_clicked()
{
    close();
}

void trolley::on_confirm_clicked()
{
    if(itemnum==0)
    {
        QMessageBox::warning(NULL, tr("错误"), tr("购物车中没有商品！"));
    }
    else
    {
        if(returnbankbound(username)==1)
        {
            pay p(username,s);
            if(p.exec()==QDialog::Accepted)
            {
                QMessageBox::information(NULL, tr("成功"), tr("购物成功！"));
                accept();
            }
        }
        else
        {
            QMessageBox::warning(NULL, tr("错误"), tr("尚未开通银行支付功能！"));
        }
    }
}

void trolley::on_delete_2_clicked()
{
    if(itemnum==0)
    {
        QMessageBox::warning(NULL, tr("错误"), tr("购物车中没有商品！"));
    }
    else
    {
        QString a =ui->bianhao->text();
        QString b = ui->shuliang->text();
        int numflag1=1;
        for(int i=0;i<b.size();i++)
            if ((b[i]<'0')||(b[i]>'9'))
            {
                numflag1=0;
                break;
            }
        if(b.size()==0)
        {
            QMessageBox::critical(NULL, "错误","数量未填写！");
        }
        else if(numflag1==0)
        {
            QMessageBox::critical(NULL, "错误","数量填写格式错误！");

        }
        else
        {
            int x = a.toInt();
            int y = b.toInt();

            QSqlTableModel model;
            model.setTable("trolley");
            model.select();
            model.setFilter(tr("number = '%1'").arg(x));
            model.select();
            if(model.rowCount()==1&&y > model.record(0).value("sum").toInt())
            {
                QMessageBox::warning(NULL, tr("错误"), tr("数量大于购物车中商品数量！"));
            }
            else
            {
                if(model.rowCount()==1)//查询到有一个结果
                {
                    model.setData(model.index(0,6),model.record(0).value("sum").toInt()-y);

                    model.submitAll();
                    if(model.record(0).value("sum").toInt()==0)
                    {
                        model.removeRow(0);
                    }
                    QSqlTableModel m;
                    m.setTable("commodity");
                    m.setFilter(tr("number = '%1'").arg(x));
                    m.select();
                    m.setData(m.index(0,6),m.record(0).value("sum").toInt()+y);
                    m.submitAll();
                    QMessageBox::information(NULL, tr("删除"), tr("商品删除成功！"));
                    accept();//隐含窗口，并返回结果QDialg::Accepted
                }else
                {
                    QMessageBox::warning(NULL, tr("错误"), tr("未查询到商品！"));
                }
            }
        }
    }
}

void trolley::on_reset_clicked()
{
    if(itemnum==0)
    {
        QMessageBox::warning(NULL, tr("错误"), tr("购物车中没有商品！"));
    }
    else
    {
        QSqlTableModel model;
        model.setTable("trolley");
        model.select();

        for(int i=0; i<model.rowCount();i++)
        {
            QSqlTableModel m;
            m.setTable("commodity");
            int a = model.record(i).value("number").toInt();
            int b = model.record(i).value("sum").toInt();
            m.setFilter(tr("number = '%1'").arg(a));
            m.select();
            if(m.rowCount()==1)//查询到有一个结果
            {
                m.setData(m.index(0,6),m.record(0).value("sum").toInt()+b);
                m.submitAll();
                model.removeRow(i);

            }
        }
        QMessageBox::information(NULL, tr("删除"), tr("购物车清空成功！"));
        accept();
    }

}
