#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


struct Task
{
    QString TaskName;
    QString TaskStatus;
    QString TaskPriority;
};

struct Project
{
    QString name;
    QString description;
    QString priority;
    QString status;

    QList<Task> tasks;

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

    void on_add_proj_2_clicked();

    void on_homebtn_clicked();

    void updated_project_counts();

    void on_Taskbtn_clicked();

    void on_Task_addbtn_clicked();

    void on_projectsbtn_clicked();

    void updated_task_counts();

private:
    QVector<Project> projects;

    int currentProjectIndex = -1;

    Project currentProject;

    

    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
