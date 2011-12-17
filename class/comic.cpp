#include "comic.h"

Comic::Comic() : Read()
{
}

Comic::Comic(const std::string& autor, const std::string& name, const std::string& ref, const int& year) : Docs(name, ref, year), Read(autor, name, ref, year)
{
}

Comic::~Comic()
{
}

std::string Comic::getType()
{
    return "Bande Dessinée";
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
