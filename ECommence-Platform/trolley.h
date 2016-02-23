#ifndef TROLLEY_H
#define TROLLEY_H

#include <QDialog>
#include "estore.h"
namespace Ui {
class trolley;
}

class trolley : public QDialog
{
    Q_OBJECT

public:
    explicit trolley(QString un,  QWidget *parent = 0);
    ~trolley();

private slots:
    void on_cancel_clicked();

    void on_confirm_clicked();

    void on_delete_2_clicked();

    void on_reset_clicked();

private:
    Ui::trolley *ui;
    QString username;
    double s;
    int itemnum;

};

#endif // TROLLEY_H
