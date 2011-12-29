#include <QtGui/QApplication>
#include"mainwindow.h"
#include <iostream>
#include "class/library.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication library(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return library.exec();
}
