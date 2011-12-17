#include "ebook.h"

Ebook::Ebook() : Read(), Multimedia()
{
}

Ebook::Ebook(const std::string& autor, const std::string& mount, const std::string& name, const std::string& ref, const int& year) : Docs(name, ref, year), Read(autor, name, ref, year), Multimedia(mount, name, ref, year)
{
}

Ebook::~Ebook()
{
}

std::string Ebook::getType()
{
    return "Livre Numérique";
}

Ebook& Ebook::operator =(const Ebook& eb)
{
    this->Read::operator =(eb);
    this->Multimedia::operator =(eb);
    return *this;
}

bool Ebook::operator ==(const Ebook& eb) const
{
    return ((this->Read::operator ==(eb)) && (this->Multimedia::operator ==(eb)));
}
