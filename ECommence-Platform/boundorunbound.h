#ifndef BOUNDORUNBOUND_H
#define BOUNDORUNBOUND_H
#include <QtNetwork>
#include <QDialog>

namespace Ui {
class boundorunbound;
}

class boundorunbound : public QDialog
{
    Q_OBJECT

public:
    explicit boundorunbound(QString un,QWidget *parent = 0);
    ~boundorunbound();

private slots:
    void on_cancel_clicked();

    void on_bound_clicked();

    void processPendingDatagram();

    void on_unbound_clicked();

private:
    Ui::boundorunbound *ui;
    QString username;
    QUdpSocket *udpSocket;
    qint16 port;
    QString bpinput;
    QString bninput;
    QString message;
};

#endif // BOUNDORUNBOUND_H
