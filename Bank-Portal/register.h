#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QSql>
#include <QtCore>
#include <QtDebug>
#include <QTextCodec>
#include <QMessageBox>
#include <QTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>
namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QDialog *parent = 0);
    ~Register();

private slots:

    void on_cancel_clicked();

    void on_confirm_clicked();


private:
    Ui::Register *ui;
};


#endif // REGISTER_H
