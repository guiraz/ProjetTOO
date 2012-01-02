#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setMainWindow();

    if(openDatabase()==false)
    {
        std::cout<<"Could not open database!"<<std::endl;
        close();
    }

    lib = new Library;
    lib->importDB();

    setTableWidgetLibrary();
    tableWidgetLibrary->show();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    lib->clearDB();
    lib->exportDB();
    closeDatabase();
    lib->erase();
    delete lib;
    delete tableWidgetLibrary;
    delete ui;
}

void MainWindow::setMainWindow()
{
    setFixedSize(800, 600);
}

void MainWindow::setTableWidgetLibrary()
{
    tableWidgetLibrary= new QTableWidget(this);

    tableWidgetLibrary->setFixedSize(582, 460);
    tableWidgetLibrary->move(mapToGlobal(QPoint(50, 50)));
    tableWidgetLibrary->setColumnCount(3);
    QStringList columnNames;
    columnNames << "Nom" << "Annee" << "Type";
    tableWidgetLibrary->setHorizontalHeaderLabels(columnNames);
    tableWidgetLibrary->setColumnWidth(0, 375);
    tableWidgetLibrary->setColumnWidth(1, 50);
    tableWidgetLibrary->setColumnWidth(2, 130);

    updateTableWidgetLibrary();
}

void MainWindow::addRow(const int& position)
{
    tableWidgetLibrary->setRowCount(tableWidgetLibrary->rowCount()+1);

    QTableWidgetItem* name;
    QTableWidgetItem* year;
    QTableWidgetItem* type;
    name= new QTableWidgetItem(QString::fromStdString(lib->getElement(position)->getName()));
    year=new QTableWidgetItem(QString::number(lib->getElement(position)->getYear()));
    type=new QTableWidgetItem(QString::fromStdString(lib->getElement(position)->getType()));

    tableWidgetLibrary->setItem(tableWidgetLibrary->rowCount()-1, 0, name);
    tableWidgetLibrary->setItem(tableWidgetLibrary->rowCount()-1, 1, year);
    tableWidgetLibrary->setItem(tableWidgetLibrary->rowCount()-1, 2, type);
}

void MainWindow::updateTableWidgetLibrary()
{
    while(0<tableWidgetLibrary->rowCount())
    {
        tableWidgetLibrary->removeRow(0);
    }

    for(unsigned int j=0; j<lib->getSize(); j++)
    {
        addRow(j);
    }
}

void MainWindow::removeSelection()
{
    while(tableWidgetLibrary->selectedItems().count() > 0)
    {
        lib->popElement(tableWidgetLibrary->selectedItems().at(0)->row());
        tableWidgetLibrary->removeRow(tableWidgetLibrary->selectedItems().at(0)->row());
    }
}

bool MainWindow::openDatabase()
{
    if (QFile::exists("../ProjetTOO/bd/bibli.bd"))
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("../ProjetTOO/bd/bibli.bd");
        return(db.open());
    }
    else
    {
        return false;
    }
}

void MainWindow::closeDatabase()
{
    db.close();
}

void MainWindow::on_pushButtonExit_clicked()
{
    int quit = QMessageBox::warning(this, "Requete de fermeture", "Vous etes sur le point de fermer l'application! Etes vous sur?", QMessageBox::Yes | QMessageBox::No);
    if (quit==QMessageBox::Yes)
    {
        close();
    }
}

void MainWindow::on_pushButtonSortName_clicked()
{
    ui->pushButtonSortName->setEnabled(false);
    ui->pushButtonSortType->setEnabled(true);
    ui->pushButtonSortYear->setEnabled(true);

    lib->sortByName();

    updateTableWidgetLibrary();
}

void MainWindow::on_pushButtonSortYear_clicked()
{
    ui->pushButtonSortName->setEnabled(true);
    ui->pushButtonSortType->setEnabled(true);
    ui->pushButtonSortYear->setEnabled(false);

    lib->sortByYear();

    updateTableWidgetLibrary();
}

void MainWindow::on_pushButtonSortType_clicked()
{
    ui->pushButtonSortName->setEnabled(true);
    ui->pushButtonSortType->setEnabled(false);
    ui->pushButtonSortYear->setEnabled(true);

    lib->sortByType();

    updateTableWidgetLibrary();
}

void MainWindow::on_pushButtonRemove_clicked()
{
    removeSelection();
}

void MainWindow::on_pushButtonHTML_clicked()
{
    lib->exportLib2Html();
}

void MainWindow::on_pushButtonAdd_clicked()
{
   AddDoc* adddoc=new AddDoc(lib, this);
   adddoc->show();
   updateTableWidgetLibrary();
   ui->pushButtonSortName->setEnabled(true);
   ui->pushButtonSortType->setEnabled(true);
   ui->pushButtonSortYear->setEnabled(true);
}
