#include "multimedia.h"

Multimedia::Multimedia() : Docs(), _mount("NC")
{
}

Multimedia::Multimedia(const std::string &mount,const std::string &name,const std::string &ref,const int &year) : Docs(name,ref,year)
{
    _mount=mount;
}

Multimedia::~Multimedia()
{
}

std::string Multimedia::getType() const
{
    return"";
}

std::string Multimedia::getMount() const
{
    return _mount;
}

void Multimedia::setMount(const std::string& mount)
{
    _mount=mount;
}

Multimedia& Multimedia::operator=(const Multimedia& mul)
{
    this->Docs::operator =(mul);
    _mount=mul.getMount();
    return *this;
}

bool Multimedia::operator==(const Multimedia& mul) const
{
    return ((_mount==mul.getMount()) && (this->Docs::operator ==(mul)));
}
