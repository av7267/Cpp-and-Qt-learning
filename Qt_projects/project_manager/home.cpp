#include "home.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"




void MainWindow::on_add_proj_clicked()
{
    QString name = ui -> proj_name -> text();
    QString des = ui -> proj_description -> text();
    QString prior = ui -> proj_priority -> currentText();
    QString stat = ui -> proj_status -> currentText();

    int rowCount = ui -> tableWidget -> rowCount();

    if(!des.isEmpty() && !name.isEmpty() && !prior.isEmpty() && !stat.isEmpty())
    {
        ui -> tableWidget -> insertRow(rowCount);

        ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(rowCount, 1, new QTableWidgetItem(prior));
        ui->tableWidget->setItem(rowCount, 2, new QTableWidgetItem(stat));

        ui->proj_name->clear();

        ui->proj_description->clear();

    }
}
