#ifndef MUSIC_H
#define MUSIC_H
/*!
 * \file music.h
 * \brief This file contains a music's representation class
 * \author Guillaume RAZIMBAUD
 * \version 0.1
 */
#include<cstring>
#include"docs.h"
#include"multimedia.h"
/*! \class Music
   * \brief Music's representation class
   *
   * This class represents a music wich inherit from \em Multimedia and \em Docs
   */
class Music : public Multimedia
{
private:
    std::string _band;/*!< Music's band*/
public:

    /*!
     *  \brief Constructor
     *
     *  Music class's constructor
     */
    Music();
    /*!
     *  \brief Constructor
     *
     *  Music class's constructor with arguments
     *
     *  \param[in] band : music's band in a constant and referenced \em std::string
     *  \param[in] mount : music's mount in a constant and referenced \em std::string
     *  \param[in] name : music's name in a constant and referenced \em std::string
     *  \param[in] ref : music's reference in a constant and referenced \em std::string
     *  \param[in] year : music's year of release in a constant and referenced \em int
     */
    Music(const std::string &band ,const std::string &mount,const std::string &name,const std::string &ref,const int &year);
    /*!
     *  \brief Destructor
     *
     *  Music class's virtual destructor
     */
    virtual ~Music();

    /*!
     *  \brief Get the type
     *
     *  Access to the type of the document (here : music)<br />
     *  Virtual and constant
     *
     *  \return type of the document in std::string (here : "Musique")
     */
    virtual std::string getType() const;
    /*!
     *  \brief Set the band
     *
     *  Access to the band of the music (set)<br />
     *  Member : \a _band<br />
     *  Virtual
     *
     *  \param[in] band : band of the music constant and referenced \em std::string
     */
    virtual void setBand(const std::string&);
    /*!
     *  \brief Get the band
     *
     *  Access to the band of the music (get)<br />
     *  Member : \a _band<br />
     *  Virtual and constant
     *
     *  \return band of the music in a \em std::string
     */
    virtual std::string getBand() const;

    /*!
     *  \brief Affectations operator
     *
     *  Affects a \em Music to a \em Music<br />
     *  Virtual
     *
     *  \param[in] mus : the other music in a constant and referenced \em Music
     *  \return a reference of this* music
     */
    virtual Music& operator=(const Music&);
    /*!
     *  \brief Comparisons operator
     *
     *  Compares two \em Music<br />
     *  Virtual and constant
     *
     *  \param[in] mus : the other music in a constant and referenced \em Music
     *  \return true if the musics are similar, false otherwise
     */
    virtual bool operator==(const Music&) const;
};

#endif // MUSIC_H
