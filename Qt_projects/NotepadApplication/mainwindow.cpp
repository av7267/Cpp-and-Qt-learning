#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->menuFile->addAction(ui->actionNew);
    ui->menuFile->addAction(ui->actionOpen);
    ui->menuFile->addAction(ui->actionSave);
    ui->menuFile->addAction(ui->actionExit);

    connect(ui->actionNew,&QAction::triggered,this,&MainWindow::NewFile);
    connect(ui->actionOpen,&QAction::triggered,this,&MainWindow::openFile);
    connect(ui->actionSave,&QAction::triggered,this,&MainWindow::saveFile);
    connect(ui->actionExit,&QAction::triggered,this,&MainWindow::closeFile);
}


void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Open File"
    );

    if(fileName.isEmpty())
    {
        return;
    }


    QFile file(fileName);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);

        ui->textEdit->setText(in.readAll());

        file.close();

        currentFile = fileName;
    }
}

void MainWindow::saveFile()
{

}

void MainWindow::closeFile()
{
    ui -> textEdit -> clear();
    currentFile.clear();
}

void MainWindow::NewFile()
{
    
}


MainWindow::~MainWindow()
{
    delete ui;
}
