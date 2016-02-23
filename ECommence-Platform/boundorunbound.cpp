#include "boundorunbound.h"
#include "ui_boundorunbound.h"
#include <QSqlTableModel>
#include <QSqlRecord>
#include "userdatabase.h"
#include <QDebug>
#include <QMessageBox>
boundorunbound::boundorunbound(QString un, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::boundorunbound)
{
    ui->setupUi(this);
    setFixedSize(340,160);
    setWindowTitle("绑定解绑");
    username=un;
    udpSocket = new QUdpSocket(this);
    port = 23232;
    udpSocket->bind(port, QUdpSocket::ShareAddress);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));


    message ="0";

}

boundorunbound::~boundorunbound()
{
    delete ui;
}

void boundorunbound::on_cancel_clicked()
{
    close();
}

void boundorunbound::on_bound_clicked()
{
    QString  bn = returnbanknumber(username);
    bpinput = ui->password->text();
    bninput =ui->banknumber->text();
    message += bninput+bpinput;
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
        QMessageBox::information(NULL, "失败","已经绑定过该账号！");
    }
    else
    {
        QByteArray m = message.toLatin1();
        udpSocket->writeDatagram(m.data(), m.size(), QHostAddress::Broadcast, 45454);
        processPendingDatagram();

    }
}

void boundorunbound::processPendingDatagram()
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
            ui->label_4->setText("成功绑定！");

            QString bn="";

            qDebug()<<bn;
            QString a= returnbanknumber(username);
            bn.append(a);
            qDebug()<<bn;
            qDebug()<<a;
            bn.append("#");
            bn.append(ui->banknumber->text());
            qDebug()<<bn;
            qDebug()<<bpinput;
            QSqlTableModel m;
            m.setTable("user");

            m.setFilter(QObject::tr("username = '%1'").arg(username));
            m.select();
            m.setData(m.index(0,7),bn);
            m.submitAll();
        }
        else
        {
            ui->label_4->setText("绑定失败！");
        }

    }
}

void boundorunbound::on_unbound_clicked()
{
    QString  bn = returnbanknumber(username);
    QString bninput =ui->banknumber->text();

    int a=1;
    for(int i=0; i<bn.size();i+=5)
    {
        if(bninput[0]==bn[i+1]&&bninput[1]==bn[i+2]&&bninput[2]==bn[i+3]&&bninput[3]==bn[i+4])
        {
            for(int k=i;k<bn.size()-5;k++)
            {
                bn[k]=bn[k+5];
            }
            bn.resize(bn.size()-5);
            a=0;
            QSqlTableModel m;
            m.setTable("user");

            m.setFilter(QObject::tr("username = '%1'").arg(username));
            m.select();
            m.setData(m.index(0,7),bn);
            m.submitAll();
            break;
        }
    }
    if(a==0)
    {
        QMessageBox::information(NULL, "成功","已经解绑该账号！");
    }
    else
    {
        QMessageBox::information(NULL, "失败","未绑定过该账号！");
    }
}
