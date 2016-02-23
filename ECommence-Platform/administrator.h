#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QDialog>

namespace Ui {
class administrator;
}

class administrator : public QDialog
{
    Q_OBJECT

public:
    explicit administrator(QWidget *parent = 0);
    ~administrator();

private slots:
    void on_exit_clicked();

    void on_add_clicked();

    void on_comminfo_clicked();

    void on_userinfo_clicked();

    void on_delete_2_clicked();

    void on_modify_clicked();

    void on_event_clicked();

private:
    Ui::administrator *ui;
};

#endif // ADMINISTRATOR_H
