#-------------------------------------------------
#
# Project created by QtCreator 2014-11-26T21:24:48
#
#-------------------------------------------------

QT       += core gui\
            sql
QT      += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BankPortal
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    login.cpp \
    register.cpp \
    bankaccount.cpp \
    database.cpp \
    deposit.cpp \
    withdraw.cpp \
    querybalance.cpp \
    passwordreedit.cpp \
    renewinfo.cpp \
    frozen.cpp \
    netpay.cpp \
    confirminterface.cpp

HEADERS  += widget.h \
    login.h \
    register.h \
    bankaccount.h \
    database.h \
    deposit.h \
    withdraw.h \
    querybalance.h \
    passwordreedit.h \
    renewinfo.h \
    frozen.h \
    netpay.h \
    confirminterface.h

FORMS    += widget.ui \
    login.ui \
    register.ui \
    deposit.ui \
    withdraw.ui \
    querybalance.ui \
    passwordreedit.ui \
    renewinfo.ui \
    frozen.ui \
    netpay.ui \
    confirminterface.ui

ICON = bank.icns
