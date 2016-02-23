#include "closeinterface.h"
#include "ui_closeinterface.h"

closeinterface::closeinterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::closeinterface)
{
    ui->setupUi(this);
    setWindowTitle("确认退出");
    setFixedSize(270,140);
}

closeinterface::~closeinterface()
{
    delete ui;
}

void closeinterface::on_cancel_clicked()
{
    close();
}

void closeinterface::on_confirm_clicked()
{
    accept();
}
