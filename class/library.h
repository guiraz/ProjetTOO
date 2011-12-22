#ifndef LIBRARY_H
#define LIBRARY_H
#include<vector>
#include<iostream>
#include<fstream>
/*#include <QtSql>
#include <QFile>
#include<QString>*/
#include "docs.h"
#include "read.h"
#include "multimedia.h"
#include "film.h"
#include "music.h"
#include "videogame.h"
#include "ebook.h"
#include "book.h"
#include "comic.h"

class Library
{
private:
    std::vector<Docs *> _docsList;
public:
    //CONSTRUCT
    Library();
    ~Library();
    void erase();

    //ACCESS
    Docs* getElement(const int&);
    void pushElement(Docs*);
    void popElement(const int&);

    //DISPLAY
    void displayAll();
    void displayFilm(const int&);
    void displayMusic(const int&);
    void displayVideoGame(const int&);
    void displayEbook(const int&);
    void displayComic(const int&);
    void displayBook(const int&);

    //SORTING
    void invert(const int&, const int&);
    void sortByType();
    void sortByName();
    void sortByYear();

    //HTML EXPORT
    void exportLib2Html();

    //DATABASE
   /* bool connectDB();
    void importDB();
    void exportDB();
    void clearDB();*/

    //TOOLS
    unsigned int intTheType(const int&);
};

#endif // LIBRARY_H
