#ifndef BOOK_H
#define BOOK_H
/*!
 * \file book.h
 * \brief This file contains a book's representation class
 * \author Loïc IRLES
 * \version 0.1
 */
#include<cstring>
#include"docs.h"
#include"read.h"
/*! \class Book
   * \brief Book's representation class
   *
   * This class represents a book wich inherit from \em Read and \em Docs
   */
class Book : public Read
{
protected:
    std::string _style;/*!< Book's style*/
public:
    /*!
     *  \brief Constructor
     *
     *  Book class's constructor
     */
    Book();
    /*!
     *  \brief Constructor
     *
     *  Book class's constructor with arguments
     *
     *  \param[in] style : book's style in a constant and referenced \em std::string
     *  \param[in] autor : book's autor in a constant and referenced \em std::string
     *  \param[in] name : book's name in a constant and referenced \em std::string
     *  \param[in] ref : book's reference in a constant and referenced \em std::string
     *  \param[in] year : book's year of edition in a constant and referenced \em int
     */
    Book(const std::string &style,const std::string &autor,const std::string &name,const std::string &ref,const int &year);
    /*!
     *  \brief Destructor
     *
     *  Book class's virtual destructor
     */
    virtual ~Book();

    /*!
     *  \brief Get the type
     *
     *  Access to the type of the document (here : book)<br />
     *  Virtual and constant
     *
     *  \return type of the document in std::string (here : "Livre")
     */
    virtual std::string getType() const;
    /*!
     *  \brief Set the style
     *
     *  Access to the style of the book (set)<br />
     *  Member : \a _style<br />
     *  Virtual
     *
     *  \param[in] style : style of the book constant and referenced \em std::string
     */
    virtual void setStyle(const std::string&);
    /*!
     *  \brief Get the style
     *
     *  Access to the style of the book (get)<br />
     *  Member : \a _style<br />
     *  Virtual and constant
     *
     *  \return style of the book in a \em std::string
     */
    virtual std::string getStyle() const;

    /*!
     *  \brief Affectations operator
     *
     *  Affects a \em Book to a \em Book<br />
     *  Virtual
     *
     *  \param[in] book : the other book in a constant and referenced \em Book
     *  \return a reference of this* book
     */
    virtual Book& operator=(const Book&);
    /*!
     *  \brief Comparisons operator
     *
     *  Compares two \em Book<br />
     *  Virtual and constant
     *
     *  \param[in] book : the other book in a constant and referenced \em Book
     *  \return true if the books are similar, false otherwise
     */
    virtual bool operator==(const Book&) const;
};

#endif // BOOK_H
