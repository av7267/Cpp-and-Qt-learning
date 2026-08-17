#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui -> Add, &QPushButton::clicked, this, &MainWindow::on_Add_clicked); //tells the compiler to connect the Add button to the on_Add_clicked function
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::on_Add_clicked()
{
    //upon adding, move the typed task into the list of tasks

    QString New_Tasks = ui->Tasks->text(); //this will get the text from the line edit and store it in a QString variable called Tasks
    ui->todo_list->addItem(New_Tasks); //this will add the task to the list of tasks
    ui->Tasks->clear(); //this will clear the text from the line edit

}

