#include "mainwindow.h"

#include <QApplication>    //this is where the project is being handled and controls the event loop.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);     //this is where we send two arguements which are arguement count(Integer representing the total number of command-line arguments passed to the program when launched from a terminal)
                                        //and arguement vector(An array of strings containing those actual command-line arguments.)
    MainWindow w;                   //this is the primary application window
    w.show();                       //Calling .show() tells Qt to flag the window as ready to be drawn and displayed on the screen.
    return QApplication::exec();    // exec() starts the application's main event loop.
}
