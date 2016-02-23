#include "confirminterface.h"
#include "ui_confirminterface.h"
#include <QSqlTableModel>
#include <QSqlRecord>
#include "database.h"
#include <QMessageBox>
#include <QDebug>

confirminterface::confirminterface(QString ban, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirminterface)
{
    ui->setupUi(this);
    setWindowTitle("确认界面");
    setFixedSize(280,130);
    udpSocket = new QUdpSocket(this);
    port = 45454;
    bankaccountnumber=ban;
    udpSocket->bind(port, QUdpSocket::ShareAddress);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));
    processPendingDatagram();
    a=0;

}

confirminterface::~confirminterface()
{
    delete ui;
}

void confirminterface::processPendingDatagram()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram; //拥于存放接收的数据报
        datagram.resize(udpSocket->pendingDatagramSize());
        //让datagram的大小为等待处理的数据报的大小，这样才能接收到完整的数据
        udpSocket->readDatagram(datagram.data(),datagram.size());
        //接收数据报，将其存放到datagram中

        string = QString(datagram);
        QString p;
        for(int i=11;i<string.size();i++)
        {
            p[i-11]=string[i];
        }
        pd = p.toDouble();
        if(string[0]=='0')
        {
            ui->label->setText("对方请求绑定");
        }
        else
        {
            ui->label->setText(tr("对方请求支付%1元").arg(pd));
        }
        QSqlTableModel m;
        m.setTable("bankaccount");

        m.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccountnumber));
        m.select();

        QString password = m.record(0).value("password").toString();

        if(password[0]==string[5]&&password[1]==string[6]&&password[2]==string[7]&&password[3]==string[8]&&password[4]==string[9]&&password[5]==string[10])
        {
            ui->label_2->setText("对方密码输入正确");
            a=1;
        }
        else
        {
            ui->label_2->setText("对方密码输入错误");
        }

    }
}

void confirminterface::on_confirm_clicked()
{
    QString message ="1";
    QByteArray m = message.toLatin1();
    if(a==1)
    {


        if(string[0]=='0')
        {
            QMessageBox::information(NULL, "成功","绑定成功！");
            udpSocket->writeDatagram(m.data(), m.size(), QHostAddress::Broadcast, 23232);
        }
        else
        {
            QSqlTableModel mo;
            mo.setTable("bankaccount");

            mo.setFilter(tr("bankaccountnumber = '%1'").arg(bankaccountnumber));
            mo.select();


            double b = mo.record(0).value("balance").toDouble();

            qDebug()<<pd;
            if(b<pd)
            {
                message ="2";
                QByteArray m = message.toLatin1();
                udpSocket->writeDatagram(m.data(), m.size(), QHostAddress::Broadcast, 23232);
                QMessageBox::information(NULL, "失败","支付金额大余额，支付失败！");
            }
            else
            {
                udpSocket->writeDatagram(m.data(), m.size(), QHostAddress::Broadcast, 23232);
                b=b-pd;
                mo.setData(mo.index(0,8),b);
                if(mo.submitAll())
                    QMessageBox::information(NULL, "成功","支付成功！");
                else
                    QMessageBox::information(NULL, "失败","支付失败！");
            }


        }
        accept();
    }
    else if(a==0)
    {
        message ="2";
        QByteArray m = message.toLatin1();
        udpSocket->writeDatagram(m.data(), m.size(), QHostAddress::Broadcast, 23232);
        if(string[0]=='0')
        {
            QMessageBox::critical(NULL, "失败","密码不正确禁止绑定！");
        }
        else
        {
            QMessageBox::critical(NULL, "失败","密码不正确禁止支付！");
        }
        close();
    }

}

void confirminterface::on_cancel_clicked()
{
    QString message ="2";
    QByteArray m = message.toLatin1();
    udpSocket->writeDatagram(m.data(), m.size(), QHostAddress::Broadcast, 23232);
    close();
}
