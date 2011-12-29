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
    QTableWidget* tableWidgetLivrary = new QTableWidget(this);
    setTableWidgetLibrary(tableWidgetLivrary);
    tableWidgetLivrary->show();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    closeDatabase();
    delete ui;
}

void MainWindow::setMainWindow()
{
    setFixedSize(800, 600);
}

void MainWindow::setTableWidgetLibrary(QTableWidget* tableWidgetLibrary)
{
    tableWidgetLibrary->setFixedSize(582, 460);
    tableWidgetLibrary->move(mapToGlobal(QPoint(50, 50)));
    tableWidgetLibrary->setColumnCount(3);
    QStringList columnNames;
    columnNames << "Nom" << "Annee" << "Reference";
    tableWidgetLibrary->setHorizontalHeaderLabels(columnNames);
    tableWidgetLibrary->setColumnWidth(0, 300);
    tableWidgetLibrary->setColumnWidth(1, 100);
    tableWidgetLibrary->setColumnWidth(2, 180);
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
