#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.set_image("start_screen");
    return a.exec();
}

