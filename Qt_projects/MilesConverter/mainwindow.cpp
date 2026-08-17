#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double miles = ui -> txtMiles -> text().toDouble();

    double kilometers = miles*1.609;

    ui -> txtKilometers -> setText(QString::number(kilometers));
}

