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
    explicit renewinfo(QString un, QWidget *parent = 0);
    ~renewinfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::renewinfo *ui;
    QString username;
};

#endif // RENEWINFO_H
