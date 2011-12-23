#include <QtGui/QApplication>
#include <iostream>
#include "class/library.h"
using namespace std;

int main(/*int argc, char *argv[]*/)
{
    if (QFile::exists("../ProjetTOO/bd/bibli.bd"))
    {
        QSqlDatabase db(QSqlDatabase::addDatabase("QSQLITE"));
        db.setDatabaseName("../ProjetTOO/bd/bibli.bd");
        if(db.open())
        {
            //QCoreApplication a(argc, argv);

            Library lib;

            lib.importDB();

            lib.displayAll();
            cout<<endl;

            lib.sortByType();

            lib.displayAll();
            cout<<endl;

            lib.clearDB();

            lib.exportDB();

            Ebook eb("Delphine de Vigan", "ePub", "Rien ne s'oppose a la nuit", "ref004", 2011);
            lib.pushElement(&eb);

            lib.exportElementDB(lib.getSize()-1);

            lib.clearElementDB(lib.getSize()-1);
            lib.popElement(lib.getSize()-1);

            lib.exportLib2Html();

            //return a.exec();

            db.close();
        }
    }
}
