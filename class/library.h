#ifndef LIBRARY_H
#define LIBRARY_H
#include<vector>
#include<iostream>
#include "docs.h"

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

    //TOOLS
    unsigned int intTheType(const int&);
};

#endif // LIBRARY_H
