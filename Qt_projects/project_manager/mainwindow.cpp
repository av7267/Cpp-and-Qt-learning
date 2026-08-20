#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->login);  //starting page
    
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        ui->Task_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //login button
    connect(ui -> loginbutton, &QPushButton :: clicked,this, &MainWindow :: on_loginbutton_clicked);
    connect(ui -> add_proj, &QPushButton :: clicked,this, &MainWindow :: on_add_proj_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}



















