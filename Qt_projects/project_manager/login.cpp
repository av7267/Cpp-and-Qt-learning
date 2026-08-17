#include "login.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

void MainWindow::on_loginbutton_clicked()
{
    QString user = ui->username->text();
    QString pass = ui->password->text();

    if (user.isEmpty() || pass.isEmpty())
    {
        QMessageBox::warning(
            this,
            "Login Failed",
            "Please enter both username and password."
        );
    }
    else
    {
        ui->stackedWidget->setCurrentWidget(ui->home);
    }
}