#ifndef EVENT_H
#define EVENT_H

#include <QDialog>

namespace Ui {
class event;
}

class event : public QDialog
{
    Q_OBJECT

public:
    explicit event(QWidget *parent = 0);
    ~event();

private slots:
    void on_cancel_clicked();

    void on_confirm_clicked();

    void on_confirm2_clicked();

private:
    Ui::event *ui;
};

#endif // EVENT_H
