#ifndef FILM_H
#define FILM_H
/*!
 * \file film.h
 * \brief This file contains a film's representation class
 * \author Guillaume RAZIMBAUD
 * \version 0.1
 */
#include<cstring>
#include"multimedia.h"
#include"docs.h"
/*! \class Film
   * \brief Film's representation class
   *
   * This class represents a film wich inherit from \em Multimedia and \em Docs
   */
class Film : public Multimedia
{
protected:
    std::string _director;/*!< Film's director*/
public:

    /*!
     *  \brief Constructor
     *
     *  Film class's constructor
     */
    Film();
    /*!
     *  \brief Constructor
     *
     *  Film class's constructor with arguments
     *
     *  \param[in] director : film's director in a constant and referenced \em std::string
     *  \param[in] mount : film's mount in a constant and referenced \em std::string
     *  \param[in] name : film's name in a constant and referenced \em std::string
     *  \param[in] ref : film's reference in a constant and referenced \em std::string
     *  \param[in] year : film's year of release in a constant and referenced \em int
     */
    Film(const std::string &director ,const std::string &mount,const std::string &name,const std::string &ref,const int &year);
    /*!
     *  \brief Destructor
     *
     *  Film class's virtual destructor
     */
    virtual ~Film();

    /*!
     *  \brief Get the type
     *
     *  Access to the type of the document (here : film)<br />
     *  Virtual and constant
     *
     *  \return type of the document in std::string (here : "Film")
     */
    virtual std::string getType() const;
    /*!
     *  \brief Get the director
     *
     *  Access to the director of the film (get)<br />
     *  Member : \a _director<br />
     *  Virtual and constant
     *
     *  \return director of the film in a \em std::string
     */
    virtual std::string getDirector() const;
    /*!
     *  \brief Set the director
     *
     *  Access to the director of the film (set)<br />
     *  Member : \a _director<br />
     *  Virtual
     *
     *  \param[in] director : director of the film constant and referenced \em std::string
     */
    virtual void setDirector(const std::string&);

    /*!
     *  \brief Affectations operator
     *
     *  Affects a \em Film to a \em Film<br />
     *  Virtual
     *
     *  \param[in] film : the other film in a constant and referenced \em Film
     *  \return a reference of this* film
     */
    virtual Film& operator=(const Film&);
    /*!
     *  \brief Comparisons operator
     *
     *  Compares two \em Film<br />
     *  Virtual and constant
     *
     *  \param[in] film : the other film in a constant and referenced \em Film
     *  \return true if the books are similar, false otherwise
     */
    virtual bool operator==(const Film&) const;
};

#endif // FILM_H
