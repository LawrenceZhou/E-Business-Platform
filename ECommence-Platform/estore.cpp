#include "estore.h"
#include "ui_estore.h"
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QMessageBox>
#include "confirm.h"
#include "commodity.h"
#include "widget.h"
#include <QDebug>
#include "trolleydatabase.h"

estore::estore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::estore)
{
    ui->setupUi(this);
    setFixedSize(670,290);
    setWindowTitle("商城");

    QSqlQueryModel *mode  = new QSqlQueryModel(ui->tableView);   //建立一个Model
    mode->setQuery("select * from commodity") ;
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
}

estore::~estore()
{
    delete ui;
}

void estore::on_cancel_clicked()
{
    close();
}

void estore::on_confirm_clicked()
{

    int num = ui->num->text().toInt();
    QSqlTableModel model;
    model.setTable("commodity");
    model.setFilter(tr("number = '%1'").arg(num));
    model.select();
    if(model.rowCount()==1)//查询到有一个结果
    {
        QString name =model.record(0).value("name").toString();
        QString description =model.record(0).value("description").toString();
        double primeprice = model.record(0).value("primeprice").toDouble();
        double saleprice = model.record(0).value("saleprice").toDouble();
        int column = model.record(0).value("column").toInt();
        int sum = model.record(0).value("sum").toInt();
        double discount = model.record(0).value("discount").toDouble();
        QString publishmentbrand =model.record(0).value("publishmentbrand").toString();
        QString ISBNmaterialcolumn =model.record(0).value("ISBNmaterialcolumn").toString();
        QString date =model.record(0).value("date").toString();
        QString pagenumbersizeweight =model.record(0).value("pagenumbersizeweight").toString();
        QString si = ui->sum->text();
        int suminput= si.toInt();
        int numflag1=1;
        for(int i=0;i<si.size();i++)
            if ((si[i]<'0')||(si[i]>'9'))
            {
                numflag1=0;
                break;
            }
        if(si.size()==0)
        {
            QMessageBox::critical(NULL, "错误","数量未填写！");
        }
        else if(numflag1==0)
        {
            QMessageBox::critical(NULL, "错误","数量填写格式错误！");

        }


        else if(suminput > sum )
        {
            QMessageBox::warning(NULL, tr("错误"), tr("输入商品数量大于库存！"));
        }
        else
        {
            confirm c(name, suminput);
            if(c.exec()==QDialog::Accepted)
            {

                if (addTrolley(num, name, description, primeprice, saleprice,column, suminput, discount, publishmentbrand, ISBNmaterialcolumn, date, pagenumbersizeweight))
                {
                    model.setData(model.index(0,6),sum-suminput);
                    model.submitAll();
                    QMessageBox::information(NULL, tr("成功"), tr("商品成功添加至购物车！"));
                    accept();
                }
            }

        }

    }else
    {
        QMessageBox::warning(NULL, tr("错误"), tr("未查询到商品！"));
    }
}
