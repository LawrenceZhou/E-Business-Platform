#ifndef ADMINISTRATOR_LOGIN_H
#define ADMINISTRATOR_LOGIN_H

#include <QDialog>

namespace Ui {
class administrator_login;
}

class administrator_login : public QDialog
{
    Q_OBJECT

public:
    explicit administrator_login(QWidget *parent = 0);
    ~administrator_login();

private slots:
    void on_cancel_clicked();

    void on_confirm_clicked();

private:
    Ui::administrator_login *ui;
};

#endif // ADMINISTRATOR_LOGIN_H
