#include "videogame.h"

VideoGame::VideoGame() : Multimedia(), _console("NC")
{
}

VideoGame::VideoGame(const std::string &console ,const std::string &mount,const std::string &name,const std::string &ref,const int &year):Multimedia(mount,name,ref,year)
{
    _console=console;
}

VideoGame::~VideoGame()
{
}

//ACCESS

std::string VideoGame::getType()
{
    return "Jeux Video";
}

void VideoGame::setConsole(const std::string& console)
{
    _console=console;
}

std::string VideoGame::getConsole() const
{
    return _console;
}

//OPERATOR
VideoGame& VideoGame::operator=(const VideoGame& vg)
{
    this->Multimedia::operator =(vg);
    _console=vg.getConsole();
    return *this;
}

bool VideoGame::operator ==(const VideoGame& vg) const
{
    return ((this->Multimedia::operator ==(vg)) && (_console==vg.getConsole()));
}
