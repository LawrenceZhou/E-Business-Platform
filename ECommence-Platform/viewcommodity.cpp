#include "viewcommodity.h"
#include "ui_viewcommodity.h"
#include "commodity.h"
#include "commoditydatabase.h"
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>


viewcommodity::viewcommodity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewcommodity)
{
    ui->setupUi(this);
    setFixedSize(900,250);
    setWindowTitle("浏览商品信息");

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

viewcommodity::~viewcommodity()
{
    delete ui;
}

void viewcommodity::on_confirm_clicked()
{
    close();
}


