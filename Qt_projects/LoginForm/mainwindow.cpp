#include "mainwindow.h"
#include "welcomewindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) //Constructor
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Login_clicked()
{
    /*check for username and password being entered or not and if the login button is pressed it should
    redirect to the next page which has a welcome thats it*/

    QString user = ui ->username ->text();
    QString pass = ui ->password ->text();

    if (user.isEmpty() || pass.isEmpty())
    {
        QMessageBox::warning(this, "Login Failed", "Please enter both username and password.");
    }
    else
    {
        // Redirect to the next page which shows a welcome message

        QMessageBox::information(this, "Success", "Login successful");
        WelcomeWindow* welcome = new WelcomeWindow();  //we create a new object of another window
        welcome-> show(); //shows the next new window

        this -> hide();
    }


}

