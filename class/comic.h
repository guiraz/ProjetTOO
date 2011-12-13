#ifndef COMIC_H
#define COMIC_H
#include<cstring>
#include"docs.h"
#include"read.h"

class Comic : public Read
{
public:
    //CONSTRUCT
    Comic();
    virtual ~Comic();

    //ACCESS
    virtual std::string getType();

    //OPERATOR
    virtual Comic& operator=(const Comic&);
    virtual bool operator==(const Comic&) const;
};

#endif // COMIC_H
