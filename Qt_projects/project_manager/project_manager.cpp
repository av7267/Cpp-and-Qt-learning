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

        updated_project_counts(); //this will make sure to count the rows properly which gives the number of projects to be displayed in the dashboard lcd.

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



void MainWindow::on_homebtn_clicked()
{
    ui -> stackedWidget -> setCurrentWidget(ui -> Dashboard);
}


void MainWindow::updated_project_counts()

{
    int activecount = 0;
    int completedcount = 0;


    for(int row = 0; row< ui->tableWidget->rowCount();row++)
    {
        QString status = ui -> tableWidget -> item(row,2) -> text(); //extract the text of the column 2 and store it in status and then loop over

        if(status == "Active")
        {
            activecount++;
        }
        else if(status == "Completed")
        {
            completedcount++;
        }

    }

    ui -> proj_count -> display(ui -> tableWidget -> rowCount());
    ui -> active_proj_count -> display(activecount);
    ui -> completed_proj_count -> display(completedcount);
}





