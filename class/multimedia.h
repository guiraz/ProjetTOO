#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include<cstring>
#include"docs.h"

class Multimedia : virtual public Docs
{
protected:
    std::string _mount;
public:
    //CONSTRUCT
    Multimedia();
    Multimedia(const std::string &mount,const std::string &name,const std::string &ref,const int &year);
    virtual ~Multimedia();

    //ACCESS
    virtual std::string getMount() const;
    virtual void setMount(const std::string&);

    //PURE VIRTUAL FUNCTIONS
    virtual std::string getType()=0;

    //OPERATOR
    virtual Multimedia& operator=(const Multimedia&);
    virtual bool operator==(const Multimedia&) const;
};

#endif // MULTIMEDIA_H
