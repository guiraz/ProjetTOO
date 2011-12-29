#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmainwindow.h"
#include<iostream>
#include<QFile>
#include<QMessageBox>
#include<QTableWidget>
#include<QStringList>
#include<QSqlDatabase>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setMainWindow();
    void setTableWidgetLibrary(QTableWidget*);

    bool openDatabase();
    void closeDatabase();

private slots:
    void on_pushButtonExit_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
