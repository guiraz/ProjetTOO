#ifndef BOOK_H
#define BOOK_H
#include<cstring>
#include"docs.h"
#include"read.h"

class Book : public Read
{
protected:
    std::string _style;
public:
    //CONSTRUCT
    Book();
    Book(const std::string &style,const std::string &autor,const std::string &name,const std::string &ref,const int &year);
    virtual ~Book();

    //ACCESS
    virtual std::string getType();
    void setStyle(const std::string&);
    std::string getStyle() const;

    //OPERATOR
    virtual Book& operator=(const Book&);
    virtual bool operator==(const Book&) const;
};

#endif // BOOK_H
