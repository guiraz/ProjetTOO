#ifndef READ_H
#define READ_H
/*!
 * \file read.h
 * \brief This file contains a read's representation class
 * \author Loïc IRLES
 * \version 0.1
 */
#include <cstring>
#include "docs.h"
/*! \class Read
   * \brief Read's representation class
   *
   * This class represents a Read wich inherit from \em Docs
   */
class Read : virtual public Docs
{
protected:
    std::string _autor;/*!< Read's autor*/

public:
    /*!
     *  \brief Constructor
     *
     *  Read class's constructor
     */
    Read();
    /*!
     *  \brief Constructor
     *
     *  Read class's constructor with arguments
     *
     *  \param[in] autor : read's autor in a constant and referenced \em std::string
     *  \param[in] name : read's name in a constant and referenced \em std::string
     *  \param[in] ref : read's reference in a constant and referenced \em std::string
     *  \param[in] year : read's year of edition in a constant and referenced \em int
     */
    Read(const std::string &autor,const std::string &name,const std::string &ref,const int &year);
    /*!
     *  \brief Destructor
     *
     *  Read class's virtual destructor
     */
    virtual ~Read();

    /*!
     *  \brief Get the type
     *
     *  Access to the type of the document (here : read)<br />
     *  Virtual and constant
     *
     *  \return type of the document in std::string (here : "Lecture")
     */
    virtual std::string getType() const;
    /*!
     *  \brief Get the autor
     *
     *  Access to the autor of the read (get)<br />
     *  Member : \a _autor<br />
     *  Virtual and constant
     *
     *  \return autor of the read in a \em std::string
     */
    virtual std::string getAutor() const;
    /*!
     *  \brief Set the autor
     *
     *  Access to the autor of the read (set)<br />
     *  Member : \a _autor<br />
     *  Virtual
     *
     *  \param[in] autor : autor of the read constant and referenced \em std::string
     */
    virtual void setAutor(const std::string&);

    /*!
     *  \brief Affectations operator
     *
     *  Affects a \em Read to a \em Read<br />
     *  Virtual
     *
     *  \param[in] read : the other read in a constant and referenced \em Read
     *  \return a reference of this* read
     */
    virtual Read& operator=(const Read&);
    /*!
     *  \brief Comparisons operator
     *
     *  Compares two \em Read<br />
     *  Virtual and constant
     *
     *  \param[in] read : the other read in a constant and referenced \em Read
     *  \return true if the reads are similar, false otherwise
     */
    virtual bool operator==(const Read&) const;
};

#endif // READ_H
