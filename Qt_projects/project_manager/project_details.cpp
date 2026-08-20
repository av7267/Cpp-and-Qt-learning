#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_backbtn_clicked()
{
    ui -> stackedWidget -> setCurrentWidget(ui -> project_manager);
}


void MainWindow::on_Taskbtn_clicked()
{
    if (currentProjectIndex < 0 ||
        currentProjectIndex >= projects.size())
    {
        return;
    }

    ui->Task_table->setRowCount(0);

    const QList<Task>& projectTasks = projects[currentProjectIndex].tasks;

    for (const Task& task : projectTasks)
    {
        int row = ui->Task_table->rowCount();

        ui->Task_table->insertRow(row);

        ui->Task_table->setItem(row, 0, new QTableWidgetItem(task.TaskName));

        ui->Task_table->setItem(row, 1, new QTableWidgetItem(task.TaskPriority));

        ui->Task_table->setItem(row, 2, new QTableWidgetItem(task.TaskStatus));
    }

    updated_task_counts();

    ui->lbl_proj_name->setText(projects[currentProjectIndex].name);

    ui->stackedWidget->setCurrentWidget(ui->Task_manager);
}