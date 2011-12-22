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
    
    //VIRTUAL FUNCTIONS FOR DAUGHTERS
    
      //Read
      virtual std::string getAutor() const;
      virtual void setAutor(const std::string&);
      
      //Multimedia
      virtual std::string getMount() const;
      virtual void setMount(const std::string&);
      
      //Book
      virtual void setStyle(const std::string&);
      virtual std::string getStyle() const;
      
      //Film
      virtual std::string getDirector() const;
      virtual void setDirector(const std::string&);
      
      //Music
      virtual void setBand(const std::string&);
      virtual std::string getBand() const;
    
      //VideoGames
      virtual void setConsole(const std::string&);
      virtual std::string getConsole() const;

      //ALL
      virtual std::string getType() const;

    //OPERATOR
    virtual Docs& operator=(const Docs&);
    virtual bool operator==(const Docs&) const;
};

#endif // DOCS_H
