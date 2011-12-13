#include "comic.h"

Comic::Comic() : Read()
{
}

Comic::~Comic()
{
}

std::string Comic::getType()
{
    return "Bande Dessiné";
}

Comic& Comic::operator =(const Comic& bd)
{
    this->Read::operator =(bd);
    return *this;
}

bool Comic::operator ==(const Comic& bd) const
{
    return (this->Read::operator ==(bd));
}
