#ifndef MODIFYCOMMODITY_H
#define MODIFYCOMMODITY_H

#include <QSqlTableModel>
#include <QDialog>

namespace Ui {
class modifycommodity;
}

class modifycommodity : public QDialog
{
    Q_OBJECT

public:
    explicit modifycommodity(QWidget *parent = 0);
    ~modifycommodity();

private slots:
    void on_cancel_clicked();

    void on_confirm_clicked();

private:
    Ui::modifycommodity *ui;
    QSqlTableModel *model;
};

#endif // MODIFYCOMMODITY_H
