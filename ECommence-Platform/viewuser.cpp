#include "viewuser.h"
#include "ui_viewuser.h"
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

viewuser::viewuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewuser)
{
    ui->setupUi(this);
    setFixedSize(600,250);
    setWindowTitle("浏览用户信息");

    QSqlQueryModel *mode  = new QSqlQueryModel(ui->tableView);   //建立一个Model
    mode->setQuery("select * from user") ;
    mode->setHeaderData(0,Qt::Horizontal,QObject::tr("用户名"));
    mode->setHeaderData(1,Qt::Horizontal,QObject::tr("性别"));
    mode->setHeaderData(2,Qt::Horizontal,QObject::tr("密码"));
    mode->setHeaderData(3,Qt::Horizontal,QObject::tr("收货人"));
    mode->setHeaderData(4,Qt::Horizontal,QObject::tr("手机"));
    mode->setHeaderData(5,Qt::Horizontal,QObject::tr("地址"));
    mode->setHeaderData(6,Qt::Horizontal,QObject::tr("银行绑定"));
    mode->setHeaderData(7,Qt::Horizontal,QObject::tr("银行账号"));
    ui->tableView->setModel(mode);
}

viewuser::~viewuser()
{
    delete ui;
}

void viewuser::on_pushButton_clicked()
{
    close();
}
