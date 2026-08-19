#include "project_manager.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"




void MainWindow::on_add_proj_clicked()
{


    QString name = ui -> proj_name -> text();
    QString des = ui -> proj_description -> text();
    QString prior = ui -> proj_priority -> currentText();
    QString stat = ui -> proj_status -> currentText();



    if(!des.isEmpty() && !name.isEmpty() && !prior.isEmpty() && !stat.isEmpty())
    {

        Project proj;

        proj.name = name;
        proj.description = des;
        proj.priority = prior;
        proj.status = stat;

        projects.append(proj);

        int rowCount = ui -> tableWidget -> rowCount();

        ui -> tableWidget -> insertRow(rowCount);

        ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(rowCount, 1, new QTableWidgetItem(prior));
        ui->tableWidget->setItem(rowCount, 2, new QTableWidgetItem(stat));

        ui->proj_name->clear();

        ui->proj_description->clear();

    }
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    Q_UNUSED(column);

    currentProject = projects[row];

    ui->projectname->setText(currentProject.name);
    ui->project_description->setText(currentProject.description);
    ui->project_priority->setText(currentProject.priority);
    ui->project_status->setText(currentProject.status);

    ui->stackedWidget->setCurrentWidget(ui->Project_details);
}






