#ifndef CONFIRM_H
#define CONFIRM_H

#include <QDialog>

namespace Ui {
class confirm;
}

class confirm : public QDialog
{
    Q_OBJECT

public:
    explicit confirm(QString name, int sum,QWidget *parent = 0);
    ~confirm();

private slots:
    void on_cancel_clicked();

    void on_confirm_2_clicked();

private:
    Ui::confirm *ui;
};

#endif // CONFIRM_H
