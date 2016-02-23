#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QString n,QString p, QWidget *parent = 0);
    ~Widget();

private slots:
    void on_frozen_clicked();

    void on_deposit_clicked();

    void on_withdraw_clicked();

    void on_exit_clicked();

    void on_balance_clicked();

    void on_pwr_clicked();

    void on_phoneadd_clicked();

    void on_netp_clicked();


private:
    Ui::Widget *ui;
    QString name;
    QString pwd;

};


#endif // WIDGET_H
