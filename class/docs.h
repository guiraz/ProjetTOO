#ifndef DOCS_H
#define DOCS_H
#include <cstring>
#include<iostream>

class Docs
{
protected:
   std::string _name;
   std::string _reference;
   int _yearReleased;
public:
    //CONSTRUCT
    Docs();
    Docs(const std::string &name,const std::string &ref,const int &year);
    virtual ~Docs();

    //ACCESS
    std::string getName() const;
    void setName(const std::string&);
    std::string getRef() const;
    void setRef(const std::string&);
    void setYear(const int&);
    int getYear() const;

    //PURE VIRTUAL FUNCTIONS
    virtual std::string getType()=0;

    //OPERATOR
    virtual Docs& operator=(const Docs&);
    virtual bool operator==(const Docs&) const;
};

#endif // DOCS_H
