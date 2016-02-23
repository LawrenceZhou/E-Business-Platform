#include "store.h"
#include "ui_store.h"
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QToolButton>
#include <QToolBox>
#include <QDebug>
#include <QGroupBox>
#include <QVBoxLayout>

store::store(QWidget *parent, Qt::WindowFlags f) :
    QToolBox(parent, f)
    //ui(new Ui::store)
{
    setWindowTitle("store");
    //ui->setupUi(this);
    QSqlTableModel model;
    model.setTable("commodity");
    //model.setFilter(QObject::tr("column = 3 ")); //根据姓名进行筛选
    model.select(); //显示结果
    qDebug()<<model.rowCount();
    //QToolButton * button[model.rowCount()];
    for (int i = 0; i < model.rowCount(); i++)
    {
        button[i]= new QToolButton;
        button[i]->setText(model.record(i).value("name").toString());
    }

    QGroupBox * groupbox = new QGroupBox;
    QVBoxLayout *layout = new QVBoxLayout(groupbox);
    layout->setMargin(20);
    for(int i = 0; i < model.rowCount(); i++)
    {
        layout->addWidget(button[i]);
    }
    this->addItem((QWidget *)groupbox,"");
}

