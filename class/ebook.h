#ifndef EBOOK_H
#define EBOOK_H
#include<cstring>
#include"docs.h"
#include"multimedia.h"
#include"read.h"

class Ebook : virtual public Docs, public Read, public Multimedia
{
public:
    //CONSTRUCT
    Ebook();
    Ebook(const std::string& autor, const std::string& mount, const std::string& name, const std::string& ref, const int& year);
    virtual ~Ebook();

    //ACCESS
    virtual std::string getType() const;

    //OPERATOR
    virtual Ebook& operator=(const Ebook&);
    virtual bool operator==(const Ebook&) const;
};

#endif // EBOOK_H
