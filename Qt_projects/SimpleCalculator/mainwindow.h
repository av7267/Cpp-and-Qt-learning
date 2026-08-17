#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void digit_pressed();
    void Operators_pressed();

    void on_calculate_clicked();
    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    double firstNum = 0; //adding this as a member variable to store the first number entered by the user
    QString operation = "";//adding this as a member variable to store the operation entered by the user


};
#endif // MAINWINDOW_H
