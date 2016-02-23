#ifndef ESTORE_H
#define ESTORE_H

#include <QDialog>
#include "commodity.h"
#include "widget.h"
namespace Ui {
class estore;
}

class estore : public QDialog
{
    Q_OBJECT

public:
    explicit estore(QWidget *parent = 0);
    ~estore();

private slots:
    void on_cancel_clicked();

    void on_confirm_clicked();

private:
    Ui::estore *ui;
};



//int i=0;
/*for(int i=0;i<100;i++)
{
    t[i]= new truck("",0,0);
};
*/

#endif // ESTORE_H
