#ifndef READ_H
#define READ_H
#include <cstring>
#include "docs.h"

class Read : virtual public Docs
{
protected:
    std::string _autor;

public:
    //CONSTRUCT
    Read();
    Read(const std::string &autor,const std::string &name,const std::string &ref,const int &year);
    virtual ~Read();

    //ACCESS
    std::string getAutor() const;
    void setAutor(const std::string&);

    //PURE VIRTUAL FUNCTIONS
    virtual std::string getType() =0;

    //OPERATOR
    virtual Read& operator=(const Read&);
    virtual bool operator==(const Read&) const;
};

#endif // READ_H
