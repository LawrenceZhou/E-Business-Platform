#ifndef VIEWUSER_H
#define VIEWUSER_H

#include <QDialog>

namespace Ui {
class viewuser;
}

class viewuser : public QDialog
{
    Q_OBJECT

public:
    explicit viewuser(QWidget *parent = 0);
    ~viewuser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::viewuser *ui;
};

#endif // VIEWUSER_H
