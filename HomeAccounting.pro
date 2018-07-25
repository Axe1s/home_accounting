#-------------------------------------------------
#
# Project created by QtCreator 2015-05-16T09:38:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HomeAccounting
TEMPLATE = app


SOURCES += main.cpp\
        homeaccounting.cpp \
    counteredit.cpp \
    cmedicineedit.cpp

HEADERS  += homeaccounting.h \
    counteredit.h \
    cmedicineedit.h

FORMS    += homeaccounting.ui \
    counteredit.ui \
    cmedicineedit.ui
