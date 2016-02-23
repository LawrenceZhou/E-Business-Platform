#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QDialog>

namespace Ui {
class withdraw;
}

class withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit withdraw(QString ban, QWidget *parent = 0);
    ~withdraw();

private slots:
    void on_cancel_clicked();

    void on_withdraw_2_clicked();

private:
    Ui::withdraw *ui;
    QString bankaccn;
};

#endif // WITHDRAW_H
