#include <QtGui/QApplication>
#include <iostream>
#include "class/library.h"
using namespace std;

int main(/*int argc, char *argv[]*/)
{
    /*if (QFile::exists("../ProjetTOO/bd/bibli.bd"))
    {
        QSqlDatabase db(QSqlDatabase::addDatabase("QSQLITE"));
        db.setDatabaseName("../ProjetTOO/bd/bibli.bd");
        if(db.open())
        {*/
            //QCoreApplication a(argc, argv);
            Library lib;
            //lib.importDB();

            lib.displayAll();
            cout<<endl;
            lib.sortByType();
            lib.displayAll();

            //lib.clearDB();

            //lib.exportDB();
            //return a.exec();
            //db.close();
       /* }
    }*/
}
