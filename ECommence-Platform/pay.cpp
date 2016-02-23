#include "pay.h"
#include "ui_pay.h"
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "userdatabase.h"
#include <QDebug>

pay::pay(QString un, double sum, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pay)
{
    ui->setupUi(this);
    setFixedSize(600,120);
    setWindowTitle("支付确认");
    username=un;
    s=sum;
    QSqlQueryModel *mode  = new QSqlQueryModel(ui->tableView);   //建立一个Model
    mode->setQuery(QObject::tr("select * from user where username = '%1'").arg(username)) ;
    mode->setHeaderData(0,Qt::Horizontal,QObject::tr("银行卡号"));
    mode->setHeaderData(0,Qt::Horizontal,QObject::tr("用户名"));
    mode->setHeaderData(1,Qt::Horizontal,QObject::tr("性别"));
    mode->setHeaderData(2,Qt::Horizontal,QObject::tr("密码"));
    mode->setHeaderData(3,Qt::Horizontal,QObject::tr("收货人"));
    mode->setHeaderData(4,Qt::Horizontal,QObject::tr("手机"));
    mode->setHeaderData(5,Qt::Horizontal,QObject::tr("地址"));
    mode->setHeaderData(6,Qt::Horizontal,QObject::tr("银行绑定"));
    mode->setHeaderData(7,Qt::Horizontal,QObject::tr("银行账号"));
    ui->tableView->setModel(mode);

    udpSocket = new QUdpSocket(this);
    port = 23232;
    udpSocket->bind(port, QUdpSocket::ShareAddress);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));
    st =  QString::number(s);

}

pay::~pay()
{
    delete ui;
}

void pay::on_cancel_clicked()
{
    close();
}

void pay::on_confirm_clicked()
{
    QString  bn = returnbanknumber(username);
    bninput =ui->ban->text();
    bpinput=ui->psw->text();
    if(bninput.size()<4)
    {
         QMessageBox::warning(NULL, "失败","银行卡号不是四位！");
    }
    else if(bpinput.size()<6)
    {
         QMessageBox::warning(NULL, "失败","密码不是六位！");
    }
    else
    {
    message ="1";
    message+=bninput+bpinput+st;

    int a=1;
    for(int i=0; i<bn.size();i+=5)
    {
        if(bninput[0]==bn[i+1]&&bninput[1]==bn[i+2]&&bninput[2]==bn[i+3]&&bninput[3]==bn[i+4])
        {
            a=0;
            break;
        }
    }
    if(a==0)
    {

        QByteArray m = message.toLatin1();
        qDebug()<<m;
        udpSocket->writeDatagram(m.data(), m.size(), QHostAddress::Broadcast, 45454);
        processPendingDatagram();
    }
    else
    {
        QMessageBox::information(NULL, "失败","未绑定过该账号！");


    }
    }
}

void pay::processPendingDatagram()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram; //拥于存放接收的数据报
        datagram.resize(udpSocket->pendingDatagramSize());
        //让datagram的大小为等待处理的数据报的大小，这样才能接收到完整的数据
        udpSocket->readDatagram(datagram.data(),datagram.size());
        //接收数据报，将其存放到datagram中
        QString q = QString(datagram);
        //将数据报内容显示出来
        if(q=="1")
        {
            ui->label_4->setText("成功支付！");
            QSqlTableModel model;
            model.setTable("trolley");
            model.select();

            for(int i=0; i<model.rowCount();i++)
            {
                model.removeRow(i);
            }
            accept();

        }
        else
        {
            ui->label_4->setText("支付失败！");
        }
    }
}



