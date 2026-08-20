#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::on_Task_addbtn_clicked()    //this button adds the data in the line edit and combo box to the task table
{

    QString task_name = ui -> Task_nameedit -> text();
    QString Task_status = ui -> Task_statusbox -> currentText();
    QString Task_priority = ui -> Task_prioritybox -> currentText();


    if(!task_name.isEmpty() && !Task_status.isEmpty() && !Task_priority.isEmpty())
    {
        Task tsk;

        tsk.TaskName = task_name;
        tsk.TaskStatus = Task_status;
        tsk.TaskPriority = Task_priority;

        projects[currentProjectIndex].tasks.append(tsk);

        int taskrows = ui -> Task_table -> rowCount();

        ui -> Task_table -> insertRow(taskrows);

        ui->Task_table->setItem(taskrows, 0, new QTableWidgetItem(task_name));
        ui->Task_table->setItem(taskrows, 2, new QTableWidgetItem(Task_status));
        ui->Task_table->setItem(taskrows, 1, new QTableWidgetItem(Task_priority));

        ui -> Task_nameedit -> clear();

        updated_task_counts();

    }
 
}


void MainWindow::on_projectsbtn_clicked()   //this button goes back to the project details page
{
    ui -> stackedWidget -> setCurrentWidget(ui -> Project_details);
}


void MainWindow :: updated_task_counts()
{
    //tasks 
    int tasks_active = 0;
    int tasks_completed = 0;

    for(int row =0; row < ui->Task_table ->rowCount();row++)
    {
        QString st = ui-> Task_table -> item(row,2) -> text();  //checking in the status row in task table

        if(st == "Active")
        {
            tasks_active++;
        }
        else if(st == "Completed")
        {
            tasks_completed++;
        }
    }

    //project details page lcd displays of tasks active and tasks completed
    ui -> Active_number -> display(tasks_active);
    ui -> completed_number -> display(tasks_completed);
}