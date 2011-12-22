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
    Comic(const std::string& autor, const std::string& name, const std::string& ref, const int& year);
    virtual ~Comic();

    //ACCESS
    virtual std::string getType() const;

    //OPERATOR
    virtual Comic& operator=(const Comic&);
    virtual bool operator==(const Comic&) const;
};

#endif // COMIC_H
