#ifndef RENEWINFO_H
#define RENEWINFO_H

#include <QDialog>

namespace Ui {
class renewinfo;
}

class renewinfo : public QDialog
{
    Q_OBJECT

public:
    explicit renewinfo(QString ban, QWidget *parent = 0);
    ~renewinfo();

private slots:
    void on_cancel_clicked();

    void on_confirm_clicked();

private:
    Ui::renewinfo *ui;
    QString bankaccn;
};

#endif // RENEWINFO_H
