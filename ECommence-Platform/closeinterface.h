#ifndef CLOSEINTERFACE_H
#define CLOSEINTERFACE_H

#include <QDialog>

namespace Ui {
class closeinterface;
}

class closeinterface : public QDialog
{
    Q_OBJECT

public:
    explicit closeinterface(QWidget *parent = 0);
    ~closeinterface();

private slots:
    void on_cancel_clicked();

    void on_confirm_clicked();

private:
    Ui::closeinterface *ui;
};

#endif // CLOSEINTERFACE_H
