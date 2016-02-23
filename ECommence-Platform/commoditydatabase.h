#ifndef COMMODITYDATABASE_H
#define COMMODITYDATABASE_H
#include "commodity.h"
bool createCommodityConnection();
bool addBook( Book B);
bool addClothes( Clothes B);
bool addFood( Food B);
bool addEProduct(ElectronicProduct B );
int returnnumber();

#endif // COMMODITYDATABASE_H
