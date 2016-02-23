#ifndef DELETECOMMODITY_H
#define DELETECOMMODITY_H

#include <QDialog>

namespace Ui {
class deletecommodity;
}

class deletecommodity : public QDialog
{
    Q_OBJECT

public:
    explicit deletecommodity(QWidget *parent = 0);
    ~deletecommodity();

private slots:
    void on_cancel_clicked();

    void on_confirm_clicked();

private:
    Ui::deletecommodity *ui;
};

#endif // DELETECOMMODITY_H
