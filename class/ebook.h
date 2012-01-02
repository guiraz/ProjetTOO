#ifndef EBOOK_H
#define EBOOK_H
/*!
 * \file ebook.h
 * \brief This file contains a ebook's representation class
 * \author Loïc IRLES
 * \version 0.1
 */
#include<cstring>
#include"docs.h"
#include"multimedia.h"
#include"read.h"
/*! \class Ebook
   * \brief eBook's representation class
   *
   * This class represents a ebook wich inherit from \em Read, \em Multimedia and \em Docs
   */
class Ebook : virtual public Docs, public Read, public Multimedia
{
public:
    /*!
     *  \brief Constructor
     *
     *  eBook class's constructor
     */
    Ebook();
    /*!
     *  \brief Constructor
     *
     *  eBook class's constructor with arguments
     *
     *  \param[in] autor : ebook's autor in a constant and referenced \em std::string
     *  \param[in] name : ebook's name in a constant and referenced \em std::string
     *  \param[in] ref : ebook's reference in a constant and referenced \em std::string
     *  \param[in] year : ebook's year of edition in a constant and referenced \em int
     */
    Ebook(const std::string& autor, const std::string& mount, const std::string& name, const std::string& ref, const int& year);
    /*!
     *  \brief Destructor
     *
     *  eBook class's virtual destructor
     */
    virtual ~Ebook();
    /*!
     *  \brief Get the type
     *
     *  Access to the type of the document (here : ebook)<br />
     *  Virtual and constant
     *
     *  \return type of the document in std::string (here : "Livre Numerique")
     */
    virtual std::string getType() const;

    /*!
     *  \brief Affectations operator
     *
     *  Affects a \em Ebook to a \em Ebook<br />
     *  Virtual
     *
     *  \param[in] ebook : the other ebook in a constant and referenced \em Ebook
     *  \return a reference of this* ebook
     */
    virtual Ebook& operator=(const Ebook&);
    /*!
     *  \brief Comparisons operator
     *
     *  Compares two \em Ebook<br />
     *  Virtual and constant
     *
     *  \param[in] ebook : the other ebook in a constant and referenced \em Ebook
     *  \return true if the ebooks are similar, false otherwise
     */
    virtual bool operator==(const Ebook&) const;
};

#endif // EBOOK_H
