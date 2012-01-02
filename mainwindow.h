#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*!
 * \file mainwindow.h
 * \brief This file contains the GUI's main window
 * \author GUILLAUME RAZIMBAUD
 * \version 0.1
 */
#include "qmainwindow.h"
#include "adddoc.h"
#include "class/library.h"
#include<iostream>
#include<QFile>
#include<QMessageBox>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QStringList>
#include<QSqlDatabase>
/*! \namespace Ui
 *
 * namespace who regroups all the function and the class
 * for the GUI's main window
 */
namespace Ui {
    class MainWindow;
}
/*! \class MainWindow
   * \brief MainWindow's representation class
   *
   * This class represents a main window wich inherit from \em QMainWindow
   */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     *  \brief Constructor
     *
     *  MainWindow class's constructor
     *  \param[in] parent : the parent widget of the \em MainWindow
     */
    explicit MainWindow(QWidget *parent = 0);
    /*!
     *  \brief Destructor
     *
     *  MainWindow class's destructor
     */
    ~MainWindow();

    /*!
     *  \brief Set up main window
     *
     *  Set up the main window. Here only the size.
     */
    void setMainWindow();

    /*!
     *  \brief Set up the \a tableWidgetLibrary
     *
     *  Set up the table widget, size, numbers of cells, columnsand rows, contents...
     */
    void setTableWidgetLibrary();
    /*!
     *  \brief Add a row
     *
     *  Add a row to the \a tableWidgetLibrary and fill it with a document thanks to his position
     *
     *  \param[in] position : position of the document in the library in a constant and referenced \em int
     */
    void addRow(const int&);
    /*!
     *  \brief Update \a tableWidgetLibrary
     *
     *  Remove all the rows from \a tableWidgetLibrary, and refill it with the library
     */
    void updateTableWidgetLibrary();
    /*!
     *  \brief Remove all the selection from \a tableWidgetLibrary
     *
     *  Remove all the selected documents from the library and update \a tableWidgetLibrary
     */
    void removeSelection();

    /*!
     *  \brief Open database
     *
     *  Open database...
     */
    bool openDatabase();
    /*!
     *  \brief Close database
     *
     *  Close database...
     */
    void closeDatabase();

private slots:
    /*!
     *  \brief \a pushButtonExit clicked()
     *
     *  When \a pushButtonExit is clicked a message appears and ask for comfirmation to close the app
     */
    void on_pushButtonExit_clicked();
    /*!
     *  \brief \a pushButtonSortName clicked()
     *
     *  When \a pushButtonSortName is clicked, the library is sort by name and \a tableWidgetLibrary is update
     */
    void on_pushButtonSortName_clicked();
    /*!
     *  \brief \a pushButtonSortYear clicked()
     *
     *  When \a pushButtonSortYear is clicked, the library is sort by year of release and \a tableWidgetLibrary is update
     */
    void on_pushButtonSortYear_clicked();
    /*!
     *  \brief \a pushButtonSortType clicked()
     *
     *  When \a pushButtonSortType is clicked, the library is sort by type and \a tableWidgetLibrary is update
     */
    void on_pushButtonSortType_clicked();
    /*!
     *  \brief \a pushButtonRemove clicked()
     *
     *  When \a pushButtonRemove is clicked, the method removeSelection() is execute
     */
    void on_pushButtonRemove_clicked();
    /*!
     *  \brief \a pushButtonHTML clicked()
     *
     *  When \a pushButtonHTML is clicked, the method lib->exportLib2Html(); is execute
     */
    void on_pushButtonHTML_clicked();
    /*!
     *  \brief \a pushButtonAdd clicked()
     *
     *  When \a pushButtonAdd is clicked, the AddDoc window is execute
     */
    void on_pushButtonAdd_clicked();

private:
    Ui::MainWindow *ui;/*!< MainWindow's user interface*/
    QSqlDatabase db;/*!< MainWindow's database*/
    Library* lib;/*!< MainWindow's library*/
    QTableWidget* tableWidgetLibrary;/*!< MainWindow's QTableWidget*/
};

#endif // MAINWINDOW_H
