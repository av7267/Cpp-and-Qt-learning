#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Dashboard.h"



void MainWindow::on_logoutbtn_clicked()
{
    ui -> stackedWidget -> setCurrentWidget(ui -> login);
}


void MainWindow::on_add_proj_2_clicked()
{
    ui -> stackedWidget -> setCurrentWidget(ui -> project_manager);
}
