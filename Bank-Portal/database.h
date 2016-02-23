#ifndef DATABASE_H
#define DATABASE_H
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


bool createConnection();
bool addAccount(BankAccount BA);


#endif // DATABASE_H
