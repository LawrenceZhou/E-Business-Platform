#include "modifycommodity.h"
#include "ui_modifycommodity.h"
#include <QSqlTableModel>
#include "commoditydatabase.h"
#include <QMessageBox>

modifycommodity::modifycommodity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifycommodity)
{
    ui->setupUi(this);
    setFixedSize(800,250);
    setWindowTitle("修改商品信息");

    model = new QSqlTableModel(this);
    model->setTable("commodity");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("名称"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("描述"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("原价"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("售价"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("种类"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("数量"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("折扣"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("出版社/品牌"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("ISBN/材料/类别"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("日期"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("页数/型号/重量"));
    model->select(); //选取整个表的所有行

    ui->tableView->setModel(model);

}

modifycommodity::~modifycommodity()
{
    delete ui;
}

void modifycommodity::on_cancel_clicked()
{
    close();
}

void modifycommodity::on_confirm_clicked()
{
    model->database().transaction(); //开始事务操作
    if (model->submitAll())
    {
        model->database().commit(); //提交
        QMessageBox::information(this, tr("成功"), tr("修改商品信息成功！"));
        accept();
    }
    else
    {
        model->database().rollback(); //回滚
        QMessageBox::warning(this, tr("失败"), tr("修改商品信息错误！"));
    }
}
