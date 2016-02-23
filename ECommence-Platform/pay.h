#ifndef PAY_H
#define PAY_H

#include <QDialog>
#include <QtNetwork>
namespace Ui {
class pay;
}

class pay : public QDialog
{
    Q_OBJECT

public:
    explicit pay(QString un, double sum,QWidget *parent = 0);
    ~pay();

private slots:
    void on_cancel_clicked();

    void on_confirm_clicked();

    void processPendingDatagram();

private:
    Ui::pay *ui;
    double s;
    QString username;
    QUdpSocket *udpSocket;
    qint16 port;
    QString message;
    QString bninput;
    QString bpinput;
    QString st;
};

#endif // PAY_H
