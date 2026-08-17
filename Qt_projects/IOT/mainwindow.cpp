#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>
#include <QRandomGenerator>
#include <cmath>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QVBoxLayout>
#include <QValueAxis>

MainWindow::MainWindow(QWidget *parent) //Constructor
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMinimumSize(800,600);

    ui->stackedWidget->setCurrentIndex(5);     //This is the starting page which is blank that the ui shows upon execution.


    //Temperature Page

    connect(ui->btnTemperature, &QPushButton::clicked, this, &MainWindow::on_btnTemperature_clicked); //Temperature button

    //Temperature Graph implementation
    temperatureSeries = new QLineSeries();      // Create the line which stores temperature points in the graph

    //Creating the temperature Chart
    temperatureChart = new QChart(); //creating the Graph paper
    temperatureChart->setTitle("Temperature Trend");
    temperatureChart->addSeries(temperatureSeries); //we are puttin the dara on the chart.

    //Create X and Y axis for the graph
    QValueAxis *temperatureAxisX = new QValueAxis();
    temperatureAxisX->setRange(0,50);
    temperatureAxisX->setTickCount(6);

    temperatureAxisX->setTitleText("Time");
    temperatureAxisX->setLabelFormat("%d");

    QValueAxis *temperatureAxisY = new QValueAxis();
    temperatureAxisY->setRange(20,40);
    temperatureAxisY->setTickCount(6);
    temperatureAxisY->setTitleText("Temperature °C");


    temperatureChart->addAxis(temperatureAxisX, Qt::AlignBottom);
    temperatureChart->addAxis(temperatureAxisY, Qt::AlignLeft);

    temperatureSeries->attachAxis(temperatureAxisX);
    temperatureSeries->attachAxis(temperatureAxisY);

    temperatureChartView = new QChartView(temperatureChart);   //now after creating the points and the graph paper and a layout with X and Y axis we print here.
    temperatureChartView->setMinimumHeight(250);

    //Creating the container to put the graph
    QVBoxLayout *layout = new QVBoxLayout(ui->temperatureGraphContainer); //we are adding the graph to the UI by putting it in the temperaturecontainer
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(temperatureChartView);

    //Dashboard page
    connect(ui->btnDashboard, &QPushButton::clicked,this, &MainWindow::on_btnDashboard_clicked); //Dashboard button

    //Humidity Page
    connect(ui -> btnHumidity, &QPushButton :: clicked, this,&MainWindow :: on_btnHumidity_clicked); //Humidity Button


    //Pressure Graph implementation
    pressureSeries = new QLineSeries();
    pressureChart = new QChart();
    pressureChart->setTitle("Pressure Trend");
    pressureChart->addSeries(pressureSeries);

    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(0, 50);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(950, 1050);
    axisY->setTitleText("Pressure (hPa)");

    pressureChart->addAxis(axisX, Qt::AlignBottom);
    pressureChart->addAxis(axisY, Qt::AlignLeft);

    pressureSeries->attachAxis(axisX);
    pressureSeries->attachAxis(axisY);


    pressureChartView = new QChartView(pressureChart);

    QVBoxLayout *pressureLayout = new QVBoxLayout(ui->pressureGraphContainer);

    pressureLayout->setContentsMargins(0, 0, 0, 0);
    pressureLayout->addWidget(pressureChartView);

    //Pressure page
    connect(ui -> btnPressure, &QPushButton :: clicked, this, &MainWindow :: on_btnPressure_clicked); //Pressure Button
    connect(ui -> pressureDial, &QDial :: valueChanged, this, &MainWindow :: updatePressureDial); //pressure page dial
    ui->pressureDial->setMinimum(950);
    ui->pressureDial->setMaximum(1050);


    //Power Page
    connect(ui -> btnPower, &QPushButton::clicked,this, &MainWindow :: on_btnPower_clicked);

    powerSeries = new QLineSeries();
    PowerChart = new QChart();
    PowerChart -> setTitle("Power Trend");
    PowerChart -> addSeries(powerSeries);



    QCategoryAxis *powerAxisX = new QCategoryAxis();

    powerAxisX->append("0%",0);
    powerAxisX->append("25%",25);
    powerAxisX->append("50%",50);
    powerAxisX->append("75%",75);
    powerAxisX->append("100%",100);

    powerAxisX->setRange(0,100);


    QValueAxis *powerAxisY = new QValueAxis();

    powerAxisY->setTitleText("Power (W)");
    powerAxisY->setRange(0,150);
    powerAxisY->setTickCount(7);

    PowerChart->addAxis(powerAxisX, Qt::AlignBottom);
    PowerChart->addAxis(powerAxisY, Qt::AlignLeft);

    powerSeries->attachAxis(powerAxisX);
    powerSeries->attachAxis(powerAxisY);


    powerChartView = new QChartView(PowerChart);
    powerChartView->setMinimumHeight(250);
    powerChartView->setSizePolicy(

        QSizePolicy::Expanding,

        QSizePolicy::Expanding);

    QVBoxLayout *powerLayout = new QVBoxLayout(ui->powerGraphContainer);

    powerLayout->setContentsMargins(0, 0, 0, 0);
    powerLayout->addWidget(powerChartView);




    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this, &MainWindow::updateSensorData);

}

