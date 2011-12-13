#include "book.h"

Book::Book() : Read(), _style("NC")
{
}

Book::Book(const std::string &style,const std::string &autor,const std::string &name,const std::string &ref,const int &year) : Read(autor,name,ref,year)
{
    _style=style;
}

Book::~Book()
{
}

std::string Book::getType()
{
    return "Livre";
}

void Book::setStyle(const std::string & style)
{
    _style=style;
}

std::string Book::getStyle() const
{
    return _style;
}

Book& Book::operator =(const Book& book)
{
    this->Read::operator =(book);
    _style=book.getStyle();
    return *this;
}

bool Book::operator ==(const Book& book) const
{
    return ((this->Read::operator ==(book)) && (_style==book.getStyle()));
}
