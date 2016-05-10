#-------------------------------------------------
#
# Project created by QtCreator 2016-03-31T10:44:32
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Captain
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serveur.cpp \
    thread.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    serveur.h \
    thread.h \
    database.h

FORMS    += mainwindow.ui
