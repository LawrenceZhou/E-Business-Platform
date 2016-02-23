#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QDialog>

namespace Ui {
class addproduct;
}

class addproduct : public QDialog
{
    Q_OBJECT

public:
    explicit addproduct(int i, QWidget *parent = 0);
    ~addproduct();

private slots:
    void on_cancel_clicked();

    void on_add_clicked();

private:
    Ui::addproduct *ui;
    int col;
};

#endif // ADDPRODUCT_H
