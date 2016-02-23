#ifndef STORE_H
#define STORE_H

#include <QToolBox>
#include <QToolButton>
#include "widget.h"



class store : public QToolBox
{
    Q_OBJECT

public:
    store(QWidget *parent = 0, Qt::WindowFlags f=0);


private:
    QToolButton *button[100];
};

#endif // STORE_H
