#ifndef BANKBOUND_H
#define BANKBOUND_H

#include <QDialog>

namespace Ui {
class bankbound;
}

class bankbound : public QDialog
{
    Q_OBJECT

public:
    explicit bankbound(QString un, QWidget *parent = 0);
    ~bankbound();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_bound_clicked();


private:
    Ui::bankbound *ui;
    QString username;
};

#endif // BANKBOUND_H
