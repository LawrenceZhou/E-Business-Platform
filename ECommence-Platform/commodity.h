#ifndef COMMODITY_H
#define COMMODITY_H
#include <QImage>
class Commodity
{
protected:
    double commodityprimeprice;
    double commoditydiscount;
    double commoditysaleprice;
private:
    static int commoditynumber;
    QString commodityname;
    QString commoditydescription;
    int commoditycolumn;
    int commoditysum;


public:
    Commodity(QString n, QString d, double p, int c, int s);
    int getCommoditynumber()const;
    QString getCommodityname()const;
    QString getCommoditydescription()const;
    int getCommoditysum()const;
    int getCommoditycolumn()const;
    double getCommodityprimeprice()const;
    double getCommoditysaleprice()const;
    double getCommoditydiscount()const;
    virtual double getPrice(){
        commoditysaleprice= commodityprimeprice*commoditydiscount;
        return commoditysaleprice;
    }

};

class Book : public Commodity
{
private:
    QString BookPublishment;
    QString BookISBN;
    QString BookDate;
    QString BookPageNumber;
public:
    Book(QString n, QString d, double p, int c, int s, QString bp, QString bi, QString bd, QString bn):Commodity(n, d, p, c, s)
    {
        BookPublishment = bp;
        BookISBN = bi;
        BookDate = bd;
        BookPageNumber =bn;
    }
    QString getBookpublishment()const
    {
        return BookPublishment;
    }
    QString getBookISBN()const
    {
        return BookISBN;
    }
    QString getBookdate()const
    {
        return BookDate;
    }
    QString getBookpagenumber()const
    {
        return BookPageNumber;
    }

};

class Clothes: public Commodity
{
private:
    QString ClothesBrand;
    QString ClothesMaterial;
    QString ClothesDate;
    QString ClothesSize;

public:
    Clothes(QString n, QString d, double p, int c, int s, QString cb, QString cm, QString cd, QString cs):Commodity(n, d, p, c, s)
    {
        ClothesBrand = cb;
        ClothesMaterial = cm;
        ClothesDate = cd;
        ClothesSize =cs;
    }
    QString getClothesbrand()const
    {
        return ClothesBrand;
    }
    QString getClothesmaterial()const
    {
        return ClothesMaterial;
    }
    QString getClothesdate()const
    {
        return ClothesDate;
    }
    QString getClothessize()const
    {
        return ClothesSize;
    }

};

class Food: public Commodity
{
private:
    QString FoodBrand;
    QString FoodColumn;
    QString FoodDate;
    QString FoodWeight;
public:
    Food(QString n, QString d, double p, int c, int s, QString fb, QString fc, QString fd, QString fw):Commodity(n, d, p, c, s)
    {
        FoodBrand = fb;
        FoodColumn = fc;
        FoodDate= fd;
        FoodWeight =fw;
    }
    QString getFoodbrand()const
    {
        return FoodBrand;
    }
    QString getFoodcolumn()const
    {
        return FoodColumn;
    }
    QString getFooddate()const
    {
        return FoodDate;
    }
    QString getFoodweight()const
    {
        return FoodWeight;
    }

};

class ElectronicProduct: public Commodity
{
private:
    QString EProductBrand;
    QString EProductColumn;
    QString EProductDate;
    QString EProductWeight;

public:
    ElectronicProduct(QString n, QString d, double p, int c, int s, QString eb, QString ec, QString ed, QString ew):Commodity(n, d, p, c, s)
    {
        EProductBrand = eb;
        EProductColumn = ec;
        EProductDate= ed;
        EProductWeight =ew;
    }
    QString getEproductbrand()const
    {
        return EProductBrand;
    }
    QString getEproductcolumn()const
    {
        return EProductColumn;
    }
    QString getEproductdate()const
    {
        return EProductDate;
    }
    QString getEproductweight()const
    {
        return EProductWeight;
    }

};

#endif // COMMODITY_H
