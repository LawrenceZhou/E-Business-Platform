#include "commodity.h"
#include "commoditydatabase.h"
Commodity::Commodity(QString n, QString d, double p, int c, int s)
{
    commoditynumber = returnnumber();
    commodityname = n;
    commoditydescription = d;
    commodityprimeprice = p;
    commoditycolumn = c;
    commoditysum = s;
    commoditydiscount=1;
    getPrice();
}
int Commodity::getCommoditynumber() const
{
    return commoditynumber;
}

QString Commodity::getCommodityname() const
{
    return commodityname;
}

QString Commodity::getCommoditydescription() const
{
    return commoditydescription;
}


int Commodity::getCommoditysum() const
{
    return commoditysum;
}

int Commodity::getCommoditycolumn() const
{
    return commoditycolumn;
}
double Commodity::getCommodityprimeprice() const
{
    return commodityprimeprice;
}

double Commodity::getCommoditysaleprice() const
{
    return commoditysaleprice;
}

double Commodity::getCommoditydiscount() const
{
    return commoditydiscount;
}

int Commodity::commoditynumber=0;
