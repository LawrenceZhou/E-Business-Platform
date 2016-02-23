#ifndef NETPAY_H
#define NETPAY_H

#include <QDialog>

namespace Ui {
class netpay;
}

class netpay : public QDialog
{
    Q_OBJECT

public:
    explicit netpay(QString ban,QWidget *parent = 0);
    ~netpay();

private slots:
    void on_n_clicked();

    void on_dn_clicked();

    void on_cancel_clicked();

    void on_confirm_clicked();

private:
    Ui::netpay *ui;
    QString bankaccn;
    int n;
};

#endif // NETPAY_H
