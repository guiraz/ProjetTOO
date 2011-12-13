#include "docs.h"

Docs::Docs() : _name("NC"), _reference("nC"), _yearReleased(0)
{
}

Docs::Docs(const std::string &name,const std::string &ref,const int &year)
{
    _name=name;
    _reference=ref;
    _yearReleased=year;
}

Docs::~Docs()
{
}

std::string Docs::getName() const
{
    return _name;
}

void Docs::setName(const std::string& name)
{
    _name=name;
}

std::string Docs::getRef() const
{
    return _reference;
}

void Docs::setRef(const std::string& ref)
{
    _reference=ref;
}

void Docs::setYear(const int & year)
{
    _yearReleased=year;
}

int Docs::getYear() const
{
    return _yearReleased;
}

Docs& Docs::operator=(const Docs& doc)
{
    _reference=doc.getRef();
    _name=doc.getName();
    _yearReleased=doc.getYear();
    return *this;
}

bool Docs::operator==(const Docs& doc) const
{
    return ((_reference==doc.getRef()) && (_name==doc.getName()) && (_yearReleased==doc.getYear()));
}
