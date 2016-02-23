#ifndef PASSWORDREEDIT_H
#define PASSWORDREEDIT_H

#include <QDialog>

namespace Ui {
class passwordreedit;
}

class passwordreedit : public QDialog
{
    Q_OBJECT

public:
    explicit passwordreedit(QString ban, QWidget *parent = 0);
    ~passwordreedit();

private slots:

    void on_cancel_clicked();

    void on_confirm_clicked();

private:
    Ui::passwordreedit *ui;
    QString bankaccn;
};

#endif // PASSWORDREEDIT_H