MainWindow::~MainWindow()  //Destructor
{
    delete ui;
}


void MainWindow:: updateDayStatus(int temperature,double humidity,int pressure)
{

    if (temperature > 30 && humidity > 70 && pressure < 1000)
    {
        ui->lblStatusValue->setText("🌧 Rainy Day");
    }

    else if (temperature >= 20 && temperature <= 30 && humidity >= 40 && humidity <= 70 && pressure >= 1000 && pressure <= 1020)
    {
        ui->lblStatusValue->setText("☁ Normal Day");
    }
    else
    {
        ui->lblStatusValue->setText("☀ Sunny Day");
    }

}

void MainWindow::updatePressureDial(int value)
{
    pressureValue = value;


    ui -> lcdPressureControl -> display(value); //pressure lcd in the pressure page
    ui->lcdPressure->display(value);   // Keep dashboard pressure in sync

    pressureSeries->append(pressureGraphTime, value);
    pressureGraphTime++;

    pressureChart->axes(Qt::Horizontal).first()->setRange(qMax(0, pressureGraphTime - 50),pressureGraphTime);

}

void MainWindow::updateSensorData() //the updation of the data is being done here in the Qlcd's
{
    //Temperature
    int temperature = QRandomGenerator :: global() -> bounded(20,36); //Generating random temperature values in the range of 20-36.

    ui -> lcdTemperature ->display(temperature);  //the lcd in dashboard.

    ui->lcdTemperatureDetail->display(temperature); //the lcd in temparature page.

    // Temperature Graph
    temperatureSeries->append(temperatureGraphTime, temperature); //Add a new point to the temperature graph where the X-axis represents the current time and the Y-axis represents the current temperature.

    temperatureGraphTime++;

    if(temperatureSeries->count() > 50)
    {
        temperatureSeries->remove(0);
    }

    if(temperatureGraphTime > 50)
    {
        temperatureChart->axes(Qt::Horizontal).first()->setRange(temperatureGraphTime - 50,temperatureGraphTime); //Get the first horizontal (X) axis of the chart and change its visible range so that it shows only the last 50 time units, ending at the current time.
    }
    else
    {
        temperatureChart->axes(Qt::Horizontal).first()->setRange(0,50); //
    }


    //Pressure and humidity
    int minDewPoint = temperature - 10; //taking the temperature and calculating the dew temp.

    if(minDewPoint < 0)
    {
        minDewPoint = 0;
    }

    int dewPoint = QRandomGenerator::global()->bounded(minDewPoint, temperature);

    ui -> lcddew -> display(dewPoint);

    double svp = calculateSaturationVapourPressure(temperature);  //passing the generated temperature into this function

    ui -> lcdSVP -> display(svp);   //we get the svp value after being calculated

    double avp = calculateActualVapourPressure(dewPoint); //passing the dewpoint which is calculated from temperature gives out avp upon calculation.

    ui -> lcdAVP -> display(avp);   //we get the avp value after being calculated through the function


    double humidity = (avp / svp) * 100.0;          //Relative humidity being calculated from the svp and avp

    ui ->lcdHumidity ->display(humidity);     //the humidity lcd in dashboard page.

    ui->humidityDial->setValue(static_cast<int>(humidity));

    ui ->lcdtemp -> display(temperature); //the lcd in humidity page.

    ui->lblHumidityValue->setText(

            QString::number((int)humidity) + "%"
        );


    ui -> lcdPressure -> display(pressureValue);    //the pressure lcd in dashboard page.


    //Power

    int load = ui -> loadSlider -> value();

    double voltage;
    double current;

    double power = calculatePower(load, voltage,current);

    ui -> voltageBar -> setValue(static_cast<int>(voltage));

    ui -> currentBar -> setValue(static_cast<int>(current));

    ui->lbl_Load->setText(QString::number(load) + "%");



    if(load == 0)
    {
        powerAt0 = power;
    }
    else if(load <= 25)
    {
        powerAt25 = power;
    }
    else if(load <= 50)
    {
        powerAt50 = power;
    }
    else if(load <= 75)
    {
        powerAt75 = power;
    }
    else
    {
        powerAt100 = power;
    }

    powerSeries->clear();

    powerSeries->append(0,   powerAt0);
    powerSeries->append(25,  powerAt25);
    powerSeries->append(50,  powerAt50);
    powerSeries->append(75,  powerAt75);
    powerSeries->append(100, powerAt100);

    if(power > 80)
    {
        ui -> lbl_Power_Status -> setText("High");
    }
    else if(power > 40)
    {
        ui -> lbl_Power_Status -> setText("Medium");
    }
    else
    {
        ui -> lbl_Power_Status -> setText("Low");
    }

    ui->lcdPower_2->display(power);
    ui -> lcdPower -> display(power); //the lcd in dashboard page.



    //Dashboard label update of the day status passing the values of temperature,humidity and pressure(from the pressure dial).
    updateDayStatus(temperature,humidity,pressureValue);

}



