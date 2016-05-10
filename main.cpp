#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <qtsql/QtSql>
#include <QCoreApplication>
#include <iostream>

#define q2c(string) string.toStdString()


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
