#include "bankbound.h"
#include "ui_bankbound.h"
#include "userdatabase.h"
#include <QMessageBox>
#include "boundorunbound.h"
bankbound::bankbound(QString un, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bankbound)
{
    ui->setupUi(this);
    setFixedSize(240,120);
    setWindowTitle("银行支付");
    username=un;
    if(returnbankbound(un)==0)
    {
        ui->label->setText(tr("您尚未开通银行支付功能。"));
    }
    else
    {
        ui->label->setText(tr("您已开通银行支付功能。"));
    }
}

bankbound::~bankbound()
{
    delete ui;
}

void bankbound::on_pushButton_3_clicked()
{
    close();
}

void bankbound::on_pushButton_clicked()
{
    if(openbankbound(username))
    {
        accept();
    }
}

void bankbound::on_pushButton_2_clicked()
{
    if(closebankbound(username))
    {
        accept();
    }
}

void bankbound::on_bound_clicked()
{
    if(returnbankbound(username)==0)
    {
        QMessageBox::warning(NULL, "注意","您的用户尚未开通银行支付功能！");
    }
    else
    {
        boundorunbound b(username);
        b.exec();

    }
}

