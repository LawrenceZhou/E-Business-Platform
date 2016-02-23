#include "deletecommodity.h"
#include "ui_deletecommodity.h"
#include "commodity.h"
#include "commoditydatabase.h"
#include <QSqlTableModel>
#include <QMessageBox>
deletecommodity::deletecommodity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletecommodity)
{
    ui->setupUi(this);
    setWindowTitle("删除商品");
    setFixedSize(240,100);
}

deletecommodity::~deletecommodity()
{
    delete ui;
}

void deletecommodity::on_cancel_clicked()
{
    close();
}

void deletecommodity::on_confirm_clicked()
{
    int num = ui->code->text().toInt();
    QSqlTableModel model;
    model.setTable("commodity");
    model.setFilter(tr("number = '%1'").arg(num));
    model.select();
    if(model.rowCount()==1)//查询到有一个结果
    {
        model.removeRow(0);
        QMessageBox::information(NULL, tr("删除"), tr("商品删除成功！"));
        accept();//隐含窗口，并返回结果QDialg::Accepted
    }else
    {
        QMessageBox::warning(NULL, tr("错误"), tr("未查询到商品！"));
    }

}
