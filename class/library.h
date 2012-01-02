#ifndef LIBRARY_H
#define LIBRARY_H
/*!
 * \file library.h
 * \brief This file contains a library's representation class
 * \author Guillaume RAZIMBAUD
 * \version 0.1
 */
#include<vector>
#include<iostream>
#include<fstream>
#include <QtSql>
#include <QFile>
#include<QString>
#include "docs.h"
#include "read.h"
#include "multimedia.h"
#include "film.h"
#include "music.h"
#include "videogame.h"
#include "ebook.h"
#include "book.h"
#include "comic.h"
/*! \class Library
   * \brief Library's representation class
   *
   * This class represents a library
   */
class Library
{
private:
    std::vector<Docs *> _docsList;/*!< Library's document list*/
public:
    /*!
     *  \brief Constructor
     *
     *  Library class's constructor
     */
    Library();
    /*!
     *  \brief Destructor
     *
     *  Library class's destructor
     */
    ~Library();
    /*!
     *  \brief Erase library
     *
     *  Erase all document of the library by clearing \a _docsList
     */
    void erase();

    /*!
     *  \brief Get a document
     *
     *  Access to a document of the library with his position (get)<br />
     *  Member : \a _docsList
     *
     *  \param[in] position : the position of the document in the library in a constant and referenced int
     *  \return a document in a pointer of document -> \a Docs*
     */
    Docs* getElement(const int&);
    /*!
     *  \brief Push an document
     *
     *  Add a document in the library, it will be place at the end of the list<br />
     *  Member : \a _docsList
     *
     *  \param[in] element : a document in a pointer of document -> \a Docs*
     */
    void pushElement(Docs*);
    /*!
     *  \brief Pop a document
     *
     *  Remove a document of the library with his position<br />
     *  Member : \a _docsList
     *
     *  \param[in] position : the position of the document in the library in a constant and referenced int
     */
    void popElement(const int&);
    /*!
     *  \brief Get the size
     *
     *  Access to the size of the library (get)<br />
     *  Member : \a _docsList
     *
     *  \return size of the library in a \em unsigned int
     */
    unsigned int getSize();

    /*!
     *  \brief Display all documents
     *
     *  Display all the documents in a terminal<br />
     *  Use to debug..<br />
     *  Member : \a _docsList , intTheType(const int&), displayFilm(const int&), displayMusic(const int&), displayVideoGame(const int&), displayEbook(const int&), displayComic(const int&), displayComic(const int&)
     */
    void displayAll();
    /*!
     *  \brief Display a film
     *
     *  Display a film of the library with his position<br />
     *  Member : getElement(const int&)
     *
     *  \param[in] position : the position of the document in the library in a constant and referenced int
     */
    void displayFilm(const int&);
    /*!
     *  \brief Display a music
     *
     *  Display a music of the library with his position<br />
     *  Member : getElement(const int&)
     *
     *  \param[in] position : the position of the document in the library in a constant and referenced int
     */
    void displayMusic(const int&);
    /*!
     *  \brief Display a video game
     *
     *  Display a video game of the library with his position<br />
     *  Member : getElement(const int&)
     *
     *  \param[in] position : the position of the document in the library in a constant and referenced int
     */
    void displayVideoGame(const int&);
    /*!
     *  \brief Display a ebook
     *
     *  Display a ebook of the library with his position<br />
     *  Member : getElement(const int&)
     *
     *  \param[in] position : the position of the document in the library in a constant and referenced int
     */
    void displayEbook(const int&);
    /*!
     *  \brief Display a comic
     *
     *  Display a comic of the library with his position<br />
     *  Member : getElement(const int&)
     *
     *  \param[in] position : the position of the document in the library in a constant and referenced int
     */
    void displayComic(const int&);
    /*!
     *  \brief Display a Book
     *
     *  Display a book of the library with his position<br />
     *  Member : getElement(const int&)
     *
     *  \param[in] position : the position of the document in the library in a constant and referenced int
     */
    void displayBook(const int&);

    /*!
     *  \brief Invert two documents
     *
     *  Invert two documents in the library with theyre positions<br />
     *  Member : \a _docsList
     *
     *  \param[in] pos1 : the position of the first document in the library in a constant and referenced int
     *  \param[in] pos2 : the position of the second document in the library in a constant and referenced int
     */
    void invert(const int&, const int&);
    /*!
     *  \brief Sort by type
     *
     *  Sort all the documents of the library by type<br />
     *  Member : \a _docsList , intTheType(const int&), invert(const int&, const int&)
     */
    void sortByType();
    /*!
     *  \brief Sort by name
     *
     *  Sort all the documents of the library by name<br />
     *  Member : \a _docsList , invert(const int&, const int&)
     */
    void sortByName();
    /*!
     *  \brief Sort by year of release
     *
     *  Sort all the documents of the library by year of release<br />
     *  Member : \a _docsList , invert(const int&, const int&)
     */
    void sortByYear();

    /*!
     *  \brief Export the library
     *
     *  Export the library in an HTML page<br />
     *  Member : \a _docsList , intTheType(const int&)
     */
    void exportLib2Html();

    /*!
     *  \brief Import DataBase
     *
     *  Import the library from the database<br />
     *  Member : pushElement()
     */
    void importDB();
    /*!
     *  \brief Export DataBase
     *
     *  Export the library in the database<br />
     *  Member : \a _docsList , exportElementDB(const int&)
     */
    void exportDB();
    /*!
     *  \brief Clear DataBase
     *
     *  Remove all the documents from the database
     */
    void clearDB();
    /*!
     *  \brief Export a document to DataBase
     *
     *  Export one document in the database with his position<br />
     *  Member : intTheType(const int&) , getElement(const int&)
     *
     *  \param[in] position : the position of the document in the library in a constant and referenced int
     */
    void exportElementDB(const int&);
    /*!
     *  \brief Remove a document from DataBase
     *
     *  Remove one document from the database with his position<br />
     *  Member : intTheType(const int&) , getElement(const int&)
     *
     *  \param[in] position : the position of the document in the library in a constant and referenced int
     */
    void clearElementDB(const int&);

    /*!
     *  \brief Gives the number of the type
     *
     *  Gives a number to the types of the documents to make the switchs easier<br />
     *  Member : getElement(const int&)
     *
     *  \param[in] position : the position of the document in the library in a constant and referenced int
     */
    unsigned int intTheType(const int&);
};

#endif // LIBRARY_H
