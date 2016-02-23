#ifndef CUSTOMERREGISTER_H
#define CUSTOMERREGISTER_H

#include <QDialog>

namespace Ui {
class CustomerRegister;
}

class CustomerRegister : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerRegister(QWidget *parent = 0);
    ~CustomerRegister();

private slots:
    void on_cancel_clicked();

    void on_confirm_clicked();

private:
    Ui::CustomerRegister *ui;
};

#endif // CUSTOMERREGISTER_H
