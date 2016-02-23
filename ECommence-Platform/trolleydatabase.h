#ifndef TROLLEYDATABASE_H
#define TROLLEYDATABASE_H
#include <QObject>
bool createTrolleyConnection();
bool addTrolley(int number, QString name, QString description, double primeprice, double saleprice, int column, int sum,  double discount, QString publishmentbrand, QString ISBNmaterialcolumn, QString date, QString pagenumbersizeweight);
#endif // TROLLEYDATABASE_H
