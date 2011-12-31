#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmainwindow.h"
#include "class/library.h"
#include<iostream>
#include<QFile>
#include<QMessageBox>
#include<QTableWidget>
#include<QTableWidgetItem>
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

    void setTableWidgetLibrary();
    void addRow(const int&);
    void updateTableWidgetLibrary();

    void removeSelection();

    bool openDatabase();
    void closeDatabase();

private slots:
    void on_pushButtonExit_clicked();
    void on_pushButtonSortName_clicked();
    void on_pushButtonSortYear_clicked();
    void on_pushButtonSortType_clicked();

    void on_pushButtonRemove_clicked();

    void on_pushButtonHTML_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    Library* lib;
    QTableWidget* tableWidgetLibrary;
};

#endif // MAINWINDOW_H
