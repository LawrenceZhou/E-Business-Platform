#include "widget.h"
#include <QApplication>
#include "login.h"
#include "userdatabase.h"
#include "commoditydatabase.h"
#include "trolleydatabase.h"
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
#include <QSqlTableModel>
#include <QObject>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    login LoginInterface;
    //QFile::remove("user.db");
    //QFile::remove("commodity.db");
    //QFile::remove("trolley.db");
    createUserConnection();
    createCommodityConnection();
    createTrolleyConnection();
    LoginInterface.exec();
    return a.exec();
}
