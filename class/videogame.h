#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include<cstring>
#include"docs.h"
#include"multimedia.h"

class VideoGame : public Multimedia
{
protected:
    std::string _console;
public:

    //CONSTRUCT
    VideoGame();
    VideoGame(const std::string &console ,const std::string &mount,const std::string &name,const std::string &ref,const int &year);
    virtual ~VideoGame();

    //ACCESS
    virtual std::string getType();
    void setConsole(const std::string&);
    std::string getConsole() const;

    //OPERATOR
    virtual VideoGame& operator=(const VideoGame&);
    virtual bool operator==(const VideoGame&) const;
};

#endif // VIDEOGAME_H
