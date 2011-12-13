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
    virtual ~Ebook();

    //ACCESS
    virtual std::string getType();

    //OPERATOR
    virtual Ebook& operator=(const Ebook&);
    virtual bool operator==(const Ebook&) const;
};

#endif // EBOOK_H
