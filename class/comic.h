#ifndef COMIC_H
#define COMIC_H
/*!
 * \file comic.h
 * \brief This file contains a book's representation class
 * \author Loïc IRLES
 * \version 0.1
 */
#include<cstring>
#include"docs.h"
#include"read.h"
/*! \class Comic
  * \brief Comic's representation class
  *
  *  This class represents a comic wich inherit from \em Read and \em Docs
  */
class Comic : public Read
{
public:
    /*!
     *  \brief Constructor
     *
     *  Book class's constructor
     */
    Comic();
    /*!
     *  \brief Constructor
     *
     *  Comic class's constructor with arguments
     *
     *  \param[in] autor : Comic's autor in a constant and referenced \em std::string
     *  \param[in] name : Comic's name in a constant and referenced \em std::string
     *  \param[in] ref : Comic's reference in a constant and referenced \em std::string
     *  \param[in] year : Comic's year of edition in a constant and referenced \em int
     */
    Comic(const std::string& autor, const std::string& name, const std::string& ref, const int& year);
    /*!
     *  \brief Destructor
     *
     *  Comic class's virtual destructor
     */
    virtual ~Comic();

    /*!
     *  \brief Get the type
     *
     *  Access to the type of the document (here : comic)<br />
     *  Virtual and constant
     *
     *  \return type of the document in \em std::string (here : "Bande dessinee")
     */
    virtual std::string getType() const;

    /*!
     *  \brief Affectations operator
     *
     *  Affects a \em Comic to a \em Comic<br />
     *  Virtual
     *
     *  \param[in] bd : the other comic in a constant and referenced \em Comic
     *  \return a reference of this* comic
     */
    virtual Comic& operator=(const Comic&);
    /*!
     *  \brief Comparisons operator
     *
     *  Compares two \em Comic<br />
     *  Virtual and constant
     *
     *  \param[in] bd : the other comic in a constant and referenced \em Comic
     *  \return true if the comics are similar, false otherwise
     */
    virtual bool operator==(const Comic&) const;
};

#endif // COMIC_H
