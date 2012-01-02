#ifndef VIDEOGAME_H
#define VIDEOGAME_H
/*!
 * \file videogame.h
 * \brief This file contains a book's representation class
 * \author GUILLAUME RAZIMBAUD
 * \version 0.1
 */
#include<cstring>
#include"docs.h"
#include"multimedia.h"
/*! \class VideoGame
   * \brief VideoGame's representation class
   *
   * This class represents a video game wich inherit from \em Multimedia and \em Docs
   */
class VideoGame : public Multimedia
{
protected:
    std::string _console;/*!< VideoGame's console*/
public:

    /*!
     *  \brief Constructor
     *
     *  VideoGame class's constructor
     */
    VideoGame();
    /*!
     *  \brief Constructor
     *
     *  VideoGame class's constructor with arguments
     *
     *  \param[in] console : video game's console in a constant and referenced \em std::string
     *  \param[in] mount : video game's mount in a constant and referenced \em std::string
     *  \param[in] name : video game's name in a constant and referenced \em std::string
     *  \param[in] ref : video game's reference in a constant and referenced \em std::string
     *  \param[in] year : video game's year of edition in a constant and referenced \em int
     */
    VideoGame(const std::string &console ,const std::string &mount,const std::string &name,const std::string &ref,const int &year);
    /*!
     *  \brief Destructor
     *
     *  VideoGame class's virtual destructor
     */
    virtual ~VideoGame();

    /*!
     *  \brief Get the type
     *
     *  Access to the type of the document (here : video game)<br />
     *  Virtual and constant
     *
     *  \return type of the document in std::string (here : "Jeux Video")
     */
    virtual std::string getType() const;
    /*!
     *  \brief Set the console
     *
     *  Access to the console of the video game (set)<br />
     *  Member : \a _console<br />
     *  Virtual
     *
     *  \param[in] console : console of the video game constant and referenced \em std::string
     */
    virtual void setConsole(const std::string&);
    /*!
     *  \brief Get the console
     *
     *  Access to the console of the video game (get)<br />
     *  Member : \a _console<br />
     *  Virtual and constant
     *
     *  \return console of the video game in a \em std::string
     */
    virtual std::string getConsole() const;

    /*!
     *  \brief Affectations operator
     *
     *  Affects a \em VideoGame to a \em VideoGame<br />
     *  Virtual
     *
     *  \param[in] video game : the other video game in a constant and referenced \em VideoGame
     *  \return a reference of this* video game
     */
    virtual VideoGame& operator=(const VideoGame&);
    /*!
     *  \brief Comparisons operator
     *
     *  Compares two \em VideoGame<br />
     *  Virtual and constant
     *
     *  \param[in] video game : the other video game in a constant and referenced \em VideoGame
     *  \return true if the video games are similar, false otherwise
     */
    virtual bool operator==(const VideoGame&) const;
};

#endif // VIDEOGAME_H
