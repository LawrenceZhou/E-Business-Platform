#ifndef CONFIRMINTERFACE_H
#define CONFIRMINTERFACE_H
#include <QtNetwork>
#include <QDialog>

namespace Ui {
class confirminterface;
}

class confirminterface : public QDialog
{
    Q_OBJECT

public:
    explicit confirminterface(QString ban, QWidget *parent = 0);
    ~confirminterface();

private slots:

    void processPendingDatagram();

    void on_confirm_clicked();

    void on_cancel_clicked();

private:
    Ui::confirminterface *ui;
    QUdpSocket *udpSocket;
    qint16 port;
    QString bankaccountnumber;
    int a;
    QString string;
    double pd;
};

#endif // CONFIRMINTERFACE_H
