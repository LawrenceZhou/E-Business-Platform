#ifndef QUERYBALANCE_H
#define QUERYBALANCE_H

#include <QDialog>

namespace Ui {
class querybalance;
}

class querybalance : public QDialog
{
    Q_OBJECT

public:
    explicit querybalance(QString ban, QWidget *parent = 0);
    ~querybalance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::querybalance *ui;
    QString bankaccn;
};

#endif // QUERYBALANCE_H
