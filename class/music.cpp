#include "music.h"

Music::Music() : Multimedia(), _band("NC")
{
}

Music::Music(const std::string &band, const std::string &mount, const std::string &name, const std::string &ref, const int &year):Multimedia(mount,name,ref,year)
{
    _band=band;
}

Music::~Music()
{
}

//ACCESS
std::string Music::getType()
{
    return "Musique";
}

void Music::setBand(const std::string& band)
{
    _band=band;
}

std::string Music::getBand() const
{
    return _band;
}

//OPERATOR
Music& Music::operator=(const Music& mus)
{
    this->Multimedia::operator =(mus);
    _band=mus.getBand();
    return *this;
}

bool Music::operator==(const Music& mus) const
{
    return ((this->Multimedia::operator ==(mus)) && (_band==mus.getBand()));
}
