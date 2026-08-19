#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


struct Project
{
    QString name;
    QString description;
    QString priority;
    QString status;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_loginbutton_clicked();

    void on_add_proj_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_backbtn_clicked();

    void on_logoutbtn_clicked();

private:
    QVector<Project> projects;

    Project currentProject;

    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
