#-------------------------------------------------
#
# Project created by QtCreator 2014-12-16T08:38:54
#
#-------------------------------------------------

QT       += core gui\
            sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ECommercePlatform
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    user.cpp \
    commodity.cpp \
    login.cpp \
    customer_login.cpp \
    administrator_login.cpp \
    customerregister.cpp \
    userdatabase.cpp \
    commoditydatabase.cpp \
    bankbound.cpp \
    renewinfo.cpp \
    administrator.cpp \
    addproduct.cpp \
    viewcommodity.cpp \
    viewuser.cpp \
    deletecommodity.cpp \
    modifycommodity.cpp \
    event.cpp \
    estore.cpp \
    confirm.cpp \
    trolley.cpp \
    trolleydatabase.cpp \
    boundorunbound.cpp \
    closeinterface.cpp \
    pay.cpp

HEADERS  += widget.h \
    user.h \
    commodity.h \
    login.h \
    customer_login.h \
    administrator_login.h \
    customerregister.h \
    userdatabase.h \
    commoditydatabase.h \
    bankbound.h \
    renewinfo.h \
    administrator.h \
    addproduct.h \
    viewcommodity.h \
    viewuser.h \
    deletecommodity.h \
    modifycommodity.h \
    event.h \
    estore.h \
    confirm.h \
    trolley.h \
    trolleydatabase.h \
    boundorunbound.h \
    closeinterface.h \
    pay.h

FORMS    += widget.ui \
    login.ui \
    customer_login.ui \
    administrator_login.ui \
    customerregister.ui \
    bankbound.ui \
    renewinfo.ui \
    administrator.ui \
    addproduct.ui \
    viewcommodity.ui \
    viewuser.ui \
    deletecommodity.ui \
    modifycommodity.ui \
    event.ui \
    estore.ui \
    confirm.ui \
    trolley.ui \
    boundorunbound.ui \
    closeinterface.ui \
    pay.ui


ICON = dollar.icns
