#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Dashboard.h"






void MainWindow::on_logoutbtn_clicked()
{
    ui -> stackedWidget -> setCurrentWidget(ui -> login);
}

