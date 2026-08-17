#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui -> display->setText("0"); // this will make the label display 0 when the application is run for the first time

    connect(ui -> zero, &QPushButton::clicked, this, &MainWindow::digit_pressed);
    connect(ui -> one, &QPushButton::clicked, this, &MainWindow::digit_pressed);
    connect(ui -> two, &QPushButton::clicked, this, &MainWindow::digit_pressed);
    connect(ui->three, &QPushButton::clicked, this, &MainWindow::digit_pressed);
    connect(ui->four, &QPushButton::clicked, this, &MainWindow::digit_pressed);
    connect(ui->five, &QPushButton::clicked, this, &MainWindow::digit_pressed);
    connect(ui->six, &QPushButton::clicked, this, &MainWindow::digit_pressed);
    connect(ui->seven, &QPushButton::clicked, this, &MainWindow::digit_pressed);
    connect(ui->eight, &QPushButton::clicked, this, &MainWindow::digit_pressed);
    connect(ui->nine, &QPushButton::clicked, this, &MainWindow::digit_pressed);

    connect(ui->plus, &QPushButton::clicked,this, &MainWindow::Operators_pressed);

    connect(ui->minus, &QPushButton::clicked,this, &MainWindow::Operators_pressed);

    connect(ui->multiply, &QPushButton::clicked,this, &MainWindow::Operators_pressed);

    connect(ui->divide, &QPushButton::clicked,this, &MainWindow::Operators_pressed);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digit_pressed()
{
    QPushButton *button = (QPushButton *)sender(); // this will get the button that was pressed, sender() is a function that returns a pointer to the object that sent the signal, in this case the button that was pressed

    QString displayvalue = ui -> display -> text();

    if(displayvalue == "0") // this will check if the label is displaying 0, if it is then it will replace it with the button that was pressed
    {
        displayvalue ="";
    }
    displayvalue += button -> text(); // this will append the button that was pressed to the label
    ui -> display -> setText(displayvalue); //after appending the button that was pressed to the label, it will set the text of the label to the new string.

    //setText() is a function that sets the text of the label to the string that is passed to it,
    //text() is a function that returns the text of the label as a string.

}

void MainWindow :: Operators_pressed()
{
    QPushButton *button = (QPushButton *)sender(); // this will get the button that was pressed, sender() is a function that returns a pointer to the object that sent the signal, in this case the button that was pressed
    QString text = ui->display->text();
    firstNum = text.toDouble();
    operation = button->text();

    ui->display->setText("0");
}

void MainWindow::on_calculate_clicked()
{
    double secondNumber = ui->display->text().toDouble();

    double result = 0;

    if (operation == "+")
    {
        result = firstNum + secondNumber;
    }
    else if (operation == "-")
    {
        result = firstNum - secondNumber;
    }
    else if (operation == "*")
    {
        result = firstNum * secondNumber;
    }
    else if(operation == "/")
    {
        if(secondNumber != 0)
        {
            result = firstNum / secondNumber;
        }
        else
        {
            ui->display->setText("Error");
            return;
        }
    }

    ui->display->setText(QString::number(result));
}

void MainWindow::on_clear_clicked()
{
    ui->display->setText("0");

    firstNum = 0;
    operation.clear();
}
