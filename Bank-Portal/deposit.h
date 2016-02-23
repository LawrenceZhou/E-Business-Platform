#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>

namespace Ui {
class deposit;
}

class deposit : public QDialog
{
    Q_OBJECT

public:
    explicit deposit(QString num, QDialog *parent = 0);
    ~deposit();

private slots:
    void on_cancel_clicked();

    void on_deposit_2_clicked();

private:
    Ui::deposit *ui;
    QString bankaccn;
};

#endif // DEPOSIT_H
