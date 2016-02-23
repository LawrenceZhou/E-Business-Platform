#include "widget.h"
#include "ui_widget.h"
#include "bankbound.h"
#include "renewinfo.h"
#include "estore.h"
#include "trolley.h"
#include "closeinterface.h"
#include "trolleydatabase.h"
#include "commoditydatabase.h"
#include <QSqlTableModel>
#include <QSqlRecord>

Widget::Widget(QString un, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Widget)
{
    username= un;
    ui->setupUi(this);
    setFixedSize(330,150);
    setWindowTitle("商城");
    ui->username->setText(tr("%1").arg(un));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_bankbound_clicked()
{
    bankbound b(username);
    b.exec();
}

void Widget::on_cancel_clicked()
{
    closeinterface c;
    if(c.exec()==QDialog::Accepted)
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
                m.setData(model.index(0,6),m.record(0).value("sum").toInt()+b);
                m.submitAll();
                model.removeRow(i);

            }
        }
        close();
    }
}

void Widget::on_modify_clicked()
{
    renewinfo r(username);
    r.exec();
}

void Widget::on_store_clicked()
{
    estore e;
    e.exec();
}

void Widget::on_trolley_clicked()
{
    trolley t(username);
    t.exec();
}
