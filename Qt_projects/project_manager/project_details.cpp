#include "project_details.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_backbtn_clicked()
{
    ui -> stackedWidget -> setCurrentWidget(ui -> project_manager);
}
