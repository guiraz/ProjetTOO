#ifndef FILM_H
#define FILM_H
#include<cstring>
#include"multimedia.h"
#include"docs.h"

class Film : public Multimedia
{
protected:
    std::string _director;
public:

    //CONSTRUCT
    Film();
    Film(const std::string &director ,const std::string &mount,const std::string &name,const std::string &ref,const int &year);
    virtual ~Film();

    //ACCESS
    virtual std::string getType();
    std::string getDirector() const;
    void setDirector(const std::string&);

    //OPERATOR
    virtual Film& operator=(const Film&);
    virtual bool operator==(const Film&) const;
};

#endif // FILM_H
