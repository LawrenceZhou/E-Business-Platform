#ifndef CUSTOMER_LOGIN_H
#define CUSTOMER_LOGIN_H

#include <QDialog>

namespace Ui {
class customer_login;
}

class customer_login : public QDialog
{
    Q_OBJECT

public:
    explicit customer_login(QWidget *parent = 0);
    ~customer_login();

private slots:
    void on_register_2_clicked();

    void on_log_clicked();

private:
    Ui::customer_login *ui;
    QString Name;
    QString Pwd;
};

#endif // CUSTOMER_LOGIN_H
