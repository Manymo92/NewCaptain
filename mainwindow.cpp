#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QtSql/QtSql>
#include <QtWidgets>

#define q2c(string) string.toStdString()

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    dt = new database();
    dt->verification();
    model2 = new QSqlQueryModel(this);

   model2->setQuery("SELECT * FROM employer");
   ui->tableView->setModel(model2);

    model2 = new QSqlQueryModel(this);
    model2->setQuery("SELECT * FROM autorisation");
    ui->tableView_2->setModel(model2);/**/


   /* QSqlQuery query;
    if(query.exec("SELECT presence FROM employer"))
    {
        int nb=0 ;
        for(int x=0;x<query.record().count();++x)
        {
            query.next();

            if(query.value(6)==1)
            {
                nb++;
                ui->label->setNum(nb);
            }
        }
    }*/
}

MainWindow::~MainWindow()
{
    //db->close();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //db->close();
  //  ui->centralWidget->close();
   /* qDebug()<<db.contains();
    qDebug()<<db.connectionName();
    qDebug()<<db.connectOptions();

    if(db.isOpen())
    { qDebug()<<"dqsdqsd couver";

    }else
    {
         qDebug()<<"ba NOON";
    }*/
}


void MainWindow::on_pushButton_2_clicked()
{
    model = new QSqlTableModel(this);
    model->setTable("autorisation");
    model->select();
    ui->tableView_2->setModel(model);
}

void MainWindow::on_pushButton_3_clicked()
{
    model = new QSqlTableModel(this);
    model->setTable("employer");
    model->select();
    ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_4_clicked()
{
    model->insertRow(model->rowCount(QModelIndex()));
}
