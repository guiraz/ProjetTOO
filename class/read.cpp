#include "read.h"

Read::Read() : Docs(), _autor("NC")
{
}

Read::Read(const std::string &autor,const std::string &name,const std::string &ref,const int &year) : Docs(name,ref,year)
{
    _autor=autor;
}

Read::~Read()
{
}

std::string Read::getType() const
{
    return"";
}

std::string Read::getAutor() const
{
    return _autor;
}

void Read::setAutor(const std::string & autor)
{
    _autor=autor;
}

Read& Read::operator=(const Read& read)
{
    this->Docs::operator =(read);
    _autor=read.getAutor();
    return *this;
}

bool Read::operator==(const Read& read) const
{
    return ((this->Docs::operator ==(read)) && (_autor==read.getAutor()));
}
