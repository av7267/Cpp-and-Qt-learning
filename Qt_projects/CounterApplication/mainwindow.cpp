#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> lcdNumber -> setText("0"); // this will make the label display 0 when the application is run for the first time
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plus_clicked()
{
    count++;
    ui -> lcdNumber -> setText(QString::number(count)); // this will convert the integer value of count to a string and display it on the label
}


void MainWindow::on_minus_clicked()
{
    count--;
    ui -> lcdNumber -> setText(QString::number(count)); // this will convert the integer value of count to a string and display it on the label
}


void MainWindow::on_Reset_clicked()
{
    count = 0;
    ui -> lcdNumber -> setText(QString::number(count)); // this will convert the integer value of count to a string and display it on the label
}

