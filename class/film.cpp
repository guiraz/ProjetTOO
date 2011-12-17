#include "film.h"


//CONSTRUCT****************************************************
Film::Film() : Multimedia(), _director("NC")
{
}

Film::Film(const std::string &director ,const std::string &mount,const std::string &name,const std::string &ref,const int &year): Docs(name, ref, year), Multimedia(mount,name,ref,year)
{
    _director=director;
}

Film::~Film()
{
}


//ACCESS*******************************************************
std::string Film::getType()
{
    return "Film";
}

std::string Film::getDirector() const
{
    return _director;
}

void Film::setDirector(const std::string& director)
{
    _director=director;
}


//OPERATOR*****************************************************
Film& Film::operator=(const Film& film)
{
    this->Multimedia::operator =(film);
    _director=film.getDirector();
    return *this;
}

bool Film::operator ==(const Film& film) const
{
    return ((this->Multimedia::operator ==(film)) && (_director==film.getDirector()));
}
