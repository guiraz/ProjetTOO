#include "ebook.h"

Ebook::Ebook() : Read(), Multimedia()
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
