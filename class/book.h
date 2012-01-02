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
#include"read.h
/*! \class Book
   * \brief Book's representation class
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
     *
     */
    Book();
    /*!
     *  \brief Constructor
     *
     *  Book class's constructor
     *
     *  \param[in] style : book's style
     *  \param[in] autor : book's autor
     *  \param[in] name : book's name
     *  \param[in] ref : book's reference
     *  \param[in] year : book's year of edition
     */
    Book(const std::string &style,const std::string &autor,const std::string &name,const std::string &ref,const int &year);
    /*!
     *  \brief Destructor
     *
     *  Book class's virtual destructor
     *
     */
    virtual ~Book();

    /*!
     *  \brief Get the type
     *
     *  Access to the type of the document (here : book)
     *  Virtual and constant
     *
     *  \return type of the document in std::string (here : book)
     */
    virtual std::string getType() const;
    /*!
     *  \brief Set the style
     *
     *  Access to the style of the book (set)
     *  Virtual
     *
     *  \param[in] style : style of the book constant and referenced std::string
     */
    virtual void setStyle(const std::string&);
    /*!
     *  \brief Get the style
     *
     *  Access to the style of the book (get)
     *  Virtual and constant
     *
     *  \return style of the book std::string
     */
    virtual std::string getStyle() const;

    /*!
     *  \brief Affectations operator
     *
     *  Affects a book to a book
     *  Virtual
     *
     *  \param[in] book : the other book in a constant and referneced Book
     *  \return a reference of this* book
     */
    virtual Book& operator=(const Book&);
    /*!
     *  \brief Comparisons operator
     *
     *  Compares two books
     *  Virtual and constant
     *
     *  \param[in] book : the other book in a constant and referneced Book
     *  \return true if the books are similar, false otherwise
     */
    virtual bool operator==(const Book&) const;
};

#endif // BOOK_H
