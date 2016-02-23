#ifndef WIDGET_H
#define WIDGET_H

#include <QDialog>

namespace Ui {
class Widget;
}

class Widget : public QDialog
{
    Q_OBJECT

public:
    explicit Widget(QString un, QDialog *parent = 0);
    ~Widget();

private slots:
    void on_bankbound_clicked();

    void on_cancel_clicked();

    void on_modify_clicked();

    void on_store_clicked();

    void on_trolley_clicked();

private:
    Ui::Widget *ui;
    QString username;
};


#endif // WIDGET_H
