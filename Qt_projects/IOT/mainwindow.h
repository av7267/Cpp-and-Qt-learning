#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>

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

   void updateDayStatus(int temperature,double humidity,int pressure);
    void updateSensorData();
    void updatePressureDial(int value);
    void on_btnDashboard_clicked();
    void on_btnTemperature_clicked();
    void on_btnHumidity_clicked();
    void on_btnPressure_clicked();
    void on_btnPower_clicked();
    void on_btnSettings_clicked();

private:

    double calculateSaturationVapourPressure(double temperatureC);
    double calculateActualVapourPressure(double dewPointTemperature);
    double calculatePower(int load,double &voltage,double &current);

    Ui::MainWindow *ui;
    QTimer *timer;

    //For Graph in Temperature page
    QLineSeries *temperatureSeries;
    QChart *temperatureChart;
    QChartView *temperatureChartView;

    // X-axis counter for temperature graph
    int temperatureGraphTime = 0;
    
    //For Graph in Pressure page
    QLineSeries *pressureSeries;
    QChart *pressureChart;
    QChartView *pressureChartView;

    // X-axis counter for pressure graph
    int pressureGraphTime = 0;

    int pressureValue = 0;

    // for Graph in power page
    QLineSeries *powerSeries;
    QChart *PowerChart;
    QChartView *powerChartView;


    //X-axis counter for power graph

    double powerAt0 = 0;
    double powerAt25 = 0;
    double powerAt50 = 0;
    double powerAt75 = 0;
    double powerAt100 = 0;
};
#endif // MAINWINDOW_H
