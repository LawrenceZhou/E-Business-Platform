#ifndef FROZEN_H
#define FROZEN_H

#include <QDialog>

namespace Ui {
class frozen;
}

class frozen : public QDialog
{
    Q_OBJECT

public:
    explicit frozen(QString ban, QWidget *parent = 0);
    ~frozen();

private slots:
    void on_cancel_clicked();

    void on_f_clicked();

    void on_df_clicked();

private:
    Ui::frozen *ui;
    QString bankaccn;
};

#endif // FROZEN_H
