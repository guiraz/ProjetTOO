#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
/*!
 * \file multimedia.h
 * \brief This file contains a multimedia's representation class
 * \author Guillaume RAZIMBAUD
 * \version 0.1
 */
#include<cstring>
#include"docs.h"
/*! \class Multimedia
   * \brief Multimedia's representation class
   *
   * This class represents a multimedia wich inherit from \em Docs
   */
class Multimedia : virtual public Docs
{
protected:
    std::string _mount;/*!< Multimedia's mount*/
public:
    /*!
     *  \brief Constructor
     *
     *  Multimedia class's constructor
     */
    Multimedia();
    /*!
     *  \brief Constructor
     *
     *  Multimedia class's constructor with arguments
     *
     *  \param[in] mount : multimedia's mount in a constant and referenced \em std::string
     *  \param[in] name : multimedia's name in a constant and referenced \em std::string
     *  \param[in] ref : multimedia's reference in a constant and referenced \em std::string
     *  \param[in] year : multimedia's year of edition in a constant and referenced \em int
     */
    Multimedia(const std::string &mount,const std::string &name,const std::string &ref,const int &year);
    /*!
     *  \brief Destructor
     *
     *  Multimedia class's virtual destructor
     */
    virtual ~Multimedia();

    /*!
     *  \brief Get the mount
     *
     *  Access to the mount of the multimedia (get)<br />
     *  Member : \a _mount<br />
     *  Virtual and constant
     *
     *  \return mount of the multimedia in a \em std::string
     */
    virtual std::string getMount() const;
    /*!
     *  \brief Set the mount
     *
     *  Access to the mount of the multimedia (set)<br />
     *  Member : \a _mount<br />
     *  Virtual
     *
     *  \param[in] mount : mount of the multimedia constant and referenced \em std::string
     */
    virtual void setMount(const std::string&);
    /*!
     *  \brief Get the type
     *
     *  Access to the type of the document (here : multimedia)<br />
     *  Virtual and constant
     *
     *  \return type of the document in std::string (here : "Multimedia")
     */
    virtual std::string getType() const;

    /*!
     *  \brief Affectations operator
     *
     *  Affects a \em Multimedia to a \em Multimedia<br />
     *  Virtual
     *
     *  \param[in] mul : the other book in a constant and referenced \em Multimedia
     *  \return a reference of this* multimedia
     */
    virtual Multimedia& operator=(const Multimedia&);
    /*!
     *  \brief Comparisons operator
     *
     *  Compares two \em Multimedia<br />
     *  Virtual and constant
     *
     *  \param[in] mul : the other multimedia in a constant and referenced \em Multimedia
     *  \return true if the multimedias are similar, false otherwise
     */
    virtual bool operator==(const Multimedia&) const;
};

#endif // MULTIMEDIA_H
