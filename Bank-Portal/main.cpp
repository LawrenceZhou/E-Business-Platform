#include "widget.h"
#include <QApplication>
#include "login.h"
#include "register.h"
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
#include "bankaccount.h"
#include "database.h"
#include <QSqlTableModel>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QFile::remove("bankaccount.db");
    createConnection();
    login LoginInterface;
    QString Name;
    QString Pwd;
    if(LoginInterface.exec()==QDialog::Accepted)
    {
        Name = LoginInterface.getName();
        Pwd = LoginInterface.getPwd();
        Widget w(Name, Pwd);
        w.show();
        return a.exec();
    }
    else{
        return 0;
    }

}
