#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::on_Task_addbtn_clicked()
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

    }
 
}


void MainWindow::on_projectsbtn_clicked()
{
    ui -> stackedWidget -> setCurrentWidget(ui -> Project_details);
}