void MainWindow::on_btnDashboard_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    if(!timer->isActive())
    {
        timer->start(1000);
    }
}

void MainWindow::on_btnTemperature_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    if(!timer->isActive())
    {
        timer->start(1000);
    }
}


void MainWindow::on_btnHumidity_clicked()
{
    ui ->stackedWidget -> setCurrentIndex(2);

    if(!timer->isActive())
    {
        timer->start(1000);
    }
}


void MainWindow::on_btnPressure_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(3);

    if(!timer->isActive())
    {
        timer->start(1000);
    }
}

double MainWindow::calculateSaturationVapourPressure(double temperatureC)
{
    double a = 17.625;
    double b = 243.04;

    return 6.1094 * std::exp((a * temperatureC) / (temperatureC + b));
}


double MainWindow::calculateActualVapourPressure(double dewPointTemperature)
{
    return 6.11 * std::pow(10.0,(7.5 * dewPointTemperature) / (237.3 + dewPointTemperature));
}


double MainWindow::calculatePower(int load, double &voltage, double &current)
{
    voltage = 12.0 + (load * 0.08);

    current = 0.5 + (load * 0.05);

    double power = voltage * current;

    return power;
}

void MainWindow::on_btnPower_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(4);

    if (!timer->isActive())
    {
        timer->start(1000);
    }
}

void MainWindow::on_btnSettings_clicked()
{
    ui -> stackedWidget ->setCurrentIndex(5);
}
