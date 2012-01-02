#ifndef DOCS_H
#define DOCS_H
/*!
 * \file docs.h
 * \brief This file contains a document's representation class
 * \author Guillaume RAZIMBAUD
 * \version 0.1
 */
#include <cstring>
#include<iostream>
/*! \class Docs
  * \brief Document's representation class
  *
  *  This class represents a document
  */
class Docs
{
protected:
   std::string _name;/*!< Document's name*/
   std::string _reference;/*!< Document's reference*/
   int _yearReleased;/*!< Document's year of release*/
public:
   /*!
    *  \brief Constructor
    *
    *  Document class's constructor
    */
    Docs();
    /*!
     *  \brief Constructor
     *
     *  Document class's constructor
     *
     *  \param[in] name : Document's name in a constant and referenced \em std::string
     *  \param[in] ref : Document's reference in a constant and referenced \em std::string
     *  \param[in] year : Document's year of release in a constant and referenced \em int
     */
    Docs(const std::string &name,const std::string &ref,const int &year);
    /*!
     *  \brief Destructor
     *
     *  Document class's virtual destructor
     */
    virtual ~Docs();

    /*!
     *  \brief Get the name
     *
     *  Access to the name of the Document (get)<br />
     *  Member : \a _name<br />
     *  Constant
     *
     *  \return the name of the Document in a \em std::string
     */
    std::string getName() const;
    /*!
     *  \brief Set the name
     *
     *  Access to the name of the Document (set)<br />
     *  Member : \a _name
     *
     *  \param[in] name :  the name of the Document in a constant and referenced \em std::string
     */
    void setName(const std::string&);
    /*!
     *  \brief Get the reference
     *
     *  Access to the reference of the Document (get)<br />
     *  Member : \a ref<br />
     *  Constant
     *
     *  \return the reference of the Document in a \em std::string
     */
    std::string getRef() const;
    /*!
     *  \brief Set the reference
     *
     *  Access to the reference of the Document (set)<br />
     *  Member : \a _ref
     *
     *  \param[in] ref :  the reference of the Document in a constant and referenced \em std::string
     */
    void setRef(const std::string&);
    /*!
     *  \brief Set the year of release
     *
     *  Access to the year of release of the Document (set)<br />
     *  Member : \a _yearReleased
     *
     *  \param[in] year : the year of release of the Document in a constant and referenced \em int
     */
    void setYear(const int&);
    /*!
     *  \brief Get the year of release
     *
     *  Access to the year of release of the Document (get)<br />
     *  Member : \a _yearReleased<br />
     *  Constant
     *
     *  \return the year of release of the Document in a \em int
     */
    int getYear() const;
    
    /*!
     *  \brief Get the autor
     *
     *  Access to the autor of the Document (get)<br />
     *  Member : \a _autor<br />
     *  Constant and virtual
     *
     *  \return the autor of the Document in a \em std::string
     */
      virtual std::string getAutor() const;
    /*!
     *  \brief Set the autor
     *
     *  Access to the autor of the Document (set)<br />
     *  Member : \a _autor<br />
     *  Virtual
     *
     *  \param[in] autor :  the autor of the Document in a constant and referenced \em std::string
     */
      virtual void setAutor(const std::string&);
      
    /*!
     *  \brief Get the mount
     *
     *  Access to the mount of the Document (get)<br />
     *  Member : \a _mount<br />
     *  Constant and virtual
     *
     *  \return the mount of the Document in a \em std::string
     */
      virtual std::string getMount() const;
    /*!
     *  \brief Set the mount
     *
     *  Access to the mount of the Document (set)<br />
     *  Member : \a _mount<br />
     *  Virtual
     *
     *  \param[in] mount :  the mount of the Document in a constant and referenced \em std::string
     */
      virtual void setMount(const std::string&);
      
    /*!
     *  \brief Set the style
     *
     *  Access to the style of the Document (set)<br />
     *  Member : \a _style<br />
     *  Virtual
     *
     *  \param[in] style :  the style of the Document in a constant and referenced \em std::string
     */
      virtual void setStyle(const std::string&);
    /*!
     *  \brief Get the style
     *
     *  Access to the style of the Document (get)<br />
     *  Member : \a _style<br />
     *  Constant and virtual
     *
     *  \return the style of the Document in a \em std::string
     */
      virtual std::string getStyle() const;
      
    /*!
     *  \brief Get the director
     *
     *  Access to the director of the Document (get)<br />
     *  Member : \a _director<br />
     *  Constant and virtual
     *
     *  \return the director of the Document in a \em std::string
     */
      virtual std::string getDirector() const;
    /*!
     *  \brief Set the director
     *
     *  Access to the director of the Document (set)<br />
     *  Member : \a _director<br />
     *  Virtual
     *
     *  \param[in] director :  the director of the Document in a constant and referenced \em std::string
     */
      virtual void setDirector(const std::string&);
      
    /*!
     *  \brief Set the band
     *
     *  Access to the band of the Document (set)<br />
     *  Member : \a _band<br />
     *  Virtual
     *
     *  \param[in] band :  the band of the Document in a constant and referenced \em std::string
     */
      virtual void setBand(const std::string&);
    /*!
     *  \brief Get the band
     *
     *  Access to the band of the Document (get)<br />
     *  Member : \a _band<br />
     *  Constant and virtual
     *
     *  \return the band of the Document in a \em std::string
     */
      virtual std::string getBand() const;
    
    /*!
     *  \brief Set the console
     *
     *  Access to the console of the Document (set)<br />
     *  Member : \a _console<br />
     *  Virtual
     *
     *  \param[in] console :  the console of the Document in a constant and referenced \em std::string
     */
      virtual void setConsole(const std::string&);
    /*!
     *  \brief Get the console
     *
     *  Access to the console of the Document (get)<br />
     *  Member : \a _console<br />
     *  Constant and virtual
     *
     *  \return the console of the Document in a \em std::string
     */
      virtual std::string getConsole() const;

    /*!
     *  \brief Get the type
     *
     *  Access to the type of the Document (here : Document)<br />
     *  Constant and virtual
     *
     *  \return the type of the Document in a \em std::string
     */
      virtual std::string getType() const;

    /*!
     *  \brief Affectations operator
     *
     *  Affects a \em Docs to a \em Docs<br />
     *  Virtual
     *
     *  \param[in] doc : the other document in a constant and referenced \em Docs
     *  \return a reference of this* document
     */
    virtual Docs& operator=(const Docs&);
    /*!
     *  \brief Comparisons operator
     *
     *  Compares two \em Docs<br />
     *  Virtual and constant
     *
     *  \param[in] doc : the other document in a constant and referenced \em Docs
     *  \return true if the documents are similar, false otherwise
     */
    virtual bool operator==(const Docs&) const;
};

#endif // DOCS_H
