#ifndef VIEWCOMMODITY_H
#define VIEWCOMMODITY_H
#include <QSqlQueryModel>
#include <QDialog>

namespace Ui {
class viewcommodity;
}

class viewcommodity : public QDialog
{
    Q_OBJECT

public:
    explicit viewcommodity(QWidget *parent = 0);
    ~viewcommodity();

private slots:
    void on_confirm_clicked();


private:
    Ui::viewcommodity *ui;
};

#endif // VIEWCOMMODITY_H
